//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_BACKGROUNDEDELEMENT_H
#define ZELOTH_BACKGROUNDEDELEMENT_H


#include "DrawableElement.h"

class BackgroundedElement : public virtual DrawableElement{
private:
    Color bgColor;
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

public:
    BackgroundedElement();

    const Color &getBgColor() const;
    void setBgColor(const Color &bgColor);
};


#endif //ZELOTH_BACKGROUNDEDELEMENT_H
