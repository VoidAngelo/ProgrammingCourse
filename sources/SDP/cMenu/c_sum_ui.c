#include "c_main.h"
#include "c_sum.h"
#include "c_sum_ui.h"

void c_sum_ui()
{
    int way;
    puts("Summ of digits task");
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
            c_sum_inp();
            c_sum_ui();
            break;
        case 2:
            system("cls");
            c_sum_help();
            c_sum_ui();
            break;
        case 9:
            system("cls");
            ui();
            break;
        default:
            system("cls");
            puts("Error. There's no such option.\n");
            c_sum_ui();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        c_sum_ui();
    }
}

void c_sum_inp()
{
    int num_t1;
    puts("Type your number\n");
    scanf("%d", &num_t1);
    c_sum_solution(num_t1);
}

void c_sum_solution(int num_t1)
{
    int result_t1 = c_calc_sum(num_t1);
    printf("Result: %d\n\n", result_t1);
    getch();
    system("cls");
}

void c_sum_help()
{
    puts("HELP:");
}
