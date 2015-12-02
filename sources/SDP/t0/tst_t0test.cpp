#include <QString>
#include <QtTest>
#include "t1.h"
#include "t2.h"
#include "t3.h"
#include "t4.h"
#include "t5.h"

int compare_m(int **matrix, int **matrix_r, int square)
{
    for (int i=0; i<square; i++)
        for (int j=0; j<square; j++)
        {
            if (matrix[i][j]!=matrix_r[i][j])
            return 1;
        }
    return 0;
}

int compare_t(int *result, int *result_r)
{
    for (int i=0; i<2; i++)
    {
        if (result[i]!=result_r[i])
        return 1;
    }
    return 0;
}

class T0Test : public QObject
{
    Q_OBJECT

public:
    T0Test();

private Q_SLOTS:
    void test_t1();
    void test_t2();
    void test_t3();
    void test_t4();
    void test_t5();
};

T0Test::T0Test()
{
}

void T0Test::test_t1()
{
    int num = 1234;
    QCOMPARE(calc_t1(num), 10);
}

void T0Test::test_t2()
{
    int array_t2[3];
    array_t2[1]=2;
    array_t2[2]=4;
    array_t2[3]=8;
    QCOMPARE(calc_t2(array_t2), 3);
}

void T0Test::test_t3()
{
    int num = 1234;
    QCOMPARE(calc_t3(num), 4321);
}

void T0Test::test_t4()
{
    int square=3;
    int **matrix;
    int i, j, k=0;
    matrix = (int**)malloc(square*sizeof(int*));
    for(i=0; i<square; i++)
    {
        matrix[i] = (int*)malloc(square*sizeof(int));
    }
    for(i=0; i<square; i++)
        for(j=0; j<square; j++)
        {
            k++;
            matrix[i][j]=k;
        }
    int **matrix_r;
    matrix_r = (int**)malloc(square*sizeof(int*));
    for(i=0; i<square; i++)
    {
        matrix_r[i] = (int*)malloc(square*sizeof(int));
    }
    k=0;
    for(i=0; i<square; i++)
        for(j=0; j<square; j++)
        {
            k++;
            matrix_r[i][j]=k+square*2-4*j-2*i;
        }
    calc_t4(square, matrix);
    QCOMPARE(compare_m(matrix, matrix_r, square), 0);
    for(i=0; i<square; i++)
    {
        free(matrix[i]);
        free(matrix_r[i]);
    }
    free(matrix);
    free(matrix_r);
}

void T0Test::test_t5()
{
    int t=3, k=2, temp, i;
    temp=t;
    char text[3][6] = {"ololo", "lol", "o"};
    char **a_text;
    a_text = (char**)malloc(temp*sizeof(char*));
    for(t=0; t<temp; t++)
    {
        a_text[t] = (char*)malloc(strlen(text[t]));
        a_text[t] = text[t];
    }
    temp=k;
    char key[2][2] = {"o", "l"};
    char **a_key;
    a_key = (char**)malloc(temp*sizeof(char*));
    for(k=0; k<temp; k++)
    {
        a_key[k] = (char*)malloc(strlen(key[k]));
        a_key[k] = key[k];
    }
    int *result;
    result = (int*)malloc(k*sizeof(int));
    calc_t5(a_text, a_key, t, k, result);
    int result_r[2] = {5, 4};
    for (i=0; i<k; i++)
    QCOMPARE(compare_t(result, result_r), 0);
    free(result);
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
QTEST_APPLESS_MAIN(T0Test)

#include "tst_t0test.moc"
