#include "hub.cpp"

/*
    THIS IS A WORK IN PROGRESS
*/

void display_cases(double *cases)
{ 
    for (int i = 0; i < 26; i++)
    {
        if (cases[i] == -1)
            cout << "Opened\t";
        else
            cout << i + 1 << "\t";
        if ((i + 1) % 7 == 0)
            cout << endl;
    }
}

void display_money(double *money)
{
    for (int i = 0; i < 26; i++)
    {
        if (money[i] == -1)
            cout << "Redacted\t";
        else
            cout << "$" << money[i] << "\t";
        if ((i + 1) % 7 == 0)
            cout << endl;
    }
}

int main()
{
    double cases[26];
    double money[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};
    int player_case;
    double player_money;
    bool deal = false;
    int choice;

    srand(time(0));
    copy(begin(money), end(money), begin(cases));
    random_shuffle(begin(cases), end(cases));

    display_cases(cases);

    cout << "\nPlease Choose your case!: ";
    cin >> player_case;

    player_money = cases[player_case];
    cases[player_case - 1] = -1;

    while (!deal)
    {
        cout << "\n-----------------------------------------\nCases Left:\n";
        display_cases(cases);
        cout << "\n-----------------------------------------\nMoney Left:\n";
        display_money(money);
        cout << "\nWhich Case Do You Want To Open?";
        cin >> player_case;

        if (cases[player_case] == -1)
        {
            cout << "\nAlready Opened!\n";
        }
        else
        {
            cout << "In Case " << player_case << " you find $" << cases[player_case] << endl;
            for (int i = 0; i < 26; i++)
            {
                if (cases[player_case] == money[i])
                {
                    money[i] = -1;
                }
            }
            cases[player_case - 1] = -1;
        }

        cout << "Exit? \n1. Yes\n2. No";
        cin >> choice;

        if (choice == 1)
        {
            deal = true;
        }
    }

    cout << "\nYour Case Has $" << player_money << " Within! \nThank you for playing!";

    return 0;
}