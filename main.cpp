#include <iostream>
#include<ctime>
#include<cstdlib>
#define PLAYER2MOVE 'X'
#define PLAYER1MOVE 'O'
using namespace std;
int display(void);
int comp_put(void);
int match(void);
int gameDriver(void);
int clashTest(void);
int translator(int);
int human_put(void);
int whoWon(void);
void player1();
void player2();
char board[3][3];
int turn='\0';
int player=0;
int row='\0',column='\0';
int main()
{   int c;
    char choice='\0';
    srand(time(NULL));//for randomizing
    c=gameDriver();
    do
    {
        cout<<"Press y to play again or n to exit:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 'y':
                gameDriver();
                break;
            case 'n':
                cout<<"Thanks you,bye"<<endl;
                exit(0);
            default:
             cout<<"Wrong choice,try again"<<endl;
        }
    }while(choice!='n');
    return 0;
}

int gameDriver()
{   int cinput='\0';
    int won='\0';
    int cchance=1;
    int hchance=1;
    char def='1';
    system( "cls" );
   for(int i=0;i<3;i++)//for initialiting 1 to 9 in board.
    {
        for(int j=0;j<3;j++)
        {
        board[i][j]=def;
        def++;
        }
    }
    cout<<"\t\t\t***Welcome to Tic Tac Toe Game***"<<endl;
    labe2:
    cout<<"1.Press 1 for 1 player\n2.Press 2 for 2 player\n";
    cin>>player;
    while(!cin)
        {
          cout<<"That is not integer! Please enter a integer:\n";
          cin.clear();
          cin.ignore();
          cin>>player;
        }
    if(player<1&&player>2)
            goto labe2;
    display();
    for(int i=1;i<10;i++)
    {
        int clash=0;
        //human is putting
        turn=1;
        if(hchance<=5)
        {
            do
            {   clash='\0';
                player1();
                clash=clashTest();
            }while(clash==1);
            board[row][column]=PLAYER1MOVE;row='\0';column='\0';
            display();
            won=match();
            if(won==1)
            return 0;
            hchance++;
        }
        //----human put ended

        //computer is putting
        turn=2;
        if(cchance<=4)
        {
            do
            {   clash='\0';
                player2();
                clash=clashTest();
            }
            while(clash==1);
            board[row][column]=PLAYER2MOVE;row='\0';column='\0';
            display();
            won=match();
            if(won==1)
            return 0;
            cchance++;
        }
    }
    cout<<"Game draw\n";
    return 0;

}
void player1()
{
    if(player==1)
    human_put();
    else
    {
        cout<<"Player 1 ";
        human_put();
    }
}
void player2()
{
    if(player==1)
    comp_put();
    else
    {
         cout<<"Player 2 ";
        human_put();
    }
}
int clashTest()
{   //returns 1 if clash found,otherwise zero
    if(board[row][column]=='O'||board[row][column]=='X')
    return 1;
    else
    return 0;
}

int translator(int input)
{   //translate input to  row column
    switch(input)
    {
        case 1:
        row=0;column=0;
        break;

        case 2:
        row=0;column=1;
        break;

        case 3:
        row=0;column=2;
        break;

        case 4:
        row=1;column=0;
        break;

        case 5:
        row=1;column=1;
        break;

        case 6:
        row=1;column=2;
        break;

        case 7:
        row=2;column=0;
        break;

        case 8:
        row=2;column=1;
        break;

        case 9:
        row=2;column=2;
        break;
    }
    return 0;
}

int human_put()//places human input to row & column using translator
{   labe1:
        int input='\0';
        cout<<"Enter number between 1 to 9:"<<endl;
        cin>>input;
        while(!cin)
        {
          cout<<"That is not integer! Please enter a integer:\n";
          cin.clear();
          cin.ignore();
          cin>>input;
        }
        cout<<input<<endl;
        if(input>0&&input<10)
            translator(input);
        else
            goto labe1;
return input;
}

int comp_put()
{   //places computer input to row & column using translator
    int input;
    do
    {
        input=rand()%10;
    }
    while(input==0);
   translator(input);
   return input;
}

int match()
{   //if match found calls whoWon() and returns 1
        //row
        for(int i=0;i<3;i++)
        {
            if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
            {
                cout<<"Row match no-"<<i+1<<endl;
                whoWon();
                return 1;
            }
        }
    //column
        for(int i=0;i<3;i++)
        {
            if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
            {
                cout<<"Column match no-"<<i+1<<endl;
                whoWon();
                return 1;
            }
        }
    //diagonal
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        {
                cout<<"Diagonal match :Left"<<endl;
                whoWon();
                return 1;
        }

         if(board[2][0]==board[1][1]&&board[1][1]==board[0][2])
        {
                cout<<"Diagonal match :right"<<endl;
                whoWon();
                return 1;
        }
return 0;
}
int whoWon()
{   if(player==1)
    {
         if(turn==1)
        cout<<"\t\t\t**You Won**\n";
        if(turn==2)
        cout<<"\t\t\t**Computer Won**\n";
    }
    else{
        if(turn==1)
        cout<<"\t\t\t**Player 1 won**\n";
        if(turn==2)
        cout<<"\t\t\t**Player 2 won**\n";
    }
    return 0;
}

int display()
{   //displays the board
    system( "cls" );
     cout<<"\t\t\t***Welcome to Tic Tac Toe Game***"<<endl;
    if(player==2)
    cout<<"\t\tPlayer 1 symbol is: "<<PLAYER1MOVE<<"\tPlayer 2 symbol is: "<<PLAYER2MOVE<<endl;
    else
    cout<<"\t\tYour symbol is: "<<PLAYER1MOVE<<"\tComputer symbol is: "<<PLAYER2MOVE<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t"<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"\t\t\t\t---------"<<endl;
    cout<<"\t\t\t\t"<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"\t\t\t\t---------"<<endl;
    cout<<"\t\t\t\t"<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
