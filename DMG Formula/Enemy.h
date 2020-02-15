#pragma once
#include <iostream>
#include <string>
using namespace std;

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