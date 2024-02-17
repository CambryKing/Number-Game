#include "hub.cpp"

/*
    THIS IS A WORK IN PROGRESS
*/

void display_cases(double *cases) // Displays Cases (What's Left)
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

void display_money(double *money) // Displays Money (What's Left)
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

double case_number(double *cases) // Returns Number of Cases
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cases[i] != -1)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    return count;
}

double max_case(double *cases) // Returns highest case left
{
    int max = -1;
    for (int i = 0; i < 26; i++)
    {
        if (cases[i] > max)
        {
            max = cases[i];
        }
    }
    return max;
}

double banker(double *cases, double player_money) // Formula from : https://www.reddit.com/r/askmath/comments/696pxs/deal_or_no_deal_figuring_out_the_deal_formula/
{
    /*double num_case = case_number(cases);
    double max = max_case(cases);
    double banker_suggestion = -1;

    banker_suggestion = 12275.30 + (0.748 * player_money) - (2714.74 * num_case) - (0.4 * max) + (0.0000006986 * (player_money * player_money)) + (32.623 * (num_case));

    */

    return 2714.74;
}

int main()
{
    double cases[26];                                                                                                                                                               // Initialize cases
    double money[26] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000}; // Initializes money
    int player_case;                                                                                                                                                                // The case the Player chooses
    double player_money;                                                                                                                                                            // The money in the Player case
    bool deal = false;                                                                                                                                                              // While loop termination condition
    int choice;                                                                                                                                                                     // Additional condition for while loop termination
    int deal_choice;                                                                                                                                                                // Choice for the banker
    double banker_suggestion = -1;                                                                                                                                                  // The suggestion for the banker
    int round = 0;                                                                                                                                                                  // Activates the banker after three rounds
    bool flag = false;

    srand(time(0));
    copy(begin(money), end(money), begin(cases));
    random_shuffle(begin(cases), end(cases));

    display_cases(cases);

    cout << "\nPlease Choose your case!: ";
    cin >> player_case;

    player_money = cases[player_case]; // THis is a change I am making
    cases[player_case - 1] = -1;

    while (!deal)
    {
        cout << "\n-----------------------------------------\nCases Left:\n";
        display_cases(cases);
        cout << "\n-----------------------------------------\nMoney Left:\n";
        display_money(money);
        cout << "\nWhich Case Do You Want To Open: ";
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

        round++;

        if (round == 3)
        {
            banker_suggestion = banker(cases, player_money);
            cout << "\n-----------------------------------------\nTHE BANKER IS OFFERING $" << banker_suggestion << endl;
            cout << "What is your choice?\n1.Deal?\n2.No Deal?\n";
            cin >> deal_choice;

            switch (deal_choice)
            {
            case 1:
                cout << "\nYou have taken the deal!\n";
                deal = true;
                break;
            case 2:
                cout << "You have rejected the deal!\n";
                round = 0;
                break;
            }
        }

        if (deal == false)
        {
            cout << "Exit? \n1. Yes\n2. No\n";
            cin >> choice;
        }

        if (choice == 1)
        {
            deal = true;
            flag = true;
        }
    }

    // cout << "\nYour Case Has $" << player_money << " Within! \nThank you for playing!";

    if (flag == false)
    {
        if (banker_suggestion > player_money)
            cout << "\nYour Case Has $" << player_money << " Within.\nYou Win!";
        else
            cout << "\nYour Case Has $" << player_money << " Within.\nYou lose!";
    }

    else
    {
        if (banker_suggestion < player_money)
            cout << "\nYour Case Has $" << player_money << " Within.\nYou Win!";
        else
            cout << "\nYour Case Has $" << player_money << " Within.\nYou Lose!";
    }

    return 0;
}