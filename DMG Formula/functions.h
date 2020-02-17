#pragma once
#include <iostream>
#include <string>

using namespace std;

void GameLoop(Ally* a1);
void BeginPlay();
int heal = 3;
int counter = 0;

void Battle(Ally* &human, Ally* &monster)
{
	string answer;
	cout << endl;
	cout << "You have slain " << counter << " monsters thus far!" << endl;
	cout << "You have " << heal << " healing items remaining, they heal for 25 health each." << endl;
	cout << "Would you like to do battle or heal? enter battle or heal to answer" << endl;
	cin >> answer;
	if (answer == "heal")
	{
		if (heal == 0)
		{
			cout << "no more healing items, sorry" << endl;
		}
		else
		{
			--heal;
			human->SetHealth(25);
			cout << "Your health is now: " << human->GetHealth() << " and you have " << heal << " healing items left" << endl << endl;
		}
	}
	else if (answer == "battle")
	{
		cout << "You have run into an enemy!" << endl;
		cout << "Battle has begun: enemy " << monster->GetName() << " has " << monster->GetHealth() << " health and " << monster->GetAttackPower() << " Attack Power " << endl << endl;

		//human->SetAttackPower(-115.f); 
		//debug line

		float DamageTaken = monster->GetAttackPower() - (human->GetDefense() * 0.2f);
		human->SetHealth(-DamageTaken);

		float DamageGiven = human->GetAttackPower() - (monster->GetDefense() * 0.2f);
		monster->SetHealth(-DamageGiven);

		cout << "You have dealt " << DamageGiven << " dmg to the " << monster->GetName() << endl;
		cout << "You have taken " << DamageTaken << " damage from the " << monster->GetName() << endl;

		if (human->GetHealth() <= 0)
		{
			cout << "The monster has reduced your hp to zero!" << endl;
			cout << "you have lost the game :(" << endl;
		}
		else if (DamageGiven > monster->GetHealth())
		{
			cout << "You have slain the monster" << endl;
			cout << "You have " << human->GetHealth() << " health remaining" << endl;
			counter++;
		}
		else
		{
			cout << "The monster lives! It has: " << monster->GetHealth() << "health remaining" << endl;
		}
	}
	else
	{
		cout << "invalid answer, enter either battle or heal";
	}

}