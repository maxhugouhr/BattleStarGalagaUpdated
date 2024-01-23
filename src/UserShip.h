//
// Created by jingl on 6/17/2019.
//

#ifndef SFML_TEMPLATE_USERSHIP_H
#define SFML_TEMPLATE_USERSHIP_H
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class UserShip {
private:
    double _xPos, _yPos; //position
    int _life; //remaining health
    double _speed; //movement speed
    int _attackCD; //auto-fire attack cooldown
    int _laserStock; //number of lasers in stock
    int _timeCD; //cooldown on time stop mechanic
    int _harpoonStock; //number of harpoons in stock
    bool _timeActive; //is time stop active
    Sprite _userShipSprite;
    Texture _texture;

public:
    UserShip(); //generates the standard user ship
    double getXPosition() const;
    double getYPosition() const;
    int getLife() const;
    int getLaserStock() const;
    int getTimeCD() const;
    int getHarpoonStock() const;
    bool isTimeActive() const;
    bool isOffScreenRight() const; //is the ship too far right
    bool isOffScreenLeft() const; //is the ship too far left
    Sprite getSprite()const; //returns sprite image
    int getAttackCD() const;

    void setXPosition(double xpos);
    void decrementLife();
    void incrementLaser(); //add a laser stock
    void incrementHarpoon(); //add a harpoon stock
    void decrementLaser(); //drop a laser stock
    void decrementHarpoon(); //drop a harpoon stock
    void setTimeCD(int timcd);
    void moveRight(); //move the ship right
    void moveLeft(); //move the ship left
    void incrementAttackCD(); //bump up the auto-fire cooldown
    void resetAttackCD(); //reset the auto-fire cooldown
    void teleport(double xpos); //teleport to a given location (for the harpoons)
    void setSpriteTexture(Texture &tex);

};


#endif //SFML_TEMPLATE_USERSHIP_H
