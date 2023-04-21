// Arena.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int combatSequence() 
{
    int playerHealth = 100;
    int enemyHealth = 60;

    cout << "A warrior approaches..." << endl;
    while (enemyHealth > 0)
    {

        int input;
        cout << "Warrior Health: " << enemyHealth << endl;
        cout << "   1.) Punch\n";
        cout << "   2.) Kick\n";
        cin >> input;

        switch (input)
        {
        case 1:
            enemyHealth = enemyHealth - 10;
            cout << "You punch the warrior for 10 health\n";
                break;
        case 2:
            enemyHealth = enemyHealth - 20;
            cout << "You punch the warrior for 20 health\n";
            break;
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }
    cout << "You defeated the warrior!\n";

    return 0;
}

int selection()
{
    char response;
    response = getchar();
    if (response == 'y') 
    {
        cout << "Begin Game (Outcome 1)" << endl;
        combatSequence();
        return 1;
    }
    else if (response == 'n') 
    {
        cout << "Exiting game... (Outcome 2)" << endl;
        return 2;
    }
    else
    {
        cout << "Invalid input! (Outcome 3)" << endl;
        return 3;
    }
}

int mainMenu() 
{
    int gameMode = 1;
    cout << "Arena -- A Virtual Combat Game\n";
    cout << "Begin Game? (y/n): ";
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
