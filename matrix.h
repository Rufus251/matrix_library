#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <time.h>
typedef struct matrix{
    int len;
    int high;
    int **arr;
}matrix;
void swap(int *a, int *b);
void matPrint(struct matrix arr);
struct matrix matCreateSqr(int lenhigh, int number);
struct matrix matCreateSingle(int lenhigh);
struct matrix matCreateRand(int len, int high, int lg, int pg);
struct matrix matCreateCopy(struct matrix arr);
struct matrix matCreateZnach(int high, int len);
struct matrix matCreate(int len, int high);
void matDel(struct matrix arr);
int matDet(struct matrix arr);
struct matrix matTrans(struct matrix arr);
struct matrix matCreateInv(struct matrix arr);
struct matrix matSum(struct matrix arr1, struct matrix arr2);
struct matrix matRazn(struct matrix arr1, struct matrix arr2);
struct matrix matMnoj(struct matrix arr1, struct matrix arr2);


#endif //UNTITLED_MATRIX_H
