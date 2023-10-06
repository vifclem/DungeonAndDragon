#pragma once
#include "Creature.h"
#include <vector>
#include<iostream>
#include<string>

class Weapon;
class Monster:public Creature
{
private:
	int mMoney;
	vector<Weapon> mWeapon;

public:

	Monster(int money, vector<Weapon> weapon);
	Monster();
	~Monster();


};

