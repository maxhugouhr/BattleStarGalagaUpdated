//
// Created by Max Uhr on 6/17/2019.
//

#ifndef SFML_TEMPLATE_BULLET_H
#define SFML_TEMPLATE_BULLET_H
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet {

private:
    double _xPos, _yPos; //tracks the x,y position of each bullet
    double _speed; //tracks speed of bullet
    double _height, _width; //tracks hitboxes of bullet
    RectangleShape _rectangle;
    bool _userBullet; //does the bullet belong to the user?
    bool _isLaser; //is the bullet a laser
    bool _isHarpoon; //is the bullet a harpoon
    short _laserFrameCount; //if the bullet is a laser, it appears for a set number of frames.
    short _harpoonDirection;

public:
    double getXPos() const;
    double getYPos() const;
    double getHeight() const;
    double getWidth() const;
    RectangleShape getRectangleShape() const;
    short getHarpoonDirection() const; // which direction is harpoon moving
    short getLaserFrameCount() const;
    bool isHarpoon() const;
    bool isLaser() const;


    void setXPos(double xpos);
    void setYPos(double ypos);
    void setHarpoonDirection(int direc); //-1 for left moving harpoon, 1 for right moving harpoon
    void updatePosition(); //updates the bullet position based on the type of bullet.
    bool isOffScreen() const;
    void decrementLaser(); //counts down the frames left till laser disappears
    Bullet(double xPos, double yPos, double width, double height, bool userBullet, bool laser, bool harpoon);
    // intakes the position of the bullet, the hitbox of the bullet, if the bullet belongs to the user, if it is a
    // harpoon and if it is a laser.


};


#endif //SFML_TEMPLATE_BULLET_H
