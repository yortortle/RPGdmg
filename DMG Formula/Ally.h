#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ally
{
public:
	Ally()
	{
		Health = 0.f;
		Defense = 0.f;
		AttackPower = 0.f;
		name = "";
	}

	void GetStats();
	float GetHealth();
	float GetDefense();
	float GetAttackPower();
	virtual string GetName();

	void SetHealth(float x);
	void SetDefense(float x);
	void SetAttackPower(float x);

protected:
	void SetStats(float health, float defense, float attackpower);
	void SetName(string name);
private:
	string name;
	float Health;
	float Defense;
	float AttackPower;
};

class Human : public Ally
{
public:
	Human()
	{
		SetStats(35.f, 50.f, 50.f);
		cout << "You have chosen to be a human, a well balanced class" << endl;
		GetStats();
	}
};

class HighElf : public Ally
{
public:
	HighElf()
	{
		SetStats(50.f, 30.f, 70.f);
		cout << "You have chosen to be a high elf, a well balanced class" << endl;
		GetStats();
	}
};

class Dwarf : public Ally
{
public:
	Dwarf()
	{
		SetStats(70.f, 50.f, 34.f);
		cout << "You have chosen to be a dwarf, a more defensive class" << endl;
		GetStats();
	}
};

class Rogue : public Ally
{
public:
	Rogue()
	{
		SetStats(120.f, 100.f, 0.f);
		cout << "You have chosen to be a Rogue, a more aggressive class" << endl;
		GetStats();
	}
};
