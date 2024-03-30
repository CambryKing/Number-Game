#include "guessing.cpp"
#include "deal.cpp"
#include "wizard.cpp"
using namespace std;

int main()
{
    int choice;
    bool exit = false;

    while (exit == false)
    {

        cout << "\n1. Guessing Game\n2. Deal or Possibly Not Deal\n3. Wizard Game\n4 Exit" << endl;
        cout << "\nPlease Enter What Game You Want!: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            run_guess();
            break;
        case 2:
            run_deal();
            break;
        case 3:
            run_wizard();
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "\nImproper Choice" << endl;
            break;
        }
    }

    return 0;
}