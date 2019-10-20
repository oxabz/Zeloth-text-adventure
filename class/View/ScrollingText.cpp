//
// Created by oxabz on 05/07/19.
//

#include "ScrollingText.h"
#include "WrappedTextElement.h"
#include <iostream>

void ScrollingText::doLayout() const {
    int y = 0;
    for (auto i = components.begin(); i != components.end(); ++i) {
        DrawableElement  * element = i->second;
        element->setPosition(Vector2i(10000,y));
        element->setSize({getSize().x,0});
        y+=dynamic_cast<WrappedTextElement*>(element)->getTextElement()->getLocalBounds().height;
    }
}

void ScrollingText::draw(RenderTarget &target, RenderStates states) const {
    if(shapeChanged){
        this->doLayout();
        shapeChanged = false;
    }

    view->setViewport(FloatRect(
            Vector2f((float)getPosition().x/target.getView().getSize().x,(float)getPosition().y/target.getView().getSize().y),
            Vector2f((float)getSize().x/target.getView().getSize().x, (float) getSize().y/target.getView().getSize().y)));
    view->setCenter(10000+getSize().x/2, getSize().y/2+offset);
    view->setSize(Vector2f(getSize()));


    target.setView(*view);
    for (auto i = components.begin(); i!=components.end(); ++i){
        Drawable &d = *(i->second);
        target.draw(d,states);
    }

    target.setView(target.getDefaultView());
}

ScrollingText::ScrollingText() {
    view = new View();
    font = new Font();
    if(!font->loadFromFile("arial.ttf")){
        std::cout<<"test";
    }
    offset = 0 ;
}

void ScrollingText::addText(string text) {
    addComponent(new WrappedTextElement(text,*font,20));
}

void ScrollingText::setPosition(const Vector2i &position) {
    DrawableElement::setPosition(position);
    setShapeChanged(true);
}

void ScrollingText::setSize(const Vector2i &size) {
    DrawableElement::setSize(size);
    setShapeChanged(true);
}

void ScrollingText::scrollUp() {
    offset += OFFSET_INCREMENT;
}

void ScrollingText::scrollDown() {
    offset -= OFFSET_INCREMENT;
}
