#ifndef PLOT_H
#define PLOT_H

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Plot
{
public:
    void WritePlot(unsigned short int chapter);
    void TextEff(char prop[]);
    const unsigned int delay = 2500;
    const unsigned int LetterDelay = 60;



};

#endif // PLOT_H

