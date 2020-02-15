#pragma once
#include <iostream>
#include <string>
using namespace std;

void BeginPlay();

void Battle(Ally* &human, Ally* &monster)
{
	cout << "Battle has begun: enemy " << monster->GetName() << " has " << monster->GetHealth() << " health and " << monster->GetAttackPower() << " Attack Power " << endl;

	//human->SetAttackPower(-115.f); 
	//debug line

	float DamageTaken = monster->GetAttackPower() - (human->GetDefense() * 0.2f);
	human->SetHealth(-DamageTaken); 

	float DamageGiven = human->GetAttackPower() - (monster->GetDefense() * 0.2f);
	monster->SetHealth(-DamageGiven);

	cout << "You have done " << DamageGiven << " dmg to the monster" << endl;

	if (human->GetHealth() <= 0)
	{
		cout << "you have lost the game, would you like to restart or quit?" << endl;
	}
	else if (DamageGiven > monster->GetHealth())
	{
		cout << "You have slain the monster" << endl;
		cout << "You have " << human->GetHealth() << " health remaining" << endl;
	}
	else
	{
		cout << "The monster lives! It has: " << monster->GetHealth() << "health remaining" << endl;
	}

}