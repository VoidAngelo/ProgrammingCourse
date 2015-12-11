#include "c_main.h"
#include "c_matrix.h"
#include "c_matrix_ui.h"

void c_matrix_ui()
{
    int num;
    puts("Matrix turn task");
    puts("Choose option:");
    puts("1. Input matrix from console");
    puts("2. Input matrix from file");
    puts("3. Help");
    puts("9. Back to main menu");
    puts("0. Exit");
    printf("Your choice: ");
    if (scanf("%d", &num) == 1)
    {
        switch (num)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            c_matrix_cinp();
            c_matrix_ui();
            break;
        case 2:
            system("cls");
            c_matrix_finp();
            c_matrix_ui();
            break;
        case 3:
            system("cls");
            c_matrix_help();
            c_matrix_ui();
            break;
        case 9:
            system("cls");
            ui();
            break;
        default:
            system("cls");
            puts("Error! Invalid number.\n");
            c_matrix_ui();
            break;
        }
    }
    else
    {
        system("cls");
        puts("Error! Input a number.\n");
        c_matrix_ui();
    }
}

void c_matrix_cinp()
{
    int size_of_matrix;

    printf("Type size of square matrix: ");
    scanf("%d", &size_of_matrix);
    printf("\n");

    int **matrix;
    int i, j;
    matrix = (int**)malloc(size_of_matrix*sizeof(int*));
    for(i=0; i<size_of_matrix; i++)
    {
        matrix[i] = (int*)malloc(size_of_matrix*sizeof(int));
    }

    puts("Type matrix numbers: ");
    for(i=0; i<size_of_matrix; i++)
        for(j=0; j<size_of_matrix; j++)
        {
            scanf("%d", &matrix[i][j]);
        }

    c_matrix_csolution(size_of_matrix, matrix);

    for(i=0; i<size_of_matrix; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void c_matrix_csolution(int size_of_matrix, int **matrix)
{
    int i, j;

    c_calc_matrix(size_of_matrix, matrix);

    puts("Result: ");
    for(i=0; i<size_of_matrix; i++)
    {
        for(j=0; j<size_of_matrix; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    getch();
    system("cls");
}

void c_matrix_finp()
{
    int size_of_matrix, **matrix;

    printf("Type size of square matrix: ");
    scanf("%d", &size_of_matrix);
    printf("\n");
    printf("Type the input file name\n"
           "(or 0 for default one): ");
    char file_i[20];
    scanf("%s", file_i);
    printf("\n");
    if (file_i[0] == '0')
        strcpy(file_i, "input_m.txt");
    FILE * finp = fopen(file_i, "r");
    if (!finp)
    {
        system("cls");
        puts("Error. Input file can't be opened.\n");
        c_matrix_ui();
    }

    c_matrix_inp(size_of_matrix, matrix, finp);

    fclose(finp);
}

void c_matrix_inp(int size_of_matrix, int **matrix, FILE *finp)
{
    int i, j;

    matrix = (int**)malloc(size_of_matrix*sizeof(int*));
    for(i=0; i<size_of_matrix; i++)
    {
        matrix[i] = (int*)malloc(size_of_matrix*sizeof(int));
    }
    for(i=0; i<size_of_matrix; i++)
        for(j=0; j<size_of_matrix; j++)
        {
            fscanf(finp, "%d", &matrix[i][j]);
        }

    c_matrix_fsolution(size_of_matrix, matrix);

    for(i=0; i<size_of_matrix; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void c_matrix_fsolution(int size_of_matrix, int **matrix)
{
    printf("Type the output file name\n"
           "(or 0 for default one): ");
    char file_o[20];
    scanf("%s", file_o);
    printf("\n");
    if (file_o[0] == '0')
        strcpy(file_o, "output_m.txt");
    FILE * fout = fopen(file_o, "w");
    if (!fout)
    {
        system("cls");
        puts("Error. Output file can't be opened.\n");
        c_matrix_ui();
    }

    c_matrix_out(size_of_matrix, matrix, fout);

    printf("Check result in %s\n\n", file_o);
    fclose(fout);
    getch();
    system("cls");
}

void c_matrix_out(int size_of_matrix, int **matrix, FILE *fout)
{
    int i, j;

    c_calc_matrix(size_of_matrix, matrix);

    for(i=0; i<size_of_matrix; i++)
    {
        for(j=0; j<size_of_matrix; j++)
        {
            fprintf(fout, "%5d", matrix[i][j]);
        }
        fprintf(fout, "\n");
    }
}

void c_matrix_help()
{
    puts("HELP:");
}

