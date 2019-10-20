//
// Created by oxabz on 02/07/19.
//

#include "AspectRatioElement.h"

void AspectRatioElement::setSize(const Vector2i &size) {
    space=size;
    Vector2i s;
    if(size.x < ratio*size.y){
        s = Vector2i(size.x,size.x/ratio);
    } else{
        s = Vector2i(size.y*ratio,size.y);
    }
    DrawableElement::setSize(s);
}

AspectRatioElement::AspectRatioElement() {
    space = Vector2i(0,0);
    ratio = 0;
}

void AspectRatioElement::setRatio(float ratio) {
    AspectRatioElement::ratio = ratio;
}
