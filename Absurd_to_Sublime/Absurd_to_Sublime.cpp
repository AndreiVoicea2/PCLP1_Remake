#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iterator>
#include <fstream>

#include "Stats.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Perk.h"
#include "Animator.h"
#include "Handlers.h"
#include "Combat.h"
#include "Plot.h"
#include "SDL2SoundEffects.h"

ofstream fout("Output.txt");

using namespace std;


Player player;
Enemy Bear, Giant_Bear, Witch, Agile_Eagle;
Animator Animation_handler;
list<Perk> AllPerks;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
Combat CombatSystem;
Plot PlotSystem;
SDL2SoundEffects se;

const unsigned short int LogoAnimationIndex = 1;


void InitializareDate()
{
    
    player = Player(100, 10, 0, 0, 0, 0, 1, 0, 0, "Player", 100, 0);
    Bear = Enemy(50, 2, 0, 0, 0, 0, 1, 1, 45, "Bear");
    Bear.itemDroped = Item("Novice Adventurer's Chalice", "+2 Magical Damage", 100, 0, 0, 2, 0, 0, 0);
    Giant_Bear = Enemy(60, 3, 1, 1, 0, 0, 1, 1, 55, "Giant Bear");
    Giant_Bear.itemDroped = Item("The Bear Fur Of The Novice Adventurer", "+1 Physical Armor , +1 Magical Armor", 100, 0, 0, 0, 1, 1, 0);
    Witch = Enemy(90, 3, 8, 0, 2, 5, 3, 1, 65, "Witch");
    Witch.itemDroped = Item("The Invisible Veil Of The Novice Adventurer", "+1 Evasion", 100, 0, 0, 0, 0, 0, 1);
    Agile_Eagle = Enemy(80, 5, 2, 2, 2, 5, 2, 1, 60, "Agile Eagle");
    Agile_Eagle.itemDroped = Item("The magic feathers of stalling", "+10 Max Health , +4 Evasion", 100, 10, 0, 0, 0, 0, 4);
    

    //Perks

    AllPerks.push_back(Perk("Mirror Force", "Reflects the physical and magical damage of the attacker as pure damage", false));
    AllPerks.push_back(Perk("Radiance", "Does 1 pure damage over time to the enemy and pierces through evasion", false));
    AllPerks.push_back(Perk("Physical Berserk", "The less life you have, the more physical damage you do", false));
    AllPerks.push_back(Perk("Lucky shot", "Gives you a chance to convert all physical and magical damage into pure damage", false));
    //list<Perk>::iterator it = AllPerks.begin();
    //Witch.AddPerk(*it);
    //std::advance(it,1);
    se.addSoundEffect("D:/ProjCom/PCLP1_Remake/Absurd_to_Sublime/MainMusic.wav");
}

void FullScreen()
{

    system("mode con COLS=700");
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(console_color, &scrBufferInfo);

    
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;

    
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    
    int Status = SetConsoleScreenBufferSize(console_color, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }

}


void Start()
{

    FullScreen();
    SetConsoleTextAttribute(console_color, 10);
    srand((unsigned)time(NULL));
    InitializareDate();
    //Animation_handler.PlayAnimation(LogoAnimationIndex);
    se.playSoundEffect(0);
    

}



int main()
{
    Start();
    //PlotSystem.WritePlot(1);
    CombatSystem.Fight(player, Bear, AllPerks);
    CombatSystem.Fight(player, Giant_Bear, AllPerks);
   //PlotSystem.WritePlot(2);
    CombatSystem.Fight(player, Agile_Eagle, AllPerks);
   // PlotSystem.WritePlot(3);
   // PlotSystem.WritePlot(4);
    CombatSystem.Fight(player, Witch, AllPerks);

    return 0;
}