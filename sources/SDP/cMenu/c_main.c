#include "c_main.h"
#include "c_main_cl.h"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        int trigger = 0;
        if (strcmp(argv[1], "--interactive") == 0 || strcmp(argv[1], "-i") == 0)
        {
            if (argc == 2)
                ui();
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
        if (strcmp(argv[1], "--sum") == 0 || strcmp(argv[1], "-s") == 0)
        {
            if (argc == 3)
                cl_sum_of_digits(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--multiples") == 0 || strcmp(argv[1], "-m") == 0)
        {
            if (argc == 5)
                cl_multiples(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--reversed") == 0 || strcmp(argv[1], "-r") == 0)
        {
            if (argc == 3)
                cl_reversed_number(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--turn") == 0 || strcmp(argv[1], "-t") == 0)
        {
            if (argc == 5)
                cl_matrix_turn(argv);
            else
            {
                puts("Incorrect number of parameters.");
                help();
            }
            trigger++;
        }
        if (strcmp(argv[1], "--keys") == 0 || strcmp(argv[1], "-k") == 0)
        {
            if (argc == 5)
                cl_keys_in_text(argv);
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
