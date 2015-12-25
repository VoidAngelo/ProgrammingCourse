#include <QString>
#include <QtTest>
#include "c_sum_of_digits.h"
#include "c_multiples.h"
#include "c_reversed_num.h"
#include "c_matrix_turn.h"
#include "c_keys_in_text.h"

int compare_matrix(int **matrix, int **matrix_r, int square)
{
    for (int i=0; i<square; i++)
        for (int j=0; j<square; j++)
        {
            if (matrix[i][j]!=matrix_r[i][j])
            return 1;
        }
    return 0;
}

int compare_text(int *result, int *result_r)
{
    for (int i=0; i<2; i++)
    {
        if (result[i]!=result_r[i])
        return 1;
    }
    return 0;
}

class CTestsTest : public QObject
{
    Q_OBJECT

public:
    CTestsTest();

private Q_SLOTS:
    void c_test_sum_of_digits();
    void c_test_search_multiples();
    void c_test_reversed_num();
    void c_test_matrix_turn();
    void c_test_keys_in_text();
};

CTestsTest::CTestsTest()
{
}

void CTestsTest::c_test_sum_of_digits()
{
    int num = 1234;
    QCOMPARE(c_calc_sum_of_digits(num), 10);
}

void CTestsTest::c_test_search_multiples()
{
    int numbers[3];
    numbers[0]=2;
    numbers[1]=4;
    numbers[2]=8;
    QCOMPARE(c_calc_multiples(numbers), 3);
}

void CTestsTest::c_test_reversed_num()
{
    int num = 1234;
    QCOMPARE(c_calc_reversed_num(num), 4321);
}

void CTestsTest::c_test_matrix_turn()
{
    int size_of_matrix=3;
    int **matrix;
    int i, j, k=0;
    matrix = (int**)malloc(size_of_matrix*sizeof(int*));
    for(i=0; i<size_of_matrix; i++)
    {
        matrix[i] = (int*)malloc(size_of_matrix*sizeof(int));
    }
    for(i=0; i<size_of_matrix; i++)
        for(j=0; j<size_of_matrix; j++)
        {
            k++;
            matrix[i][j]=k;
        }
    int **matrix_r;
    matrix_r = (int**)malloc(size_of_matrix*sizeof(int*));
    for(i=0; i<size_of_matrix; i++)
    {
        matrix_r[i] = (int*)malloc(size_of_matrix*sizeof(int));
    }
    k=0;
    for(i=0; i<size_of_matrix; i++)
        for(j=0; j<size_of_matrix; j++)
        {
            k++;
            matrix_r[i][j]=k+size_of_matrix*2-4*j-2*i;
        }
    c_calc_matrix_turn(size_of_matrix, matrix);
    QCOMPARE(compare_matrix(matrix, matrix_r, size_of_matrix), 0);
    for(i=0; i<size_of_matrix; i++)
    {
        free(matrix[i]);
        free(matrix_r[i]);
    }
    free(matrix);
    free(matrix_r);
}

void CTestsTest::c_test_keys_in_text()
{
    int num_of_strings=3, num_of_keys=2, temp, i;

    temp=num_of_strings;

    char strings[3][6] = {"ololo", "lol", "o"};

    char **a_strings;
    a_strings = (char**)malloc(temp*sizeof(char*));
    for(num_of_strings=0; num_of_strings<temp; num_of_strings++)
    {
        a_strings[num_of_strings] = (char*)malloc(strlen(strings[num_of_strings]));
        a_strings[num_of_strings] = strings[num_of_strings];
    }

    temp=num_of_keys;

    char keys[2][2] = {"o", "l"};

    char **a_keys;
    a_keys = (char**)malloc(temp*sizeof(char*));
    for(num_of_keys=0; num_of_keys<temp; num_of_keys++)
    {
        a_keys[num_of_keys] = (char*)malloc(strlen(keys[num_of_keys]));
        a_keys[num_of_keys] = keys[num_of_keys];
    }

    int *result;
    result = (int*)malloc(num_of_keys*sizeof(int));

    c_calc_keys_in_text(a_strings, a_keys, num_of_strings, num_of_keys, result);

    int result_r[2] = {5, 4};

    for (i=0; i<num_of_keys; i++)
    QCOMPARE(compare_text(result, result_r), 0);

    free(result);

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

QTEST_APPLESS_MAIN(CTestsTest)

#include "tst_cteststest.moc"
