#include "Matrix.h"

#include <iostream>
#include <fstream>


using namespace std;
int n, m;
int** matrix = new int*[1000];
int** matrix_new = new int*[1000];
int* c = new int[2000];


//СОЗДАНИЕ ДВУМЕРНОГО МАССИВА
int CreateMatrix(int cols, int rows, int **matrix){
    if (cols > 1000)
        cout << "Лимит допустимых размеров превышен!" << endl;
    n = cols;
    m = rows;
    for (int i = 0; i < cols + 1; i++)
        matrix[i] = new int[rows];
    
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++){
            cout << "Введите элемент " << i+1 << " строки, " << j+1 << " столбца:" << endl;
            cin >> matrix[i][j];
        }
    }
    return 0;
}

//ЧТЕНИЕ
int ReadingMatrix(int **matrix, int cols, int rows, string filename){
    if (cols > 1000 || rows > 1000)
        cout << "Лимит допустимых размеров превышен!" << endl;
    ifstream reading(filename);
    reading >> cols;
    reading >> rows;
    n = cols;
    m = rows;
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    if (reading){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                reading >> matrix[i][j];
            }
        }
    }
    
    reading.close();
    return 0;
}

//СОРТИРОВКА
int SortMatrix(int **matrix, int n, int m)
{
    int r = 0;
    int *arr = new int[n*m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[r] = matrix[i][j];
                r++;
            }
        }
    
    for (int i = 0; i < (n*m - 1); i++)
        for (int j = i + 1; j < n*m; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
    int r_=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = arr[r_];
            r_++;
        }
    }
    delete [] arr;
    return 0;
}

//добавление
int AddElement(int **matrix, int a, int i, int j) {
    matrix[i-1][j-1] = a;
    SortMatrix(matrix, n, m);
    return 0;
}

//ПОИСК
int SearchElement(int search, int **matrix, int n, int m, int *x){
    SortMatrix(matrix, n, m);
    int z = 0;
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == search) {
                    x[z] = (i+1)*10 + (j+1);
                    z += 1;
                }
            }
        }
    if (z == 0) {
        cout << "Element is not found" << endl;
        return 0;
    }
    else
        return z;
}

//ОБЪЕДИНЕНИЕ
int Union(int **matrix, int cols1, int rows1, int **matrix_new, int cols2, int rows2, int *c){

    SortMatrix(matrix, cols1, rows1);
    SortMatrix(matrix_new, cols2, rows2);
    
    int *a = new int[cols1*rows1];
    int *b = new int[cols2*rows2];
    int x = 0;
    for (int i = 0; i < cols1; i++) {
        for (int j = 0; j < rows1; j++) {
            a[x] = matrix[i][j];
            x++;
        }
    }
    
    int y = 0;
    for (int i = 0; i < cols2; i++) {
        for (int j = 0; j < rows2; j++) {
            b[y] = matrix_new[i][j];
            y++;
        }
    }
    
    for (int i=0; i<cols1*rows1; i++)
    {
        c[i] = a[i];
    }
    
    int r = 0;
    for (int i=cols1*rows1; i<cols2*rows2+cols1*rows1; i++)
    {
        c[i] = b[r];
        r++;
    }
    
    for (int i = 0; i < (cols2*rows2+cols1*rows1 - 1); i++)
        for (int j = i + 1; j < cols2*rows2+cols1*rows1; j++)
            if (c[i] > c[j])
                swap(c[i], c[j]);
    delete [] a;
    delete [] b;
    return 0;
}

//ПЕРЕСЕЧЕНИЕ
int Intersection(int **matrix, int n, int m, int **matrix_new, int n1, int m1, int *c){
    SortMatrix(matrix, n, m);
    SortMatrix(matrix_new, n1, m1);
    
    int *a = new int[n*m];
    int *b = new int[n1*m1];
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[x] = matrix[i][j];
            x++;
        }
    }
    
    int y = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            b[y] = matrix_new[i][j];
            y++;
        }
    }
    int z = 0;
    for (int i = 0; i<n*m; i++){
        for (int j = 0; j<n1*m1; j++) {
            if (a[i] == b[j]) {
                c[z] = a[i];
                z++;
            }
        }
    }
    
    delete [] a;
    delete [] b;
    if (z == 0) {
        cout << "No elemets!" << endl;
        return 0;
    }
    else
        return z;
}

