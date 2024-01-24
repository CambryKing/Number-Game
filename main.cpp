#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <chrono>

using namespace std;

int GetNumber(const string &message)
{
    int input;
    while (true)
    {
        cout << message; // Print message passed to function
        if (cin >> input)
        {
            break; // Ends loop if number is inputed
        }

        else
        {
            cin.clear();                                         // Reset Error Flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Through out non-numeric input
            cout << "Error with input. Try again." << endl;      // Printed Error Message
        }
    }
    return input; // Returns number
}

int main()
{
    int minVal = GetNumber("\nEnter Minimum Value: "); // Returns minVal
    int maxVal = GetNumber("\nEnter Maximum Value: "); // Returns maxVal

    int random;
    int guess = 0;
    int flag = 0;
    bool correct = false;
    srand(time(0)); // Seed random number

    if (maxVal < minVal) // Swap function if maxVal is smaller than minVal
    {
        int temp = maxVal;
        maxVal = minVal;
        minVal = temp;
    }

    random = (rand() % (maxVal - minVal + 1)) + minVal; // Create random number

    while (!correct)
    {
        guess = GetNumber("\nPlease Enter your Guess: "); // Return guessed number

        cout << "\nYour Guess is";

        while (flag < 3) // Added periods for dramatic effect
        {
            cout << ".";
            usleep(5000000); // OH! So dramatic!
            flag++;
        }

        if (guess < random)
        {
            cout << "Too Small!" << endl;
        }

        else if (guess > random)
        {
            cout << "Too Big!" << endl;
        }

        else
        {
            cout << "Correct!!!" << endl;
            correct = true; // Breaks loop
        }
        flag = 0; // Resets the drama flags
    }

    return 0;
}