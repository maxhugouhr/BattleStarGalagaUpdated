//
// Created by Max Uhr on 6/17/2019.
//

#ifndef SFML_TEMPLATE_FLYER_H
#define SFML_TEMPLATE_FLYER_H
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>


#include <SFML/Graphics.hpp>

//The Flyer class is the backbone of any moving object including ships, bullets, bombs, etc. 

class Flyer {
protected:

	int _health;
	std::pair<double, double> _velocity; //will be scaled based on the resolution of the screen
	std::pair<double, double> _position; //will be scaled based on the resolution of the screen
	sf::Sprite _sprite;
	std::pair<double, double> _dimensions;


public:

	Flyer(std::pair<double, double> startPosition, std::pair<double, double> startVelocity, std::pair<double, double>startDimemsions, int health, sf::Texture& texture);
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

#endif //SFML_TEMPLATE_FLYER_H