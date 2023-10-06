#include "Character.h"
#include <iostream>
#include <string>
#include "Weapon.h"
#include <vector>
#include <cstdlib>


using namespace std;


Character::Character(string name, string lastName, string catchPhrase, int money, int lifePoints, vector<Weapon> weapon, Race race) {

	mFirstName = name;
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mLifePoints = lifePoints;
	mWeapon = weapon;
	mRace = race;

}

Character::Character() {

	mFirstName = "clem";
	mLastName = "expert";
	mCatchPhrase = " wsh poto trkl ou quoi";
	mMoney = 100;
	mLifePoints = 100;
	mWeapon = vector<Weapon>{Weapon()};
	mRace = Race::Human;

}

Character::~Character() {

}

void Character::Update() {

	

}

void Character::Inventaire() {

	cout << "Hello ! Tu t'appel " << mFirstName << " " << mLastName << ", tu as " << mLifePoints << " points de vie et tu est un humain " << endl;

	//Faire une boucle

	cout << "Tes armes sont :  " << endl;
	for (size_t i = 0; i < mWeapon.size(); i++)
	{
		 cout << mWeapon[i].GetName() << endl;
	}
	cout << " Et tu as " << mMoney << " $" << endl;


}

vector<Weapon> Character::GetCharaWeapon() {

	return mWeapon;
}
void Character::SetLifePoints(int lifePoints) {
	
	mLifePoints = lifePoints;
	
}

int Character::GetLifePoints() {

	return mLifePoints;
}

void Character::IntroduceChara() {
	cout << " Voici ton adversaire : " << endl;
	cout << " Il s'appel " << mFirstName << " " << mLastName << " sa phrase d'accroche est " << " " << mCatchPhrase << endl;
	cout << "Il a : " << mMoney << " $, et " << mLifePoints << " points de vies ! " << endl;
}

void Character::AddWeapon(Weapon weapon) {

	mWeapon.push_back(weapon);
}

void Character::DeleteWeapon(int position) {

	mWeapon.erase(mWeapon.begin() + position);
}


void Character::LootMoney() {


}

void Character::LootWeapon() {


}

int Character::GetMoney() {

	return mMoney;

}

void Character::SetMoney(int money) {

	mMoney = money;
}

void Character::Use(Character& character, int weapon) {

	srand((unsigned)time(NULL));
	mWeapon[weapon].SetDurability(mWeapon[weapon].GetDurability() - (rand() % 5 + 1) * 0.01f);
		
}

string Character::GetWeaponDurability(int weapon) {

	return to_string(mWeapon[weapon].GetDurability());
}







