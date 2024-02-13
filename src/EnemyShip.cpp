//
// Created by Max Uhr on 6/17/2019.
//

#include "EnemyShip.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
#include <cmath>

#include <SFML/Graphics.hpp>
using namespace sf;

int EnemyShip::getHealth() const {
    return _health;
}

double EnemyShip::getSpeed() const {
    return _speed;
}

double EnemyShip::getXPosition() const {
    return _xPos;
}

double EnemyShip::getYPosition() const {
    return _yPos;
}

double EnemyShip::getXStart() const {
    return _startXPos;
}

double EnemyShip::getYStart() const {
    return _startYPos;
}

int EnemyShip::getDeathCD() const {
    return _deathCD;
}


void EnemyShip::setXPos(double xpos) {
    _xPos = xpos;
}

void EnemyShip::setYPos(double ypos) {
    _yPos = ypos;
}

void EnemyShip::setXStart(double xstart) {
    _startXPos = xstart;
}

void EnemyShip::setYStart(double ystart) {
    _startYPos = ystart;
}

int EnemyShip::getTimesKilled() const {
    return _timesKilled;
}

void EnemyShip::updatePositionStraight() {
    _yPos += _speed;
    _enemyShipSprite.setPosition(_xPos, _yPos);
}

void EnemyShip::incrementTimesKilled() {
    if (_timesKilled < 20) {
        _timesKilled++;
        _speed += 0.25;
    }
}

void EnemyShip::updatePositionDiagonal() {
    if (_startXPos < (255/2 - 40)) {
        _xPos = _xPos + 0.6 * _speed;
    } else if (_startXPos > (255/2 + 40)) {
        _xPos = _xPos - 0.6 * _speed;
    }
    _yPos += _speed;
    _enemyShipSprite.setPosition(_xPos, _yPos);
}

bool EnemyShip::isAttacking() const {
    return _attacking;
}

bool EnemyShip::isOffScreen() const {
    if (_yPos > 255 || _xPos < -20 || _xPos > 255) {
        return 1;
    }
    return 0;
}

bool EnemyShip::attackRoll() {
    if (rand() % (30 * 30 - _timesKilled * 30) == 1) {
        return 1;
    }
    return 0;
}

void EnemyShip::makeAttack() {
    _attacking = 1;
}

void EnemyShip::stopAttack() {
    _attacking = 0;
}

bool EnemyShip::isActive() const {
    return _active;
}

void EnemyShip::makeActive() {
    _active = 1;
}

void EnemyShip::deactivate() {
    _active = 0;
}

Sprite EnemyShip::getSprite()  {
    return _enemyShipSprite;
}

void EnemyShip::decrementDeathCD() {
    if (_deathCD > 0) {
        _deathCD--;
    } else {
        _deathCD = 30 * 5;
        _active = 1;
        _attacking = 0;
        _xPos = _startXPos;
        _yPos = _startYPos;
        _enemyShipSprite.setPosition(_startXPos, _startYPos);
    }
}

EnemyShip::EnemyShip(double startingX, double startingY) {
    _startYPos = startingY;
    _startXPos = startingX;
    _xPos = startingX;
    _yPos = startingY;
    _speed = 8;
    _health = 1;
    _active = 1;
    _deathCD = 30 * 5;
    _timesKilled = 0;
    _attacking = 0;
    _enemyShipSprite.setScale(1.5,1.5);
    _enemyShipSprite.setPosition(_xPos, _yPos);
}

void EnemyShip::setSpriteTexture(Texture &tex) {
    _enemyShipSprite.setTexture(tex);
}


