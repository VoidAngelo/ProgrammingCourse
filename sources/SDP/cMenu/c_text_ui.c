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
    int max = 100, len= 255, t, k, temp, i;
    puts ("Type text(100 strings max)");
    scanf("%*c");
    char text[max][len];
    for (t=0; t<max; t++)
    {
        printf ("%d: ", t);
        gets(text[t]);
        if(!*text[t]) break;
    }
    temp=t;
    char **a_text;
    a_text = (char**)malloc(temp*sizeof(char*));
    for(t=0; t<temp; t++)
    {
        a_text[t] = (char*)malloc(strlen(text[t]));
        a_text[t] = text[t];
    }
    system("cls");
    puts ("Type keywords(100 words max)");
    char key[max][len];
    for (k=0; k<max; k++)
    {
        printf ("%d: ", k);
        gets(key[k]);
        if(!*key[k]) break;
    }
    temp=k;
    char **a_key;
    a_key = (char**)malloc(temp*sizeof(char*));
    for(k=0; k<temp; k++)
    {
        a_key[k] = (char*)malloc(strlen(key[k]));
        a_key[k] = key[k];
    }
    system("cls");
    c_text_csolution(a_text, a_key, t, k);
    for(i=0; i<t; i++)
    {
        free(a_text[i]);
    }
    free(a_text);
    for(i=0; i<k; i++)
    {
        free(a_key[i]);
    }
    free(a_key);
}

void c_text_csolution(char **text, char **key, int t, int k)
{
    int i;
    for (i=0; i<t; i++)
    {
        printf("%s\n", text[i]);
    }
    printf ("\n");
    int *result;
    result = (int*)malloc(k*sizeof(int));
    c_calc_text(text, key, t, k, result);
    for (i=0; i<k; i++)
    {
        printf("Number of matches found for '%s'",key[i]);
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
    int max = 100, len= 255, t, k, i, temp;
    char **a_text;
    char text[max][len];
    for (t=0; t<max; t++)
    {
        fgets(text[t], len, finp1);
        if(!*text[t]) break;
        if ( text[t][strlen(text[t])- 1] == '\n') text[t][strlen(text[t])- 1]='\0';
    }
    temp=t;
    a_text = (char**)malloc(temp*sizeof(char*));
    for(t=0; t<temp; t++)
    {
        a_text[t] = (char*)malloc(strlen(text[t]));
        a_text[t] = text[t];
    }
    char **a_key;
    char key[max][len];
    for (k=0; k<max; k++)
    {
        fgets(key[k], len, finp2);
        if(!*key[k]) break;
        if ( key[k][strlen(key[k])- 1] == '\n') key[k][strlen(key[k])- 1]='\0';
    }
    temp=k;
    a_key = (char**)malloc(temp*sizeof(char*));
    for(k=0; k<temp; k++)
    {
        a_key[k] = (char*)malloc(strlen(key[k]));
        a_key[k] = key[k];
    }
    c_text_fsolution(a_text, a_key, t, k);
    for(i=0; i<t; i++)
    {
        free(a_text[i]);
    }
    free(a_text);
    for(i=0; i<k; i++)
    {
        free(a_key[i]);
    }
    free(a_key);
}

void c_text_fsolution(char **text, char **key, int t, int k)
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
    c_text_out(text, key, t, k, fout);
    printf("Check result in %s", file_o);
    fclose(fout);
    getch();
    system("cls");
}

void c_text_out(char **text, char **key, int t, int k, FILE *fout)
{
    int i;
    for (i=0; i<t; i++)
    {
        fprintf(fout, "%s\n", text[i]);
    }
    printf ("\n");
    int *result;
    result = (int*)malloc(k*sizeof(int));
    c_calc_text(text, key, t, k, result);
    fprintf(fout, "\n");
    for (i=0; i<k; i++)
    {
        fprintf(fout, "Number of matches found for '%s'",key[i]);
        fprintf(fout, ": %d\n",result[i]);
    }
    free(result);
}

void c_text_help()
{
    puts("HELP:");
}
