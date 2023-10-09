#pragma once
#include "Creature.h"
#include <vector>
#include<iostream>
#include<string>
#include "Attack.h"

class Weapon;
class Monster:public Creature
{
private:
	int mMoney;
	vector<Weapon> mWeapon;

public:

	Monster(int money, vector<Weapon> weapon, string name, string description, int lifePoints, vector<Attack> attack, int defenceScore);
	Monster();
	~Monster();

	
};

