#include <QString>
#include <QtTest>

#include "cpp_int_unlim.h"
//#include "cpp_keys_in_text.h"
//#include "cpp_matrix_turn.h"
#include "cpp_multiples.h"
#include "cpp_reversed_num.h"
#include "cpp_sum_of_digits.h"

class CppTestsTest : public QObject
{
    Q_OBJECT

public:
    CppTestsTest();

private Q_SLOTS:
    void test_sum_of_digits();
    void test_reversed_num();
    void test_multiples();
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
