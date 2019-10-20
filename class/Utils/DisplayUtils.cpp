//
// Created by oxabz on 22/04/19.
//



#include "DisplayUtils.h"

#include "../GameState.h"

#include <iostream>

using std::iostream;

#ifndef NCURES

void DisplayUtils::DisplayText(string text) {
    std::cout<<processeText(text)<<std::endl;
}

string DisplayUtils::GetPlayerInput() {
    string text;
    getline(std::cin,text);
    return text;
}

#else

WINDOW* DisplayUtils::window = initscr();
string DisplayUtils::textBuffer;
int DisplayUtils::lineOffset = 0;

string DisplayUtils::GetPlayerInput() {
    string input;
    int arrowcount = -1;
    move(LINES - Y_IN_ORIGIN, X_TEXT_ORIGIN);
    do {
        input += getch();
        if (input[input.size() - 1] == '\177') {
            input.pop_back();
            int y, x;
            getsyx(y, x);
            if (input.size() != 0) {
                input.pop_back();
                move(y, --x);
                addch(' ');
            }
            for (int i = 0; i < 2; ++i) {
                move(y, --x);
                addch(' ');
            }
            move(y, x);
        } else if (input[input.size() - 1] == '\t') {
            int y, x;
            getsyx(y, x);
            move(y, x - 5);
            input.pop_back();
        } else if (input[input.size() - 1] == '\033') {
            int y, x;
            getsyx(y, x);
            for (int i = 0; i < 2; ++i) {
                move(y, --x);
                addch(' ');
            }
            move(y, x);
            arrowcount = 1;
            input.pop_back();
        } else if (arrowcount >= 0) {
            int y, x;
            getsyx(y, x);
            for (int i = 0; i < 1; ++i) {
                move(y, --x);
                addch(' ');
            }
            move(y, x);
            if (arrowcount == 0) {
                if (input[input.size() - 1] == 'A') {
                    if (lineOffset + 1 < lineCount()) {
                        int yb, xb;
                        getsyx(yb, xb);
                        lineOffset++;
                        clear();
                        drawBuffer();
                        drawBox();
                        move(yb, xb - 1);
                        refresh();
                    }
                } else if (input[input.size() - 1] == 'B') {
                    if (lineOffset > 0) {
                        int yb, xb;
                        getsyx(yb, xb);
                        lineOffset--;
                        clear();
                        drawBuffer();
                        drawBox();
                        move(yb, xb - 1);
                        refresh();
                    }
                }
            }
            arrowcount--;
            input.pop_back();
        }
    } while (input.size() < COLS - X_TEXT_MAX - Y_TEXT_MAX + 2 && input[input.size() - 1] != '\n');
    input.pop_back();
    return input;
}

void DisplayUtils::initDisplay(){
    initscr();
}

int DisplayUtils::lineCount() {
    int c = 0;
    for (int i = 0; i < textBuffer.size(); ++i) {
        if (textBuffer[i]=='\n'){
            c++;
        }
    }
    return c;
}

void DisplayUtils::drawBox() {
    move(0,0);
    addstr(UPPER_LEFT_CORNER1);
    move(1,0);
    addstr(UPPER_LEFT_CORNER2);
    move(2,0);
    addstr(UPPER_LEFT_CORNER3);
    move(0,COLS-7);
    addstr(UPPER_RIGHT_CORNER1);
    move(1,COLS-7);
    addstr(UPPER_RIGHT_CORNER2);
    move(2,COLS-7);
    addstr(UPPER_RIGHT_CORNER3);
    move(LINES-6,1);
    addstr(LOWER_LEFT_CORNER1);
    move(LINES-5,1);
    addstr(LOWER_LEFT_CORNER2);
    move(LINES-4,1);
    addstr(LOWER_LEFT_CORNER3);
    move(LINES-6,COLS-4);
    addstr(LOWER_RIGHT_CORNER1);
    move(LINES-5,COLS-4);
    addstr(LOWER_RIGHT_CORNER2);
    move(LINES-4,COLS-4);
    addstr(LOWER_RIGHT_CORNER3);
    for (int j = 5; j < COLS-5; ++j) {
        move(0,j);
        addch('-');
        move(2,j);
        addch('_');
    }
    for (int j = 4; j < COLS-4; ++j) {
        move(LINES-7,j);
        addch('_');
        move(LINES-4,j+1);
        addch('-');
    }
    for (int i = 3; i < LINES-6; ++i) {
        move(i,3);
        addch('|');
        move(i,COLS-4);
        addch('|');
    }

}

void DisplayUtils::DisplayText(string text) {
    string processedText = processeText(text);
    textBuffer.append(processedText+'\n');
    formatBuffer();
    clear();
    drawBuffer();
    drawBox();
    refresh();
}

string DisplayUtils::getWord(const string &text, int &pos, int &wordSize) {
    string word;
    wordSize = 0;
    while(pos<text.size()&&text[pos]!=' '&&text[pos]!='\n'){
        word+=text[pos++];
        wordSize++;
    }
    if(text[pos++]==' '){
        word+=' ';
        wordSize++;
    }else{
        word+='\n';
        wordSize++;
    }
    return word;
}

void DisplayUtils::formatBuffer() {
    string newBuffer;
    int pos = 0;
    int screenPosX = X_TEXT_ORIGIN;
    while(pos<textBuffer.size()){
        string word;
        int wordSize = 0;
        word = getWord(textBuffer,pos,wordSize);
        screenPosX += wordSize;
        if(screenPosX>COLS-1-X_TEXT_MAX){
            newBuffer += '\n';
            screenPosX = wordSize;
        }
        if(word[word.size()-1]=='\n'){
            screenPosX = X_TEXT_ORIGIN;
        }
        newBuffer+=word;
    }
    textBuffer = newBuffer;
}

void DisplayUtils::drawBuffer() {
    wmove(window,Y_TEXT_ORIGIN,X_TEXT_ORIGIN);
    int numLigne = Y_TEXT_ORIGIN;
    int i=0;
    int c=0;
    while(c<lineOffset){
        if(textBuffer[i]=='\n'){
            c++;
        }
        i++;
    }
    c=0;
    while (i < textBuffer.size() && c < LINES - Y_TEXT_ORIGIN - Y_TEXT_MAX) {
        if(textBuffer[i] == '\n'){
            numLigne++;
            move(numLigne,X_TEXT_ORIGIN);
            c++;
        } else{
            addch( textBuffer[i]);
        }
        i++;
    }
}

#endif

string DisplayUtils::processeText(string &text) {
    string processedText;
    for (int i = 0; i < text.size(); ++i) {
        if(text[i] == '$'){
            string variable;
            while(++i<text.size()&&text[i]!=' ' ){
                variable+=text[i];
            }
            string value = std::to_string(GameState::getGameVariable(variable));
            while(value[value.size()-1] == '0'){value.pop_back();}
            if(value[value.size()-1]=='.'){value.pop_back();}
            processedText.append(value);
            processedText+=' ';
        } else {
            processedText+=text[i];
        }
    }
    return processedText;
}












