#include "Attack.h"
#include "Weapon.h"
#include"Creature.h"
#include <vector>
#include<iostream>
#include<string>
#include <cstdlib>

Attack::Attack(string Label, vector<Weapon> Weapon, int DamagesPoints, int AttackBonus) {

	mLabel = Label;
	mWeapon = Weapon;
	mDamagesPoints = DamagesPoints;
	mAttackBonus = AttackBonus;

}

Attack::Attack() {

	mLabel = " foudre ";
	mWeapon = vector<Weapon>{ Weapon() };
	mDamagesPoints = 20;
	mAttackBonus = (rand() % 5);


}

Attack::~Attack() {


}





