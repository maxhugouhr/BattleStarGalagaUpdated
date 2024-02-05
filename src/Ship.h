//
// Created by jingl on 6/17/2019.
//

#ifndef SFML_TEMPLATE_SHIP_H
#define SFML_TEMPLATE_SHIP_H
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Ship {
private:
	int _health;
	double[2] _velocity; //will be scaled based on the resolution of the screen
	int[2] _position; //will be scaled based on the resolution of the screen
	Sprite _shipSprite;
	Texture _texture;

public:
	Ship(int[2] startingPosition, double[2] startingVelocity);
	int getHealth() const;
	double[2] getVelocity() const;
	double[2] getPosition() const;
	void setPosition(double[2] newPosition);
	void setVelocity(double[2] newVelocity);
	void move();
	Sprite getSprite() const;
	void setSpriteTexture(Texture &tex);
};