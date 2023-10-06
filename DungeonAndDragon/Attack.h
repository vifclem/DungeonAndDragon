#pragma once
#include "Weapon.h"
#include"Creature.h"
#include <vector>
#include<iostream>
#include<string>

using namespace std;

class Attack
{
private:
	string mLabel;
	vector<Weapon> mWeapon;
	int mDamagesPoints;
	DamageType mDamageType;
	int mAttackBonus;

public:

	Attack(string Label, vector<Weapon> Weapon, int DamagesPoints, int AttackBonus);
	Attack();
	~Attack();


	bool Resolve();
};

                                                              