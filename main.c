// a game of chance.(craps)

/* A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6
spots. After the dice have come to rest, the sum of the spots on the two upward faces is
calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3,
or 12 on the first throw (called “craps”), the player loses (i.e., the “house” wins). If the
sum is 4, 5, 6, 8, 9, or 10 on the first throw, then that sum becomes the player’s
“point.” To win, you must continue rolling the dice until you “make your point.” The
player loses by rolling a 7 before making the point. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumeration constant represents game status
enum status {CONTINUE, WON, LOST};

unsigned short roll_dice(void); // function prototype

int main()
{
    unsigned short sum; // sum of rolled dice
    unsigned short my_point;    // points earned by player from first roll

    enum status game_status;

    srand(time(NULL));

    sum = roll_dice();

    switch (sum)    // first roll
    {
    // win on first roll
    case 7:
    case 11:
        game_status = WON;
        break;

    // lose on first roll
    case 2:
    case 3:
    case 12:
        game_status = LOST;
        break;
    // continue
    default:
        game_status = CONTINUE;
        my_point = sum;
        printf("your points = %hu\n", my_point);
        break;
    }

    // case continue (game not complete)
    while (game_status == CONTINUE) //
    {
        sum = roll_dice();
        if(sum == my_point)
        {
            game_status = WON;
        }
        else
        {
            if(sum == 7)
            {
                game_status = LOST;
            }   // end if
        }   // end else
    }   // end while


    // win case
    if(game_status == WON)
    {
        printf("player wins\n");
    }   // end if


    // losing case
    else
    {
        printf("player loses\n");
    }   // end else

    return 0;   // successful termination
}   // end main


unsigned short roll_dice(void)
{
    unsigned short die1;    // first die
    unsigned short die2;    // second die
    unsigned short die_sum; // die summation

    die1 = 1 + rand() % 6;  // pick random die1 value from 1 to 6
    die2 = 1 + rand() % 6;  // pick random die2 value from 1 to 6

    die_sum = die1 + die2;  // sum die1 and die2

    // display results of the roll
    printf("player rolled %hu + %hu = %hu\n", die1, die2, die_sum);

    return die_sum;    // return sum of dice
}   // end function roll_dice
