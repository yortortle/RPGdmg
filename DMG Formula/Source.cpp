#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	//A project where I build a console based RPG attribute game to practice fundamental C++ skills
	//practice overriding, overloading, passing in pointers to functions, general inheritence and encapsulation skills.
	//virtual functions / abstract classes

	enum ratios
	{
	};

	attack2();

	

}

void BeginPlay()
{
	cout << "game has begun" << endl;
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