
// Include standard headers
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

// Include custom headers
#include "gameSpecs.h"
#include "enemyAI.h"

/**
 * Displays random battleship coordinates in quick succession to make the
 * illusion that the computer/enemy is thinking about which coordinate to shoot
 * at.
 *
 * After the function returns the last random coordinate is still on the screen,
 * but the cursor is back up so that it can be overwritten with something new.
 */
void randomCoordinatesAnimation();

int main ()
{

	return 0;
}

void randomCoordinatesAnimation()
{
	// Variables to hold random coordinates to print
	int colNumber;
	char rowLetter;

	cout << left; // left align columns

	// Repeatedly output a random coordinate, then wait, then backup to overwrite
	// The pauses increase in time exponentially until it is >= 160 msecs
	for (int msecs = 10; msecs < 160; msecs = static_cast<int>(msecs * 1.1))
	{
		// Get random numbers
		rowLetter = rand() % BOARD_LENGTH + 'A';
		colNumber = rand() % (BOARD_LENGTH) + 1;

		// Output numbers
		cout << rowLetter << setw(2) << colNumber << flush;

		// Wait the alloted time
		this_thread::sleep_for(chrono::milliseconds(msecs));

		// Backup for next output.
		cout << "\b\b\b";
	}

	cout << right; // reset alignment back to the default
}