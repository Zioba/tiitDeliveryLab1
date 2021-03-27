#include <iostream>

#include "SufLibrary.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
   
   

            char a[80];
            cout << "Vvedite stroky ";
            gets_s(a, 80);
            SufAr(a);

            char b[80];
            cout << "Vvedite stroky ";
            gets_s(b);
            MCS(b);

            char X[80];
            cout << "\nVvedite stroky odin ";
            gets_s(X);
            char Y[80];
            cout << "Vvedite stroky dva  ";
            gets_s(Y);
            LCP(X, Y);
       
    }