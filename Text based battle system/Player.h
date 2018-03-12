#pragma once


#include "Base class.h"
#include"Enemy.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;
using namespace base;
using namespace e;


namespace P
{
	class Player : public game
	{
	public:

		Player(int health, int defence) : game(health, defence)

		{

			cout << "welcome to the ill conceived waste of time that is the battle! enter your name:" << endl;

			getline(cin, name);//using getline outputs the whole string.
		}

		void gap_() override; //partitions text based on the entity, for example a human would gave the "==============HUMAN=========" partition.

		int lightAttack()override;
		int heavyAttack()override;

		void raiseDefence()override;//raises defence by +8, but health by 3.
		void speech()override;
		void damage(int dValue)override; //dValue = damage value.
		void behaviour() override;
		void death() override;
		void help();


	};
}