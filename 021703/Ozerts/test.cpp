#include "pch.h"



#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

#include "gtest/gtest.h"

using namespace std;



struct suffix

{
    int index;
    char* suff;
};

int cmp(struct suffix a, struct suffix b)

{
    return strcmp(a.suff, b.suff) < 0 ? 1 : 0;
}

int* buildSuffixArray(char* txt, int n)

{

    struct suffix suffixes[100];

    for (int i = 0; i < n; i++)

    {

        suffixes[i].index = i;

        suffixes[i].suff = (txt + i);

    }

    sort(suffixes, suffixes + n, cmp);

    int* suffixArr = new int[n];

    for (int i = 0; i < n; i++)

        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}

void printArr(int arr[], int n)

{
    ofstream fin("C:\\users\\PuzAsus\\desktop\\Data.txt");
    for (int i = 0; i < n; i++)

        fin << arr[i] << " ";
    fin.close();
}

void printArr2(int arr[], int n)

{
    ofstream fin2("C:\\users\\PuzAsus\\desktop\\Data2.txt");
    for (int i = 0; i < n; i++)

        fin2 << arr[i] << " ";
    fin2.close();
}

void printArr3(int arr[], int n)

{
    ofstream fin("C:\\users\\PuzAsus\\desktop\\Data3.txt");
    for (int i = 0; i < n; i++)

        fin << arr[i] << " ";
    fin.close();
}

void printArr4(int arr[], int n)

{
    ofstream fin("C:\\users\\PuzAsus\\desktop\\Data4.txt");
    for (int i = 0; i < n; i++)

        fin << arr[i] << " ";
    fin.close();
}

void Suf(char* txt)
{
    int n = strlen(txt);
    int* suffixArr = buildSuffixArray(txt, n);
    printArr(suffixArr, n);

}
void Suf2(char* txt)
{
    int n = strlen(txt);
    int* suffixArr = buildSuffixArray(txt, n);
    printArr2(suffixArr, n);
}
void Suf3(char* txt)
{
    int n = strlen(txt);
    int* suffixArr = buildSuffixArray(txt, n);
    printArr3(suffixArr, n);
}
void Suf4(char* txt)
{
    int n = strlen(txt);
    int* suffixArr = buildSuffixArray(txt, n);
    printArr4(suffixArr, n);
}

string LCP(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int result = 0;
    int end;
    int len[2][50];
    int currRow = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else {
                len[currRow][j] = 0;
            }
        }
        currRow = 1 - currRow;
    }

    if (result == 0) {
        return "-1";
    }

    return X.substr(end - result + 1, result);
}

string MCS(string s)
{
    s += s;
    int n = (int)s.length();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                ++k;
            ++j;
        }
        while (i <= k)  i += j - k;
    }
    return s.substr(ans, n / 2);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



TEST(MCStest1, TestF)
{
    string actual = "kitten";
    string expected = "enkit";
    EXPECT_NE(MCS(actual), expected);

}

TEST(MCStest2, TestT)
{
    string actual = "hedgehog";
    string expected = "dgehoghe";

    EXPECT_EQ(MCS(actual), expected);
}

TEST(MCStest3, TestT)
{
    string actual = "jirrobass";
    string expected = "assjirrob";
    EXPECT_EQ(MCS(actual), expected);

}

TEST(MCStest4, TestT)
{
    string actual = "puzerman";
    string expected = "anpuzerm";

    EXPECT_EQ(MCS(actual), expected);
}

TEST(LCPtest1, TestT)
{
    string actual1 = "puzerjir";
    string actual2 = "puzerman";
    string expected = "puzer";

    EXPECT_EQ(LCP(actual1, actual2), expected);
}

TEST(LCPtest2, TestT)
{
    string actual1 = "strachpl";
    string actual2 = "fsfacmba";
    string expected = "ac";

    EXPECT_EQ(LCP(actual1, actual2), expected);
}

TEST(LCPtes3, TestF)
{
    string actual1 = "ploadfh";
    string actual2 = "looad";
    string expected = "load";

    EXPECT_NE(LCP(actual1, actual2), expected);
}

TEST(LCPtest4, TestT)
{
    string actual1 = "snusavgd";
    string actual2 = "plesnusaeffd";
    string expected = "snusa";

    EXPECT_EQ(LCP(actual1, actual2), expected);
}

::testing::AssertionResult IsTrue1(bool foo)
{
    int arr2[6] = { 5,3,1,0,4,2 };
    char x[] = "banana";
    Suf(x);
    ifstream fon("C:\\users\\PuzAsus\\desktop\\Data.txt");
    int ch;
    int Count = 0;
    while (fon >> ch)
        Count++;

    fon.close();

    float* mass = new float[Count];
    ifstream file("C:\\users\\PuzAsus\\desktop\\Data.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
    }

    int compare = 1;
    int i;
    for (i = 0; i < Count && compare; i++)
        if (mass[i] != arr2[i]) compare = 0;
    if (compare)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << foo;

    delete[] mass;
}

::testing::AssertionResult IsTrue2(bool foo2)
{
    int arr2[6] = { 4,1,0,5,3,2 };
    char a[] = "kitten";
    Suf2(a);
    ifstream fot("C:\\users\\PuzAsus\\desktop\\Data2.txt");
    int ch;
    int Count = 0;
    while (fot >> ch)
        Count++;

    fot.close();

    float* mass = new float[Count];
    ifstream file2("C:\\users\\PuzAsus\\desktop\\Data2.txt");
    for (int i = 0; i < Count; i++) {
        file2 >> mass[i];
    }

    int compare = 1;
    int i;
    for (i = 0; i < Count && compare; i++)
        if (mass[i] != arr2[i]) compare = 0;
    if (compare)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << foo2;

    delete[] mass;


}

::testing::AssertionResult IsTrue3(bool foo3)
{
    int arr2[10] = { 5,4,8,1,0,9,3,2,7,6 };
    char x[] = "jirobassik";
    Suf3(x);
    ifstream fon("C:\\users\\PuzAsus\\desktop\\Data3.txt");
    int ch;
    int Count = 0;
    while (fon >> ch)
        Count++;

    fon.close();

    float* mass = new float[Count];
    ifstream file("C:\\users\\PuzAsus\\desktop\\Data3.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
    }

    int compare = 1;
    int i;
    for (i = 0; i < Count && compare; i++)
        if (mass[i] != arr2[i]) compare = 0;
    if (compare)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << foo3;

    delete[] mass;


}

::testing::AssertionResult IsTrue4(bool foo4)
{
    int arr2[6] = { 2,1,7,3,6,0 };
    char x[] = "zanoza";
    Suf4(x);
    ifstream fon("C:\\users\\PuzAsus\\desktop\\Data4.txt");
    int ch;
    int Count = 0;
    while (fon >> ch)
        Count++;

    fon.close();

    float* mass = new float[Count];
    ifstream file("C:\\users\\PuzAsus\\desktop\\Data4.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
    }

    int compare = 1;
    int i;
    for (i = 0; i < Count && compare; i++)
        if (mass[i] != arr2[i]) compare = 0;
    if (compare)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << foo4;

    delete[] mass;


}

TEST(Sufar1, TestT)
{
    EXPECT_TRUE(IsTrue1(true));
}

TEST(Sufar2, TestT)
{
    EXPECT_TRUE(IsTrue2(true));
}

TEST(Sufar3, TestT)
{
    EXPECT_TRUE(IsTrue3(true));
}

TEST(Sufar4, TestF)
{
    EXPECT_FALSE(IsTrue4(true));
}