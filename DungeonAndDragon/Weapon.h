#pragma once
#include <string>

using namespace std;

enum class WeaponTypes
{
	Default,
	Bow,
	Dagger,
	Staff,
	Sword

};

class Weapon
{

private:
		string mName;
		string mDescription;
		WeaponTypes mWeaponType;
		int mWeight;
		int mDamages;
		int mBuyingCost;
		float mDurability;

public:

	Weapon(string name,string description, WeaponTypes weaponTypes, int weight, int damages, int buyingCost, float durability );
	Weapon();
	~Weapon();



	void Update();
	string GetShopDescription();
	string GetName();
	
	int GetPrice();
	float GetDurability();
	void SetDurability(float durablity);






};

