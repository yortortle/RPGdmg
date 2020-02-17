#pragma once
#include <iostream>
#include <string>

using namespace std;

int heal = 3;
int counter = 0;

void GameLoop(Ally* a1);
void BeginPlay();
void ClassSelection(string ChosenClass);
void Battle(Ally* &human, Ally*& monster);
