#include "main.h"

int menu()
{
    int way;
    puts("Choose a task:");
    puts("1. Summ of digits.");
    puts("2. Search for multiples.");
    puts("3. Reversion of given number.");
    puts("4. Matrix turn.");
    puts("5. Search of text constructs.");
    puts("0. Exit");
    printf("Your choice: ");
    if (scanf("%d", &way) == 1)
    {
        switch(way)
        {
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                menu_t1();
                break;
            case 2:
                system("cls");
                menu_t2();
                break;
            case 3:
                system("cls");
                menu_t3();
                break;
            case 4:
                system("cls");
                menu_t4();
                break;
            case 5:
                system("cls");
                menu_t5();
                break;
            default:
                system("cls");
                puts("\nError.There's no such task.\n");
                menu();
                break;
        }
    }
        else
        {
            puts("Error. Wrong input data type.\n");
            menu();
        }
    return 0;
}

void help()
{
    puts("Subdirs Project. Lukashenko R.");
    puts("Commands available: ");
    puts("\t--help (-h)");
    puts("\t--imode (-i)");
    puts("\t--task1 (-t1) number");
    puts("\t--task2 (-t2) number1 number2 number3");
    puts("\t--task3 (-t3) number");
    puts("\t--task4 (-t4) size_of_square_matrix input_file_name output_file_name");
}


