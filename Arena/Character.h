#pragma once
#include <iostream>
using namespace std;


/*
 In Arena, all entities seen by the computer are called characters, including
 the player character.
*/

// Base class
class Character
{
protected:
	string characterName;
	int maxHealth; // This stat will be more relevant later when healing is introduced.
	int characterHealth;
};


/*
 For now, the playerCharacter class will be used to iron out the combatSequence function, but eventually we will want to create a
 non-Playable character class, or NPC. These NPC's will be for now aggressive towards the character, but maybe in the future we could
 alter this behavior to be passive and/or interactable with the PC.
*/

// Derived Character class
class playerCharacter : public Character
{
public:
	void setCharacterName(string SCN)
	{
		characterName = SCN;
	}
	string getCharacterName()
	{
		return characterName;
	}
	void setMaxHealth(int SMH)
	{
		maxHealth = SMH;
	}
	int getMaxHealth()
	{
		return maxHealth;
	}
	void setCharacterHealth(int SCH)
	{
		characterHealth = SCH;
	}
	int getCharacterHealth() 
	{
		return characterHealth;
	}
	playerCharacter(string SCN, int SMH, int SCH)
	{
		setCharacterName(SCN);
		setMaxHealth(SMH);
		setCharacterHealth(SCH);
	}
};