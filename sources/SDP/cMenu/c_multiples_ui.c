#include "c_main.h"
#include "c_multiples.h"
#include "c_multiples_ui.h"

void c_multiples_ui()
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
            c_multiples_inp();
            c_multiples_ui();
            break;
        case 2:
            system("cls");
            c_multiples_help();
            c_multiples_ui();
            break;
        case 9:
            system("cls");
            ui();
            break;
        default:
            system("cls");
            puts("Error! Invalid number.\n");
            c_multiples_ui();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        c_multiples_ui();
    }
}

void c_multiples_inp()
{
    int i, numbers[3];
    puts("Type your numbers:\n");
    for (i=0; i<3; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("\n");
    c_multiples_solution(numbers);
}

void c_multiples_solution(int *numbers)
{
    puts("Result:");
    c_calc_multiples(numbers);
    printf("\n\n");
    getch();
    system("cls");
}

void c_multiples_help()
{
    puts("HELP:");
}
