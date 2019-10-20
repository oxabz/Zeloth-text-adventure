//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_DRAWABLEELEMENT_H
#define ZELOTH_DRAWABLEELEMENT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class DrawableElement : public Drawable{
private:
    /*
     * ATTRIBUTES
     */

    Vector2i position;
    Vector2i size;

protected:
    virtual void draw(RenderTarget &target, RenderStates states) const override = 0;

public:

    /*
     * CONSTRUCTOR
     */

    DrawableElement();

    /*
     * GETTER SETTER
     */

    //Position
    const Vector2i &getPosition() const;

    virtual void setPosition(const Vector2i &position);

    //Size
    const Vector2i &getSize() const;

    virtual void setSize(const Vector2i &size);
};


#endif //ZELOTH_DRAWABLEELEMENT_H
