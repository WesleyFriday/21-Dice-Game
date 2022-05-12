#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Player Dataset Up
struct Players
{
  string playername;
  int playerscore;
};

//Call Functions
void peopleplaying();
void maingame();
int dice();
void gamemenu();
void check();

//Global Var/Array
const int size = 2;
int r = 1;
Players game[size];

//Main
int main(int argc, char const *argv[]) {
  gamemenu();

 return 0;
}

//Dice
int dice()
{ // Create the dice numbers from 1-6
  // Randomlly GenRATED numbers for each dice roll
  int dice1Roll;
  // set seed.
	srand(time(0));
  dice1Roll = rand() % 6 + 1;	// 1 to 6
return dice1Roll;
};

//Game Menu
void gamemenu()
{//Create a user interface with an if staements to check if they want to play the game or exit the gamemenu
  char input;
  cout << "\t\t\t\t21 Dice " << endl;
  cout << "\t\t\tEnter One Of These Options" << endl;
  cout << "\tPlay [P]"<< endl;
  cout << "\tExit [E]" << endl;
  cin  >> input;
    if(input == 'P'){ peopleplaying(); }
    else if(input == 'E'){ cout << "The Roll is not in your future player!" << endl;}
      else{cout << "Please re-entry your decision with the correct inputs" << endl; gamemenu();  }
};

//Player Info
void peopleplaying() //Setting the two players
{
  int m = 1;
  string van;

for(int i = 0; i < size; i++){
    cout << "Name of player " << m << ": ";
    cin >> van;
    game[i].playername = van;
    game[i].playerscore = 0;
    m++;
  };
maingame();
};

//Gameplay
void maingame(){
  char d;
  string a;
  cout << "\n" << endl;
  cout << "Round " << r << "!" << endl;

  for(int i = 0; i < size; i++)
  {
    cout  << game[i].playername <<" it's your turn." << endl;
    do {
      cout << " Press d to roll the dice: ";
      cin >> d;
        } while(d != 'd');

      int dicenumber = dice(); //Calling the roll of the dice

      cout << "Your roll a " << dicenumber << "! " << endl;
//Paths made by the roll of the dice
      switch (dicenumber) {
        case 1: game[i].playerscore = 1; break;

        case 6: if(game[i].playerscore < 7) {game[i].playerscore = 1;} else{game[i].playerscore = game[i].playerscore - 6;}; break;

        default: game[i].playerscore = dicenumber + game[i].playerscore; break;
                        }
cout << "Your score is now " << game[i].playerscore << endl;
cout << endl;
    }
check();
};
//Checks if player hit 21
void check()
{
  int s;
for(int i = 0; i < size; i++)
{
    if(game[i].playerscore >= 21)
    {cout << game[i].playername << " the winner! Lady luck shines on you " <<game[i].playername <<"." <<  endl; exit (EXIT_SUCCESS);}
};
     r++;
    maingame();
}
