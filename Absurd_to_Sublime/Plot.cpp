#include "Plot.h"

void Plot::WritePlot(unsigned short int chapter)
{
    

}

void Plot::TextEff(char prop[])
{

    for (int i = 0; i <= strlen(prop) - 1; i++)
    {
        cout << prop[i];
        Sleep(LetterDelay);
    }
    cout << endl;
}
