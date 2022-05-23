#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Testing");

    Menu menu(window.getSize().x, window.getSize().y); 

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch(ev.type){
            case sf::Event::KeyReleased:
                switch (ev.key.code){
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();  
                    break;  
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Return:
                    switch(menu.PressedItem()){
                        case 0:
                            std::cout << "Play" << std::endl;
                            break;
                        case 1:
                            window.close();
                            //std::cout << "Quit" <<std::endl;
                            break;
                        }
                        break;  
                    }
                    break;
                case sf::Event::Closed:
                window.close();
                break;   
            }
        }

        window.clear();

        menu.draw(window);

        window.display();
    }

    return 0;
}