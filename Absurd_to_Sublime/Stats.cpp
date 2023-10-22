#include "Stats.h"


using namespace std;

//static fstream fisier("CombatLog.txt");

Stats::Stats()
{
    health = 100;
    Maxhealth = 100;
    PhysicalDamage = 1;
    MagicalDamage = 1;
    PhysicalArmor = 0;
    MagicalArmor = 0;
    Evasion = 0;
    Level = 1;
    Evasion = 0;
    Coins = 0;
    Experience = 0;
    Name = "default_name";

}


Stats::Stats(unsigned short int _Maxhealth, unsigned short int _PhysicalDamage, unsigned short int _MagicalDamage, unsigned short int _PhysicalArmor,
    unsigned short int _MagicalArmor, unsigned short int _Evasion, unsigned short int _Level, int _Coins, int _Experience, string _Name)
{
    Maxhealth = _Maxhealth;
    PhysicalDamage = _PhysicalDamage;
    MagicalDamage = _MagicalDamage;
    PhysicalArmor = _PhysicalArmor;
    MagicalArmor = _MagicalArmor;
    Evasion = _Evasion;
    Level = _Level;
    Coins = _Coins;
    Experience = _Experience;
    health = Maxhealth;
    Name = _Name;

}

void Stats::DrainHealth(unsigned short int PhysicalAmount, unsigned short int MagicalAmount, unsigned short int PureAmount)
{
    health = health - (PhysicalAmount + MagicalAmount + PureAmount);
}

string Stats::GetName()
{
    return Name;
}

unsigned short int Stats::GetMAXHEALTH()
{
    return Maxhealth;
}

int Stats::GetCoins()
{
    return Coins;
}

int Stats::GetExperience()
{
    return Experience;
}

short int Stats::GetHEALTH()
{
    return health;
}

unsigned short int Stats::GetLevel()
{
    return Level;
}

unsigned short int Stats::GetPHYSICALDAMAGE()
{
    return PhysicalDamage;
}

unsigned short int Stats::GetMAGICALDAMAGE()
{
    return MagicalDamage;
}

unsigned short int Stats::GetPHYSICALARMOR()
{
    return PhysicalArmor;
}

unsigned short int Stats::GetMAGICALARMOR()
{
    return MagicalArmor;
}

unsigned short int Stats::GetEVASION()
{
    return Evasion;
}

void Stats::SetName(string _Name)
{
    Name = _Name;
}

void Stats::SetExperience(int valoare)
{
    Experience = valoare;
}

void Stats::AddExperience(int valoare)
{
    Experience += valoare;
}

void Stats::AddLevel(unsigned short int valoare)
{
    Level += valoare;
}

void Stats::AddCoins(int valoare)
{
    Coins += valoare;
}

void Stats::SpendCoins(int valoare)
{
    Coins -= valoare;
}

void Stats::RestoreHealth()
{
    health = Maxhealth;
}

void Stats::AddStat(unsigned short int AddMaxHealth,
    unsigned short int AddPhysicalDamage,
    unsigned short int AddMagicalDamage,
    unsigned short int AddPhysicalArmor,
    unsigned short int AddMagicalArmor,
    unsigned short int AddEvasion)
{
    Maxhealth += AddMaxHealth;
    PhysicalDamage += AddPhysicalDamage;
    MagicalDamage += AddMagicalDamage;
    PhysicalArmor += AddPhysicalArmor;
    MagicalArmor += AddMagicalArmor;
    Evasion += AddEvasion;
}


void Stats::AddPerk(Perk perk)
{
    perks.push_back(perk);
}

void Stats::ShowPerks()
{
    
    WriteColoredText("Perks: \n\n" , true , false);
    for (list<Perk>::iterator it = perks.begin(); it != perks.end(); ++it)
        WriteColoredText( it->GetName() + ": " + it->GetDescription() + '\n', false , false);
    cout << endl;
}


void Stats::ShowStats()
{
    WriteColoredText("Maxhealth: " + to_string(Maxhealth) + '\n' + "PhysicalDamage: " + to_string(PhysicalDamage) + '\n' + "MagicalDamage: " + to_string(MagicalDamage) + '\n' + "PhysicalArmor: " +     
        to_string(PhysicalArmor) + '\n' + "MagicalArmor: " + to_string(MagicalArmor) + '\n' + "Evasion: " + to_string(Evasion) + "%" + '\n' + "Level : " + to_string(Level) + '\n' + "Exp: " + to_string(Experience) + '\n' + "Coins: " + to_string(Coins) + '\n' + '\n' , false , false);
}



void Stats::TakeDamage(Stats* Atacator, string& _CombatLog, bool HasDodged)
{
    const unsigned short int RadianceDamage = 1;
    unsigned short int TotalPhysicalDamage = 0;
    unsigned short int TotalMagicalDamage = 0;
    unsigned short int TotalPureDamage = 0;

    if (HasDodged == false)
    {
        TotalPhysicalDamage = Atacator->GetPHYSICALDAMAGE();
        TotalMagicalDamage = Atacator->GetMAGICALDAMAGE();

            _CombatLog += GetName() + " was hit with: " + '\n';
        if (TotalPhysicalDamage > 0)
            _CombatLog += "+ " + to_string(TotalPhysicalDamage) + " Physical Damage" + '\n';
        if (TotalMagicalDamage > 0)
            _CombatLog += "+ " + to_string(TotalMagicalDamage) + " Magical Damage" + '\n';

    }
    else _CombatLog += GetName() + " dodged the attack" + '\n' + '\n';

    ///Atacator perks
    for (list<Perk>::iterator it = Atacator->perks.begin(); it != Atacator->perks.end(); ++it)
    {
        if (HasDodged == false)
        {
            //....
        }
        else
        {
            //....
        }

        if (it->GetName() == "Radiance")
        {
            TotalPureDamage += RadianceDamage;
            _CombatLog += "+ " + to_string(RadianceDamage) + " Radiance Damage" + '\n';
        }

    }

    ///Aparator perks
    for (list<Perk>::iterator it = perks.begin(); it != perks.end(); ++it)
    {

        if (HasDodged == false)
        {
            if (it->GetName() == "Mirror Force" && TotalPhysicalDamage + TotalMagicalDamage > 0)
            {
                Atacator->DrainHealth(0, 0, TotalMagicalDamage + TotalPhysicalDamage);
                _CombatLog += "- " + to_string(TotalPhysicalDamage + TotalMagicalDamage) + ' ' + Atacator->GetName() + " health (Mirror effect)" + '\n';
            }
        }
        else
        {
            //....
        }

        if (it->GetName() == "Radiance")
        {
            Atacator->DrainHealth(0, 0, RadianceDamage);
            _CombatLog += "- " + to_string(RadianceDamage) + ' ' + Atacator->GetName() + " health (Radiance effect)" + '\n';

        }

    } 

    if (HasDodged == false)
    {
        if (PhysicalArmor > 0)
            _CombatLog += "- " + to_string(PhysicalArmor) + " Physical Damage (Armor effect)" + '\n';
        if (MagicalArmor > 0)
            _CombatLog += "- " + to_string(MagicalArmor) + " Magical Damage (Armor effect)" + '\n';

        if (TotalPhysicalDamage >= PhysicalArmor)
            TotalPhysicalDamage -= PhysicalArmor;
        else TotalPhysicalDamage = 0;
        if (TotalMagicalDamage >= MagicalArmor)
            TotalMagicalDamage -= MagicalArmor;
        else TotalMagicalDamage = 0;

        _CombatLog += "= " + to_string(TotalPhysicalDamage + TotalMagicalDamage + TotalPureDamage) + " Total Damage" + '\n' + '\n';

    }
   
    health = health - (TotalPhysicalDamage + TotalMagicalDamage + TotalPureDamage);

    _CombatLog += '\n';
}


Stats* Stats::ReturnStats()
{
    return this;
}
