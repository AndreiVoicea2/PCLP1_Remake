#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "Perk.h"
#include "Handlers.h"
#include "GlobalVariables.h"


using namespace std;

class Combat
{
public:

    void ShowStatsBeforeCombat(Player& player, Enemy& _enemy);
    void Fight(Player& player, Enemy& _enemy, list<Perk>& _AllPerks);
    bool ContinueTheFight(Player& player, Enemy& enemy);

    int StatPrice = 1;
    Handlers MainHandle;
    

};

#endif // COMBAT_H

