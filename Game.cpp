#include "Game.h"
//Prywatne funkcje//
void Game::initVaribles(){

    this->window = nullptr;
    //Logika gry//
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;


}

void Game::initWindow(){

    this->videoMode.height = 480;
    this->videoMode.width = 640;
    
    this->window = new sf::RenderWindow(this->videoMode,"Falling Objects", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);

}

void Game::initEnemies(){

    this->enemy.setPosition(10.f,10.f);
    this->enemy.setRadius(50.f);
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
    this->enemy.setFillColor(sf::Color::Green);

}

//Konstruktory i Destruktory//
Game::Game(){

    this->initVaribles();
    this->initWindow();
    this->initEnemies();
}

Game::~Game(){

    delete this->window;

}
//Funkcja 
const bool Game::running() const{

    return this->window->isOpen();

}
//Funkcje//
void Game::spawnEnemy(){

    this->enemy.setPosition(
        static_cast<float>(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getRadius())),0.f
    );

    this->enemy.setFillColor(sf::Color::Green);

    //Spawn objektu(wroga)//
    this->enemies.push_back(this->enemy);

}
void Game::pollEvents(){

        while(this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        
        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }

}
void Game::updateMousePositions(){

    this->mousePosition = sf::Mouse::getPosition(*this->window);

    this->mousePositionView = this->window->mapPixelToCoords(this->mousePosition);

}
void Game::updateEnemies(){
    
    if(this->enemies.size() < this->maxEnemies){

        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
        
    }
    //Ruch objekt??w(wrog??w)//
    for (int i = 0;i < this->enemies.size();i++)
    {
        bool deleted = false;
        
        this->enemies[i].move(0.f,2.f);

        //Je??li klikniemy na objekt(wroga)//
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            if(this->enemies[i].getGlobalBounds().contains(this->mousePositionView)){

                deleted = true;

                this->points += 1;

            }
        }

        //Je??li obiekt spadnie i dotknie ekranu dolnego//
        if(this->enemies[i].getPosition().y > this->window->getSize().y){

            deleted = true;

        }
        //Je??li jest do usuni??cia//
        if(deleted){

            this->enemies.erase(this->enemies.begin() + i);

        }
        
    }
    
}
void Game::update(){

    this->pollEvents();

    this->updateMousePositions();

    this->updateEnemies();


    //Aktualizowanie pozycji myszki//
    //W stosunku do ca??ego ekranu//
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition().x <<" "<< sf::Mouse::getPosition().y << "\n";//
    //W stosunku do okna//
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x <<" "<< sf::Mouse::getPosition(*this->window).y << "\n";

    std::cout << "Points:" << this->points << std::endl;

}
void Game::renderEnemies(){

    //Renderowanie wszytkich objekt??w(wrog??w)//
    for (auto &i : this->enemies)
    {
        this->window->draw(i);
    }

}
void Game::render(){

    //Czyszczenie starych obiekt??w i renderowanie nowych//
    
    this->window->clear();

   //Rysowanie obiekt??w gry 
    this->renderEnemies();

    this->window->display();

}