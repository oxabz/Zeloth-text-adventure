//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_GAMEVIEW_H
#define ZELOTH_GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <thread>
#include "Scroll.h"
#include "WrappedTextElement.h"

using std::string;
using std::thread;
using namespace sf;

class GameView : public RenderWindow {
private:

    /*
     * CONSTANTS
     */

    //Window setting
    static const Vector2i WINDOW_SIZE;
    static const string WINDOW_TITLE;

    /*
     * ATTRIBUTES
     */

    Scroll * scroll;
    WrappedTextElement * textElement;
    Sprite * sprite;

    /*
     * THREAD
     */

    void run();

    thread * runThread;

public:

    /*
     * CONSTRUCTOR
     */

    GameView();

    /*
     * GETTER SETTER
     */

    thread *getRunThread() const;
};


#endif //ZELOTH_GAMEVIEW_H
