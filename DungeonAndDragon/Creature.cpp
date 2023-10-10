#include "Creature.h"
#include <vector>
#include"Attack.h"
#include<string>
#include <cstdlib>
using namespace std;

Creature::Creature(string name, string description, int lifePoints, vector<Attack> attack, int defenceScore) {

	mName = name;
	mDescription = description;
	mLifePoints = lifePoints;
	mAttack = attack;
	mDefenceScore = defenceScore;

}

Creature::Creature() {

	mName = " lacostTn";
	mDescription = " Parle mal";
	mLifePoints = 100;
	mAttack = vector<Attack>{ Attack() };
	mDefenceScore = (rand() % 20);
}

Creature::~Creature() {

}

string Creature::GetName() {

	return mName;
}

int Creature::GetDefenceScore() {
	return mDefenceScore;
}

int Creature::GetLifePoints() {
	return mLifePoints;
}

void Creature::IntroduceCreature() {
	cout << " Voici ton adversaire : " << endl;
	cout << " Il s'appel " << mName << " " << mDescription << endl;
	cout << "Il a : " << mLifePoints << " points de vies ! " << " et " << mDefenceScore << " score de defense " << endl;
}