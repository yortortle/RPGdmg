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
	//exception handling
	//practice refactoring

	srand(time(0));
	BeginPlay();
}

void BeginPlay()
{
	cout << "game has begun" << endl;
	cout << "please select your class between human, elf, dwarf, or rogue" << endl;
	
	string ChosenClass;
	cin >> ChosenClass;

	//running function to determine which class you selected and generate the appropriate object
	ClassSelection(ChosenClass);
}

void ClassSelection(string ChosenClass)
{
	Ally* a1;
	if (ChosenClass == "human")
	{
		Human hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if (ChosenClass == "elf")
	{
		HighElf hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if (ChosenClass == "dwarf")
	{
		Dwarf hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else if (ChosenClass == "rogue")
	{
		Rogue hero;
		a1 = &hero;
		GameLoop(a1);
	}
	else
	{
		cout << "invalid, start over with a valid class name" << endl;
	}
}

void GameLoop(Ally* a1)
{
	Ally* e2;
	while (a1->GetHealth() >= 0)
	{
		int num = rand() % 5;

		if (num == 0)
		{
			Orc enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 1)
		{
			Bat enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 2)
		{
			Vampire enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 3)
		{
			Giant enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
		else if (num == 4)
		{
			Mage enemy;
			e2 = &enemy;
			Battle(a1, e2);
		}
	}
}

void Battle(Ally*& human, Ally*& monster)
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

void Ally::SetAttackPower(float x)
{
	AttackPower += x;
}

void Ally::SetDefense(float x)
{
	Defense += x;
}

void Ally::SetHealth(float x)
{
	Health += x;
}

void Ally::SetName(string x)
{
	name = x;
}

string Ally::GetName()
{
	return name;
}

