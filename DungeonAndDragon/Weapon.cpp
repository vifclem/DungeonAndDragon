#include "Weapon.h"
#include "Character.h"


Weapon::Weapon(string name, string description, WeaponTypes weaponTypes, int weight, int damages, int buyingCost, float durability) {

	mName = name;
	mDescription = description;
	mWeaponType = weaponTypes;
	mWeight = weight;
	mDamages = damages;
	mBuyingCost = buyingCost;
	mDurability = durability;

}

Weapon::Weapon() {

	mName = "Sword";
	mDescription = "Coupe coupe";
	mWeaponType = WeaponTypes::Sword;
	mWeight = 10;
	mBuyingCost = 10;
	mDurability = 1;
}




Weapon::~Weapon() {
	


}

string Weapon::GetName() {

	return mName;
}


int Weapon::GetPrice() {

	return mBuyingCost;

}

float Weapon::GetDurability() {

	return mDurability;
}

void Weapon::SetDurability( float durability) {

	mDurability = durability;
}

string Weapon::GetShopDescription() {

	return mName + " " + mDescription + " " + to_string(mBuyingCost) + " $ ";
}



