#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <fstream>


using namespace std;

//СОЗДАНИЕ ДВУМЕРНОГО МАССИВА
int CreateMatrix(int cols, int rows, int **matrix);
//ЧТЕНИЕ МАССИВА
int ReadingMatrix(int **matrix, int cols, int rows, string filename);
//СОРТИРОВКА ДВУМЕРНОГО МАССИВА
int SortMatrix(int **matrix, int n, int m);
//ВСТАВКА ЭЛЕМЕНТА В ОТСОРТИРОВАННЫЙ МАССИВ
int AddElement(int **matrix, int a, int i, int j);
//ПОИСК ЭЛЕМЕНТА В ОТСОРТИРОВАННОМ МАССИВЕ
int SearchElement(int search, int **matrix, int n, int m, int *x);
//ОБЪЕДИНЕНИЕ ДВУХ ОТСОРТИРОВАННЫХ МАССИВОВ
int Union(int **matrix, int cols1, int rows1, int **matrix_new, int cols2, int rows2, int *c);
//ПЕРЕСЕЧЕНИЕ ДВУХ ОТСОРТИРОВАННЫХ МАССИВОВ
int Intersection(int **matrix, int cols1, int rows1, int **matrix_new, int cols2, int rows2, int *c);

#endif /* Matrix_h */
