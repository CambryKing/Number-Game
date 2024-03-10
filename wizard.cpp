#include "hub.h"

void run_wizard()
{
    cout << "==============Welcome To The Wizard Game!==============\n\n\n";

    int low_bound, high_bound, guess;
    int count = 1;
    char answer;

    cout << "Enter Lower Bound: "; // Asks for the low bound of the range
    cin >> low_bound;
    cout << "Enter Higher Bound: "; // Asks for the high bound of the range
    cin >> high_bound;

    if (low_bound > high_bound)
    {
        int temp = low_bound;
        low_bound = high_bound;
        high_bound = temp;
    }

    while (answer != 'y')
    {
        guess = (low_bound + high_bound) / 2;
        cout << "Is your number " << guess << "?\ny for yes\nh if it's higher\nl if it's lower" << endl;
        cin >> answer;

        switch (answer)
        {
        case 'h':
            low_bound = guess + 1; // Adjust the low bound to change guess
            count++;
            break;
        case 'l':
            high_bound = guess - 1; // Adjust the high to change guess
            count++;
            break;
        case 'y':
            break;
        default:
            cout << "Invalid Choice, try again."; // If the choice was outside of the approved answers, ask again
            break;
        }
    }

    cout << "\nYour Number is: " << guess << ". It was guessed in " << count << " attemps." << endl;

    return;
}