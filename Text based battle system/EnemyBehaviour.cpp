#include <iostream>
#include <random>
#include <string>
#include <map>

#include "Enemy.h"
#include "Base class.h"

using namespace std;
using namespace base;
using namespace e;


void Enemy::gap_()
{
	cout << "=====================================ENEMY=====================================" << endl;
}

int Enemy::lightAttack()
{
	attack = game::lightAttack();

	random_device rd;
	uniform_int_distribution<int> dist(0, 4);

	attack = dist(rd);
	//some conditions to take if the attack is a certain number, such as outputting text.

	cout << name << " performed a light attack." << endl;
	gap();
	cout << name << " ";

	switch (attack)
	{
	case 0:
		cout << "...missed, raising a shaking fist in fury and dismay." << endl;
		break;
	case 1:
		cout << "...did the minimum damage, profusely sweating with a blatant sense of anxiety." << endl;
		break;
	case 2:
		cout << "...attained minute damage, tugging at their collar with apprehension." << endl;
		break;
	case 3:
		cout << "...barely even hit you. What was the point in that?" << endl;
		break;
	case 4:
		cout << "...damaged you, but to a somewhat  small extent." << endl;
		break;
	}


	return attack;

}//assigns a random attack value between 0 and 4, prints a statement, and returns a value.


int Enemy::heavyAttack()
{
	attack = game::heavyAttack();

	random_device rd;
	uniform_int_distribution<int> dist(0, 8);
	attack = dist(rd);
	//some conditions to take if the attack is a certain number.
	cout << name << " performed a heavy attack, sacrificing -5 DEFENCE/HEALTH." << endl;

	cout << name << " ";

	switch (attack)
	{
	case 0:
		cout << "...missed, raising a shaking fist in fury and dismay." << endl;
		break;
	case 1:
		cout << "...did the minimum damage, profusely sweating with a blatant sense of anxiety." << endl;
		break;
	case 2:
		cout << "...attained minute damage, tugging at their collar with apprehension." << endl;
		break;
	case 3:
		cout << "...barely even hit you. What was the point in that?" << endl;
		break;
	case 4:
		cout << "...damaged you, but to a somewhat  small extent." << endl;
		break;
	case 5:
		cout << "...got in a medium hit on you, retreating quickly as to avoid any arrogance." << endl;
		break;
	case 6:
		cout << "...Did heavy damage, smirking slightly.This, of course, annoys you, so you screw him in a mix of disapproval and surprise. " << endl;
		break;
	case 7:
		cout << "...managed to do critical damage, laughing from the top of their metaphorical high horse while you ponder the attack's fairness." << endl;
		break;
	case 8:
		cout << "...did 'legendary damage!!!!'...Ok, can that even be considered fair? Someone, please fix this fucking game, and asap: this AI is out of control." << endl;
		break;
	}

	return attack;

}//does the same as light attack, but instead ranges from 0 to 8.

void Enemy::raiseDefence()
{
	defence += 8;
	health -= 5;

	cout << name << " raised their DEFENCE, in exchange for -5 HEALTH!" << endl;
	gap();
	cout << name << "'s health is now: " << health << endl << name << "'s Defence is now: " << defence << endl;
}

void Enemy::speech()//prints out random text dialogue.
{

	string Speech;//where the random phrases will be placed.

	const vector <string> phrases = {

		"Is THAT all??",
		"Waste of life and space, IMO",
		"<insert some wise, over the top Sun Tzu quote>",
		"Can u hurry up? i have a gynaecology appointment at 3.",
		"Don't play wise cracker with me, kid.",
		"Running away, are we, kid? what are you: french?",
		"How tasteful.",
		"Can this go faster? i'm dying of old age over here.",
		"I was gonna say something: forget it.",
		"Wow, and i thought i was bad.",
		"More ways to waste my time, i see?",
		"Wow, you are really annoying.",
		"This is a placeholder line, because the game creator was too lazy to add so many lines.",
		"The job...KILLER IS DEAD.",
		"Look at all this ice on my wrist ya'll can't tell me shit!",
		"I PLAY TO WIN!",
		"What a mess.",
		"One name you didn't know my name and now you want my fame?",
		"What does one even say to such a swine as incompetent as you!",
		"Is it even worth insulting you?",
		"Fantastic.",
		"OK DEXTER",
		"NANI?!",
		"I am not gonna die sober! <glugs tonic>",
		"Oh, I'm pissed now."
		"Is there even enough space left to process all these voice lines?"
	};

	size_t phrasesLength = phrases.size();//gets size of the array of phrases.
	random_device rd;
	uniform_int_distribution<int> dist(0, phrasesLength - 1); //gets a random index to iterate through.

	int randomIndex = dist(rd);

	Speech = phrases[randomIndex];

	cout << name << ": " << endl << "============" << endl << Speech << endl;
}

void Enemy::damage(int dValue)
{
	game::damage(dValue);

	if (health > 0)
	{
		cout << name << " 's health is currently: " << health << endl << name << " 's defence is currently: " << defence << endl;
	}

	line_gap();
}


void Enemy::behaviour()
{
	gap_();
	random_device rd;
	uniform_int_distribution<int> dist(0, 3);

	//switch case statements in order to manage calling of functions.
	int _behaviour = dist(rd);
	switch (_behaviour)
	{
	case 0:
		lightAttack();
		break;
	case 1:
		heavyAttack();
		break;
	case 2:
		raiseDefence();
		break;
	case 3:
		speech();
		break;
	}

}

void Enemy::death()
{
	if (health <= 0)
	{
		cout << "The " << name << " finally died. or did it get bored with you and off itself...?" << endl;
	}
}