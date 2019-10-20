//
// Created by oxabz on 02/07/19.
//

#include "Scroll.h"

Scroll::Scroll() {
    text = new ScrollingText();
    text->addText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed et egestas tellus. Sed lacus dui, varius vitae aliquet a, tincidunt non nulla. Suspendisse dictum risus id blandit bibendum. Duis dapibus posuere orci quis consectetur. Aliquam non dignissim dui. Aliquam cursus massa a leo semper consequat. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque interdum justo sit amet dolor lobortis finibus. Etiam sit amet feugiat lectus, sit amet mollis mauris. Aenean sed tellus nisi.\n");
    text->addText("Phasellus lobortis lacus tincidunt, faucibus tortor eget, interdum lectus. Aliquam efficitur vitae dolor quis molestie. Aliquam non dapibus magna, at interdum lacus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Vivamus mattis tortor eget elit ornare, sed consequat est feugiat. Donec mattis metus gravida maximus pellentesque. Maecenas vel turpis nec elit consectetur posuere in quis enim. Vestibulum convallis scelerisque massa id iaculis. Etiam egestas maximus tristique. Vestibulum semper viverra consequat. Morbi dapibus porttitor nunc sit amet rutrum. Integer commodo lorem odio. Pellentesque vel lacinia magna, ac viverra diam. Nunc nisl elit, aliquet vel quam at, porta facilisis magna. Proin nec metus arcu. In ullamcorper sollicitudin libero luctus commodo.\n");
    text->addText("Nam at sapien at lacus vehicula euismod. Fusce suscipit scelerisque enim, at pulvinar felis consequat in. Suspendisse pretium a nulla eget cursus. Vestibulum sed turpis quis elit pulvinar tincidunt in nec lorem. Vivamus porta at massa eget rutrum. Aenean massa purus, dapibus nec lectus nec, tincidunt scelerisque nisl. Nulla accumsan molestie dui, vel sodales augue accumsan et. Praesent finibus massa orci, sit amet efficitur arcu iaculis et. Mauris nec ante sed ex aliquet ullamcorper. Vivamus vitae lectus elit. Duis malesuada vehicula nunc non ultrices. Nunc imperdiet nibh at elit feugiat, et bibendum mauris convallis.\n");
    text->addText("Nunc consequat, leo et fermentum pulvinar, arcu ligula rutrum augue, ac condimentum ex turpis nec odio. Donec dictum lectus nec justo consequat, in tincidunt turpis facilisis. Praesent dapibus, velit non feugiat interdum, ligula magna gravida leo, ut vehicula risus ligula eget odio. Pellentesque vitae mauris lorem. Nullam porttitor tristique placerat. Proin at dolor sollicitudin, tempor enim in, mattis dui. Donec pharetra nisi nulla, sed congue est efficitur quis. Mauris facilisis suscipit sem, in ullamcorper tellus aliquet sed.\n"
                  "Proin sit amet sapien ut tellus dictum commodo eget sollicitudin dolor. Integer vel est pharetra, elementum eros faucibus, malesuada tortor. Ut congue ex risus, ac rhoncus augue facilisis eget. Quisque elit nisi, vestibulum eleifend cursus nec, efficitur nec orci. Aliquam porttitor elit non lectus aliquam iaculis. Donec et quam a ligula volutpat mattis. Sed non mauris ut tellus luctus iaculis ac in ipsum. Vestibulum massa quam, sollicitudin id porta vel, laoreet vel ipsum. Fusce condimentum justo urna, et maximus justo tincidunt sit amet. Sed viverra est justo, eu tempus nibh sagittis bibendum. Cras gravida ipsum in nibh ullamcorper, sed elementum erat varius. Sed id molestie nibh. Vivamus et cursus nibh, eget ullamcorper ligula. Suspendisse gravida sed felis ac mollis.\n"
                  "In hac habitasse platea dictumst. Suspendisse finibus vitae metus vel suscipit. Etiam laoreet posuere placerat. Nullam vel fermentum sapien, eget condimentum purus. Ut lobortis ex at sem varius, ut imperdiet libero porta. Duis convallis facilisis purus ut tempor. Pellentesque eleifend turpis sit amet magna tristique, et efficitur leo commodo. Aenean nec lacinia nulla, vel lobortis lacus.\n"
                  "Vivamus non maximus ex. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nulla efficitur justo sit amet ante lacinia congue. Nam lobortis purus ac lobortis congue. Nullam eget velit massa. Maecenas laoreet ante nisl, eget pretium orci blandit id. Ut enim felis, sagittis ac sagittis sit amet, egestas id eros. Donec eu ligula quis tortor pellentesque mollis laoreet tristique enim. Cras rhoncus sagittis dolor, in lobortis est efficitur nec. Sed vitae vulputate odio. Maecenas faucibus semper mi, id condimentum nunc luctus in.");
}

void Scroll::draw(RenderTarget &target, RenderStates states) const {
    doLayout();
    BackgroundedElement::draw(target, states);
    target.draw(*text, states);
}

void Scroll::doLayout() const {
    text->setSize(getSize()-Vector2i(20,20));
    text->setPosition(getPosition()+Vector2i(10,10));
}

void Scroll::scrollUp() {
    text->scrollUp();
}

void Scroll::scrollDown() {
    text->scrollDown();
}




