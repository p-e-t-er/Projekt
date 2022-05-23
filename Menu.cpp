#include "Menu.h"

Menu::Menu(float width, float height){

    if(!font.loadFromFile("A Smile Can Change The World.ttf")){
        std::cout << "Czcionka niedostępna"<<std::endl;
    }
    
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Blue);
    menu[0].setString("PLAY");
    menu[0].setPosition(sf::Vector2f((width / 2) -25 ,height / (MAX_ITEMS + 1)* 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("QUIT");
    menu[1].setPosition(sf::Vector2f((width / 2)- 25,height / (MAX_ITEMS + 1)* 2));

    selectedItem = 0;
}
Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){

    for(int i = 0; i < MAX_ITEMS; i++){
        window.draw(menu[i]);
    }

}

void Menu::MoveUp(){

    if(selectedItem - 1 >= 0){
        menu[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setColor(sf::Color::Blue);
    }

}
void Menu::MoveDown(){

    if(selectedItem + 1 < MAX_ITEMS){
        menu[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setColor(sf::Color::Blue);
    }    

}