#pragma once
#include <iostream>
#include <string>
#include "Ally.h"
using namespace std;

class Orc : public Ally
{
public:
	string name;
	Orc()
	{
		SetStats(20.f, 10.f, 20.f);
		name = "orc";
	}
	string GetName() override
	{
		return name;
	}
};

class Bat : public Ally
{
public:
	string name;
	Bat()
	{
		SetStats(5.f, 5.f, 100.f);
		name = "bat";
	}
	string GetName() override
	{
		return name;
	}
};

class Vampire : public Ally
{
public:
	string name;
	Vampire()
	{
		SetStats(50.f, 30.f, 40.f);
		name = "vampire";
	}
	string GetName() override
	{
		return name;
	}
};

class Giant : public Ally
{
public:
	string name;
	Giant()
	{
		SetStats(60.f, 40.f, 40.f);
		name = "giant";
	}
	string GetName() override
	{
		return name;
	}
};

class Mage : public Ally
{
public:
	string name;
	Mage()
	{
		SetStats(30.f, 10.f, 30.f);
		name = "mage";
	}
	string GetName() override
	{
		return name;
	}
};
