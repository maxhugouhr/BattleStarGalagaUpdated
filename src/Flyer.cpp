//
//created by Max Uhr on 2/10/2024

#include "Flyer.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>


#include <SFML/Graphics.hpp>


int Flyer::getHealth() const {
	return _health;
}

std::pair<double, double> Flyer::getVelocity() const {
	return _velocity;
}

std::pair<double, double> Flyer::getPosition() const {
	return _position;
}

void Flyer::setDimensions(double width, double height) {
	_dimensions.first = width;
	_dimensions.first = height;
}

void Flyer::setPosition(double xPos, double yPos) {
	_position = std::pair<double, double>{ xPos, yPos };
}

void Flyer::setVelocity(double xVel, double yVel) {
	_velocity = std::pair<double, double>{ xVel, yVel };
}

void Flyer::setHealth(int inc) {
	_health = _health + inc;
}

void Flyer::move() {
	_position.first = _position.first + _velocity.first;
	_position.second = _position.second + _velocity.second;
}

sf::Sprite Flyer::getSprite() const{
	return _sprite;
}


Flyer::Flyer(std::pair<double, double> sPos, std::pair<double, double> sVel, std::pair<double,double>sDim, int health, sf::Texture& tex) {
	_position = sPos;
	_velocity = sVel;
	_health = health;
	_sprite.setTexture(tex);
	_dimensions = sDim;
}
