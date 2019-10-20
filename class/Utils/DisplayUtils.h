//
// Created by oxabz on 22/04/19.
//

#ifndef ZELOTH_DISPLAYUTILS_H
#define ZELOTH_DISPLAYUTILS_H

#define NCURES

#include <string>

#ifdef NCURES
#include <ncurses.h>
#endif

using std::string;

class DisplayUtils {
private:
#ifdef NCURES
    static constexpr int X_TEXT_ORIGIN = 6;
    static constexpr int Y_TEXT_ORIGIN = 4;
    static constexpr int X_TEXT_MAX = 6;
    static constexpr int Y_TEXT_MAX = 9;
    static constexpr int Y_IN_ORIGIN = 2;

    static constexpr char * UPPER_LEFT_CORNER1 = " .-.-";
    static constexpr char * UPPER_LEFT_CORNER2 = "((O))";
    static constexpr char * UPPER_LEFT_CORNER3 = " \\U/_";
    static constexpr char * UPPER_RIGHT_CORNER1 = "-.-.";
    static constexpr char * UPPER_RIGHT_CORNER2 = "    )";
    static constexpr char * UPPER_RIGHT_CORNER3 = "___/";
    static constexpr char * LOWER_LEFT_CORNER1 = " /A\\";
    static constexpr char * LOWER_LEFT_CORNER2 = "((O))";
    static constexpr char * LOWER_LEFT_CORNER3 = " '-'-";
    static constexpr char * LOWER_RIGHT_CORNER1 = " \\";
    static constexpr char * LOWER_RIGHT_CORNER2 = "  )";
    static constexpr char * LOWER_RIGHT_CORNER3 = "-'";


    static WINDOW* window;
    static string textBuffer;
    static int lineOffset;


    static string getWord(const string &text, int &pos, int &wordSize);
    static void formatBuffer();
    static void drawBuffer();
    static int lineCount();
    static void drawBox();
#endif

    static string processeText(string &text);
public:
    static void DisplayText(string text);
    static string GetPlayerInput();
    static void initDisplay();
};


#endif //ZELOTH_DISPLAYUTILS_H
