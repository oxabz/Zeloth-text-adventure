//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_ASPECTRATIOELEMENT_H
#define ZELOTH_ASPECTRATIOELEMENT_H


#include "DrawableElement.h"

class AspectRatioElement : public virtual DrawableElement{
private:
    Vector2i space;
    float ratio; // ratio=x/y // x=ratio*y // y=x/ratio
public:
    AspectRatioElement();

    void setRatio(float ratio);

    void setSize(const Vector2i &size) override;
};


#endif //ZELOTH_ASPECTRATIOELEMENT_H
