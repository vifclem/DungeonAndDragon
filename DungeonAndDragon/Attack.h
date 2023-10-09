#pragma once
#include "Weapon.h"
#include"Creature.h"
#include <vector>
//#include<iostream>
#include<string>

using namespace std;

enum DamageType
{
	Bludgeoning,
	Slashing,
	Piercing,
	Burning
};

class Attack
{
private:
	string mLabel;
	Weapon mWeapon;
	int mDamagesPoints;
	DamageType mDamageType;
	int mAttackBonus;

public:

	Attack(string Label, Weapon Weapon, int DamagesPoints, DamageType DamageType,int AttackBonus);
	Attack();
	~Attack();


	bool Resolve(Creature creature);
};

                                                              