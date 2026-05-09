#pragma once
#include <iostream>
#include <vector>
#include "Spell.h"
using namespace std;

class Wizard
{
protected:
	std::string name;
	float f_hp;
	float hp;
	float mana;
	float skillFactor;
	animals Animal;
	std::vector<Spell*> spells;
public:
	virtual Spell* chooseSpell();
	virtual float attack();
	virtual float takeDamage(float d);
	bool isAlive();
	Wizard(std::string name_init, float hp_init, float mana_init, int skill_init, animals animal);

	virtual std::string get_home() = 0;
	std::string get_name();
	int get_mana();
	float get_hp();
	int get_fhp();
	int get_skill();
	int get_spell_power(int i);
	int get_spell_mana(int i);
	void reset();
};

