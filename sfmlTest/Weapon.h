#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Weapon {
	public:
		sf::Sprite sprite;
		bool canUse;
		float attackDamage;
		float attackSpeed;
		float attackRange;
		float critChance;
		float armorPen;
		int Durability;
		bool use();
		void weaponBreak();
		bool deflect();
		void followPlayer();
		int useDamage();
};

