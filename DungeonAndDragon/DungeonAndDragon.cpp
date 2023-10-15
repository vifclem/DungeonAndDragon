
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Merchant.h"
#include "Weapon.h"
#include "Attack.h"



using namespace std;


#pragma region Class define

Character player;
Character ennemie;
Merchant merchant;
Creature creature;
Attack attack;

#pragma endregion



#pragma region weapon define

Weapon bow = Weapon("Arc", "arme a longue distance", WeaponTypes::Bow, 10, 20, 20, 1);
Weapon Dagger = Weapon("Dagger", "arme de poing", WeaponTypes::Dagger, 10, 20, 20, 1);
Weapon Staff = Weapon("Staff", "arme efficace", WeaponTypes::Staff, 10, 20, 20, 1);
Weapon Sword = Weapon("Sword", "arme courte distance", WeaponTypes::Sword, 10, 20, 20, 1);

#pragma endregion

#pragma region attack define
Attack sucumb = Attack(" sucumb", bow, 20, DamageType::Bludgeoning, (rand() % 5 + 1));
Attack crush = Attack("crush", Dagger, 20, DamageType::Bludgeoning, (rand() % 5 + 1));
Attack destroy = Attack("destroy", Staff, 20, DamageType::Bludgeoning, (rand() % 5 + 1));
Attack doomFist = Attack("doomFist", Sword, 20, DamageType::Bludgeoning, (rand() % 5 + 1));

#pragma endregion

#pragma region creature define

Creature bouboule = Creature("BouBoule", " un enorme tat de merde", 50, vector<Attack>{crush}, (rand() % 20 + 1));

#pragma endregion




#pragma region Data
string firstName;
string lastName;
string catchPhrase;
int money; 
int lifePoints;
#pragma endregion

 
void MerchantIntroduce();
void FightEnnemie();
void Attacke(bool firstCall = false);


int InputHandler() {
    int num;
    while (cout<<" Ton choix :" && !(cin >> num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Rentre un chiffre " << endl;
    }
    return num;
}
void Choice() {

    cout << "1 : Parler au marchant " << endl;
    cout << "2 : Ce battre " << endl;
    cout << "3 : Regarder son inventaire" << endl;
    
    int Banswer;
    do {
        Banswer = InputHandler();

        if (Banswer == 1) MerchantIntroduce();
           
        else if (Banswer == 2) FightEnnemie();

        else if (Banswer == 3) player.Inventaire(player);

    } while (Banswer != 1 && Banswer != 2 && Banswer != 3);

    Choice();
}

void MerchantIntroduce() {

    cout << " Bonjour, je m'appel " << merchant.GetMerchantName() << ". Et te voici dans mon shop ! Le " << merchant.ShopName() << endl;
    cout << " J'ai plein de chose a vendre ! Mais je peut aussi acheter " << endl;
    cout << " Que veut tu ? " << endl;
    cout << " 1 : Acheter une arme " << endl;
    cout << " 2 : Vendre une arme " << endl;
    int Aanswer;
    do {
         Aanswer = InputHandler();
       

       
         if (Aanswer == 1) {
             if (player.GetMoney() >= 15) {
                 cout << "Voici mes armes : " << endl;
                 cout << " La quel veut tu acheter ? " << endl;
                 cout << " 1 : " << merchant.GetWeapon()[0].GetShopDescription() << endl;
                 cout << " 2 : " << merchant.GetWeapon()[1].GetShopDescription() << endl;
                 cout << " 3 : " << merchant.GetWeapon()[2].GetShopDescription() << endl;
                 cout << " 4 : " << merchant.GetWeapon()[3].GetShopDescription() << endl;


                 int Banswer;
                 do {
                     Banswer = InputHandler();

                     if (Banswer == 1) merchant.SellWeapon(player, merchant.GetWeapon()[0], Banswer);
                     else if (Banswer == 2)  merchant.SellWeapon(player, merchant.GetWeapon()[1], Banswer);
                     else if (Banswer == 2)  merchant.SellWeapon(player, merchant.GetWeapon()[2], Banswer);
                     else if (Banswer == 3)  merchant.SellWeapon(player, merchant.GetWeapon()[3], Banswer);

                 } while (Banswer != 1 && Banswer != 2 && Banswer != 3 && Banswer != 4);

             }
             else
             {
                 cout << "Tu n'as pas assez d'argent pour acheter un arme " << endl;
             }
         }
        else if (Aanswer == 2)
        {
            cout << "Quel arme veut tu me vendre ? " << endl;
            cout<< " Tu as : " <<endl;
            for (size_t i = 0; i < player.GetCharaWeapon().size(); i++)
            {
                cout << i+1 << player.GetCharaWeapon()[i].GetShopDescription() << endl;
                
            }
            int Canswer;
            do {
                 Canswer = InputHandler();
                if (Canswer == 1) merchant.BuyWeapon(player, merchant.GetWeapon()[0], Canswer);
                else if (Canswer == 2)  merchant.BuyWeapon(player, merchant.GetWeapon()[1], Canswer);
                else if (Canswer == 2)  merchant.BuyWeapon(player, merchant.GetWeapon()[2], Canswer);
                else if (Canswer == 3)  merchant.BuyWeapon(player, merchant.GetWeapon()[3], Canswer);

            } while (Canswer != 1 && Canswer != 2 && Canswer != 3 && Canswer != 4);


        }

    } while (Aanswer != 1 && Aanswer != 2);

}

void FightEnnemie() {
    while (player.GetLifePoints() > 0 && ennemie.GetLifePoints() > 0)
    {
        ennemie = Character(" Igore ", " Le Gore ", " Va mourir", 50, 100, vector<Weapon>{ Sword}, Race::Orc, "Creature horrible", vector<Attack>{crush}, (rand() % 20));
        ennemie.IntroduceChara();
        cout << " Que veut tu faire ? " << endl;
        cout << "1 : Le frapper en premier " << endl;
        cout << "2 : Fuire ! Et retourner au menu " << endl;
        int Fanswer;
        do {
            Fanswer = InputHandler();
            if (Fanswer == 1) Attacke(true);
            if (Fanswer == 2) Choice();
        } while (Fanswer != 1 && Fanswer != 2);


    }
}



void Attacke(bool firstCall) {

    while (player.GetLifePoints() > 0 && ennemie.GetLifePoints() > 0)
    {


        cout << "Nous allons jeter le des pour savoir si ton attack peut toucher " << endl;
        if (attack.Resolve(ennemie)) {
            cout << "Super ton attack peut toucher ! " << endl;
            cout << " Mainetant choisis qu'elle arme veut-tu utiliser " << endl;
            for (size_t i = 0; i < player.GetCharaWeapon().size(); i++)
            {
                cout << i + 1 << player.GetCharaWeapon()[i].GetName() << endl;

            }
            int Gamswer;
            do {
                Gamswer = InputHandler();
                if (Gamswer == 1 || Gamswer == 2) {

                    player.Use(player, Gamswer - 1);
                }

            } while (Gamswer != 1 && Gamswer != 2);
            
 
            ennemie.SetLifePoints(ennemie.GetLifePoints() - player.RollTheDice());
            
            cout << " Vous l'avez bien toucher ! Il n'a plus que " << ennemie.GetLifePoints() << " points de vie " << endl;
            cout << "De ton coter ton arme a " << player.GetWeaponDurability(Gamswer - 1) << " points de durabiliter " << endl;
            player.SetLifePoints(player.GetLifePoints() - 20);
            cout << " Attention il vient de vous attacker ! Vous avez perdu 20 points de vie. Il vous reste " << player.GetLifePoints() << " point de vies " << endl;

            cout << " Que veut tu faire ? " << endl;
            cout << "1 : Le frapper " << endl;
            cout << "2 : Te heal et partir " << endl;
            int Panswer;
            do {
                Panswer = InputHandler();
                if (Panswer == 1) Attacke();
                if (Panswer == 2) {
                    player.SetLifePoints(player.GetLifePoints() + 20);
                    cout << "Super ! Tu t'est soigner..., tu as " << player.GetLifePoints() << " points de vie " << endl;
                    Choice();

                }
            } while (Panswer != 1 && Panswer != 2 && player.GetLifePoints() > 0 && ennemie.GetLifePoints() > 0);
        }
        else
        {
            cout << " Malheuresement ton attack ne peut pas toucher..." << endl;
            cout << "IL VIENT DONC TE T'ATTAQUER ! " << endl;
            player.SetLifePoints(player.GetLifePoints() - 20);
            cout << " Tu as " << player.GetLifePoints() << " points de vie " << endl;
            Attacke();
        }
    }
    if (firstCall) {

        if (ennemie.GetLifePoints() <= 0) {
            cout << " L'ennemie est mort ! Tu peut le loot !" << endl;
            player.LootMoney(ennemie, player);
            player.AddWeapon(ennemie.GetCharaWeapon()[0]);

        }

        if (player.GetLifePoints() <= 0) {
            cout << "-------- G A M E  O V E R -------- " << endl;
        }
    }

   

    
   
}


int main()  
{

    cout << "Bonjour voyageur ! Bienvenu dans ce simulateur RPG" << endl;
    cout << " Je t'invite a cree ton personnage : " << endl;

    cout << " Quel est ton nom ? " << endl; 
    getline(cin, firstName);

    cout << "Tres bien ! Quel est ton nom de famille ? " << endl;
    getline(cin, lastName);

    cout << "Quel est ta phrase d'accroche ? " << endl;
    getline(cin, catchPhrase);

    cout << "Combien a-tu d'argent ? " << endl;
    money = InputHandler();

    cout << "Combien a-tu de point de vie ?" << endl;
    lifePoints = InputHandler();


    cout << "Et pour finir, quel est ton arme ? Et ton attack" << endl;
    cout << "1 : Un arc avec l'attaque sucumb " << endl;
    cout << "2 : Une dague avec l'attaque crush" << endl;
    cout << "3 : Un staff avec l'attaque destroy" << endl;
    cout << "4 : Une epee avec l'attaque doomfist" << endl;
    int Aanswer;

    do {
         Aanswer = InputHandler();

        if (Aanswer == 1) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ bow }, Race::Human, "Creature innofensive", vector<Attack>{sucumb}, (rand() % 20));

        else if (Aanswer == 2) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Dagger }, Race::Human, "Creature innofensive", vector<Attack>{crush}, (rand() % 20));
        
        else if (Aanswer == 3) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Staff }, Race::Human, "Creature innofensive", vector<Attack>{destroy}, (rand() % 20));

        else if (Aanswer == 4) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Sword }, Race::Human, "Creatureinnofensive", vector<Attack>{doomFist}, (rand() % 20));
        
       
    }
    while (Aanswer != 1 && Aanswer != 2 && Aanswer != 3 && Aanswer != 4);

    cout << "Super " << firstName << " Votres personnage a etais cree !" << endl;
    cout << " Vous avez " << money << " $ " << " et " << lifePoints << " points de vies ! " << endl;
    cout << " Maintenant que voulez vous faire ? " << endl;
    
    Choice();

    }








