#include "c_main_cl.h"

void cl_sum(char* argv[])
{
    int num_t1 = atoi(argv[2]);
    c_sum_of_digits_solution(num_t1);
}

void cl_multiples(char* argv[])
{
    int i, array_t2[3];
    for(i = 0; i < 3; i++)
    {
        array_t2[i] = atoi(argv[1+1*i]);
    }
    c_multiples_solution(array_t2);
}

void cl_reversion(char* argv[])
{
    int num_t3 = atoi(argv[2]);
    c_reversed_num_solution(num_t3);
}

void cl_matrix(char* argv[])
{
    int square = atoi(argv[2]);
    char *file_i;
    file_i = argv[3];
    if (file_i[0] == '0')
        strcpy(file_i, "input_m.txt");
    FILE * finp = fopen(file_i, "r");
    if (!finp)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
    }
    int **matrix;
    int i, j;
    matrix = (int**)malloc(square*sizeof(int*));
    for(i=0; i<square; i++)
    {
        matrix[i] = (int*)malloc(square*sizeof(int));
    }
    for(i=0; i<square; i++)
        for(j=0; j<square; j++)
        {
            fscanf(finp, "%d", &matrix[i][j]);
        }
    fclose(finp);
    char *file_o;
    file_o = argv[4];
    if (file_o[0] == '0')
        strcpy(file_o, "output_m.txt");
    FILE * fout = fopen(file_o, "w");
    if (!fout)
    {
        system("cls");
        puts("Error. Output file can't be opened.\n");
        c_matrix_turn_ui();
    }
    c_matrix_turn_out(square, matrix, fout);
    printf("Check result in %s\n\n", file_o);
    fclose(fout);
}

void cl_text(char* argv[])
{
    char *file_i1;
    file_i1 = argv[2];
    if (file_i1[0] == '0')
        strcpy(file_i1, "input_t.txt");
    FILE * finp1 = fopen(file_i1, "r");
    if (!finp1)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
        c_matrix_turn_ui();
    }
    char *file_i2;
    file_i2 = argv[3];
    if (file_i2[0] == '0')
        strcpy(file_i2, "input_k.txt");
    FILE * finp2 = fopen(file_i2, "r");
    if (!finp2)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
        c_matrix_turn_ui();
    }
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
    fclose(finp1);
    fclose(finp2);
    char *file_o;
    file_o = argv[4];
    if (file_o[0] == '0')
        strcpy(file_o, "output_m.txt");
    FILE * fout = fopen(file_o, "w");
    if (!fout)
    {
        system("cls");
        puts("Error. Output file can't be opened.\n");
        c_matrix_turn_ui();
    }
    c_keys_in_text_out(a_text, a_key, t, k, fout);
    printf("Check result in %s", file_o);
    fclose(fout);
}
