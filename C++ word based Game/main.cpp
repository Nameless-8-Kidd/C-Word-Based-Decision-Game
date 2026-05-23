#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// ================= GLOBAL VARIABLES =================

string playerName;
int lives = 10;
bool gameRunning = true;

// ================= SAFE INPUT =================

int getChoice(int min, int max)
{
    int choice;

    while (true)
    {
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Enter a number: ";
        }
        else if (choice < min || choice > max)
        {
            cout << "Choose between " << min << " and " << max << ": ";
        }
        else
        {
            return choice;
        }
    }
}

// ================= SHOW LIVES =================

void showLives()
{
    cout << "\nLives Remaining: " << lives << endl;
}

// ================= GAME INTRO =================

void intro()
{
    cout << "\n==========================================================" << endl;
    cout << "                LIFE IS A GAMBLE                         " << endl;
    cout << "==========================================================" << endl;

    cout << "\nYear: 1998" << endl;
    cout << "Location: Blackwood Amusement Park" << endl;

    cout << "\nFor over 20 years..." << endl;
    cout << "People have mysteriously vanished inside this abandoned" << endl;
    cout << "theme park." << endl;

    cout << "\nSome say the park is cursed." << endl;
    cout << "Others say something still lives inside it..." << endl;

    cout << "\nBut you?" << endl;
    cout << "You entered willingly." << endl;

    cout << "\nWhy?" << endl;
    cout << "Money?" << endl;
    cout << "Fame?" << endl;
    cout << "Or are you simply another FOOL searching for answers?" << endl;

    cout << "\nRumors say a hidden treasure lies deep within the park." << endl;
    cout << "Nobody who searched for it ever returned." << endl;

    cout << "\nYou stand before the rusted entrance gates." << endl;
    cout << "The wind howls." << endl;
    cout << "The rides creak in the darkness." << endl;

    cout << "\nYou feel a cold chill run down your spine..." << endl;

    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();

    cout << "\nThe gates slowly open..." << endl;
    cout << "Your nightmare begins now." << endl;

    cout << "\n==========================================================" << endl;
}

// ================= GAME OVER =================

void gameOver()
{
    cout << "\n====================================" << endl;
    cout << "           GAME OVER               " << endl;
    cout << "====================================" << endl;

    gameRunning = false;
}

// ================= CHECK LIVES =================

void checkLives()
{
    if (lives <= 0)
    {
        lives = 0;
        showLives();
        gameOver();
    }
}

// ================= SECRET ENDING =================

void secretEnding()
{
    cout << "\n==========================================" << endl;
    cout << "         SECRET ENDING UNLOCKED          " << endl;
    cout << "==========================================" << endl;

    cout << "You Found The Hidden Treasure!" << endl;
    cout << "You Escaped The Theme Park Rich!" << endl;
    cout << "Legends Will Remember Your Name..." << endl;

    gameRunning = false;
}

// ================= LEFT PATH =================

void leftPath()
{
    int op;

    cout << "\n------------------------------------------------------" << endl;
    cout << "| You Encounter Three Strange Tunnels                |" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "1. Tunnel Of Greed" << endl;
    cout << "2. Snake Tunnel" << endl;
    cout << "3. Party Tunnel" << endl;

    cout << "\nChoose A Tunnel: ";
    op = getChoice(1, 3);

    switch (op)
    {
        case 1:
        {
            lives += 5;

            cout << "\nLucky You! +5 Lives" << endl;
            showLives();

            int luckyNumber = rand() % 5 + 1;

            cout << "\nGuess The Lucky Number (1-5): ";
            op = getChoice(1, 5);

            if (op == luckyNumber)
            {
                lives += 3;

                cout << "\nCorrect Guess!" << endl;
                cout << "+3 Bonus Lives!" << endl;
            }
            else
            {
                cout << "\nWrong Guess!" << endl;
                cout << "The Correct Number Was: " << luckyNumber << endl;

                lives -= 5;
            }

            showLives();
            break;
        }

        case 2:
            lives -= 4;

            cout << "\nYou Fell Into A Snake Pit!" << endl;
            cout << "-4 Lives" << endl;

            showLives();
            break;

        case 3:
        {
            int reward = rand() % 2;

            cout << "\nYou Entered A Strange Party!" << endl;

            if (reward == 1)
            {
                lives += 2;

                cout << "You Found Free Food!" << endl;
                cout << "+2 Lives" << endl;
            }
            else
            {
                cout << "Nothing Happened..." << endl;
            }

            showLives();
            break;
        }
    }

    checkLives();
}

// ================= RIGHT PATH =================

void rightPath()
{
    int op;

    cout << "\n------------------------------------------------------" << endl;
    cout << "| You Enter A Dark Forest                            |" << endl;
    cout << "| Something Is Watching You...                       |" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "1. Run Away" << endl;
    cout << "2. Investigate Noise" << endl;
    cout << "3. Climb Tree" << endl;

    cout << "\nChoose: ";
    op = getChoice(1, 3);

    switch(op)
    {
        case 1:
            cout << "\nYou Escaped Safely!" << endl;
            break;

        case 2:
            lives -= 5;

            cout << "\nA Monster Attacked You!" << endl;
            cout << "-5 Lives" << endl;

            showLives();
            break;

        case 3:
            lives += 2;

            cout << "\nYou Found Hidden Supplies!" << endl;
            cout << "+2 Lives" << endl;

            showLives();
            break;
    }

    checkLives();
}

// ================= STRAIGHT PATH =================

void straightPath()
{
    int op;

    cout << "\n------------------------------------------------------" << endl;
    cout << "| You Discover A Hidden Underground Door             |" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "1. Enter The Door" << endl;
    cout << "2. Explore Outside" << endl;

    cout << "\nChoose: ";
    op = getChoice(1, 2);

    switch(op)
    {
        case 1:
            cout << "\nThe Underground Gets Freezing Cold..." << endl;

            cout << "1. Continue" << endl;
            cout << "2. Return Back" << endl;

            cout << "\nChoose: ";
            op = getChoice(1, 2);

            if (op == 1)
            {
                lives = 0;

                cout << "\nYou Froze To Death!" << endl;
            }
            else
            {
                cout << "\nWise Choice." << endl;
            }

            break;

        case 2:
            cout << "\nYou Discover An Abandoned Carnival Ride" << endl;

            cout << "1. Rollercoaster" << endl;
            cout << "2. Ferris Wheel" << endl;

            cout << "\nChoose: ";
            op = getChoice(1, 2);

            switch(op)
            {
                case 1:
                {
                    int reward = rand() % 10 + 1;

                    cout << "\nYou Survived The Rollercoaster!" << endl;

                    if (reward >= 8)
                    {
                        cout << "You Found Hidden Treasure!" << endl;

                        secretEnding();
                        return;
                    }

                    break;
                }

                case 2:
                    lives -= 4;

                    cout << "\nThe Ferris Wheel Collapsed!" << endl;
                    cout << "-4 Lives" << endl;

                    showLives();
                    break;
            }

            break;
    }

    checkLives();
}

// ================= EXIT GAME =================

void exitGame()
{
    cout << "\n------------------------------------------------" << endl;
    cout << "| Wise Choice. You Escaped The Theme Park      |" << endl;
    cout << "------------------------------------------------" << endl;

    gameRunning = false;
}

// ================= MAIN GAME =================

void game()
{
    int op;

    cout << "\n=================================================" << endl;
    cout << "            LIFE IS A GAMBLE                     " << endl;
    cout << "=================================================" << endl;

    cout << "\nWelcome " << playerName << "!" << endl;

    showLives();

    cout << "\nChoose Your Path:" << endl;
    cout << "1. Left Path" << endl;
    cout << "2. Right Path" << endl;
    cout << "3. Straight Path" << endl;
    cout << "4. Escape Theme Park" << endl;

    cout << "\nEnter Choice: ";
    op = getChoice(1, 4);

    switch(op)
    {
        case 1:
            leftPath();
            break;

        case 2:
            rightPath();
            break;

        case 3:
            straightPath();
            break;

        case 4:
            exitGame();
            break;
    }
}

// ================= MAIN METHOD =================

int main()
{
    srand(time(0));

    cout << "====================================" << endl;
    cout << "      LIFE IS A GAMBLE GAME        " << endl;
    cout << "====================================" << endl;

    cout << "\nEnter Your Name: ";
    getline(cin, playerName);

    intro();

    while (gameRunning)
    {
        game();
    }

    return 0;
}
