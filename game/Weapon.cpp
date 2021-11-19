#include "Weapon.h"
#include "Hitbox.h"

#include <iostream>
#include <stdlib.h> 

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


void Weapon::weaponBreak()
{
	this->canUse = false;
}

bool Weapon::deflect()
{
	return false;
}


void Weapon::followPlayer()
{

}

int Weapon::useDamage()
{
	int critcal = (this->critChance);
	int randomNumber = (rand() % 100);
	int damage = (this->attackDamage * this->armorPen);
	if (randomNumber < critChance + 1) {
		int damage = (this->attackDamage * (1 + this->armorPen*0.01)) * 1.5;
	}

	return damage;
}

// call use when attack occurs
bool Weapon::use()
{
	if (this->canUse) {
		// attack or whatever


		this->Durability -= 1;

		if (this->Durability <= 0) {
			this->weaponBreak();
		}

		return true;
	}
	return false;
}


