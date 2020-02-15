#pragma once
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

class Ally
{
public:
	virtual void attack()
	{

	}

	virtual void heal()
	{

	}
protected:
private:

};

class Enemy
{
public:
	virtual void Defend() = 0;
	void setHealth(int x);
	int getHealth();

	void setDefense(int x);
	int getDefense();
protected:
private:
	int Health = 0;
	int Defense = 0;
};

