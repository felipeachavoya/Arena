// Arena.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;
const int pause = 800;

/*
    -- List of things to do --

    1.) Introduce misses.

    2.) Introduce some variability into damage received.

    3.) Introduce a defense move. Lowers damage received by some factor

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
*/

/*
    This function decides what the enemy will attack with using the rand function.
    It essentially is a coin flip and then returns what the damage is to the combatSequence function
    to update the player health.
*/
int processEnemyTurn(int playerHealth)
{
    int selection = rand() % 2 + 1;
    switch (selection)
    {
    case 1:
        cout << "Warrior throws a punch for 10 damage!\n";
        return playerHealth - 10;
        break;
    case 2:
        cout << "Warrior throws a kick for 20 damage!\n";
        return playerHealth - 20;
        break;
    }
    return 0;
}

int processPlayerTurn(int enemyHealth)
{
    int input;
    cout << "   1.) Punch\n";
    cout << "   2.) Kick\n";
    cin >> input;

    switch (input)
    {
    case 1:
        cout << "You punch the warrior for 10 health\n";
        return enemyHealth - 10;
        break;
    case 2:
        cout << "You kick the warrior for 20 health\n";
        return enemyHealth - 20;
        break;
    default:
        return enemyHealth;
        cout << "Turn Skipped...\n";
        break;
    }
}

int combatSequence() 
{
    int turnCount = 1;
    int playerHealth = 100;
    int enemyHealth = 60;

    cout << "A warrior approaches..." << endl;
    Sleep(pause);
    while (enemyHealth > 0 && playerHealth > 0)
    {
        string combatOutcome;
        int input;
        cout << "Turn " << turnCount << ":\n";
        cout << "Player Health: " << playerHealth << endl;
        cout << "Warrior Health: " << enemyHealth << endl;

        // Before you start the list, these needs to be fixed.
        enemyHealth = processPlayerTurn(enemyHealth);
        Sleep(pause);
        playerHealth = processEnemyTurn(playerHealth);
        Sleep(pause);

        turnCount += 1;
    }
    if (enemyHealth <= 0)
    {
        cout << "You are Victorious!\n";
        Sleep(pause);
    }
    else if (playerHealth <= 0)
    {
        cout << "You were defeated...\n";
        Sleep(pause);
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
