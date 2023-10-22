#include "Player.h"


using namespace std;


Player::Player(unsigned short int _Maxhealth, unsigned short int _PhysicalDamage, unsigned short int _MagicalDamage, unsigned short int _PhysicalArmor,
    unsigned short int _MagicalArmor, unsigned short int _Evasion, unsigned short int _Level, int _Coins, int _Experience, string _Name, int _ExperienceLimit,
    unsigned short int _ItemNumber)
    :Stats(_Maxhealth, _PhysicalDamage, _MagicalDamage, _PhysicalArmor, _MagicalArmor, _Evasion, _Level, _Coins, _Experience, _Name)
{

    ExperienceLimit = _ExperienceLimit;
    ItemNumber = _ItemNumber;

}

Player::Player()
{

    ExperienceLimit = 100;
    ItemNumber = 0;

}


int Player::GetEXPERIENCELIMIT()
{
    return ExperienceLimit;
}

void Player::SetEXPERIENCELIMIT(int valoare)
{
    ExperienceLimit = valoare;
}

void Player::Defeat()
{

    WriteColoredText("Ai pierdut!\n" , false , true);
    system("pause");
    PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);

}

void Player::IncrementItemNumber()
{
    ItemNumber++;
}

unsigned short int Player::GetItemNumber()
{
    return ItemNumber;
}

void Player::AddItem(string _Name, string _Description)
{
    ItemNumber++;
    Inventory[ItemNumber].SetNAME(_Name);
    Inventory[ItemNumber].SetDESCRIPTION(_Description);
}

void Player::ShowInventory()
{
 
    WriteColoredText("Inventory : \n\n", true , false);
    for (unsigned short int i = 1; i <= ItemNumber; i++)
        WriteColoredText(to_string(i) + ". " + Inventory[i].GetNAME() + ": " + Inventory[i].GetDESCRIPTION() + '\n' , false , false);
}


void Player::LevelUp(list<Perk>& p, Handlers _MainHandle)
{


    system("cls");
    int AdditionalXP = GetExperience() - ExperienceLimit;
    AddLevel(1);
    SetExperience(AdditionalXP);
    ExperienceLimit = ExperienceLimit * 2 - ExperienceLimit / 2;
    WriteColoredText("You have leveled up !! Current level : " + to_string(GetLevel()) + ", you have " + to_string(ExperienceLimit) + " XP left until the next level." + '\n' + '\n' , false , false);

    unsigned short int i = 0;
    unsigned short int pi = 0;
    unsigned short int ui = 0;
    list<Perk>::iterator it = p.begin();

    WriteColoredText("Perks available: \n\n" , true , false);
    for (it; it != p.end(); ++it)
    {
        i++;
        if (i <= GetLevel() && it->GetActiveState() == false)
        {

            if (pi == 0)
                pi = i;
            else
                ui = i;

            WriteColoredText(it->GetName() + ": " + it->GetDescription() + '\n' + '\n', false , false);
        }

    }

    if (pi < ui)
    {
        if (_MainHandle.InputHandler("Choose the Perk (1 or 2)", 2) == 1)
        {

            it = p.begin();
            std::advance(it, pi - 1);
            AddPerk(*it);


        }
        else
        {
            it = p.begin();
            std::advance(it, ui - 1);
            AddPerk(*it);
        }



    }
    else if (pi != 0)
    {

        it = p.begin();
        std::advance(it, pi - 1);
        AddPerk(*it);
        WriteColoredText("The perk was added automatically \n\n" , false , true);
        system("pause");

    }
    else
    {
        WriteColoredText("There are no more Perks to choose from \n\n" , false , true);
        system("pause");
    }

    it->SetActiveState(true);

    system("cls");
}


void Player::BuyStats(Handlers _MainHandle, int& _StatPrice)
{

    while (GetCoins() >= _StatPrice)
    {

        system("cls");

        if (_MainHandle.InputHandler("Do you want to use the money earned to improve the player? (1-YES, 2-NO)", 2) == 1)
        {

            system("cls");
            ShowStats();

            WriteColoredText("Upgrade price: " + to_string(_StatPrice) + '\n', true, false);
            WriteColoredText("1. Maximum Health (+" + to_string(BuyMaxHealthValue) + ")" + '\n' , false , false);
            WriteColoredText("2. Physical Damage (+" + to_string(BuyPhysicalDamageValue) + ")" + '\n', false, false);
            WriteColoredText("3. Magical Damage (+" + to_string(BuyMagicalDamageValue) + ")" + '\n' , false , false);
            WriteColoredText("4. Physical Armor (+" + to_string(BuyPhysicalArmorValue) + ")" + '\n' , false , false);
            WriteColoredText("5. Magical Armor (+" + to_string(BuyMagicalArmorValue) + ")" + '\n' + '\n', false, false);

            unsigned short int index = _MainHandle.InputHandler("What feature do you want to improve?", 5);

            if (index == 1)AddStat(BuyMaxHealthValue, 0, 0, 0, 0, 0);
            else if (index == 2)AddStat(0, BuyPhysicalDamageValue, 0, 0, 0, 0);
            else if (index == 3)AddStat(0, 0, BuyMagicalDamageValue, 0, 0, 0);
            else if (index == 4)AddStat(0, 0, 0, BuyPhysicalArmorValue, 0, 0);
            else if (index == 5)AddStat(0, 0, 0, 0, BuyMagicalArmorValue, 0);

            SpendCoins(_StatPrice);
            _StatPrice++;

        }
        else
        {
            system("cls");
            break;
        }

        system("cls");
    }

}