#include "main.h"
#include "main_cl.h"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        int trigger = 0;
        if (strcmp(argv[1], "--imode") == 0 || strcmp(argv[1], "-i") == 0)
        {
            if (argc == 2)
                menu();
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            if (argc == 2)
                help();
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--task1") == 0 || strcmp(argv[1], "-t1") == 0)
        {
            if (argc == 3)
                cl_task5(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--task2") == 0 || strcmp(argv[1], "-t2") == 0)
        {
            if (argc == 5)
                cl_task2(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--task3") == 0 || strcmp(argv[1], "-t3") == 0)
        {
            if (argc == 3)
                cl_task3(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--task4") == 0 || strcmp(argv[1], "-t4") == 0)
        {
            if (argc == 5)
                cl_task4(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--task5") == 0 || strcmp(argv[1], "-t5") == 0)
        {
            if (argc == 5)
                cl_task5(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (trigger == 0)
        {
            puts("Wrong parameter input.");
        }
    }
    else
        puts("Type --help (-h) for usage.");
    return 0;
}
