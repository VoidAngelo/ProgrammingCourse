#include <QString>
#include <QtTest>

#include "UnlimitedInt.h"
#include "KeysInText.h"
#include "MatrixTurn.h"
#include "Multiples.h"
#include "ReversedNum.h"
#include "SumOfDigits.h"

class CppTestsTest : public QObject
{
    Q_OBJECT

public:
    CppTestsTest();

private Q_SLOTS:
    void testSumOfDigits();
    void testReversedNum();
    void testMultiples();
    void testMatrixTurn();
    void testKeysInText();
    /*void test_iu_sum();
    void test_iu_subt();
    void test_iu_mult();*/
};

CppTestsTest::CppTestsTest()
{
}

void CppTestsTest::testSumOfDigits()
{
    SumOfDigits num;
    int sum=num.Sum(248);
    QCOMPARE(sum, 14);
}

void CppTestsTest::testReversedNum()
{
    ReversedNum num;
    int reversion=num.Reversion(248);
    QCOMPARE(reversion, 842);
}

void CppTestsTest::testMultiples()
{
    int trigger=0;
    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(22);
    vector<vector<int> > multiples_test;
    vector<int> pair;
    pair.reserve(2);
    for (unsigned int i=0; i<numbers.size(); i++)
    {
        for (unsigned int j=0; j<numbers.size(); j++)
        {
            if(i!=j && numbers[i]%numbers[j]==0)
            {
                pair[0]=numbers[i];
                pair[1]=numbers[j];
                multiples_test.push_back(pair);
            }
        }
    }
    Multiples nums(numbers);
    vector<vector<int> > multiples=nums.findMultiples();
    for (unsigned int i=0; i<multiples_test.size(); i++)
    {
        for (unsigned int j=0; j<pair.size(); j++)
        {
            if (multiples[i][j]!=multiples_test[i][j])
            {
                trigger=1;
                break;
            }
        }
    }
    QCOMPARE(trigger, 0);
}

void CppTestsTest::testMatrixTurn()
{
    int sizeOfMatrix=3, k=0, trigger=0;

    MatrixTurn matrix(sizeOfMatrix);
    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            k++;
            matrix.putNum(i, j, k);
        }
    }

    int **matrix_r = new int* [sizeOfMatrix];
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        matrix_r[i] = new int [sizeOfMatrix];
    }

    k=0;
    for(int i=0; i<sizeOfMatrix; i++)
    {
        for(int j=0; j<sizeOfMatrix; j++)
        {
            k++;
            matrix_r[i][j]=k+sizeOfMatrix*2-4*j-2*i;
        }
    }

    matrix.turnMatrix();

    for (int i=0; i<sizeOfMatrix; i++)
    {
        for (int j=0; j<sizeOfMatrix; j++)
        {
            if (matrix_r[i][j]!=matrix.getNum(i, j))
            {
                trigger=1;
                break;
            }
        }
    }

    QCOMPARE(trigger, 0);

    for (int i=0; i<sizeOfMatrix; i++)
    {
        delete [] matrix_r[i];
    }
    delete [] matrix_r;
}

void CppTestsTest::testKeysInText()
{
    int trigger=0;
    vector<string> strings;
    strings.push_back("ololo");
    strings.push_back("lol");
    strings.push_back("o");

    vector<string> keys;
    keys.push_back("o");
    keys.push_back("l");

    KeysInText kit(strings);
    vector<int> result=kit.findKeys(keys);

    vector<int> r_test;
    r_test.push_back(5);
    r_test.push_back(4);

    for (unsigned int i=0; i<r_test.size(); i++)
    {
        if (r_test[i]!=result[i])
        {
            trigger=1;
            break;
        }
    }
    QCOMPARE(trigger, 0);
}

/*void CppTestsTest::test_iu_sum()
{
    UnlimitedInt num1(5);
    num1[0]=1;
    num1[1]=2;
    num1[2]=3;
    num1[3]=4;
    num1[4]=5;
    UnlimitedInt num2(5);
    num2[0]=6;
    num2[1]=5;
    num2[2]=4;
    num2[3]=3;
    num2[4]=2;
    UnlimitedInt sum;
    sum=num1+num2;
    QCOMPARE(sum, 77777);
}

void CppTestsTest::test_iu_subt()
{
    UnlimitedInt num1(5);
    num1[0]=1;
    num1[1]=2;
    num1[2]=3;
    num1[3]=4;
    num1[4]=5;
    UnlimitedInt num2(5);
    num2[0]=6;
    num2[1]=5;
    num2[2]=4;
    num2[3]=3;
    num2[4]=2;
    UnlimitedInt subt;
    subt=num1-num2;
    QCOMPARE(subt, 77777);
}

void CppTestsTest::test_iu_mult()
{
    UnlimitedInt num1(5);
    num1[0]=1;
    num1[1]=2;
    num1[2]=3;
    num1[3]=4;
    num1[4]=5;
    UnlimitedInt num2(5);
    num2[0]=6;
    num2[1]=5;
    num2[2]=4;
    num2[3]=3;
    num2[4]=2;
    UnlimitedInt mult;
    mult=num1*num2;
    QCOMPARE(mult, 807758040);
}*/

QTEST_APPLESS_MAIN(CppTestsTest)

#include "tst_cppteststest.moc"
