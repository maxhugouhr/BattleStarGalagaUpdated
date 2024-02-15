//
//created by Max Uhr on 2/11/2024

#include "Projectile.h"


#include <SFML/Graphics.hpp>

int Projectile::getDamage() const {
	return _damage;
}

int Projectile::getHealth() const {
	return _health;
}