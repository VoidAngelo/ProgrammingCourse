#include "c_main.h"
#include "c_text.h"
#include "c_text_ui.h"

void c_text_ui()
{
    int way;
    puts("Search of text constructs task");
    puts("Choose option:");
    puts("1. Input text and contstructs from console");
    puts("2. Input text and contstructs from file");
    puts("3. Help");
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
            c_text_cinp();
            c_text_ui();
            break;
        case 2:
            system("cls");
            c_text_finp();
            c_text_ui();
            break;
        case 3:
            system("cls");
            c_text_help();
            c_text_ui();
            break;
        case 9:
            system("cls");
            ui();
            break;
        default:
            system("cls");
            puts("Error. There's no such option.\n");
            c_text_ui();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error. Wrong input data type.\n");
        c_text_ui();
    }
}

void c_text_cinp()
{
    system("cls");

    int max = 100, len= 255, num_of_strings, num_of_keys, temp, i;

    puts ("Type text(100 strings max)");
    scanf("%*c");
    char strings[max][len];
    for (num_of_strings=0; num_of_strings<max; num_of_strings++)
    {
        printf ("%d: ", num_of_strings);
        gets(strings[num_of_strings]);
        if(!*strings[num_of_strings]) break;
    }

    temp=num_of_strings;

    char **a_strings;
    a_strings = (char**)malloc(temp*sizeof(char*));
    for(num_of_strings=0; num_of_strings<temp; num_of_strings++)
    {
        a_strings[num_of_strings] = (char*)malloc(strlen(strings[num_of_strings]));
        a_strings[num_of_strings] = strings[num_of_strings];
    }

    system("cls");

    puts ("Type keywords(100 words max)");
    char keys[max][len];
    for (num_of_keys=0; num_of_keys<max; num_of_keys++)
    {
        printf ("%d: ", num_of_keys);
        gets(keys[num_of_keys]);
        if(!*keys[num_of_keys]) break;
    }

    temp=num_of_keys;

    char **a_keys;
    a_keys = (char**)malloc(temp*sizeof(char*));
    for(num_of_keys=0; num_of_keys<temp; num_of_keys++)
    {
        a_keys[num_of_keys] = (char*)malloc(strlen(keys[num_of_keys]));
        a_keys[num_of_keys] = keys[num_of_keys];
    }

    system("cls");

    c_text_csolution(a_strings, a_keys, num_of_strings, num_of_keys);

    for(i=0; i<num_of_strings; i++)
    {
        free(a_strings[i]);
    }
    free(a_strings);

    for(i=0; i<num_of_keys; i++)
    {
        free(a_keys[i]);
    }
    free(a_keys);
}

void c_text_csolution(char **strings, char **keys, int num_of_strings, int num_of_keys)
{
    int i;

    for (i=0; i<num_of_strings; i++)
    {
        printf("%s\n", strings[i]);
    }

    printf ("\n");

    int *result;
    result = (int*)malloc(num_of_keys*sizeof(int));

    c_calc_text(strings, keys, num_of_strings, num_of_keys, result);

    for (i=0; i<num_of_keys; i++)
    {
        printf("Number of matches found for '%s'",keys[i]);
        printf(": %d\n",result[i]);
    }

    free(result);
    getch();
    system("cls");
}

void c_text_finp()
{
    system("cls");

    printf("Type the input file name with text\n"
           "(or 0 for default one): ");
    char file_i1[20];
    scanf("%s", file_i1);
    printf("\n");
    if (file_i1[0] == '0')
        strcpy(file_i1, "input_t.txt");
    FILE * finp1 = fopen(file_i1, "r");
    if (!finp1)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
        c_matrix_ui();
    }

    system("cls");

    printf("Type the input file name with constructs\n"
           "(or 0 for default one): ");
    char file_i2[20];
    scanf("%s", file_i2);
    printf("\n");
    if (file_i2[0] == '0')
        strcpy(file_i2, "input_k.txt");
    FILE * finp2 = fopen(file_i2, "r");
    if (!finp2)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
        c_matrix_ui();
    }

    system("cls");

    c_text_inp(finp1, finp2);
    fclose(finp1);
    fclose(finp2);
}

void c_text_inp(FILE *finp1, FILE *finp2)
{
    int max = 100, len= 255, num_of_strings, num_of_keys, i, temp;

    char strings[max][len];
    for (num_of_strings=0; num_of_strings<max; num_of_strings++)
    {
        fgets(strings[num_of_strings], len, finp1);
        if(!*strings[num_of_strings]) break;
        if ( strings[num_of_strings][strlen(strings[num_of_strings])- 1] == '\n') strings[num_of_strings][strlen(strings[num_of_strings])- 1]='\0';
    }

    temp=num_of_strings;

    char **a_strings;
    a_strings = (char**)malloc(temp*sizeof(char*));
    for(num_of_strings=0; num_of_strings<temp; num_of_strings++)
    {
        a_strings[num_of_strings] = (char*)malloc(strlen(strings[num_of_strings]));
        a_strings[num_of_strings] = strings[num_of_strings];
    }

    char keys[max][len];
    for (num_of_keys=0; num_of_keys<max; num_of_keys++)
    {
        fgets(keys[num_of_keys], len, finp2);
        if(!*keys[num_of_keys]) break;
        if ( keys[num_of_keys][strlen(keys[num_of_keys])- 1] == '\n') keys[num_of_keys][strlen(keys[num_of_keys])- 1]='\0';
    }

    temp=num_of_keys;

    char **a_keys;
    a_keys = (char**)malloc(temp*sizeof(char*));
    for(num_of_keys=0; num_of_keys<temp; num_of_keys++)
    {
        a_keys[num_of_keys] = (char*)malloc(strlen(keys[num_of_keys]));
        a_keys[num_of_keys] = keys[num_of_keys];
    }

    c_text_fsolution(a_strings, a_keys, num_of_strings, num_of_keys);

    for(i=0; i<num_of_strings; i++)
    {
        free(a_strings[i]);
    }
    free(a_strings);
    for(i=0; i<num_of_keys; i++)
    {
        free(a_keys[i]);
    }
    free(a_keys);
}

void c_text_fsolution(char **strings, char **keys, int num_of_strings, int num_of_keys)
{
    printf("Type the output file name\n"
           "(or 0 for default one): ");
    char file_o[20];
    scanf("%s", file_o);
    printf("\n");
    if (file_o[0] == '0')
        strcpy(file_o, "output_t.txt");
    FILE * fout = fopen(file_o, "w");
    if (!fout)
    {
        system("cls");
        puts("Error. Output file can't be opened.\n");
        c_matrix_ui();
    }

    c_text_out(strings, keys, num_of_strings, num_of_keys, fout);

    printf("Check result in %s", file_o);

    fclose(fout);
    getch();
    system("cls");
}

void c_text_out(char **strings, char **keys, int num_of_strings, int num_of_keys, FILE *fout)
{
    int i;

    for (i=0; i<num_of_strings; i++)
    {
        fprintf(fout, "%s\n", strings[i]);
    }

    printf ("\n");

    int *result;
    result = (int*)malloc(num_of_keys*sizeof(int));
    c_calc_text(strings, keys, num_of_strings, num_of_keys, result);
    fprintf(fout, "\n");
    for (i=0; i<num_of_keys; i++)
    {
        fprintf(fout, "Number of matches found for '%s'",keys[i]);
        fprintf(fout, ": %d\n",result[i]);
    }

    free(result);
}

void c_text_help()
{
    puts("HELP:");
}
