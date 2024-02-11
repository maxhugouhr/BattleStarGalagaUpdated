//
//created by jingl on 2/10/2024

#include "Ship.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>


#include <SFML/Graphics.hpp>


int Ship::getHealth() const {
	return _health;
}

std::pair<double, double> Ship::getVelocity() const {
	return _velocity;
}

std::pair<double, double> Ship::getPosition() const {
	return _position;
}

void Ship::setDimensions(double width, double height) {
	_dimensions.first = width;
	_dimensions.first = height;
}

void Ship::setPosition(double xPos, double yPos) {
	_position = std::pair<double, double>{ xPos, yPos };
}

void Ship::setVelocity(double xVel, double yVel) {
	_velocity = std::pair<double, double>{ xVel, yVel };
}

void Ship::setHealth(int inc) {
	_health = _health + inc;
}

void Ship::move() {
	_position.first = _position.first + _velocity.first;
	_position.second = _position.second + _velocity.second;
}

sf::Sprite Ship::getSprite() const{
	return _shipSprite;
}


Ship::Ship(std::pair<double, double> sPos, std::pair<double, double> sVel, std::pair<double,double>sDim, int health, sf::Texture& tex) {
	_position = sPos;
	_velocity = sVel;
	_health = health;
	_shipSprite.setTexture(tex);
	_dimensions = sDim;
}
