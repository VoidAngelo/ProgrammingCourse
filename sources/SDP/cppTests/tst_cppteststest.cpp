#include <QString>
#include <QtTest>

#include "cpp_int_unlim.h"
//#include "cpp_keys_in_text.h"
#include "cpp_matrix_turn.h"
#include "cpp_multiples.h"
#include "cpp_reversed_num.h"
#include "cpp_sum_of_digits.h"

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

class CppTestsTest : public QObject
{
    Q_OBJECT

public:
    CppTestsTest();

private Q_SLOTS:
    void test_sum_of_digits();
    void test_reversed_num();
    void test_multiples();
    void test_matrix_turn();
    void test_iu_sum();
    void test_iu_subt();
    void test_iu_mult();
};

CppTestsTest::CppTestsTest()
{
}

void CppTestsTest::test_sum_of_digits()
{
    cpp_sum_of_digits sum;
    sum.enter_number(248);
    sum.sum_of_digits();
    QCOMPARE(sum.get_sum(), 14);
}

void CppTestsTest::test_reversed_num()
{
    cpp_reversed_num num;
    num.enter_number(248);
    num.reversion_of_num();
    QCOMPARE(num.get_reversion(), 842);
}

void CppTestsTest::test_multiples()
{
    int numbers[3];
    numbers[1]=2;
    numbers[2]=4;
    numbers[3]=8;
    cpp_multiples num;
    num.enter_numbers(numbers);
    num.find_multiples();
    QCOMPARE(num.get_amount(), 3);
}

void CppTestsTest::test_matrix_turn()
{
    int size_of_matrix=3, k;
    int **matrix = new int* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
        matrix[i] = new int [size_of_matrix];

    for(int i=0; i<size_of_matrix; i++)
        for(int j=0; j<size_of_matrix; j++)
        {
            k++;
            matrix[i][j]=k;
        }

    int **matrix_r = new int* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
        matrix_r[i] = new int [size_of_matrix];
    k=0;
    for(int i=0; i<size_of_matrix; i++)
        for(int j=0; j<size_of_matrix; j++)
        {
            k++;
            matrix_r[i][j]=k+size_of_matrix*2-4*j-2*i;
        }
    cpp_matrix_turn matr;
    matr.enter_matrix(size_of_matrix, matrix);
    matr.turn_matrix();
    for(int i=0; i<size_of_matrix; i++)
        for(int j=0; j<size_of_matrix; j++)
        {
            matrix[i][j]=matr.matrix_turned[i][j];
        }
    QCOMPARE(compare_matrix(matrix, matrix_r, size_of_matrix), 0);
    delete[] matrix;
    delete[] matrix_r;
}

void CppTestsTest::test_iu_sum()
{
    vector<int> num1;
    for(int i = 0; i < 6; i++)
    {
        num1.push_back(6-i);
    }

    vector<int> num2;
    for(int i = 0; i < 6; i++)
    {
        num2.push_back(1+i);
    }

    cpp_int_unlim iu;
    iu.enter_numbers(num1, num2);
    iu.basic_calculations();
    iu.sum_of_iu();
    QCOMPARE(iu.get_sum(), 777777);
}

void CppTestsTest::test_iu_subt()
{
    vector<int> num1;
    for(int i = 0; i < 6; i++)
    {
        num1.push_back(6-i);
    }

    vector<int> num2;
    for(int i = 0; i < 6; i++)
    {
        num2.push_back(1+i);
    }

    cpp_int_unlim iu;
    iu.enter_numbers(num1, num2);
    iu.basic_calculations();
    iu.subtraction_of_iu();
    QCOMPARE(iu.get_subtraction(), 530865);
}

void CppTestsTest::test_iu_mult()
{
    vector<int> num1;
    for(int i = 0; i < 4; i++)
    {
        num1.push_back(4-i);
    }

    vector<int> num2;
    for(int i = 0; i < 4; i++)
    {
        num2.push_back(1+i);
    }

    cpp_int_unlim iu;
    iu.enter_numbers(num1, num2);
    iu.basic_calculations();
    iu.multiplication_of_iu();
    QCOMPARE(iu.get_multiplication(), 5332114);
}

QTEST_APPLESS_MAIN(CppTestsTest)

#include "tst_cppteststest.moc"
