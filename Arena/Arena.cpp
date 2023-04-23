// Arena.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;

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
    Sleep(500);
    return 0;
}

int processPlayerTurn(int input, int enemyHealth)
{
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
    Sleep(500);
}

int combatSequence() 
{
    int turnCount = 1;
    int playerHealth = 100;
    int enemyHealth = 60;

    cout << "A warrior approaches..." << endl;
    while (enemyHealth > 0 && playerHealth > 0)
    {
        int input;
        Sleep(500);
        cout << "Turn " << turnCount << ":\n";
        cout << "Player Health: " << playerHealth << endl;
        cout << "Warrior Health: " << enemyHealth << endl;
        cout << "   1.) Punch\n";
        cout << "   2.) Kick\n";
        cin >> input;

        enemyHealth = processPlayerTurn(input, enemyHealth);
        playerHealth = processEnemyTurn(playerHealth);

        turnCount += 1;
    }
    if (enemyHealth <= 0)
    {
        cout << "You are Victorious!\n";
        Sleep(400);
    }
    else if (playerHealth <= 0)
    {
        cout << "You were defeated...\n";
    }

    return 0;
}

int selection()
{
    cout << "1.) Start Game\n";
    cout << "2.) Exit Game\n";
    int input;
    cin >> input;
    Sleep(100);
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
