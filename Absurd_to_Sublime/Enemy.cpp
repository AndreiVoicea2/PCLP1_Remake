#include "Enemy.h"


Enemy::Enemy()
{

}

Enemy::Enemy(unsigned short int _Maxhealth, unsigned short int _PhysicalDamage, unsigned short int _MagicalDamage, unsigned short int _PhysicalArmor,
    unsigned short int _MagicalArmor, unsigned short int _Evasion, unsigned short int _Level, int _Coins, int _Experience, string _Name)
    :Stats(_Maxhealth, _PhysicalDamage, _MagicalDamage, _PhysicalArmor, _MagicalArmor, _Evasion, _Level, _Coins, _Experience, _Name) {


}


void Enemy::Drop(Player& p)
{

    system("cls");
    p.AddCoins(GetCoins());
    p.AddExperience(GetExperience());

    unsigned short int RandomNumber = 1 + (rand() % 100);


    if (RandomNumber <= itemDroped.GetDROPCHANCE())
    {

        if (itemDroped.GetDROPEDSTATE() == false)
        {
            WriteColoredText("You got: " + itemDroped.GetNAME() + '\n' + '\n' , false , false );
            WriteColoredText("Description: " + itemDroped.GetDESCRIPTION() + '\n' + '\n' + "+ Coins: " + to_string(GetCoins()) + " and " + to_string(GetExperience()) + " XP" +'\n' + '\n' , false , true);

            p.AddItem(itemDroped.GetNAME(), itemDroped.GetDESCRIPTION());
            p.AddStat(itemDroped.GetAddMaxHealth(), itemDroped.GetAddPhysicalDamage(), itemDroped.GetAddMagicalDamage(),
                itemDroped.GetAddPhysicalArmor(), itemDroped.GetAddMagicalArmor(), itemDroped.GetAddEvasion());
            itemDroped.SetDROPEDSTATE(true);



        }
        else WriteColoredText("You have already obtained this enemy's item!\n\nBut you got: " + to_string(GetCoins()) + " Coins and " + to_string(GetExperience()) + " XP" + '\n' + '\n' , false , true);

    }
    else
    {
       WriteColoredText("You did not get any items after the battle\n\nBut you got: " + to_string(GetCoins()) + " Coins and " + to_string(GetExperience()) + " XP" + '\n' + '\n' , false , true);

    }

}
