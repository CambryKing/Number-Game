#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <chrono>

using namespace std;

int GetNumber(const string &message)
{
    int input;
    while(true)
    {
        cout<<message;
        if(cin>>input)
        {
            break;
        }

        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Error with input. Try again."<<endl;
        }
    }
    return input;
}

int main()
{
    int minVal = GetNumber("\nEnter Minimum Value: ");
    int maxVal = GetNumber("\nEnter Maximum Value: ");

    int random;
    int guess = 0;
    int flag = 0;
    bool correct = false;
    srand(time(0));

    if (maxVal < minVal)
    {
        int temp = maxVal;
        maxVal = minVal;
        minVal = temp;
    }

    random = (rand() % (maxVal - minVal + 1)) + minVal;

    while (!correct)
    {
        guess = GetNumber("\nPlease Enter your Guess: ");

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