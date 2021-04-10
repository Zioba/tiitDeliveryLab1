#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"
using namespace std;


int main(){
    
    //ВЫЗОВ ФУНКЦИИ ЧТЕНИЯ
    int** matrix = new int*[1000];
    int** matrix_new = new int*[1000];
    int* array_matrix = new int[1000];
    
    ofstream record("Test.doc", ios::app);
    record.close();
    
    /*-----------ТЕСТЫ-------------*/
    ifstream reading("Test.doc");
    int n, m, a;
    int** matrix_test = new int*[1000];
    int *array_test = new int[1000];
    string s;
    if(reading)
    {
        reading >> n;
        reading >> m;
        for(int i = 0; i < n; i++)
        {
            matrix_test[i] = new int[m];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                reading >> matrix_test[i][j];
                }
            }
        //проверка чтения данных
        ReadingMatrix(matrix, n, m, "Matrix.doc");
        
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix_test[i][j]==matrix[i][j])
                        continue;
                    else
                        cout << "Test #1: FAILED" << endl;
                    }
                }
                cout << "Test #1: SUCCEED" << endl;

        
        reading >> a;
        reading >> s;
        
        //проверка сортировки
        SortMatrix(matrix, n, m);
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array_matrix[count] = matrix[i][j];
                count++;
            }
        }
        for (int i = 0; i < n*m; i++) {
            reading >> array_test[i];
        }
        
        int check = 0;
        for (int i = 0; i < n*m; i++) {
            if(array_test[i] == array_matrix[i]){
                check += 1;
            }
        }
        
        if (check == n*m)
            cout << "Test #2: SUCCEED" << endl;
        else
            cout << "Test #2: FAILED" << endl;
        
        
       reading >> s;
    
        //проверка вставки элемента
        AddElement(matrix, 7, 1, 2);
        
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array_matrix[count] = matrix[i][j];
                count++;
            }
        }
        for (int i = 0; i < n*m; i++) {
            reading >> array_test[i];
        }
        
        check = 0;
        for (int i = 0; i < n*m; i++) {
            if(array_matrix[i] == array_test[i]){
                check += 1;
            }
        }
        
        if (check == n*m)
            cout << "Test #3: SUCCEED" << endl;
        else
            cout << "Test #3: FAILED" << endl;
        
        reading >> s;
        
        //проверка поиска элемента
        SearchElement(7, matrix, n, m, array_matrix);
        for (int i = 0; i < 2; i++) {
            reading >> array_test[i];
        }
        
        for (int i = 0; i < SearchElement(7, matrix, n, m, array_matrix); i++) {
            if (i != SearchElement(7, matrix, n, m, array_matrix) - 1) {
        
                if (array_test[i] == array_matrix[i])
                    continue;
                else
                    cout << "Test #4: FAILED" << endl;
            }
            else
                cout << "Test #4: SUCCEED" << endl;
        }
        
        reading >> s;
       
        //проверка объединения
        ReadingMatrix(matrix_new, 2, 2, "Matrix1.doc");
        SortMatrix(matrix_new, 2, 2);
        Union(matrix, n, m, matrix_new, 2, 2, array_matrix);
        for (int i = 0; i < n*m+4; i++) {
            reading >> array_test[i];
        }
        
        check = 0;
        for (int i = 0; i < n*m+4; i++) {
            if(array_test[i] == array_matrix[i]){
                check += 1;
            }
        }
        if (check == n*m+4)
            cout << "Test #5: SUCCEED" << endl;
        else
            cout << "Test #5: FAILED" << endl;
        
        reading >> s;
        
        //проверка пересечения
        Intersection(matrix, n, m, matrix_new, 2, 2, array_matrix);
        for (int i = 0; i < Intersection(matrix, n, m, matrix_new, 2, 2, array_matrix); i++) {
            reading >> array_test[i];
        }
        
        check = 0;
        for (int i = 0; i < Intersection(matrix, n, m, matrix_new, 2, 2, array_matrix); i++) {
            if(array_test[i] == array_matrix[i]){
                check += 1;
            }
        }
        if (check == Intersection(matrix, n, m, matrix_new, 2, 2, array_matrix))
            cout << "Test #6: SUCCEED" << endl;
        else
            cout << "Test #6: FAILED" << endl;
        
    }
    
    reading.close();
    return 0;
}
