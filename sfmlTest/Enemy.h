#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy
{
	public:
		sf::Sprite sprite;
		float maxHealth;
		float healthRegen;
		float armor;
		float resistance;
		bool hitReg();
};

