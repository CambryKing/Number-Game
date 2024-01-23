#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <chrono>

using namespace std;

int main()
{
    int minVal;
    int maxVal;
    int chosen;
    int random;
    int guess = 0;
    int flag = 0;
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

        cout << "\nYour Guess is";

        while (flag < 3)
        {
            cout << ".";
            usleep(5000000);
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
            correct = true;
        }
        flag = 0;
    }

    return 0;
}