#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Creature.h"
#include "Attack.h"

using namespace std;

enum class Job
{
	Archer, 
	Warrior, 
	Priest, 
	Paladin
};


enum class Race
{
	Elf,
	Orc, 
	Gobelin, 
	Human
};

class Character: public Creature
{
private:
	string mFirstName;
	string mLastName;
	string mCatchPhrase;
	int mMoney;
	int mLifePoints;
	vector<Weapon> mWeapon;
	Race mRace;


public:
	Character(string name, string lasteName, string catchPhrase, int money, int lifePoints, vector<Weapon> weapon, Race race, string description, vector<Attack> attack, int defenceScore);
	Character();
	~Character();


	void Update();
	void IntroduceChara();
	void SetLifePoints(int lifePoints);
	int GetLifePoints();
	void Inventaire(Creature creature);
	vector<Weapon> GetCharaWeapon();
	void AddWeapon(Weapon weapon);
	void DeleteWeapon(int position);
	void LootMoney(Character& money);
	void LootWeapon();
	int GetMoney();
	void SetMoney(int money);
	void Use(Character& character, int weapon);
	string GetWeaponDurability(int weapon);


	
	


};

