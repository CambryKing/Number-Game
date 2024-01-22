#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int minVal;
    int maxVal;
    int chosen;
    int random;
    int guess = 0;
    bool correct = false;
    srand(time(0));

    cout << "\nEnter Minimum Value: ";
    cin >> minVal;
    cout << "\nEnter Maximum Value: ";
    cin >> maxVal;

    if (maxVal < minVal)
    {
        int temp = maxVal;
        maxVal = minVal;
        minVal = temp;
    }

    random = (rand() % (maxVal - minVal + 1)) + minVal;

    while (!correct)
    {
        cout << "\nPlease Enter Your Guess: ";
        cin >> guess;

        if (guess < random)
        {
            cout << "\nYour Guess is Too Small!";
        }

        else if (guess > random)
        {
            cout << "\nYour Guess is Too Big!";
        }

        else
        {
            cout << "\nYour Guess is Correct!!!";
            correct = true;
        }
    }

    return 0;
}