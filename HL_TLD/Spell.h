#pragma once
#include <iostream>

typedef enum class animals { owl, doe, stag, phoenix }animals;

class Spell {
protected:
	std::string name;
	float manaCost;
public:
	Spell(std::string name_init);
	virtual float getPower() = 0;
	virtual float getManaCost() = 0;
	std::string getName();
	virtual ~Spell() = default;
};


class Expelliarmus :
	public Spell
{
private:
	int skillFactor;
public:
	Expelliarmus(std::string name, int skill);
	float getPower() override;
	float getManaCost() override;
};


class Stupefy :
	public Spell
{
public:
	Stupefy(std::string name);
	float getPower() override;
	float getManaCost() override;
};


class Lumos :
	public Spell
{
private:
	bool isDark;
public:
	Lumos(std::string name, bool dark);
	float getPower() override;
	float getManaCost() override;
};


class Expecto_Patronum :
	public Spell
{
private:
	animals animal;
public:
	Expecto_Patronum(std::string name, animals anim);
	float getPower() override;
	float getManaCost() override;
};