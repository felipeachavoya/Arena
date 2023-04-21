// Arena.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int selection()
{
    char response;
    response = getchar();
    if (response == 'y') 
    {
        cout << "I made a change (Outcome 1)" << endl;
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
