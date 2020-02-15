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
	BeginPlay();
}

void BeginPlay()
{
	cout << "game has begun" << endl;
	cout << "please select your class" << endl;
	Rogue rogue;

	Orc orc;
	orc.GetStats();

	Ally* a1 = &rogue;
	a1->GetStats();
	a1->SetAttackPower(30.2);
	a1->GetStats();

	Ally* e1 = &orc;

	Battle(a1, e1);

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
	Defense += x;
}

