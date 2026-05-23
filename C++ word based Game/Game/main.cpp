#include <iostream>

using namespace std;

string name;
int lives = 10;
int op;

void leftPath()
{
    cout << "(Bold Decision For A FOOL Such As Yourself)" << endl << endl;
    cout << "Luck Might Be On Your Side (Who Knows!) Venture On" << endl << endl;
    cout << "Now You Encounter Three Strange Looking Tunnels " << endl << endl;
    cout << "-------------------------------------" <<endl;
    cout << "|It's Time To Make A Wise Decision: |" << endl;
    cout << "-------------------------------------" <<endl << endl;

    cout << "1.First Tunnel Looks Kinda Sketchy I Reckon." << endl;
    cout << "2.Second Tunnel Looks Kinda Bougee ." << endl;
    cout << "3.Third Tunnel Looks Kinda Sus :)." << endl;


    cout << "|| Choose Your nEXT pATH: ||";
    cin >> op;
    cout << endl;

    switch (op)
    {
     case 1:
         cout << "Congrats You Gained 5 Extra Lives How Lucky!  " << endl;
         cout << "There Might Still Be Hope For You" << endl;
         lives = lives + 5;
         cout << "You Have Currently " << lives << " Lives Left" << endl;
        break;

     case 2:
         cout << "You Entered A good One :)        " << endl;
         cout << "Ha Ha Ha Ha Just Joking Around You Fell Into A Pit filled With Venomus Snakes And Lost 3 Lives" << endl;
         cout << "Hope You Carried An Antidote." << endl;
         lives = lives - 3;
         cout << "You Have Currently " << lives << " Lives Left" << endl;

        break;

     case 3:
         cout << "You Suddenly Got Into A Party :)" << endl;
         cout << "Apparently You Got Stung By A Hallucigenic Bug" << endl;
         cout << "You Feel On Top Of The World You Lucked Out Once Again " << endl;
         cout << "You Didn't Gain Or Loose Lives " << endl << endl;
         cout << "You Have Currently " << lives << " Lives Left" << endl;

    }
}

void rightPath()
{

}

void straightPath()
{

}

void exit()

{
    cout << "    YOUNG FOOL FINALLY DECIDED TO TURN   " << endl;
    cout << "              BACK I SEE                 " << endl;
    cout << "           WELL WISE CHOICE              " << endl;
    cout << "      WE'RE TIRED OF CLEANING CORPES!!   " << endl;
}

game()
{
    cout << " ------------------------------------------------" << endl;
    cout << "|                                                |" << endl;
    cout << "| |====||====||====| SCREAMS |====||====||====|  |" << endl;
    cout << "|                                                |" << endl;
    cout << " ------------------------------------------------" << endl << endl;

    cout << "You Have Ventured To An Abandoned Theme Park: " << endl;
    cout << "Welcome To The End :)" << endl << endl;

    cout << "-------------------------------" <<endl;
    cout << "|Choose Your Path: (Good Luck)|" <<endl;
    cout << "-------------------------------" <<endl;
    cout << "Enter 1 to take a left turn." << endl;
    cout << "Enter 2 to take a right turn." << endl;
    cout << "Enter 3 to head straight." << endl;
    cout << "Enter 4 to go back to where you come from you FOOL." << endl << endl;
    cout << "Select A Number From The Above And Begin Your Adventure: ";
    cin >> op;

    switch (op)
    {
    case 1: leftPath();
        break;

    case 2: rightPath();
        break;

    case 3: straightPath();
        break;

    case 4: exit();
        break;
    }

    if (lives <= 0)
    {
        cout << "GAME OVER!!" << endl;
    }

    else
    {
        cout << "" << endl;
    }
}

int main()
{
    do
    {
       game();
    }

    while (lives > 0);

    return 0;
}
