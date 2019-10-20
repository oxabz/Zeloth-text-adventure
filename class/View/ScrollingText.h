//
// Created by oxabz on 05/07/19.
//

#ifndef ZELOTH_SCROLLINGTEXT_H
#define ZELOTH_SCROLLINGTEXT_H


#include "ElementContainer.h"
#include <deque>

using std::deque;
using std::string;

class ScrollingText : public ElementContainer{
private:
    sf::Font * font;


    constexpr static int OFFSET_INCREMENT = 5;

    int offset;
    View * view;
protected:

    void doLayout() const override;

    void draw(RenderTarget &target, RenderStates states) const override;
public:


    ScrollingText();

    void addText(string text);

    void scrollUp();
    void scrollDown();

    void setPosition(const Vector2i &position) override;

    void setSize(const Vector2i &size) override;
};


#endif //ZELOTH_SCROLLINGTEXT_H
