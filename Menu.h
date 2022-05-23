#pragma once 
#include <iostream>
#include "SFML/Graphics.hpp"

#define MAX_ITEMS 2

class Menu{
    private:
        sf::RenderWindow* window;
        int selectedItem;
        sf::Font font;
        sf::Text menu[MAX_ITEMS];
    public:
        Menu(float width, float height);
        ~Menu();
        const bool running() const;

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();

        int PressedItem(){return selectedItem;}
};