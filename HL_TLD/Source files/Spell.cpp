#include "Spell.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

Spell::Spell(string name_init) {
	name = name_init;
	manaCost = 0;
}

string Spell::getName(){
	return name;
}

//---------------------------------------------

Expelliarmus::Expelliarmus(string name, int skill)
	: Spell(name)
{
	skillFactor = skill;
	manaCost = getManaCost();
}

float Expelliarmus::getPower()
{
	return (40 + skillFactor);
}

float Expelliarmus::getManaCost()
{
	return (10);
}

//---------------------------------------------


Stupefy::Stupefy(string name)
	: Spell(name)
{
	manaCost = getManaCost();
}

float Stupefy::getPower()
{
	return (60 + (rand() % 21));
}

float Stupefy::getManaCost()
{
	return (20 + 0.2 * getPower());
}

//---------------------------------------------

Lumos::Lumos(string name, bool dark)
	: Spell(name)
{
	isDark = dark;
	manaCost = getManaCost();
}

float Lumos::getPower()
{
	return (10);
}

float Lumos::getManaCost()
{
	return ((isDark) ? (5) : (2.5));
}

//---------------------------------------------

Expecto_Patronum::Expecto_Patronum(string name, animals anim)
	: Spell(name)
{
	animal = anim;
	manaCost = getManaCost();
}

float Expecto_Patronum::getPower()
{
	return (100 + ((float)animal * 0.12));
}

float Expecto_Patronum::getManaCost()
{
	return (50 + (getPower() * 0.3));
}