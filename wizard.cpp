#include "hub.cpp"

void run_wizard()
{
    int low_bound, high_bound, guess;
    char answer;

    cout << "Enter Lower Bound: ";
    cin >> low_bound;
    cout << "Enter Higher Bound: ";
    cin >> high_bound;

    while (answer != 'y')
    {
        guess = (low_bound + high_bound) / 2;
        cout << "Is your number " << guess << "?\ny for yes\nh if it's higher\nl if it's lower" << endl;
        cin >> answer;

        switch (answer)
        {
        case 'h':
            low_bound = guess + 1;
            break;
        case 'l':
            high_bound = guess - 1;
            break;
        case 'y':
            break;
        default:
            cout << "Invalid Choice, try again.";
            break;
        }
    }

    cout << "Your Number is: " << guess << endl;

    return;
}