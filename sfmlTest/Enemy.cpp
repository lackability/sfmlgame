#include "Enemy.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//updates the hitbox to the enemy sprite.
bool Enemy::hitReg()
{
    while (this->maxHealth > 0) {
        //sf::IntRect hitbox(this->getPosition().x, this->getPosition().y, 40, 40);
    }
    return false;
}
