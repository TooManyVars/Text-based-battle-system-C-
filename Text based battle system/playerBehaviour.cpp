#include "Base class.h"
#include "Player.h"

#include <vector>
#include <string>
#include <random>
#include <map>


using namespace std;
using namespace base;
using namespace P;



void Player::gap_()
{
	cout << "=====================================PLAYER=====================================" << endl;
}

void Player::help()
{

	cout << "======================================Command list=====================================" << endl;
	cout << "-(heavy)attack: reduces DEFENCE by 5, and if there is not enough, it reduces HEALTH by 5 instead. similar to LIGHT ATTACK, but has a chance to do large damage.\n-(light)attack: perform a small damage attack with little consequence. \n-speak: abuse the AI with whatever profrane insult you can roll off of the top of your head.\n-defend: raise your DEFENCE." << endl;
	cout << "=======================================================================================" << endl;
	system("Pause");

}

int Player::lightAttack()
{

	attack = game::lightAttack();


	random_device rd;
	uniform_int_distribution<int> dist(0, 4);

	attack = dist(rd);


	cout << "You, " << name << ", performed a light attack!" << endl;
	cout << "You";

	switch (attack)
	{
	case 0:
		cout << "...missed.Moving on... ? " << endl;
		break;
	case 1:
		cout << "...made the enemy sustain the minimum damage, ever so slightly displacing the atoms on your opponents' personal bubble ." << endl;
		break;
	case 2:
		cout << "...dealt minute damage...you shake your head in disappointment." << endl;
		break;
	case 3:
		cout << "...did extremely little damage.  Ok... I guess?" << endl;
		break;
	case 4:
		cout << "...achieved small detriment to your opponent(nothing worth bragging about, though)." << endl;
		break;
	}



	return attack;

}

int Player::heavyAttack()
{

	attack = game::heavyAttack(); //set the attack stat to zero before operating in order to avoid any damage stacking.

	random_device rd;
	uniform_int_distribution<int> dist(0, 8);

	attack = dist(rd);

	cout << "You, " << name << ", perform a heavy attack, in exchange for -5 DEFENCE/HEALTH!" << endl;
	cout << "You";

	switch (attack)
	{
	case 0:
		cout << "missed. Moving on... ? " << endl;
		break;
	case 1:
		cout << "...made the enemy sustain the minimum damage, ever so slightly displacing the atoms on your opponents' personal bubble ." << endl;
		break;
	case 2:
		cout << "...dealt minute damage...you shake your head in disappointment." << endl;
		break;
	case 3:
		cout << "...did extremely little damage.  Ok... I guess?" << endl;
		break;
	case 4:
		cout << "...achieved small detriment to your opponent(nothing worth bragging about, though)." << endl;
		break;
	case 5:
		cout << "...made the enemy undergo light damage...gaining a small twang in confidence." << endl;
		break;
	case 6:
		cout << "...exercised your (lets say, might), dealing large damage." << endl;
		break;
	case 7:
		cout << "...Became the metaphorical grim reaper, dishing out massive damage!" << endl;
		break;
	case 8:
		cout << "...are pretty much cheating. You pretty much nuked your opponent. Play fair next turn, will ya?" << endl;
		break;

	}

	return attack;


}

void Player::raiseDefence()
{
	defence += 8;
	health -= 3;

	cout << "You raised your DEFENCE by +8, in exchange for -3 HEALTH" << endl << "Your defence is now: " << defence << endl << "Your health is now: " << health << endl;
}


void Player::speech()
{
	string phrase;
	cout << "Say something..." << endl;
	getline(cin, phrase);
	cout << name << ": " << endl << "============" << endl << phrase << endl;
}

void Player::damage(int dValue)
{
	game::damage(dValue);

	if (health > 0)
	{
		cout << name << " 's health is currently: " << health << endl << name << " 's defence is currently: " << defence << endl;
	}
	line_gap();

}

void Player::behaviour()
{
	string choice;
	cout << "What would you like to do?" << endl;
	getline(cin, choice);

	while (choice != "light" && choice != " light" && choice != "Light" && choice != " Light" && choice != "Heavy" && choice != " Heavy" && choice != " heavy" && choice != "heavy" && choice != "Defend" && choice != " Defend" && choice != "defend" && choice != " defend" && choice != "Speak" && choice != " Speak" && choice != "speak" && choice != " speak")
	{
		cout << "Choice is invalid; please try again." << endl;
		cout << "What would you like to do?" << endl;
		getline(cin, choice);

	}

	Player::gap_();

	//handling all commands manually was the most reliable method of making sure functions were appropriately called  when CORRECT input is entered.

	if (choice == "light" || choice == " light" || choice == "Light" || choice == " Light")
	{
		lightAttack();
	}

	else if (choice == "Heavy" || choice == " Heavy" || choice == " heavy" || choice == "heavy")
	{
		heavyAttack();
	}

	else if (choice == "Defend" || choice == " Defend" || choice == "defend" || choice == " defend")
	{
		raiseDefence();
	}

	else if (choice == "Speak" || choice == " Speak" || choice == "speak" || choice == " speak")
	{
		speech();
	}


	gap();
	system("Pause");
	gap();

}

void Player::death()
{
	if (health <= 0)
	{
		cout << "Your HEALTH has hit zero." << endl << "rest in peace, my man(or attack chopper, i don't misgender) " << name << " ..." << endl;
	}
}