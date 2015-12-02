#include "main.h"
#include "t2.h"
#include "menu_t2.h"

void menu_t2()
{
    int way;
    puts("Search for multiples task");
    puts("Choose option:");
    puts("1. Input 3 numbers");
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
            input_t2();
            menu_t2();
            break;
        case 2:
            system("cls");
            help_t2();
            menu_t2();
            break;
        case 9:
            system("cls");
            menu();
            break;
        default:
            system("cls");
            puts("Error! Invalid number.\n");
            menu_t2();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        menu_t2();
    }
}

void input_t2()
{
    int i, array_t2[3];
    puts("Type your numbers:\n");
    for (i=0; i<3; i++)
    {
        scanf("%d", &array_t2[i]);
    }
    printf("\n");
    solution_t2(array_t2);
}

void solution_t2(int *array_t2)
{
    puts("Result:");
    calc_t2(array_t2);
    printf("\n\n");
    getch();
    system("cls");
}

void help_t2()
{
    puts("HELP:");
}
