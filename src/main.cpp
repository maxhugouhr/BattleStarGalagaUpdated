//Name: Max Uhr
// Final Project: Battlestar Galaga
//Descr: KILL THOSE INVADERS!!

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <cmath>
#include <iomanip>
#include "Bullet.h"
#include "UserShip.h"
#include "EnemyShip.h"
#include <filesystem>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;



int main() {


    bool movingRight = 0, movingLeft = 0, shooting = 0; //keeps track of ship on/off activities
    UserShip userShip; //initializes the usership sprite
    vector<Bullet> activeBullets;
    int mainCounter = 0; //frame counter for laser and harpoon stock
    bool activeHarpoon = 0; //only allows for one active harpoon at a time.
    srand(time(0));
    vector<EnemyShip> enemyVector;
    int score = 0;


    Texture enemyShip1;
    if (!enemyShip1.loadFromFile("C:\\Users\\uhrma\\source\\repos\\BattleStarGalagaUpdated\\data\\EnemyShip1.png")) {
        cerr << "Error Loading Texture, check directory";
        return -1;
    }

    Texture enemyShip2;
    if (!enemyShip2.loadFromFile("C:\\Users\\uhrma\\source\\repos\\BattleStarGalagaUpdated\\data\\EnemyShip2.png")) {
        cerr << "Error Loading Texture";
        return -1;
    }

    Texture userShipTexture;
    if (!userShipTexture.loadFromFile("C:\\Users\\uhrma\\source\\repos\\BattleStarGalagaUpdated\\data\\MainShip.png")) {
        cerr << "Error Loading Texture";
        return -1;
    }

    Texture enemyShip3;
    if (!enemyShip3.loadFromFile("C:\\Users\\uhrma\\source\\repos\\BattleStarGalagaUpdated\\data\\EnemyShip3.png")) {
        cerr << "Error Loading Texture";
        return -1;
    }


    userShip.setSpriteTexture(userShipTexture);


    for (int j = 0; j < 4; j++) { //creates a pyramid of invaders and puts them in a vector
        for (int i = 10 + 25*j; i < 255-20 - 25*j; i++) {
            if (!(i % 20)) {
                EnemyShip invader(i, 20 * j + 10);
                enemyVector.push_back(invader);
            }
        }
    }


    for (int i = 0; i < enemyVector.size(); i++) { //assigns random skins to each invader
        if (rand() % 2) {
            enemyVector[i].setSpriteTexture(enemyShip1);
        } else if (rand() % 3) {
            enemyVector[i].setSpriteTexture(enemyShip2);
        } else {enemyVector[i].setSpriteTexture(enemyShip3);}
    }




    RenderWindow window(VideoMode(255,255), "Battlestar Galaga");
    window.setFramerateLimit(30); //limits framerate to 30fps



    //create a drawing loop
    while (window.isOpen()) {
        window.clear(); //clears the current display contents so it doesn't bleed images


        //---------------------------------------------------------------------------------------------------------------
        // Check for collisions and dead space invader ships and update counters
        //---------------------------------------------------------------------------------------------------------------
        if (userShip.getAttackCD() >= 0) { //keeps track of the auto-fire counter
            userShip.incrementAttackCD();
            if (userShip.getAttackCD() >= 10) {
                userShip.resetAttackCD();
            }
        }

        mainCounter++;
        if (!(mainCounter % (7*30))) { // every 5 seconds, the user will gain a new laser and harpoon stock
            userShip.incrementLaser();
            userShip.incrementHarpoon();
        }

        for (int i = 0; i < activeBullets.size(); i++) { //check all the bullets
            for (int j = 0; j < enemyVector.size(); j++) { //check all the enemies
                if ((activeBullets[i].getXPos() + activeBullets[i].getWidth()) >= enemyVector[j].getXPosition() &&
                    activeBullets[i].getXPos() <= (enemyVector[j].getXPosition() + 9 * 1.5) &&
                    activeBullets[i].getYPos() <= enemyVector[j].getYPosition() && enemyVector[j].isActive() && !enemyVector[j].isAttacking()) { //if the bullet collides with the enemies
                    enemyVector[j].deactivate(); //deactivate the enemy
                    enemyVector[i].incrementTimesKilled(); //makes the enemy  attack more frequently.
                    score++;
                    if (!activeBullets[i].isLaser()) {
                        activeBullets.erase(activeBullets.begin() + i); //destroy the bullet as long as it isn't a laser.aa
                        
                    }
                }

            }
        }

        for (int i = 0; i < enemyVector.size(); i++) {
            if (enemyVector[i].isOffScreen()) { //check if the ship is on screen, deactivate if not
                enemyVector[i].deactivate();
            }
            if (!enemyVector[i].isActive()) { //if the enemy is inactive, decrease it's death cooldown
                enemyVector[i].decrementDeathCD();
            }
            if (enemyVector[i].attackRoll()) { //check if the ship will be attacking
                enemyVector[i].makeAttack();
            }
            if (enemyVector[i].isAttacking()) { //move the attacking ship
                enemyVector[i].updatePositionDiagonal();
            }
            if ((enemyVector[i].getXPosition() + 1.5 * 9) >= userShip.getXPosition() && enemyVector[i].getXPosition() <= (userShip.getXPosition() + 2 * 10) && enemyVector[i].getYPosition() > userShip.getYPosition() && enemyVector[i].isActive()) {
                userShip.decrementLife(); // if the user gets hit by the enemy, drop life, deactivate the enemy and flash the screen
                enemyVector[i].deactivate();
                window.clear(Color::White);
            }
        }

        if (userShip.getLife() == 0) { //endgame at 0 life
            window.close();
            cout << "You lost! Your total score was: " << score << endl; //output the score
        }


        //---------------------------------------------------------------------------------------------------------------
        //  Draw objects
        //---------------------------------------------------------------------------------------------------------------
        window.draw(userShip.getSprite()); //draws the user ship

        for (int i = 0; i < enemyVector.size(); i++) { //draws the enemy invaders
            if (enemyVector.at(i).isActive()) {
                window.draw(enemyVector[i].getSprite());
            }
        }

        for (int i = 0; i < activeBullets.size(); i++) { //draws all of the active bullets
            window.draw(activeBullets[i].getRectangleShape());
        }



        window.display();

        //---------------------------------------------------------------------------------------------------------------
        //  Intake keyboard commands
        //---------------------------------------------------------------------------------------------------------------


        Event event;
        while (window.pollEvent(event)) {
            //event will now hold the Event information
            if (event.type == Event::Closed) { //if the close window was pressed
                window.close(); //window will close
            } else if (event.type == Event::KeyPressed) {

                switch (event.key.code) {
                    case Keyboard::A:
                        movingLeft = 1; //ship will move left until this is set to 0
                        break;
                    case Keyboard::D:
                        movingRight = 1; //ship will move right until this is set to 0
                        break;
                    case Keyboard::Space:
                        shooting = 1; //sets the ship to active shooting mode
                        if (userShip.getAttackCD() == -1) { //if this main gun counter is not active, make it active.
                            userShip.incrementAttackCD();
                        }
                        break;
                    case Keyboard::Right:
                        if (userShip.getHarpoonStock() && !activeHarpoon) { //fires a harpoon if one is available and there is not already an active one
                            Bullet bullet(userShip.getXPosition() + 25, 238, 7, 2, 1, 0, 1); //builds the harpoon
                            bullet.setHarpoonDirection(1); //sets the harpoon to move right
                            activeBullets.push_back(bullet); //adds the harpoon the the vector of active bulelts
                            userShip.decrementHarpoon(); //reduces the number of harpoon available
                            activeHarpoon = 1; //a harpoon is active
                        } else if (activeHarpoon) { //if pressed while a harpoon is active
                            for (int i = 0; i < activeBullets.size(); i++) {
                                if (activeBullets[i].isHarpoon()) {
                                    userShip.teleport(activeBullets[i].getXPos()); //teleport the ship to the harpoon
                                    activeBullets.erase(activeBullets.begin() + i); //remove the harpoon from active bullets
                                    activeHarpoon = 0; //no more active harpoon
                                    break;
                                }
                            }
                        }
                        break;
                    case Keyboard::Left: //see Keyboard::Right
                        if (userShip.getHarpoonStock() && !activeHarpoon) {
                            Bullet bullet(userShip.getXPosition() - 5, 238, 7, 2, 1, 0, 1);
                            bullet.setHarpoonDirection(-1);
                            activeBullets.push_back(bullet);
                            userShip.decrementHarpoon();
                            activeHarpoon = 1;
                        } else if (activeHarpoon) {
                            for (int i = 0; i < activeBullets.size(); i++) {
                                if (activeBullets[i].isHarpoon()) {
                                    userShip.teleport(activeBullets[i].getXPos());
                                    activeBullets.erase(activeBullets.begin() + i);
                                    activeHarpoon = 0;
                                    break;
                                }
                            }
                        }
                        break;
                    case Keyboard::Up:
                        if (userShip.getLaserStock()) { //if the user has available lasers, fire out the laser and remove a stock.
                            Bullet bullet(userShip.getXPosition() + 9, 5, 4, 225, 1, 1, 0); //create the laser
                            activeBullets.push_back(bullet); //add the laser to the active bullets vector
                            userShip.decrementLaser(); //reduce laser stock
                        }
                        break;
                    case Keyboard::Down: //stops time temporarily while still allowing user movement
                        //coming soon to theaters near me!!
                        break;
                }

            } else if (event.type == Event::KeyReleased) {
                switch (event.key.code) {
                    case Keyboard::A:
                        movingLeft = 0; //stop left movement of the ship
                        break;
                    case Keyboard::D:
                        movingRight = 0; //stop right movement of the ship
                        break;
                    case Keyboard::Space:
                        shooting = 0; //deactivate shooting mode.
                        break;
                }
            }
        }


        //---------------------------------------------------------------------------------------------------------------
        // Generate New Bullets
        //---------------------------------------------------------------------------------------------------------------


        if (shooting && userShip.getAttackCD() == -1) { //if space is still held this restarts the attack counter for auto-firing
            userShip.incrementAttackCD();
        }

        if (shooting && !userShip.getAttackCD()) { //if the ship is shooting and the gun is off cooldown
            Bullet bullet(userShip.getXPosition() + 9, userShip.getYPosition() - 10, 2, 7, 1, 0, 0); //create a new bullet
            activeBullets.push_back(bullet); //add to active bullets
        }

        //---------------------------------------------------------------------------------------------------------------
        // Update positions
        //---------------------------------------------------------------------------------------------------------------


        if (movingRight && !userShip.isOffScreenRight()) { //move the user ship right
            userShip.moveRight();
        }

        if (movingLeft && !userShip.isOffScreenLeft()) { //move the user ship left
            userShip.moveLeft();
        }

        for (int i = 0; i < activeBullets.size(); i++) {
            if (activeBullets[i].isOffScreen() && activeBullets[i].getLaserFrameCount() == -1) { //if the bullet is not a laser and no longer on screen
                if (activeBullets[i].isHarpoon()) { //if the bullet is a harpoon, deactivate harpoon bool
                    activeHarpoon = 0;
                }
                activeBullets.erase(activeBullets.begin() + i); //delete the bullet
            }
            if (!activeBullets[i].getLaserFrameCount()) { //once the laser framecount hits zero, stop displaying the laser
                activeBullets.erase(activeBullets.begin() + i);
            } else if (activeBullets[i].getLaserFrameCount() > 0) { //continue laser frame countdown
                activeBullets[i].decrementLaser();
            }
        }

        for (int i = 0; i < activeBullets.size(); i++) { //update the positions of all bullets
            activeBullets[i].updatePosition();
        }



    }



    return 0;
}