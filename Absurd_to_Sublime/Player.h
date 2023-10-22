#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include <iterator>
#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <string>
#include "Handlers.h"
#include "Stats.h"
#include "Item.h"
#include "Perk.h"
#include "GlobalVariables.h"


class Player :public Stats
{
public:

    Player();
    Player(unsigned short int _Maxhealth, unsigned short int _PhysicalDamage, unsigned short int _MagicalDamage, unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor, unsigned short int _Evasion, unsigned short int _Level, int _Coins, int _Experience, string _Name, int _ExperienceLimit,
        unsigned short int _ItemNumber);

    int GetEXPERIENCELIMIT();
    void SetEXPERIENCELIMIT(int valoare);
    void Defeat();
    void ShowInventory();
    void IncrementItemNumber();
    unsigned short int GetItemNumber();
    void AddItem(string _Name, string _Description);
    void LevelUp(list<Perk>& p, Handlers _MainHandle);
    void BuyStats(Handlers _MainHandle, int& _StatPrice);

    static constexpr unsigned short int BuyMaxHealthValue = 10;
    static constexpr unsigned short int BuyPhysicalDamageValue = 1;
    static constexpr unsigned short int BuyMagicalDamageValue = 1;
    static constexpr unsigned short int BuyPhysicalArmorValue = 1;
    static constexpr unsigned short int BuyMagicalArmorValue = 1;


private:

    int ExperienceLimit;
    unsigned short int ItemNumber;
    constexpr static unsigned short int InventoryLength = 10;
    Item Inventory[InventoryLength];
    



};


#endif // PLAYER_H