//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_SCROLL_H
#define ZELOTH_SCROLL_H


#include "ElementContainer.h"
#include "BackgroundedElement.h"
#include "AspectRatioElement.h"
#include "WrappedTextElement.h"
#include "ScrollingText.h"

class Scroll : public ElementContainer, public BackgroundedElement, public AspectRatioElement{
private:
    ScrollingText * text;
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    void doLayout() const override;
public:
    Scroll();

    void scrollUp();
    void scrollDown();
};


#endif //ZELOTH_SCROLL_H
