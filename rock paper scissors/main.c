#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
// stdlib and time.h for srand function and bool usage
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define player_win 0
#define npc_win -1
#define DRAW 1

void LightBlue(void) // Text Coloring
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 9);
}

void red(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);
}

void yellow(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 14);
}

void reset(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 15);
}

// using macros for better usage to replace ex(replacing rock with 1 )
// a function for comparing inputs from the user and detrmines who wins.
// setting up every propalty

int rock_paper_scissors(int player, int npc)
{
    int result;
    if ((player == PAPER) && (npc == ROCK))
    {
        (result = player_win);
    }
    else if ((player == ROCK) && (npc == SCISSOR))
    {
        (result = player_win);
    }
    else if ((player == SCISSOR) && (npc == PAPER))
    {
        (result = player_win);
    }
    else if ((player == ROCK) && (npc == PAPER))
    {
        (result = npc_win);
    }
    else if ((player == SCISSOR) && (npc == ROCK))
    {
        (result = npc_win);
    }
    else if ((player == PAPER) && (npc == SCISSOR))
    {
        (result = npc_win);
    }
    else
    {
        result = DRAW;
    }

    return result;
}

// getting the player choice between rock, paper and scissors.
int get_player_input(void)
{
    int selection;
    do
    {
        printf("1. rock\n");
        printf("2. paper\n");
        printf("3. scissors\n");
        printf("please select between [1,2,3]:");
        scanf("%d", &selection);
        if (!(selection >= 1 && selection <= 3))
        {
            printf("INVALID VALUE --- PLEASE TRY AGAIN\n");
        }
        // While loop for letting the player to choose again
    } while (!(selection >= 1 && selection <= 3));
    return selection;
}

void print_word(int A)
{
    if (A == ROCK)
    {
        printf("ROCK\n");
    }
    else if (A == PAPER)
    {
        printf("PAPER\n");
    }
    else if (A == SCISSOR)
    {
        printf("SCISSOR\n");
    }
}

// seeding the random number generator with the current time to get different
// random numbers each time the program is run
int npcchoice()
{
srand(time(NULL));
return rand() % 3 + 1;
}

// main game starts here

int main()
{
    int player_score = 0;
    int npc_score = 0;

    int x;
    for( x = 1; x < 4; x++)
    {
        int player_input = get_player_input();
        LightBlue();
        printf("computer chose:");
        print_word(npcchoice());
        red();
        printf("player chose: ");
        print_word(player_input);

        reset();
        // int rock_paper_scissors = result (player_input, npc_choice) ;

        int result = rock_paper_scissors(player_input, npcchoice());
        if (result == DRAW)
        {

            printf("---------------------------------\n");
            yellow();
            printf("ITS A DRAW,GOOD LUCK NEXT TIME\n");
            reset();
            printf("---------------------------------\n");
            red();
            printf("player score: %d\n", player_score);
            LightBlue();
            printf("npc score:%d\n", npc_score);
            reset();
            printf("---------------------------------\n");
        }
        else if (result == player_win)
        {
            printf("---------------------------------\n");
            red();
            printf("YOU WIN ,GOOD GAME\n");
            player_score++;
            reset();
            printf("---------------------------------\n");
            red();
            printf("player score: %d\n", player_score);
            LightBlue();
            printf("npc score:%d\n", npc_score);
            reset();
            printf("---------------------------------\n");
        }
        else if (result == npc_win)
        {
            printf("---------------------------------\n");
            LightBlue();
            printf("YOU LOSE, TRY AGAIN\n");
            reset();
            npc_score++;
            printf("---------------------------------\n");
            red();
            printf("player score: %d\n", player_score);
            LightBlue();
            printf("npc score:%d\n", npc_score);
            reset();
            printf("---------------------------------\n");
        }

        printf("YOU SCORE: %d\n",player_score);
        printf("NPC SCORE: %d\n",npc_score);
        if (player_score > npc_score){
            printf("YOU Win The Match\n");
        } else if (player_score < npc_score){
        printf(" computer Win THE MATCH");
        }
        else {
            printf("Its A Draw \n");
        }


        //Sleep(3000);
        //system("cls");
    }
    return 0;
}
