//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_WRAPPEDTEXTELEMENT_H
#define ZELOTH_WRAPPEDTEXTELEMENT_H


#include "DrawableElement.h"

using std::string;

class WrappedTextElement : public virtual DrawableElement{
private:
    /*
     * ATTRIBUTES
     */

    string unprocessedText;
    sf::Text * textElement;

    /*
     * METHODS
     */

    string getProcessedText();

public:
    WrappedTextElement(const String &string, const Font &font, unsigned int characterSize);

    void setString(const String &string);

    void setSize(const Vector2i &size) override;

    Text *getTextElement();

    Texture getTextTexture();

private:
    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //ZELOTH_WRAPPEDTEXTELEMENT_H
