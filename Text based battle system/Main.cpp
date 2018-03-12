#include <iostream>
#include <cstdlib>
#include <random>

#include "Enemy.h"
#include "Player.h"


using namespace std;
using namespace e;
using namespace P;


//note: the RNG element of this game may be slightly uncontrollable which isn't exactly fair(to either the player or the enemy).

/*Changes to make:
* clean up all the comments on this code.
* upload to gitHub.
*/

void battleLoop()
{
	int turns = 1;
	//create objects.
	Player player(15, 105); //i gave the player more defence in order to try and balance the damage done by the enemy.

							//lists commands at the start.
	player.help();

	Enemy enemy(10, 100);

	player.line_gap();
	cout << "Initial Health values: " << endl << " " << endl << enemy.getName() << ":" << endl << "Health: " << enemy.getHealth() << ", Defence: " << enemy.getDefence() << endl;
	cout << " " << endl;
	cout << player.getName() << ":" << endl << "Health: " << player.getHealth() << ", Defence: " << player.getDefence() << endl;
	player.line_gap();
	system("Pause");


	//create while loop that is repeated until enemy or player is dead.
	while (player.getHealth() > 0 && enemy.getHealth() > 0)
	{

		cout << "=====================================Turn " << turns << " ===================================== " << endl;

		player.setAttack(0);
		enemy.setAttack(0);

		player.behaviour();
		enemy.damage(player.getAttack());


		enemy.behaviour();
		player.damage(enemy.getAttack());

		turns++;
	}


	if (player.getHealth() <= 0)
	{
		player.death();
	}

	else if (player.getHealth() <= 0)
	{
		enemy.death();
	}


}


int main()
{
	battleLoop();


	/*

	Debug functions:

	//string phrase = "Yo";
	//string p2 = "yoo";

	//ob.formatOutput(phrase);
	//ob.formatOutput(p2);

	Enemy ob1(10, 100);

	ob1.lightAttack();
	cout << " Current attack is: " << ob1.getAttack() << endl;//note that damage does not and should not stack.


	ob1.behaviour();
	ob1.lightAttack();
	ob1.raiseDefence();
	ob1.heavyAttack();
	ob1.speech();
	ob1.damage(2);


	Player ob2(10, 100);
	ob2.damage(100000);
	ob2.death();
	ob2.behaviour();
	ob2.lightAttack();
	ob2.gap_();
	ob2.heavyAttack();
	ob2.raiseDefence();
	ob2.speech();
	ob2.damage(10);

	*/

	cout << "press ENTER to exit..." << endl; //technically you could enter anything, not just enter.


	cin.ignore(); //ignores input entered, exiting the program.
	return 0;

}

