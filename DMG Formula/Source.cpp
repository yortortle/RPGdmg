#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Header.h"
#include "Enemy.h"
#include "functions.h"
using namespace std;

int main()
{
	//A project where I build a console based RPG attribute game to practice fundamental C++ skills
	//practice overriding, overloading, passing in pointers to functions, general inheritence and encapsulation skills.
	//virtual functions / abstract classes
	//exception handling
	//practice refactoring

	srand(time(0));
	BeginPlay();
}

void BeginPlay()
{
	cout << "game has begun" << endl;
	cout << "please select your class between human, elf, dwarf, or rogue" << endl;
	
	string ChosenClass;
	cin >> ChosenClass;

	
	Ally* a1;

	if (ChosenClass == "human")
	{
		Human hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if(ChosenClass == "elf")
	{
		HighElf hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if (ChosenClass == "dwarf")
	{
		Dwarf hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if (ChosenClass == "rogue")
	{
		Rogue hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else
	{
		cout << "invalid, start over with a valid class name" << endl;
	}
}

void GameLoop(Ally* a1)
{
	Ally* e2;
	while (a1->GetHealth() >= 0)
	{
		int num = rand() % 5;

		if (num == 0)
		{
			Orc enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 1)
		{
			Bat enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 2)
		{
			Vampire enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 3)
		{
			Giant enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 4)
		{
			Mage enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
	}
}
void Ally::SetStats(float attack, float health, float defense)
{
	AttackPower = attack;
	Health = health;
	Defense = defense;
}

void Ally::GetStats()
{
	cout << "You have " << Health << " Health, " << Defense << " Defense and " << AttackPower << " AttackPower" << endl;
}

float Ally::GetHealth()
{
	return Health;
}

float Ally::GetAttackPower()
{
	return AttackPower;
}

float Ally::GetDefense()
{
	return Defense;
}

void Ally::SetAttackPower(float x)
{
	AttackPower += x;
}

void Ally::SetDefense(float x)
{
	Defense += x;
}

void Ally::SetHealth(float x)
{
	Health += x;
}

void Ally::SetName(string x)
{
	name = x;
}

string Ally::GetName()
{
	return name;
}

