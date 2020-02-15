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
	//using pointers to parent classes in game for efficient memory storage
	//exception handling

	srand(time(0));

	BeginPlay();
}

void BeginPlay()
{
	cout << "game has begun" << endl;
	cout << "please select your class" << endl;

	Human hero;
	Ally* a1 = &hero;
	Ally* e2;

	while (a1->GetHealth() >= 0)
	{
		int num = rand() % 5;
		cout << num << " random number" << endl;

		if (num == 0)
		{
			Orc enemy;
			e2 = &enemy;
		}
		else if (num == 1)
		{
			Bat enemy;
			e2 = &enemy;
		}
		else if (num == 2)
		{
			Vampire enemy;
			e2 = &enemy;

		}
		else if (num == 3)
		{
			Giant enemy;
			e2 = &enemy;
		}
		else if (num == 4)
		{
			Mage enemy;
			e2 = &enemy;
		}
		//Ally* e1 = &enemy;
		cout << "infinite" << endl;
		Battle(a1, e2);
	}

	//Battle(a1, e1);
	//Battle(a1, e1);
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

