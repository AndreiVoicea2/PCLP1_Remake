#include "Combat.h"

void Combat::ShowStatsBeforeCombat(Player& player, Enemy& _enemy)
{

    WriteColoredText("                                                                                                        Player|" + _enemy.GetName() + " Health: " + to_string(player.GetHEALTH()) + "|" + to_string(_enemy.GetHEALTH()) + '\n' + '\n', false , false);
    WriteColoredText("Player|" + _enemy.GetName() + " Stats: " + '\n' + '\n' , true , false);
    WriteColoredText("Maximum Health: " + to_string(player.GetMAXHEALTH()) + "|" + to_string(_enemy.GetMAXHEALTH()) + '\n' , false , false);
    WriteColoredText("Physical Damage: " + to_string(player.GetPHYSICALDAMAGE()) + "|" + to_string(_enemy.GetPHYSICALDAMAGE()) + '\n' , false , false);
    WriteColoredText("Magical Damage: "  + to_string(player.GetMAGICALDAMAGE()) + "|" + to_string(_enemy.GetMAGICALDAMAGE()) + '\n' , false , false);
    WriteColoredText("Physical Armor: " + to_string(player.GetPHYSICALARMOR()) + "|" + to_string(_enemy.GetPHYSICALARMOR()) + '\n' , false , false);
    WriteColoredText("Magical Armor: " + to_string(player.GetMAGICALARMOR()) + "|" + to_string(_enemy.GetMAGICALARMOR()) + '\n', false , false);
    WriteColoredText("Evasion: " + to_string(player.GetEVASION()) + "%|" + to_string(_enemy.GetEVASION()) + "%" + '\n' , false , false);
    WriteColoredText("Level: " + to_string(player.GetLevel()) + "|" + to_string(_enemy.GetLevel()) + '\n' , false , false);
    WriteColoredText("Experience: " + to_string(player.GetExperience()) + '\n' , false , false);
    WriteColoredText("Coins: " + to_string(player.GetCoins()) + '\n', false , false);
    
    cout << endl;
    player.ShowInventory();
    cout << endl;
    player.ShowPerks();
    WriteColoredText("Combat Log: \n\n", true , false);

}


void Combat::Fight(Player& player, Enemy& _enemy, list<Perk>& _AllPerks)
{

Grind:
    string CombatLog;
    system("cls");
    player.RestoreHealth();
    _enemy.RestoreHealth();



    while (player.GetHEALTH() > 0 && _enemy.GetHEALTH() > 0)
    {


        system("cls");

        ///Player Turn

        unsigned short int RandomNumber = 1 + (rand() % 100);

        if (RandomNumber > _enemy.GetEVASION())
        {

            _enemy.TakeDamage(player.ReturnStats(), CombatLog, false);
            ShowStatsBeforeCombat(player, _enemy);

            if (ContinueTheFight(player, _enemy) == false)break;


        }
        else
        {
            _enemy.TakeDamage(player.ReturnStats(), CombatLog, true);
            ShowStatsBeforeCombat(player, _enemy);


        }

        WriteColoredText(CombatLog , false , true);
        CombatLog.clear();

        system("pause");
        system("cls");

        ///Enemy Turn

        RandomNumber = 1 + (rand() % 100);

        if (RandomNumber > player.GetEVASION())
        {
            player.TakeDamage(_enemy.ReturnStats(), CombatLog, false);
            ShowStatsBeforeCombat(player, _enemy);

            if (ContinueTheFight(player, _enemy) == false)break;

        }
        else
        {
            player.TakeDamage(_enemy.ReturnStats(), CombatLog, true);
            ShowStatsBeforeCombat(player, _enemy);

        }

        WriteColoredText(CombatLog, false , true);
        CombatLog.clear();

        system("pause");

    }




    if (player.GetExperience() >= player.GetEXPERIENCELIMIT())
        player.LevelUp(_AllPerks, MainHandle);

    player.BuyStats(MainHandle, StatPrice);


    if (MainHandle.InputHandler("Do you want to fight the enemy again? (1-YES, 2-NO)", 2) == 1)
        goto Grind;
    else system("cls");



} 

bool Combat :: ContinueTheFight(Player& player, Enemy& enemy)
{
    if (player.GetHEALTH() <= 0)
    {
        player.Defeat();
        return false;
    }
    else if (enemy.GetHEALTH() <= 0)
    {
        enemy.Drop(player);
        system("pause");
        system("cls");
        return false;
    } 

    return true;
}
