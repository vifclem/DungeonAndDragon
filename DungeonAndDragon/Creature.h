#pragma once
#include <vector>
#include <string>
#include <iostream>
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
	int GetLifePoints();
	void IntroduceCreature();
	void SetLifePoints(int lifePoints);
	
	//heal fonction


};

