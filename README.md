# PCLP1_Remake
 
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
     <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
        <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#getting-started">Getting Started</a></li>
      <ul>
        <li><a href="#stats">Stats</a></li>
       <li><a href="#perks">Perks</a></li>
      </ul>
    </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project
The project is an RPG console game, strongly inspired by the game "Shakes and Fidget".

### Built With

Project made in c++ console application using Visual Studio 2019 (initially created in Code::Blocks). For audio, the SDL library and SDL_mixer were used.


## Getting Started

* The game consists of continuous battles with different enemies. The fight is strongly influenced by different attributes. During the fight you can attack using any key. The UI provides information about the attributes of the player, but also of the enemy, as well as the player's inventory and perks. At the end of each attack, all the information about the respective attack is displayed in the combat log section.
* For each battle won, the player receives a certain number of coins, experience and equipment (which has a certain chance of being won) that modify the attributes in the game. At the end, the option is offered to spend the coins to improve certain attributes in the game. You can also fight the enemy again if you want to collect money, experience or win the respective equipment.

### Stats

* There are three types of damage in the game: physical, magical and pure. Physical damage is mitigated by physical armor, and magical damage is mitigated by magical ones. Pure damages cannot be mitigated.
* Evasion is the player's or enemy's chance to avoid a direct attack.

### Perks

Perks are special abilities that can significantly alter combat:
* Mirror Force -> Reflects the physical and magical damage of the attacker as pure damage;
* Radiance -> Does 1 pure damage over time to the enemy and pierces through evasion;
* Physical Berserk -> The less life you have, the more physical damage you do;
* Lucky shot -> Gives you a chance to convert all physical and magical damage into pure damage;
