#pragma once
#include "Wizard.h"

int fight(Wizard& w1, Wizard& w2);
void round_fight(Wizard& w1, Wizard& w2, int& r);
void group_fight(vector<Wizard*> ws1, vector<Wizard*> ws2);