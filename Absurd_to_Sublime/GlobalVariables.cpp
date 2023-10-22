#include "GlobalVariables.h"



void WriteColoredText(string text, bool isHighlt , bool Reset)
{
    GlobalVariables g;
    if (isHighlt == false)
        cout << "\033[38;5;" << 47 << ";48;5;" << 0 << "m" << text << "\033[0m";
    else cout << "\033[38;5;" << 11 << ";48;5;" << 22 << "m" << text << "\033[0m";
    if (Reset == true) SetConsoleTextAttribute(g.console_color, 2);

}
