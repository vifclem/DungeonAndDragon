
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Merchant.h"
#include "Weapon.h"

using namespace std;

#pragma region Class define

Character player;
Character ennemie;
Merchant merchant;

#pragma endregion


#pragma region weapon define

Weapon bow = Weapon("Arc", "arme a longue distance", WeaponTypes::Bow, 10, 20, 20, 1);
Weapon Dagger = Weapon("Dagger", "arme de poing", WeaponTypes::Dagger, 10, 20, 20, 1);
Weapon Staff = Weapon("Staff", "arme efficace", WeaponTypes::Staff, 10, 20, 20, 1);
Weapon Sword = Weapon("Sword", "arme courte distance", WeaponTypes::Sword, 10, 20, 20, 1);

#pragma endregion



#pragma region Data
string firstName;
string lastName;
string catchPhrase;
int money; 
int lifePoints;
#pragma endregion

 
void MerchantIntroduce();
void Fight();
void Attack();


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
           
        else if (Banswer == 2) Fight();

        else if (Banswer == 3) player.Inventaire();

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

void Fight() {

    ennemie = Character("Bangala", " bieloRusse", " Va mourir", 50, 100, vector<Weapon>{ Sword}, Race::Orc);
    ennemie.IntroduceChara();
    cout << " Que veut tu faire ? " << endl;
    cout << "1 : Le frapper en premier " << endl;
    cout << "2 : Fuire ! Et retourner au menu " << endl;
    int Fanswer;
    do {
         Fanswer = InputHandler();
        if (Fanswer == 1) Attack();
    } while (Fanswer != 1);
    

}



void Attack() {
    cout << " Qu'elle arme veut-tu utiliser ? " << endl;
    for (size_t i = 0; i < player.GetCharaWeapon().size(); i++)
    {
        cout << i + 1 << player.GetCharaWeapon()[i].GetName() << endl;

    }
    int Gamswer;
    do {
        Gamswer = InputHandler();
        if (Gamswer == 1 || Gamswer == 2) {
           
            //Weapon* weaponUse =&(player.GetCharaWeapon()[Gamswer - 1]);
            player.Use(player, Gamswer - 1);
            cout << " La durabiliter de ton arme est de : " << player.GetWeaponDurability(Gamswer-1) << endl;
        }

    } while (Gamswer != 1 && Gamswer != 2);
    

    ennemie.SetLifePoints(ennemie.GetLifePoints() - 20);
    
    cout << " Vous l'avez bien toucher ! Il n'a plus que "<< ennemie.GetLifePoints() << endl;
    player.SetLifePoints(player.GetLifePoints() - 20);
    cout << " Attention il vient de vous attacker ! Vous avez perdu 20 points de vie. Il vous reste "<< player.GetLifePoints() << " point de vies " << endl;


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


    cout << "Et pour finir, quel est ton arme ? " << endl;
    cout << "1 : Un arc" << endl;
    cout << "2 : Une dague" << endl;
    cout << "3 : Un staff" << endl;
    cout << "4 : Une epee" << endl;
    int Aanswer;

    do {
         Aanswer = InputHandler();

        if (Aanswer == 1) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ bow }, Race::Human);

        else if (Aanswer == 2) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Dagger }, Race::Human);
        
        else if (Aanswer == 3) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Staff }, Race::Human);

        else if (Aanswer == 4) player = Character(firstName, lastName, catchPhrase, money, lifePoints, vector<Weapon>{ Sword }, Race::Human);
        
       
    }
    while (Aanswer != 1 && Aanswer != 2 && Aanswer != 3 && Aanswer != 4);

    cout << "Super " << firstName << " Votres personnage a etais cree !" << endl;
    cout << " Vous avez " << money << " $ " << " et " << lifePoints << " points de vies ! " << endl;
    cout << " Maintenant que voulez vous faire ? " << endl;
    
    Choice();

    }








