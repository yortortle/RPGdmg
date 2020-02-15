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


}

void Enemy::setHealth(int x)
{
	Health = x;
}

void Enemy::setDefense(int x)
{
	Defense = x;
}

int Enemy::getDefense()
{
	return Defense;
}

int Enemy::getHealth()
{
	return Health;
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