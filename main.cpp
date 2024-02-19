#include "guessing.cpp"
#include "deal.cpp"

int main()
{
    int choice;

    cout<<"\n1. Guessing Game\n2. Deal or No Deal"<<endl;

    cout<<"\nPlease Enter What Game You Want!: ";

    cin>> choice;

    switch(choice){
        case 1:
            run_guess();
            break;
        case 2:
            run_deal();
            break;
    }

    return 0;
}