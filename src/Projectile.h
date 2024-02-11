//
// Created by Max Uhr on 2/11/2024
//

#ifndef SFML_TEMPLATE_PROJECTILE_H
#define SFML_TEMPLATE_PROJECTILE_H
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include <iomanip>

#include<SFML/Graphics.hpp>

class Projectile {

private:

	std::pair<double, double> _position;
	std::pair<double, double> _velocity;
	int _damage;
	sf::Sprite _sprite;
	std::pair<double, double> _dimensions;
	int _health; //will be -1 for indestructible

public:

	std::pair<double, double> getPosition() const;
	std::pair<double, double> getVelocity() const;
	std::pair<double, double> getDimensions() const;
	int getDamage() const;
	sf::Sprite getSprite() const;
	int getHealth() const;

};


#endif // !SFML_TEMPLATE_PROJECTILE_H
