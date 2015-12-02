#include "main.h"
#include "t3.h"
#include "menu_t3.h"

void menu_t3()
{
    int way;
    puts("Reversion of given number task");
    puts("Choose option:");
    puts("1. Input number from console");
    puts("2. Help");
    puts("9. Back to main menu");
    puts("0. Exit");
    printf("Your choice: ");
    if (scanf("%d", &way) == 1)
    {
        switch (way)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            input_t3();
            menu_t3();
            break;
        case 2:
            system("cls");
            help_t3();
            menu_t3();
            break;
        case 9:
            system("cls");
            menu();
            break;
        default:
            system("cls");
            puts("Error. There's no such option.\n");
            menu_t3();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        menu_t3();
    }
}

void input_t3()
{
    int num_t3;
    puts("Type your number\n");
    scanf("%d", &num_t3);
    solution_t3(num_t3);
}

void solution_t3(int num_t3)
{
    int result_t3 = calc_t3(num_t3);
    printf("Result: %d\n\n", result_t3);
    getch();
    system("cls");
}

void help_t3()
{
    puts("HELP:");
}
