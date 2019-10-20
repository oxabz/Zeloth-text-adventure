//
// Created by oxabz on 02/07/19.
//

#include "DrawableElement.h"

const Vector2i &DrawableElement::getPosition() const {
    return position;
}

void DrawableElement::setPosition(const Vector2i &position) {
    DrawableElement::position = position;
}

const Vector2i &DrawableElement::getSize() const {
    return size;
}

void DrawableElement::setSize(const Vector2i &size) {
    DrawableElement::size = size;
}

DrawableElement::DrawableElement() {}


