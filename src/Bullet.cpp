//
// Created by jingl on 6/17/2019.
//

#include "Bullet.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

double Bullet::getXPos() const {
    return _xPos;
}

double Bullet::getYPos() const {
    return _yPos;
}

double Bullet::getHeight() const {
    return _height;
}

double Bullet::getWidth() const {
    return _width;
}

RectangleShape Bullet::getRectangleShape() const {
    return _rectangle;
}

void Bullet::setXPos(double xpos) {
    _xPos = xpos;
}

void Bullet::setYPos(double ypos) {
    _yPos = ypos;
}

void Bullet::updatePosition() {
    if (_userBullet && !_isHarpoon && !_isLaser) {
        _yPos = _yPos - _speed;
    } else if (!_userBullet) {
        _yPos = _yPos + _speed;
    } else if (_userBullet && _isHarpoon) {
        _xPos = _xPos + _harpoonDirection * _speed   ;
    }

    _rectangle.setPosition(_xPos, _yPos);
}

bool Bullet::isOffScreen() const {
    if (_yPos > 255 || _yPos < _height || _xPos < 0 || _xPos > 245) {
        return 1;
    }
    return 0;
}

short Bullet::getHarpoonDirection() const {
    return _harpoonDirection;
}

void Bullet::setHarpoonDirection(int direc) {
    _harpoonDirection = direc;
}

bool Bullet::isLaser() const {
    return _isLaser;
}

short Bullet::getLaserFrameCount() const {
    return _laserFrameCount;
}

void Bullet::decrementLaser() {
    _laserFrameCount--;
}

Bullet::Bullet(double xPos, double yPos, double width, double height, bool userBullet, bool laser, bool harpoon) {
    _xPos = xPos;
    _yPos = yPos;
    _width = width;
    _height = height;
    _userBullet = userBullet;
    _rectangle.setFillColor(Color::White);
    _rectangle.setSize(Vector2f(_width, _height));
    _rectangle.setPosition(_xPos, _yPos);
    _isHarpoon = harpoon;
    _isLaser = laser;

    if (harpoon) {
        _speed = 5;
    } else {_speed = 15;}
    if (laser) {
        _laserFrameCount = 3;
    } else {_laserFrameCount = -1;}
}

bool Bullet::isHarpoon() const {
    if (_isHarpoon) {
        return 1;
    }
    return 0;
}