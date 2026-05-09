#include "Wizard.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

Spell* Wizard::chooseSpell() {
	vector<Spell*> avalibale_spells = {};

	for (auto elem : spells) {
		if (elem->getManaCost() <= this->mana) avalibale_spells.push_back(elem);
	}

	int length = avalibale_spells.size();
	if (length == 0) return NULL;

	int choose = (rand() % length);
	return avalibale_spells[choose];
}

float Wizard::attack() {
	Spell* spl = chooseSpell();
	if (spl == NULL) return 0;
	this->mana -= spl->getManaCost();
	return spl->getPower();
}

float Wizard::takeDamage(float d) {
	hp -= d;
	if (hp < 0) {
		hp = 0;
		return (-hp);
	}
	return (d);
}

bool Wizard::isAlive() {
	return (hp > 0);
}

Wizard::Wizard(string name_init, float hp_init, float mana_init, int skill_init, animals animal) {
	name = name_init;
	f_hp = hp = hp_init;
	mana = mana_init;
	skillFactor = skill_init;
	Animal = animal;
	spells = {};
	spells.push_back(new Expelliarmus("exp", skillFactor));
	spells.push_back(new Stupefy("stp"));
	spells.push_back(new Lumos("lms", rand()%2));
	spells.push_back(new Expecto_Patronum("pat", Animal));
}

string Wizard::get_name() {
	return name;
}

int Wizard::get_mana() {
	return int(mana);
}

float Wizard::get_hp() {
	return (hp / f_hp);
}

int Wizard::get_fhp() {
	return (hp);
}

int Wizard::get_skill() {
	return int(skillFactor);
}

int Wizard::get_spell_power(int i) {
	return (int)spells[i]->getPower();
}
int Wizard::get_spell_mana(int i) {
	return (int)spells[i]->getManaCost();;
}

void Wizard::reset() {
	hp = f_hp;
}