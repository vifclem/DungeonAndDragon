#include "Attack.h"
#include"Creature.h"
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

bool Attack::Resolve(Creature creature){
	return  (rand() % 20 + 1) + mAttackBonus >= creature.GetDefenceScore();
}





