//
// Created by oxabz on 02/07/19.
//

#include "GameView.h"

/*
 * ///////////////////////////////////////////////////////////////
 * /////////////////////////PRIVATE///////////////////////////////
 * ///////////////////////////////////////////////////////////////
 */

/*
 * CONSTANT
 */

const Vector2i GameView::WINDOW_SIZE(600,500);
const string GameView::WINDOW_TITLE("titre");

/*
* THREAD
 */

void GameView::run() {
    while (this->isOpen()){
        //Event treatment
        Event event;
        while (this->pollEvent(event)){
            if (event.type == Event::Closed){
                exit(0);
            } else if (event.type == Event::Resized){
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                this->setView(sf::View(visibleArea));
            } else if (event.type == Event::MouseWheelScrolled ){
                if(event.mouseWheelScroll.delta<0) {
                    scroll->scrollUp();
                } else if (event.mouseWheelScroll.delta>0){
                    scroll->scrollDown();
                }
            }
        }

        //Do display
        this->clear();//Clearing the screen

        //Drawing
        scroll->setSize((Vector2i)getSize());
        scroll->setPosition(Vector2i(0,0));
        scroll->setShapeChanged(true);
        draw(*scroll);


        setView(getDefaultView());
        this->display();//Displaying the screen
    }
}

/*
 * ///////////////////////////////////////////////////////////////
 * //////////////////////////PUBLIC///////////////////////////////
 * ///////////////////////////////////////////////////////////////
 */

GameView::GameView()
        : RenderWindow(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, Style::Default) {
    scroll = new Scroll();
    scroll->setBgColor(Color::Green);
    scroll->setRatio(0.75);


    sf::Font * font = new Font();
    if(font->loadFromFile("arial.ttf")){

    }
    textElement = new WrappedTextElement("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur eleifend malesuada elementum. Integer ut ullamcorper mauris, a interdum eros. Maecenas ut pulvinar velit, id eleifend nulla. Integer non dui massa. In quis condimentum quam. Fusce blandit, massa sed gravida pharetra, mi eros pharetra purus, sit amet vestibulum massa risus imperdiet enim. Ut sagittis, mauris id viverra pulvinar, lectus dolor tristique tortor, nec sollicitudin elit sem ut metus. Integer tempus facilisis libero, vitae iaculis risus egestas ac. Quisque enim tellus, tempor sed justo eu, tristique facilisis ex. Suspendisse id venenatis augue, vel tempus quam. Mauris quis sem eu risus elementum pulvinar imperdiet in nisl. Suspendisse potenti. Nunc convallis accumsan orci et scelerisque.",
                                         *font,
                                         25);
    textElement->getTextElement()->setFillColor(Color::Blue);
    textElement->setPosition(Vector2i(50,50));

    sprite = new Sprite(textElement->getTextTexture());

    runThread = new thread(&GameView::run,this);

}

thread *GameView::getRunThread() const {
    return runThread;
}
