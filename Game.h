#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

//Pozycja myszki//    
sf::Vector2i mousePosition;

//Logika gry//

int points;
float enemySpawnTimer;
float enemySpawnTimerMax;
int maxEnemies;

//Obiekty//
std::vector<sf::CircleShape> enemies;
sf::CircleShape enemy;

//Prywatne funkcje//
    void initVaribles();
    void initWindow(); 
    void initEnemies();

public:
//Konstruktor i Destruktor//
    Game();
    virtual ~Game();

    const bool running() const;

//Funkcje//
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();
    void renderEnemies();
    void render();
};