#include <stdio.h>
#include "matrix.h"
int main() {
    matrix arr1, arr2, arr3;

    printf("Square Matrix\n");
    arr1 = matCreateSqr(3, 1);
    matPrint(arr1);


    printf("\nRand matrix\n");
    arr1 = matCreateRand(3, 3, 1, 10);
    matPrint(arr1);

    printf("\nRand Copy matrix\n");
    arr2 = matCreateCopy(arr1);
    matPrint(arr2);

    printf("\nRand trans matrix\n");
    arr2 = matTrans(arr1);
    matPrint(arr2);


    printf("\nRand matrix * Rand matrix\n");
    arr1 = matCreateRand(2, 5, 1, 10);
    arr2 = matCreateRand(7, 2, 1, 10);
    arr3 = matMnoj(arr1, arr2);
    matPrint(arr3);

    printf("\nError when first matrix len != second matrix high\n");
    arr3 = matMnoj(arr2, arr1);
    matPrint(arr3);
    arr3 = matMnoj(arr1, arr1);
    matPrint(arr3);
    printf("\n");

    printf("\nMatrix Sum\n");
    arr1 = matCreateSqr(3, 1);
    arr2 = matCreateSqr(3, 2);
    arr3 = matSum(arr1, arr2);
    matPrint(arr3);

    printf("\nMatrix Razn\n");
    arr3 = matRazn(arr1, arr2);
    matPrint(arr3);

    printf("\nMatrix Det\n");
    arr1 = matCreateRand(3, 3, 1, 2);
    matPrint(arr1);
    printf("det = %d\n", matDet(arr1));

    printf("\nMatrix Invert\n");
    arr1 = matCreateInv(arr1);
    matPrint(arr1);
    return 0;
}