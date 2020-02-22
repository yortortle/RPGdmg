#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Ally.h"
#include "Enemy.h"
#include "functions.h"
using namespace std;

//A project where I build a console based RPG attribute game to practice fundamental C++ skills. Goals are:
//implement function overriding
//implement pointers as parametrs in functions and gain understanding of their uses
//practice inheritence skills with base and children classes
//virtual functions
//practice refactoring


int main()
{
	srand(time(0));
	BeginPlay();
}

void BeginPlay()
{
	cout << "please select your class between human, elf, dwarf, or rogue" << endl;
	
	string ChosenClass;
	cin >> ChosenClass;

	//running function to determine which class you selected and generate the appropriate object
	ClassSelection(ChosenClass);
}

void ClassSelection(string ChosenClass)
{
	//make a pointer to base class Ally which we will set a value for in the conditionals statements below.
	Ally* a1 = new Ally;

	if (ChosenClass == "human")
	{
		Human hero;
		//We declare the pointer to be a reference to the derived class Human named hero.
		//I'm not wondering if I could have avoided making the pointer to Base class Ally and instead just passed in a reference to hero in the gameloop function
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
		cout << endl << "invalid entry, start over with a valid class name" << endl;
		BeginPlay();
	}
}

void GameLoop(Ally* a1)
{
	//Declaring a pointer named monster of type ally to use as the enemy
	Ally* Monster = new Ally;
	while (a1->GetHealth() >= 0)
	{
		//a loop that runs until you die, generates random number and decides monster encounter based on that number.
		int num = rand() % 5;

		if (num == 0)
		{
			//still unsure if I'm using pointers / memory right here. Wondering if it would be more efficient to just pass in the refrence to enemy directly into the function and how that differs to using the pointer. 
			//Will continue practicing and doing research.
			Orc enemy;
			Monster = &enemy;
			Battle(a1, Monster);
		}
		else if (num == 1)
		{
			Bat enemy;
			Monster = &enemy;
			Battle(a1, Monster);
		}
		else if (num == 2)
		{
			Vampire enemy;
			Monster = &enemy;
			Battle(a1, Monster);
		}
		else if (num == 3)
		{
			Giant enemy;
			Monster = &enemy;
			Battle(a1, Monster);
		}
		else if (num == 4)
		{
			Mage enemy;
			Monster = &enemy;
			Battle(a1, Monster);
		}
	}
}

void Battle(Ally* &human, Ally* &monster)
{
	//Battle function which takes in a pointer to base class ally for the main character, and another pointer to base class Ally for the monster. I use pointers as arguments in these functions so the objects are directly 
	//altered rather than just being copied and then not changing when it returns from the battle function.

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

