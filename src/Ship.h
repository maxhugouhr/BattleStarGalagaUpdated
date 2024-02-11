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


#include <SFML/Graphics.hpp>


class Ship {
private:

	int _health;
	std::pair<double, double> _velocity; //will be scaled based on the resolution of the screen
	std::pair<double, double> _position; //will be scaled based on the resolution of the screen
	sf::Sprite _shipSprite;
	std::pair<double, double> _dimensions;


public:

	Ship(std::pair<double,double> sPos, std::pair<double,double> sVel, int health, sf::Texture &tex);
	int getHealth() const;
	std::pair<double,double> getVelocity() const;
	std::pair<double,double> getPosition() const;
	std::pair<double, double> getDimensions() const;
	void setDimensions(double, double);
	void setPosition(double, double);
	void setVelocity(double, double);
	void setHealth(int);
	void move();
	sf::Sprite getSprite() const;
};

#endif //SFML_TEMPLATE_SHIP_H