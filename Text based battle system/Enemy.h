#pragma once



#include "Base class.h"

#include <iostream>
#include <random>
#include <string>
#include <vector>



using namespace std;
using namespace base;

namespace e
{
	class Enemy : public game
	{

	private:
		
		// a randdom string of names for the enemy. i'll add more later.
		
		//i should probably justify some of the enemy names.
		const vector<string> names =
		{ "Shady Buinessman",
			"Corrupt politician",
			"Person who puts pineapple on their pizza", //shame on you.
			"Corrupt buisnesman called ajit pai", //net nuetrality: let's end it there.
			"Symmetra", //the biggest villan of all.
			"Deity",
			"Classy millenial",
			"Sun Tzu",
			"The wolf of wall street.",
			"A dead meme",
			"An r/dankmemes moderator.",
			"Johnny dang",
			"Leftoff",
			"Kogami", //i'm a sucker for psycho-pass
			"[Read at: 7:45 pm]", //:salt:
			"Amy Rose", //sonic character.
			"A personification of the dev's adolescent confusion", //???
			"a Placeholder name",
			"A pig" //because why not.

		};

		const vector<string> actions =
		{
			"Slithers before you...",
			"Charges for your oh so petrified soul...!",
			"walks into a bar...",
			"Approaches you dilligently, a seductive look in his eye.",
			"makes a cringe worthy 21st century joke before rasing his fists in a fighting game esque fashion. you roll your eyes.",
			"..Dabs. you'vew won this fight already.",
			"Pops a tide pod into his mouth, chewing for the meme.",
			"Starts getting all stirred ip because they can't handle being left on read.",
			"Coughs to signal his arrival.",
			"Screams...",
			"Makes a edgy and contriversal joke to stir you. wow, you're all rhilled up now.",
			"comes bouncing onto the scene, like some hyperactive battle toad.",
			"Stomps over to your with a monmumentous rage.",
			"...non chalantly struts onto the stage, bowing.",
			"Readies his dominator.",
			"Straps on his diamond AP watch. you sigh, acknowledging such a waste of precious metals."
		};


		//change the below slightly.
		size_t namesLength = names.size();//we'll probably need another method of finding the length of a string.
		size_t actionsLength = actions.size();

	public:

		// we'll sort this initialisation out in a seprate file.
		//Constructor goes here, looks like we'll be writing all the code here, to avoid the nightmare that are separate files and inheritence.
		Enemy(int health, int defence) : game(health, defence)

		{
			//how it works: get a random number; that number will serve as a random index in oder to generate a random name for the enemy.
			random_device rd;
			uniform_int_distribution<int> dist(0, namesLength - 1);//learn how to get the length of an array.
			int randIndex = dist(rd);
			name = names[randIndex];

			//NOTE: WE SHOULD BE FINE RE-USING RD, BUT IF ANY PROBLEMS COME UP TRYING TO ALLOCATE A TRULY RANDOM NUMBER, REFER BACK TO HERE.

			//create similar algorithiim to declare a random action.
			uniform_int_distribution<int> dist2(0, actionsLength - 1);
			randIndex = dist2(rd);
			string randAction = actions[randIndex];

			cout << "A " << name << " " << randAction << endl;
			cout << " " << endl;
			cout << "You raise your fists, ready for a fight." << endl;
			cout << " " << endl;

		};

		void gap_() override; //partitions text based on the entity, for example a human would gave the "==============HUMAN=========" partition.

		int lightAttack()override;
		int heavyAttack()override;


		void raiseDefence()override;//raises defence by +8, but health by 3.
		void speech()override;
		void damage(int dValue)override; //dValue = damage value.
		void behaviour() override;//returns a random number and decides the enemy behaviour.
		void death() override;


	};

}
