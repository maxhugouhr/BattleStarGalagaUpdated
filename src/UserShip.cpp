//
// Created by jingl on 6/17/2019.
//

#include "UserShip.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;



UserShip::UserShip() {
    _yPos = 255 - 25;
    _xPos = 100;
    _life = 3;
    _laserStock = 1;
    _harpoonStock = 1;
    _timeActive = 0;
    _timeCD = 0;
    _speed = 8;
    _attackCD = -1;

    _userShipSprite.setScale(2, 2);
    _userShipSprite.setPosition(_xPos, _yPos);
}

double UserShip::getYPosition() const {
    return _yPos;
}

Sprite UserShip::getSprite() const {
    return _userShipSprite;
}

int UserShip::getLife() const {
    return _life;
}

int UserShip::getLaserStock() const {
    return _laserStock;
}

int UserShip::getTimeCD() const {
    return _timeCD;
}

int UserShip::getHarpoonStock() const {
    return _harpoonStock;
}

bool UserShip::isTimeActive() const {
    return _timeActive;
}

void UserShip::setXPosition(double xpos) {
    _xPos = xpos;
}

void UserShip::incrementLaser() {
    _laserStock++;
}

void UserShip::incrementHarpoon() {
    _harpoonStock++;
}

void UserShip::decrementLaser() {
    _laserStock--;
}

void UserShip::decrementHarpoon() {
    _harpoonStock--;
}

void UserShip::setTimeCD(int timecd) {
    _timeCD = timecd;
}

void UserShip::moveRight() {
    _xPos = _xPos + _speed;
    _userShipSprite.setPosition(_xPos, _yPos);
}

void UserShip::moveLeft() {
    _xPos = _xPos - _speed;
    _userShipSprite.setPosition(_xPos, _yPos);
}

bool UserShip::isOffScreenRight() const {
    if (_xPos > 225) {
        return 1;
    }
    return 0;
}

bool UserShip::isOffScreenLeft() const {
    if (_xPos  < 10) {
        return 1;
    }
    return 0;
}

int UserShip::getAttackCD() const {
    return _attackCD;
}

double UserShip::getXPosition() const {
    return _xPos;
}

void UserShip::incrementAttackCD() {
    _attackCD++;
}

void UserShip::resetAttackCD() {
    _attackCD = -1;
}

void UserShip::teleport(double xpos) {
    _xPos = xpos;
    _userShipSprite.setPosition(_xPos, _yPos);
}

void UserShip::setSpriteTexture(Texture &tex) {
    _userShipSprite.setTexture(tex);
}

void UserShip::decrementLife(){
    _life--;
}