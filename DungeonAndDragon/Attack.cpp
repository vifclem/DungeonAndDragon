#include "Attack.h"
#include"Creature.h"
#include <cstdlib>

Attack::Attack(string Label, Weapon Weapon, int DamagesPoints, DamageType DamageType,int AttackBonus) {

	mLabel = Label;
	mWeapon = Weapon;
	mDamagesPoints = DamagesPoints;
	mDamageType = DamageType;
	mAttackBonus = AttackBonus;

}

Attack::Attack() {

	mLabel = " foudre ";
	mWeapon = Weapon();
	mDamagesPoints = 20;
	mDamageType = DamageType::Burning;
	mAttackBonus = (rand() % 5 + 1);


}

Attack::~Attack() {


}

bool Attack::Resolve(Creature creature){
	return  (rand() % 20 + 1) + mAttackBonus >= creature.GetDefenceScore();
}

string Attack::GetAttackName() {

	return mLabel;
}



