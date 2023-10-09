#pragma once
#include <vector>
#include <string>
using namespace std;

class Attack;


class Creature
{
private:
	string mName;
	string mDescription;
	int mLifePoints;
	vector<Attack> mAttack;
	int mDefenceScore;



public:

	Creature(string name, string description, int lifePoints, vector<Attack> attack, int defenceScore);
	Creature();
	~Creature();

	string GetName();
	int GetDefenceScore();

	//heal fonction


};

