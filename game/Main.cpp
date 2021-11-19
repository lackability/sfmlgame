#include <iostream>
#include "Weapon.h"
#include "Enemy.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


int main() {
    //Define Events
    //creates the window of 1200 x 900 with the the title "test" and default minimize,and close
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Test", sf::Style::Default);
    sf::Event ev;
    sf::Music music;

    sf::Texture playerrightTexture;
    sf::Texture playerleftTexture;

    sf::Texture weapontexturerightKnife;
    sf::Texture weapontextureleftKnife;

    sf::Texture enemytextureSkeleton;   
    sf::Sprite weaponKnife;
    sf::Sprite player;
    sf::Sprite enemySkeleton;


    //hitbox test, check mouse1 event for more test
    sf::IntRect hitbox(300,300,64,64);
    sf::RectangleShape testBox(sf::Vector2f(64, 64)); 


    //objects
    Player user;
    user.sprite = player;
    user.maxHealth = 100;
    user.currentHealth = 60;

    Enemy enemytestSkeleton;
    enemytestSkeleton.sprite = enemySkeleton;
    enemytestSkeleton.maxHealth = 100;
    enemySkeleton.setPosition(300, 300);

    Weapon testKnife;
    testKnife.sprite = weaponKnife;
    testKnife.attackRange = 50;

    //Healthbar
    sf::RectangleShape maxhealthPlayer(sf::Vector2f(user.maxHealth, 20));
    sf::RectangleShape currenthealthPlayer(sf::Vector2f(user.currentHealth, 20));

    maxhealthPlayer.setFillColor(sf::Color::Red);
    currenthealthPlayer.setFillColor(sf::Color(32, 199, 64));



    // create a class in one of the members


    //GUI SETUP
    sf::Font font;
    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString("Menu"); 
    menuText.setCharacterSize(108);
    menuText.setFillColor(sf::Color::Blue);
    menuText.setStyle(sf::Text::Regular);
    menuText.setPosition(sf::Vector2f(window.getSize().x - window.getSize().x/2 - menuText.getCharacterSize(), window.getSize().y - window.getSize().y/1.1));

    sf::Text optionsText;
    optionsText.setFont(font);
    optionsText.setString("Options");
    optionsText.setCharacterSize(56);
    optionsText.setFillColor(sf::Color::Blue);
    optionsText.setStyle(sf::Text::Regular);
    optionsText.setPosition(sf::Vector2f(window.getSize().x - window.getSize().x / 2 - menuText.getCharacterSize(), window.getSize().y - window.getSize().y / 1.4));

    //menu outline
    sf::RectangleShape menuOutline(sf::Vector2f(1200, 900));
    menuOutline.setFillColor(sf::Color(250,100,150));


    //loads things
    if (!enemytextureSkeleton.loadFromFile("sprites/enemy.png")) {
        std::cout << "enemy gone" << std::endl;
    }
    if (!weapontexturerightKnife.loadFromFile("sprites/knife.png")) {
        std::cout << "knife gone" << std::endl;
    }
    if (!weapontextureleftKnife.loadFromFile("sprites/knife2.png")) {
        std::cout << "knife left gone" << std::endl;
    }
    if (!playerrightTexture.loadFromFile("sprites/sprite1.png")) {
        std::cout << "error image right" << std::endl;
    }
    if (!playerleftTexture.loadFromFile("sprites/sprite2.png")) {
        std::cout << "left gone" << std::endl;
    }
    if (!music.openFromFile("audio/background.wav")) {
        std::cout << "music gone" << std::endl;
    }
    if (!font.loadFromFile("font/AmaticSC-Regular.ttf")) {
        std::cout << "Error: font not loaded" << std::endl;
    }

    //after load
    music.setVolume(5);
    music.play();
    //setting textures
    player.setTexture(playerrightTexture);
    player.setPosition(150, 500);
    enemySkeleton.setTexture(enemytextureSkeleton);
    weaponKnife.setTexture(weapontexturerightKnife);



    //Game
    while (window.isOpen()) {

        //allows for closure of the window through titlebar
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
        }

        maxhealthPlayer.setPosition(sf::Vector2f(player.getPosition().x - (user.maxHealth / 4), player.getPosition().y - 35));
        currenthealthPlayer.setPosition(sf::Vector2f(player.getPosition().x - (user.maxHealth/4), player.getPosition().y - 35));

        // using inputs
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(sf::Vector2f(0, -0.5));
            weaponKnife.setPosition(sf::Vector2f(weaponKnife.getPosition().x, player.getPosition().y + 32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //flipping towards left side
            player.setTexture(playerleftTexture);
            player.move(sf::Vector2f(-0.5, 0));
            weaponKnife.setTexture(weapontextureleftKnife);
            weaponKnife.setPosition(sf::Vector2f(player.getPosition().x - 50, player.getPosition().y + 32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(sf::Vector2f(0, 0.5));
            weaponKnife.setPosition(sf::Vector2f(weaponKnife.getPosition().x, player.getPosition().y + 32));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //flipping towards right side
            player.setTexture(playerrightTexture);
            player.move(sf::Vector2f(0.5, 0));
            weaponKnife.setTexture(weapontexturerightKnife);
            weaponKnife.setPosition(sf::Vector2f(player.getPosition().x + 50, player.getPosition().y + 32));
        }


        //Render
        window.clear(sf::Color::White); // clear Frame
        window.draw(player);
        window.draw(testBox);
        window.draw(enemySkeleton);
        window.draw(maxhealthPlayer);
        window.draw(currenthealthPlayer);

        //mouse1 events
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (hitbox.contains(sf::Mouse::getPosition(window))) {
                user.currentHealth = user.currentHealth - 0.1;
                currenthealthPlayer.setSize(sf::Vector2f(user.currentHealth, 20));
                std::cout << user.currentHealth << std::endl;
            }
            window.draw(weaponKnife);
            window.draw(testKnife.sprite);
        }

        if (user.currentHealth <= 0) {
            window.close();
        }
        
        //esc key events
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.draw(menuOutline);
            window.draw(menuText);
            window.draw(optionsText);
        }



        // Draw game
        window.display(); // tell that window is done drawing
    }

    //end of game

    return 0;
}