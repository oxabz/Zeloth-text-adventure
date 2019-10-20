//
// Created by oxabz on 02/07/19.
//

#include "WrappedTextElement.h"

WrappedTextElement::WrappedTextElement(const String &string, const Font &font, unsigned int characterSize)  {
    unprocessedText = string;
    textElement = new Text(string,font,characterSize);
}

string WrappedTextElement::getProcessedText() {
    string processedText = unprocessedText;
    sf::Font * f = new Font();
    f->loadFromFile("arial.ttf");
    int s = 0;
    if(textElement != nullptr){
        string str = textElement->getString();
         f = (Font * )textElement->getFont();
         s = textElement->getCharacterSize();
    }
    Text * text = new Text(processedText,*f,s);
    View view = View();
    text->setPosition(0,0);
    int lastSpace = 0;
    int i = 0;
    while (i < processedText.length()){
        if (processedText[i] == ' '){
            lastSpace = i;
        }

        if (getSize().x < text->findCharacterPos(i).x){
            processedText[lastSpace] = '\n';
            text->setString(processedText);
        }
        i++;
    }
    return processedText;
}

void WrappedTextElement::setString(const String &string) {
    unprocessedText = string;
    textElement->setString(getProcessedText());
}

void WrappedTextElement::setSize(const Vector2i &size) {
    DrawableElement::setSize(size);
    textElement->setString(getProcessedText());
}

void WrappedTextElement::draw(RenderTarget &target, RenderStates states) const {
    textElement->setPosition(Vector2f(getPosition()));
    target.draw(*this->textElement,states);
}

Text *WrappedTextElement::getTextElement() {
    return textElement;
}

Texture WrappedTextElement::getTextTexture() {
    Image image = Image();
    string s = textElement->getString();
    image.create(textElement->getLocalBounds().width,textElement->getLocalBounds().height,Color(0,0,0,0));
    textElement->setPosition(0,0);
    for (int i = 0; i < s.length(); ++i) {
        IntRect posGlyph = textElement->getFont()->getGlyph((Uint32)s[i],textElement->getCharacterSize(), false).textureRect;
        Image characterSheet = textElement->getFont()->getTexture(textElement->getCharacterSize()).copyToImage();
        Vector2f v = textElement->findCharacterPos(i);
        image.copy(characterSheet,v.x,v.y,posGlyph, true);
    }
    Texture texture;
    texture.loadFromImage(image,IntRect());
    image = texture.copyToImage();
    return texture;
}

