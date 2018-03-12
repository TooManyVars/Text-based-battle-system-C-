#include"Base class.h"

using namespace base;

int game::lightAttack()
{

	setAttack(0); //sets the player's attack to be 0 in this superclass method in order to ensure no stacked values.
	return attack;
}

void game::damage(int dValue)
{
	line_gap();

	while (dValue > 0)
	{


		if (defence <= 0) //check if defence is less than zero before subtracting.
		{
			setDefence(0);
			health -= dValue * 2;
		}

		else if (defence > 0) //otherwise if it is more than zero, subtract from the defence
		{
			defence -= dValue * 2;

		}


		dValue--;
	}


}

void game::setDefence(int value)
{
	defence = value;
}

int game::heavyAttack()
{

	int reductionValue = 5; //the value to reduce the player's defence/health by.

							//check if there is enough defence.
							//if so, take away from the defence.
	if (defence >= reductionValue)
	{
		defence -= reductionValue;
	}

	else if (defence < reductionValue)
	{
		health -= reductionValue;
	}

	//set the player's attack to 0 to avoid damage stacking.
	setAttack(0); //sets the player's attack to be 0 in this superclass method in order to ensure no stacked values.
	return attack; //return the attack instead of null.
}