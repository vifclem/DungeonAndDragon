#include "Monster.h"
#include "Weapon.h"
#include <cstdlib>
using namespace std;

Monster::Monster(int money, vector<Weapon> weapon, string name, string description, int lifePoints, vector<Attack> attack, int defenceScore) 
	:Creature(name, description, lifePoints, attack, defenceScore) {

	mMoney = money;
	mWeapon = weapon;
}

Monster::Monster() :Creature() {
	mMoney = (rand() % 100);
	mWeapon = vector<Weapon>{ Weapon("Arc", "arme a longue distance", WeaponTypes::Bow, 10, 20, 20, 1) };
}

Monster::~Monster(){}