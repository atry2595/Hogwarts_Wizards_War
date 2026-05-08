#pragma once
#include "Wizard.h"

class Gryffindor : public Wizard {
public:
	using Wizard::Wizard; 
	float attack() override;
	string get_home() override;
};

class Slytherin : public Wizard {
public:
	using Wizard::Wizard;
	float takeDamage(float d) override;
	string get_home() override;
};

class Ravenclaw : public Wizard {
public:
	using Wizard::Wizard;
	Spell* chooseSpell() override;
	float attack() override;
	string get_home() override;
};

class Hufflepuff : public Wizard {
private:
	bool expired = false;
public:
	using Wizard::Wizard;
	float takeDamage(float d) override;
	string get_home() override;
};