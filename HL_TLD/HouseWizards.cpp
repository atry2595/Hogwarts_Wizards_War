#include "HouseWizards.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

float Gryffindor::attack() {
	if (f_hp > hp * 2) return (Wizard::attack() * 1.25);
	else return (Wizard::attack());
}

string Gryffindor::get_home() {
	return "Gryffindor";
}

float Slytherin::takeDamage(float d) {
	if (f_hp > hp * 2) return Wizard::takeDamage(d * 0.8);
	else return Wizard::takeDamage(d * 0.9);
}

string Slytherin::get_home() {
	return "Slytherin";
}

Spell* Ravenclaw::chooseSpell() {
	Spell* max_spell = NULL;
	int power = -1;

	for (auto elem : spells) {
		if (elem->getManaCost() <= this->mana && power < elem->getPower()) {
			max_spell = elem;
			power = max_spell->getPower();
		}
	}

	return max_spell;
}

float Ravenclaw::attack() {
	Spell* spl = chooseSpell();
	if (spl == NULL) return 0;
	this->mana -= (spl->getManaCost() * 0.8);
	return spl->getPower();
}

string Ravenclaw::get_home() {
	return "Ravenclaw";
}

float Hufflepuff::takeDamage(float d) {
	if (f_hp * 0.3 > hp && !expired) {
		expired == true;
		return Wizard::takeDamage(d * 0.5);
	}
	else return Wizard::takeDamage(d);
}

string Hufflepuff::get_home() {
	return "Hufflepuff";
}