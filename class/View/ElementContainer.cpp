//
// Created by oxabz on 02/07/19.
//

#include "ElementContainer.h"

int ElementContainer::getNewId() {
    return ++id;
}

ElementContainer::ElementContainer() {
    id = 0;
    components.clear();
}

DrawableElement* ElementContainer::getComponent(string key) {
    return components[key];
}

void ElementContainer::addComponent(DrawableElement *component) {
    addComponent(std::to_string(getNewId()), component);
}

void ElementContainer::addComponent(string key, DrawableElement *component) {
    components.emplace(key,component);
}

void ElementContainer::removeComponent(string key) {
    components.erase(key);
}

void ElementContainer::draw(RenderTarget &target, RenderStates states) const {
    if(shapeChanged){
        this->doLayout();
        shapeChanged = false;
    }
    for (auto i = components.begin(); i!=components.end(); ++i){
        Drawable &d = *(i->second);
        target.draw(d,states);
    }
}

bool ElementContainer::isShapeChanged() const {
    return shapeChanged;
}

void ElementContainer::setShapeChanged(bool shapeChanged) {
    for (auto i = components.begin(); i!=components.end(); ++i){
        if (ElementContainer * e = dynamic_cast<ElementContainer*>(i->second)){
            e->setShapeChanged(true);
        }
    }
    ElementContainer::shapeChanged = shapeChanged;
}
