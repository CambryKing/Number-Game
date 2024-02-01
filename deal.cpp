#include "hub.cpp"

/*
    THIS IS A WORK IN PROGRESS
*/

void display_cases(double *cases)
{
    int i = 0;

    while (i < 26)
    {
        for (int j = 0; j < 13; j++)
        {
            if (cases[i] == -1)
                cout << "Opened\t";
            else
                cout << i + 1 << "\t";
            i++;
        }
        cout << endl;
    }
}

int main()
{
    double cases[26];

    double money[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};

    // int options[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, }

    /*for (int i = 0; i < 26; i++)
    {
        cases[i] = i + 1;
    }*/

    for (int i = 0; i < 26; i++)
    {
        cout << money[i] << " ";
    }

    // display_cases(cases);

    return 0;
}