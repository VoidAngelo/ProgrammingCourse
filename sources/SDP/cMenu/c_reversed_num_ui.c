#include "c_main.h"
#include "c_reversed_num.h"
#include "c_reversed_num_ui.h"

void c_reversed_num_ui()
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
            c_reversed_num_inp();
            c_reversed_num_ui();
            break;
        case 2:
            system("cls");
            c_reversed_num_help();
            c_reversed_num_ui();
            break;
        case 9:
            system("cls");
            ui();
            break;
        default:
            system("cls");
            puts("Error. There's no such option.\n");
            c_reversed_num_ui();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        c_reversed_num_ui();
    }
}

void c_reversed_num_inp()
{
    int num_t3;
    puts("Type your number\n");
    scanf("%d", &num_t3);
    c_reversed_num_solution(num_t3);
}

void c_reversed_num_solution(int num_t3)
{
    int result_t3 = c_calc_reversed_num(num_t3);
    printf("Result: %d\n\n", result_t3);
    getch();
    system("cls");
}

void c_reversed_num_help()
{
    puts("HELP:");
}
