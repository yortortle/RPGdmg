#pragma once
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class Orc : public Ally
{
public:
	Orc()
	{
		SetStats(20.f, 10.f, 20.f);
		SetName("orc");
	}
};

class Bat : public Ally
{
public:
	Bat()
	{
		SetStats(5.f, 5.f, 100.f);
		SetName("bat");
	}
};

class Vampire : public Ally
{
public:
	Vampire()
	{
		SetStats(50.f, 30.f, 40.f);
		SetName("vampire");
	}
};

class Giant : public Ally
{
public:
	Giant()
	{
		SetStats(60.f, 40.f, 40.f);
		SetName("giant");
	}
};

class Mage : public Ally
{
public:
	Mage()
	{
		SetStats(30.f, 10.f, 30.f);
		SetName("mage");
	}
};
