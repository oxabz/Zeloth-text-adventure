//
// Created by oxabz on 30/06/19.
//

#include <SFML/Graphics.hpp>
#include "class/View/GameView.h"


int main() {

    GameView * view = new GameView();
    view->getRunThread()->join();
    return 0;
}