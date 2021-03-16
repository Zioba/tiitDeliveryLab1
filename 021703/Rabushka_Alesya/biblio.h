#pragma once
#ifndef _biblio_H_
#define _biblio_H_

void build(int a[], int v, int tl, int tr);

//сумма на всём массиве
int Sum(int v, int tl, int tr);

//сумма на отрезке массива
int sum(int v, int tl, int tr, int l, int r);

//изменение
void  Up(int v, int tl, int tr, int l, int r, int y);

#endif;