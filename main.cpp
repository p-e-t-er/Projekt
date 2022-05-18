#include <iostream>
#include "Game.h"

int main()
{
    //Inicjalizacja Generatora losowania//
    std::srand(static_cast<unsigned>(time(NULL)));
    //Inicializacja silnika gry//
    Game game;


    //Pętla gry//
    while(game.running())
    {   
        //Aktualizacja//
        game.update();

        //Renderowanie//
        game.render();
        
    }

    return 0;
}
