#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Character.h"


using namespace std;



class Merchant
{

private:

	string mFirstName;
	string mShopName;
	string mDescription;
	string mCatchPhrase;
	vector<Weapon> mWeapon;
	int mMoney;






public:

	Merchant(string FirstName, string ShopName, string Description, string CatchPhrase, vector<Weapon> Weapon, int Money);
	Merchant();
	~Merchant();

	void BuyWeapon(Character& character, Weapon weapon, int position);
	void SellWeapon(Character& character, Weapon weapon, int position);

	vector<Weapon> GetWeapon();
	string GetMerchantName();
	string ShopName();
	string MerchantDescription();
	string MerchantCatchPhrase();
	float GetMerchantMoney();



};
