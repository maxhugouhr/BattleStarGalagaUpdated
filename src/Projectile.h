//
// Created by Max Uhr on 2/11/2024
//

#ifndef SFML_TEMPLATE_PROJECTILE_H
#define SFML_TEMPLATE_PROJECTILE_H
#include "Flyer.h"
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include <iomanip>

#include<SFML/Graphics.hpp>

class Projectile : protected Flyer {

private:

	int _damage;
	int _health; //will be -1 for indestructible

public:

	int getDamage() const;
	int getHealth() const;
	
};


#endif // !SFML_TEMPLATE_PROJECTILE_H
