// Arena.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Character.h"

using namespace std;
const int pause = 800;

#define dice_roll (rand() % 32 + 1)
#define coin_flip (rand() % 2 + 1)

// 0 = hit, 1 = miss. Set chanceMod to 1 for no modifier
#define miss_result (variable)

/*
    -- List of things to do --

    1.) (COMPLETED) Introduce misses.

    2.) (COMPLETED) Introduce some variability into damage received.

    3.) Introduce a dodge and heal move which take a turn. Dodge decreases odds of an attack landing. Heal restores
        a random amount of health.

    4.) Improve enemy logic, create some logic which prioritizes specific choices based off of health. For example, if the enemyHealth
        integer is less than %30 of its' max health, then the processEnemyTurn function is more likely to choose heal rather than kick
        or dodge.

    -- Spitballs (stuff I might do later, I don't know) --

    1.) Introduce critical hits, fails, and heals. Critical hits are pretty obvious, if either entity lands a critical blow, the amount of
        damage received is increased by a signficant amount. A critical fail occurs as a substitute to a miss. This can result in the attacking
        entity either losing a turn (meaning the other entity goes twice) or receiving damage as a result. Critical heals can are like critical
        hits, but instead the target entity (in this case, the entity who's turn it is), recieves a significant health restoration.

    2.) Add a selection menu which changes the enemy type on each combat encounter. The player can select from Warrior, Goblin, Orc, and so on...
        This change affects a variety of things, more importantly enemy behaviour. For example, a Warrior would be the standard enemy behaviour.
        A Goblin is weaker and has worse attack and health stats than a warrior, so it is more likely to dodge. An Orc would be more aggressive,
        so rather than dodging or healing, it is more likely to try and land hits, even if its health is low.

    3.) Introduce a defense stat. Lowers damage received by some factor
*/

string generatePlayer()
{
    string playername;
    cout << "Choose your name: ";
    cin >> playername;

    return playername;
}

int processTurn(string name, int IP)
{
    int selection;

    // If the Character is the player
    if (IP == 1) {
        int input;
        cout << "1.) Punch\n";
        cout << "2.) Kick\n";
        cout << "3.) Heal\n";
        cin >> input;
        selection = input;
    }

    // If the character is an AI
    else if (IP == 0) {
        int input = coin_flip;
        selection = input;
    }

    string missMsg = " and misses!\n";
    int damageCalc;
    switch (selection)
    {
    case 1:
        // damageCalc = ((pow(diceRoll(), 2)/64) + 2);
        cout << name << " throws a punch";
     
        Sleep(pause);
        if (miss_result(.75) < 1)
        {
            damageCalc = ((pow(dice_roll, 2) / 64) + 2);
            cout << " and lands a hit for " << damageCalc << "!\n";
        }
        else
        {
            damageCalc = 0;
            cout << missMsg << endl;
        }
        return -damageCalc;
        break;
    case 2:
        cout << name << " initiates a kick";
        Sleep(pause);
        if (miss_result(1.25) < 1)
        {
            damageCalc = ((pow(dice_roll, 2) / 48) + 2);
            cout << " and lands a hit for " << damageCalc << "!\n";
        }
        else
        {
            damageCalc = 0;
            cout << missMsg << endl;
        }
        return -damageCalc;
        break;
    case 3:
        damageCalc = ((pow(dice_roll, 2)/70) + 2);
        cout << name << " healed for " << damageCalc << " HP!\n";
        return damageCalc;
    default:
        cout << "Turn skipped...\n";
        return 0;
        break;
    }
}

int checkOverHeal(int maxHealth, int currentHealth)
{
    if (maxHealth >= currentHealth)
    {
        return currentHealth;
    }
    else if (maxHealth < currentHealth)
    {
        return maxHealth;
    }
}

string toString(char* a, int sizeOf) 
{
    string s = "";
    for (int index = 0; index < sizeOf; index++)
    {
        s = s + a[index];
    }
    return s;
}

void healthBar(int maxHealth, int currentHealth, string name)
{
    char HP = '#';
    char empty = '.';
    int pipIndex = (currentHealth / maxHealth) * 10;

    //Initialize Health Bar
    char healthBar[10];
    for (int thisPip = 0; thisPip < 10; thisPip++)
    {
        healthBar[thisPip] = empty;

        if (thisPip <= pipIndex)
        {
            healthBar[thisPip] = HP;
        }
    }

    int barSize = sizeof(healthBar);

    cout << name << "'s Health: [" << toString(healthBar, barSize) << "] " << pipIndex << endl;
}

int combatSequence() 
{

    int turnCount = 1;
    string playerName = generatePlayer();

    // (name, maxHealth, charHealth, isPlayer?)
    Character player(playerName, 60, 60, 1);
    Character opChar("Warrior", 60, 60, 0);

    cout << "A " << opChar.getCharacterName() << " approaches..." << endl;
    Sleep(pause);

    while (opChar.getCharHP() > 0 && player.getCharHP() > 0)
    {
        /*
        if (playerChar.getCharacterHealth() > playerChar.getMaxHealth())
        {
            // Prevents overheal
            playerChar.setCharacterHealth(playerChar.getMaxHealth());
        }
        if (opChar.getCharacterHealth() > opChar.getMaxHealth())
        {
            // Prevents overheal
            opChar.setCharacterHealth(opChar.getMaxHealth());
        }
        */

        string combatOutcome;
        cout << "Turn " << turnCount << ":\n";
        Sleep(pause);
        healthBar(player.getMaxHP(), player.getCharHP(), player.getCharacterName());
        cout << player.getCharacterName() << "'s Health: " << player.getCharHP() << endl;
        cout << opChar.getCharacterName() <<"'s Health: " << opChar.getCharHP() << endl;

        /*
        Below is how combatSequence process attacks and updates the health of each player. It is messy, and it will be worth it later to clean this
        up with a new class maybe called "Actions".
        */
        
        int points = 0;

        points = processTurn(player.getCharacterName(), 1);
        if (points <= 0)
        {
            opChar.setCharHP(opChar.getCharHP() + points);
            if (opChar.getCharHP() <= 0)
            {
                Sleep(pause);
                cout << "You are Victorious!" << endl;
                break;
            }
        }
        else if (points > 0)
        {
            player.setCharHP(player.getCharHP() + points);
            player.setCharHP(checkOverHeal(player.getMaxHP(), player.getCharHP()));
        }
        
        Sleep(pause);
        points = processTurn(opChar.getCharacterName(), 0);
        if (points <= 0)
        {
            player.setCharHP(player.getCharHP() + points);
            if (player.getCharHP() <= 0)
            {
                Sleep(pause);
                cout << "You were defeated..." << endl;
                break;
            }
        }
        else if (points > 0)
        {
            opChar.setCharHP(opChar.getCharHP() + points);
            opChar.setCharHP(checkOverHeal(opChar.getMaxHP(), opChar.getCharHP()));
        }
        /*
        points = processTurn(opChar.getCharacterName(), 0);
        playerChar.setCharHP(playerChar.getCharHP() + points);
        if (playerChar.getCharHP() <= 0)
        {
            cout << playerChar.getCharacterName() << " was defeated!\n";
            break;
        }
        */

        Sleep(pause);

        turnCount += 1;
    }
    return 0;
}

int selection()
{
    cout << "1.) Start Game\n";
    cout << "2.) Exit Game\n";
    int input;
    cin >> input;
    switch (input)
    {
    case 1:
        combatSequence();
        return 1;
        break;
    case 2:
        cout << "Exitting Game...\n";
        return 2;
        break;
    default:
        cout << "Invalid Input... Try again...\n";
        return 1;
        break;
    }
}

int mainMenu() 
{
    srand(time(0));
    int gameMode = 1;
    cout << "Arena -- A Virtual Combat Game\n";
    while (gameMode != 2)
    {
        gameMode = selection();
    }
    return 0;
}
int main()
{
    mainMenu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
