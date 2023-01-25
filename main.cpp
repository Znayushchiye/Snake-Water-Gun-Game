#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//This function returns the Computer's choice
char computerMove()
{
    int random = (rand()*10000)%3;
    char computerChoice;
    switch(random)
    {
        case 0:computerChoice = 'S';
        break;
        case 1:computerChoice = 'W';
        break;
        default:computerChoice = 'G';
    }
    return computerChoice;
}
    
int main()
{
    int human=0,computer=0;
    char option, again;
    string str,test="CWG";
    
    cout<<("-----------------------------------------------------------\n");
    cout<<("Welcome to the Snake-Water-Gun game.\n");
    cout<<("You'll choose an option and the computer will choose one.\n");
    cout<<("Snake beats Water, Water beats Gun and Gun beats Snake.\n");
    cout<<("The winner gets +1 point.\n");
    for(int i=0;i<100000;i++) for(int j=0;j<10000;j++) for(int k=0;k<5;k++);
    cout<<("Let's begin. Enter 'y' to start and 'n' to terminate.\n");

    cin>>str;
    option = toupper(str.at(0));
    if(option == 'Y')
    {
        do{
            cout<<("\n\nSnaake...Wateeerrr..Gun!");
            cout<<("\n(\'S\' for snake, \'W\' for water, \'G\' for gun)");
            cout<<("\nYour move : ");
            cin>>str;
            char humanChoice = toupper(str.at(0));
            srand(time(0));
            char computerChoice = computerMove();
            if(!(humanChoice=='S' || humanChoice=='G' || humanChoice=='W'))
            {
                cout<<"Wrong choice entered!\n";
                cout<<"Enter \'S\', \'G\' or \'W\' only.\n";
            }
            else if((humanChoice=='S'&&computerChoice=='G')||(humanChoice=='W'&&computerChoice=='S')||(humanChoice=='G'&&computerChoice=='W'))
            {
                cout<<("Computer wins !");
                computer++;
            }
            else if((humanChoice=='S'&&computerChoice=='W')||(humanChoice=='W'&&computerChoice=='G')||(humanChoice=='G'&&computerChoice=='S'))
            {
                cout<<("Human wins !");
                human++;
            }
            else cout<<"Tie !";
            cout<<("\nWanna go again?(y/n) ");
            
            cin>>str;
            again = toupper(str.at(0));

            if(again == 'Y') system("cls");
        }while(again=='Y');

        cout<<("\n\nFinal Score :-");
        cout<<"\nHuman : "<<human;
        cout<<"\nComputer : "<<computer<<"\n\n";
        cout<<( (human>computer?"Congratulations!! Human wins the game.":(human==computer?"Match tied!!":"You lost! Better luck next time.")) );
    }
    else cout<<("\nSee ya next time!!");
    return 0;
}