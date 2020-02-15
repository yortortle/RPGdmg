#pragma once
#include <iostream>
#include <string>
using namespace std;

void BeginPlay();

void Battle(Ally* &human, Ally* &monster)
{
	cout << "test " << human->GetAttackPower() << " space " << &monster << endl;
}