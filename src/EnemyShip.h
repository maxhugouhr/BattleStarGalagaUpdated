//
// Created by jingl on 6/17/2019.
//

#ifndef SFML_TEMPLATE_ENEMYSHIP_H
#define SFML_TEMPLATE_ENEMYSHIP_H
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class EnemyShip {
private:
    int _health;
    double _speed, _xPos, _yPos, _startXPos, _startYPos;
    int _deathCD;
    bool _attacking;
    int _timesKilled;
    bool _active;
    Sprite _enemyShipSprite;
    Texture _texture;

public:
    EnemyShip(double startingX, double startingY);
    int getHealth() const;
    double getSpeed() const;
    double getXPosition() const;
    double getYPosition() const;
    double getXStart() const;
    double getYStart() const;
    int getDeathCD() const;
    bool isAttacking() const;
    bool isOffScreen() const;
    bool isActive() const;
    int getTimesKilled() const;
    void incrementTimesKilled();

    void setXPos(double xpos);
    void decrementDeathCD();
    void setYPos(double ypos);
    void setXStart(double xstart);
    void setYStart(double ystart);
    void updatePositionStraight();
    void updatePositionDiagonal();
    bool attackRoll();
    void makeActive();
    void deactivate();
    void makeAttack();
    void stopAttack();
    Sprite getSprite();
    void setSpriteTexture(Texture &tex);

};


#endif //SFML_TEMPLATE_ENEMYSHIP_H
