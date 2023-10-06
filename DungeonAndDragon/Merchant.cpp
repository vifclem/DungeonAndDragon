#include "Merchant.h"
#include "Weapon.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Merchant::Merchant(string FirstName, string ShopName, string Description, string CatchPhrase, vector<Weapon> Weapon, int Money) {

	mFirstName = FirstName;
	mShopName = ShopName;
	mDescription = Description;
	mCatchPhrase = CatchPhrase;
	mWeapon = Weapon;
	mMoney = Money;


}

Merchant::Merchant() {

	mFirstName = " Rodrigo";
	mShopName = "Rod Shop";
	mDescription = "Buy weapon";
	mCatchPhrase = "Hey, this is my shop ! Com take a look !";
	mWeapon = vector<Weapon>{ Weapon("Arc", "arme a longue distance", WeaponTypes::Bow, 10, 20, 20, 1), Weapon("Dagger", "arme de poing", WeaponTypes::Dagger, 10, 20, 20, 1), 
		Weapon("Dagger", "arme de poing", WeaponTypes::Dagger, 10, 20, 20, 1), Weapon() };
	mMoney = 100;
}

Merchant::~Merchant() {


}

void Merchant::BuyWeapon(Character& character, Weapon weapon, int position) {

	character.SetMoney(character.GetMoney() + weapon.GetPrice() * ( weapon.GetDurability()));
	character.DeleteWeapon(position - 1);

	 mMoney -= weapon.GetPrice() * (1 - weapon.GetDurability());
	 mWeapon.push_back(weapon);

}

void Merchant::SellWeapon(Character& character, Weapon weapon, int position) {

	character.SetMoney(character.GetMoney() - weapon.GetPrice() * (0.2 + weapon.GetDurability()));
	character.AddWeapon(weapon);

     mMoney += weapon.GetPrice() * (1 + weapon.GetDurability());
	 mWeapon.erase(mWeapon.begin() + position - 1);
	
}

string Merchant::GetMerchantName() {
	return mFirstName;

}

float Merchant::GetMerchantMoney(){

	return mMoney;
}

vector<Weapon> Merchant::GetWeapon() {

	return mWeapon;
}

string Merchant::ShopName() {

	return mShopName;
}





	



