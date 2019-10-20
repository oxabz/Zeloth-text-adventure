//
// Created by oxabz on 02/07/19.
//

#ifndef ZELOTH_ELEMENTCONTAINER_H
#define ZELOTH_ELEMENTCONTAINER_H

#include <map>
#include "DrawableElement.h"

using std::map;
using std::string;

class ElementContainer : public virtual DrawableElement{
private:

    /*
     * ATTRIBUTES
     */

    int id;

protected:

    /*
     * ATTRIBUTS
     */

    map<string, DrawableElement *> components;

    mutable bool shapeChanged;

    /*
     * METHODS
     */

    void draw(RenderTarget &target, RenderStates states) const override;
    virtual void doLayout()const  = 0 ;

public:

    /*
     * CONSTRUCTOR
     */

    ElementContainer();

    /*
     * METHODS
     */

    int getNewId();

    /*
     * GETTER SETTER
     */

    void addComponent(DrawableElement *  component);
    void addComponent(string key, DrawableElement * component);

    DrawableElement * getComponent(string key);

    void removeComponent(string key);

    bool isShapeChanged() const;

    void setShapeChanged(bool shapeChanged);
};


#endif //ZELOTH_ELEMENTCONTAINER_H
