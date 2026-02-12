#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum DiceChoice 
{
    CHOICE_UNKNOWN,
    CHOICE_HELP,
    CHOICE_D2,
    CHOICE_D4,
    CHOICE_D6,
    CHOICE_D8,
    CHOICE_D10,
    CHOICE_D12,
    CHOICE_D20,
    CHOICE_D100
};

enum DiceChoice get_choice(char *input) 
{
    if (strcmp(input, "help") == 0) return CHOICE_HELP;
    if (strcmp(input, "2") == 0)    return CHOICE_D2;
    if (strcmp(input, "4") == 0)    return CHOICE_D4;
    if (strcmp(input, "6") == 0)    return CHOICE_D6;
    if (strcmp(input, "8") == 0)    return CHOICE_D8;
    if (strcmp(input, "10") == 0)   return CHOICE_D10;
    if (strcmp(input, "12") == 0)   return CHOICE_D12;
    if (strcmp(input, "20") == 0)   return CHOICE_D20;
    if (strcmp(input, "100") == 0)  return CHOICE_D100;
    return CHOICE_UNKNOWN;
}

int diceroll(int range);

//function prototypes
void print_d2(int rolled);
void print_d4(int rolled);
void print_d6(int rolled);
void print_d8(int rolled);
void print_d10(int rolled);
void print_d12(int rolled);
void print_d20(int rolled);
void print_d100(int rolled);

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <dice_type> (or 'help')\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    switch(get_choice(argv[1]))
    {
        case CHOICE_HELP:
            printf("Available dice types: 2, 4, 6, 8, 10, 12, 20, 100\n");
            break;

        case CHOICE_D2:   print_d2(diceroll(2));     break;
        case CHOICE_D4:   print_d4(diceroll(4));     break;
        case CHOICE_D6:   print_d6(diceroll(6));     break;
        case CHOICE_D8:   print_d8(diceroll(8));     break;
        case CHOICE_D10:  print_d10(diceroll(10));   break;
        case CHOICE_D12:  print_d12(diceroll(12));   break;
        case CHOICE_D20:  print_d20(diceroll(20));   break;
        case CHOICE_D100: print_d100(diceroll(100)); break;

        default:
            printf("That dice does NOT exist! Enter 'help' for a list.\n"); 
            break;   
    }

    return 0;
}

int diceroll(int range) 
{
    return (rand() % range) + 1;
}

//ASCII Art

void print_d2(int rolled)
{
    printf("\n   [ COIN FLIP ]\n");
    printf("      .---.      \n");
    printf("     /     \\     \n");
    printf("    (   %d   )    \n", rolled);
    printf("     \\     /     \n");
    printf("      '---'      \n");
    printf("   (%s)\n", (rolled == 1) ? "HEADS" : "TAILS");
}

void print_d4(int rolled)
{
    printf("\n    [ D4 ROLL ]\n");
    printf("        /\\        \n");
    printf("       /  \\       \n");
    printf("      / %d  \\      \n", rolled);
    printf("     /______\\     \n");
}

void print_d6(int rolled)
{
    printf("\n    [ D6 ROLL ]\n");
    printf("    .----------.  \n");
    printf("    |          |  \n");
    printf("    |    %d     |  \n", rolled);
    printf("    |          |  \n");
    printf("    '----------'  \n");
}

void print_d8(int rolled)
{
    printf("\n    [ D8 ROLL ]\n");
    printf("       /\\      \n");
    printf("      /  \\     \n");
    printf("     / %d  \\    \n", rolled);
    printf("     \\    /    \n");
    printf("      \\  /     \n");
    printf("       \\/      \n");
}

void print_d10(int rolled)
{
    printf("\n    [ D10 ROLL ]\n");
    printf("       /\\      \n");
    printf("      /  \\     \n");
    printf("     | %2d |    \n", rolled);
    printf("      \\  /     \n");
    printf("       \\/      \n");
}

void print_d12(int rolled)
{
    printf("\n    [ D12 ROLL ]\n");
    printf("      .----.     \n");
    printf("     /      \\    \n");
    printf("    |   %2d   |   \n", rolled);
    printf("     \\      /    \n");
    printf("      '----'     \n");
}

void print_d20(int rolled)
{
    printf("\n    [ D20 ROLL ]\n");
    printf("       .---.       \n");
    printf("      /     \\      \n");
    printf("     |  %2d   |     \n", rolled);
    printf("      \\     /      \n");
    printf("       '---'       \n");
    if (rolled == 20) printf("  CRITICAL HIT!\n");
    if (rolled == 1)  printf("  CRITICAL FAIL!\n");
}

void print_d100(int rolled)
{
    printf("\n    [ D100 ROLL ]\n");
    printf("    .-----------.  \n");
    printf("    |           |  \n");
    printf("    |    %3d    |  \n", rolled);
    printf("    |           |  \n");
    printf("    '-----------'  \n");
}