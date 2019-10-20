//
// Created by oxabz on 02/07/19.
//

#include "BackgroundedElement.h"

void BackgroundedElement::draw(RenderTarget &target, RenderStates states) const {
    RectangleShape bg(Vector2f(this->getSize()));
    bg.setPosition(Vector2f(this->getPosition()));
    bg.setFillColor(bgColor);
    target.draw(bg,states);

}

BackgroundedElement::BackgroundedElement() {}

const Color &BackgroundedElement::getBgColor() const {
    return bgColor;
}

void BackgroundedElement::setBgColor(const Color &bgColor) {
    BackgroundedElement::bgColor = bgColor;
}
