#include "main.h"
#include "t1.h"
#include "menu_t1.h"

void menu_t1()
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
            input_t1();
            menu_t1();
            break;
        case 2:
            system("cls");
            help_t1();
            menu_t1();
            break;
        case 9:
            system("cls");
            menu();
            break;
        default:
            system("cls");
            puts("Error. There's no such option.\n");
            menu_t1();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        menu_t1();
    }
}

void input_t1()
{
    int num_t1;
    puts("Type your number\n");
    scanf("%d", &num_t1);
    solution_t1(num_t1);
}

void solution_t1(int num_t1)
{
    int result_t1 = calc_t1(num_t1);
    printf("Result: %d\n\n", result_t1);
    getch();
    system("cls");
}

void help_t1()
{
    puts("HELP:");
}
