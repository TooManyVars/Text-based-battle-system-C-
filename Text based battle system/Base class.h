#pragma once

#include <iostream>

using namespace std;
namespace base
{
	class game
	{
	protected:
		int attack, defence, health;
		int turns;
		string name;


	public:

		game(int defence, int health)
		{
			this->attack = attack;
			this->defence = defence;
			this->health = health;
			this->name = name;
		}

		game() //new default constructor for our newest change.
		{
			this->attack = attack;
			this->defence = defence;
			this->health = health;
			this->name = name;
		}

		//simply partitions text.
		void gap() { cout << " " << endl; }

		//virtual functions with different implementations.



		virtual void gap_() { cout << "<Gap method>" << endl; }; //partitions text based on the entity, for example a human would gave the "==============HUMAN=========" partition.
		void line_gap() { cout << "--------------------------------------------------------------------------------" << endl; };

		//integer return functions
		virtual int lightAttack();//quick, will do less damage.
		virtual int heavyAttack();//more damage but is slower, will decrease defence by the damage value, say a base value of 8 would mean 15 - 8 defence.

								  //no return type functions.
		virtual void raiseDefence() { cout << "Defence method" << endl; }//raises defence by +5.
		virtual void speech() { cout << "<Speech method>" << endl; };
		virtual void damage(int dValue);//dValue = damage value.//note: damage is only called if the damage is higher than 0, so the enemy missing/doing another attack wouldn't print the player's current health
		virtual void behaviour() { cout << "behaviour method" << endl; }
		virtual void death() { cout << "Death method" << endl; }//checks if the player/enemy should be dead and displays a "You died" message type thing.

		/**virtual*/ int getHealth() { return health; }//return function to handle data outside the class.
		/**virtual*/ int getAttack() { return attack; }
		int getDefence() { return defence; };
		void setAttack(int value) { attack = value; }
		void setDefence(int value);

		string getName() { return name; };

	};
};