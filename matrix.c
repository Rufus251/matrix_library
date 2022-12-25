#include "matrix.h"
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void matPrint(struct matrix arr){
    for (int i = 0; i < arr.high; i++){
        for(int j = 0; j < arr.len; j++){
            printf("%d ", arr.arr[i][j]);
        }
        printf("\n");
    }
}
struct matrix matCreateSqr(int lenhigh, int number){
    struct matrix arr;
    arr.arr = (int**)malloc(sizeof(int*)*lenhigh);
    for (int i = 0; i < lenhigh; i++){
        arr.arr[i] = (int*)malloc(sizeof(int*)*lenhigh);
    }
    for (int i = 0; i < lenhigh; i++){
        for(int j = 0; j < lenhigh; j++){
            arr.arr[i][j] = number;
        }
    }
    arr.len = lenhigh;
    arr.high = lenhigh;
    return arr;
}
struct matrix matCreateSingle(int lenhigh){
    struct matrix arr;
    arr.len = lenhigh;
    arr.high = lenhigh;
    arr.arr = (int**)malloc(sizeof(int*)*lenhigh);
    for (int i = 0; i < lenhigh; i++){
        arr.arr[i] = (int*)malloc(sizeof(int*)*lenhigh);
    }
    for (int i = 0; i < lenhigh; i++){
        for(int j = 0; j < lenhigh; j++){
            if (i == j){
                arr.arr[i][j] = 1;
            }
            else{
                arr.arr[i][j] = 0;
            }
        }
    }
    return arr;
}
struct matrix matCreateRand(int len, int high, int lg, int pg){
    struct matrix arr;
    srand(time(NULL));
    arr.len = len;
    arr.high = high;
    arr.arr = (int**)malloc(sizeof(int*)*high);
    for (int i = 0; i < high; i++){
        arr.arr[i] = (int*)malloc(sizeof(int*)*len);
    }
    for (int i = 0; i < high; i++){
        for(int j = 0; j < len; j++){
            arr.arr[i][j] = rand() % (pg - lg + 1) + lg;
        }
    }
    return arr;
}
struct matrix matCreateCopy(struct matrix arr){
    struct matrix arrCopy = matCreate(arr.high, arr.len);
    for(int i = 0; i < arr.high; i++){
        for(int j = 0; j < arr.len; j++){
            arrCopy.arr[i][j] = arr.arr[i][j];
        }
    }
    return arrCopy;
}
struct matrix matCreateZnach(int high, int len){
    struct matrix arr;
    arr.len = len;
    arr.high = high;
    arr.arr = (int**)malloc(sizeof(int*)*high);
    for (int i = 0; i < high; i++){
        arr.arr[i] = (int*)malloc(sizeof(int*)*len);
    }
    for (int i = 0; i < high; i++){
        for(int j = 0; j < len; j++){
            scanf("%d", &arr.arr[i][j]);
        }
    }
    return arr;
}
struct matrix matCreate(int high, int len){
    struct matrix arr;
    arr.len = len;
    arr.high = high;
    arr.arr = (int**)malloc(sizeof(int*)*high);
    for (int i = 0; i < high; i++){
        arr.arr[i] = (int*)malloc(sizeof(int*)*len);
    }
    for (int i = 0; i < high; i++){
        for(int j = 0; j < len; j++){
            arr.arr[i][j] = 0;
        }
    }
    return arr;
}
void matDel(struct matrix arr){
    for(int i = 0; i < arr.len; i++){
        free(arr.arr[i]);
    }
}
int matDet(struct matrix arr){
    if (arr.len != arr.high){
        printf("Det not found, matrix not square!!!");
        return 0;
    }
    if (arr.len == 1){
        return arr.arr[0][0];
    }
    if (arr.len == 2){
        return arr.arr[0][0] * arr.arr[1][1] - arr.arr[0][1] * arr.arr[1][0];
    }
    int det = 0, shift = 0;
    struct matrix newArr = matCreateSqr(arr.len - 1, 0);
    for (int k = 0; k < arr.len; k++){
        for (int i = 1; i < arr.high; i++){
            for(int j = 0; j < arr.len; j++){
                if (j == k){
                    shift++;
                    continue;
                }
                newArr.arr[i - 1][j - shift] = arr.arr[i][j];
            }
            shift = 0;
        }
        det += pow(-1, k) * arr.arr[0][k] * matDet(newArr);
    }
    return det;
}
struct matrix matTrans(struct matrix arr){
    matrix arr2 = matCreate(arr.len, arr.high);
    for(int i = 0; i < arr2.high; i++){
        for (int j = 0; j < arr2.len; j++){
            arr2.arr[i][j] = arr.arr[j][i];
        }
    }
    return arr2;
}
struct matrix matCreateInv(struct matrix arr){
    if (arr.len != arr.high){
        printf("ERROR! Matrix is not square!\n");
        matrix arr1 = {-1, -1, NULL};
        return arr1;
    }
    if (matDet(arr) == 0){
        matrix arr1 = {-1, -1, NULL};
        printf("ERROR! det = 0\n");
        return arr1;
    }
    struct matrix arrAdj = matCreateCopy(arr);
    int adj = 0, shifti = 0, shiftj = 0;
    struct matrix newArr = matCreateSqr(arr.len - 1, 0);
    for (int k = 0; k < arr.len; k++) {
        for (int l = 0; l < arr.high; l++) {
            for (int i = 0; i < arr.high; i++) {
                for (int j = 0; j < arr.len; j++) {
                    if (k == i){
                        shifti++;
                        break;
                    }
                    if (l == j) {
                        shiftj++;
                        continue;
                    }
                    newArr.arr[i - shifti][j - shiftj] = arr.arr[i][j];
                }
                shiftj = 0;
            }
            adj = pow(-1, l + k) * matDet(newArr);
            arrAdj.arr[k][l] = adj;
            shifti = 0;
        }
    }
    arrAdj = matTrans(arrAdj);
    int det = matDet(arr);
    for (int i = 0; i < arrAdj.high; i++){
        for (int j = 0; j < arrAdj.len; j++){
            arrAdj.arr[i][j] = arrAdj.arr[i][j] / det;
        }
    }
    return arrAdj;
}
struct matrix matSum(struct matrix arr1, struct matrix arr2){
    struct matrix arr3 = {-1, -1, NULL};
    if (arr1.len != arr2.len || arr1.high != arr2.high){
        printf("ERROR! Matrices are different!!!\n");
        return arr3;
    }
    arr3 = matCreate(arr1.high, arr2.len);
    for (int i = 0; i < arr1.high; i++){
        for(int j = 0; j < arr1.len; j++){
            arr3.arr[i][j] = arr1.arr[i][j] + arr2.arr[i][j];
        }
    }
    return arr3;
}
struct matrix matRazn(struct matrix arr1, struct matrix arr2){
    struct matrix arr3 = {-1, -1, NULL};
    if (arr1.len != arr2.len || arr1.high != arr2.high){
        printf("ERROR! Matrices are different!!!\n");
        return arr3;
    }
    arr3.arr = (int**)malloc(sizeof(int*)*arr1.high);
    for (int i = 0; i < arr1.high; i++){
        arr3.arr[i] = (int*)malloc(sizeof(int*)*arr1.len);
    }
    for (int i = 0; i < arr1.high; i++){
        for(int j = 0; j < arr1.len; j++){
            arr3.arr[i][j] = arr1.arr[i][j] - arr2.arr[i][j];
        }
    }
    arr3.high = arr1.high;
    arr3.len = arr1.len;
    return arr3;
}
struct matrix matMnoj(struct matrix arr1, struct matrix arr2){
    if (arr1.len != arr2.high){
        printf("ERROR! Matrix1.len != Matrix2.high!!!\n");
        matrix arr3 = {-1, -1, NULL};
        return arr3;
    }
    matrix arr3 = matCreate(arr1.high, arr2.len);
    for (int i = 0; i < arr1.high; i++){
        for(int j = 0; j < arr2.len; j++){
            int summa = 0;
            for (int l = 0; l < arr1.len; l++) {
                summa += arr1.arr[i][l] * arr2.arr[l][j];
            }
            arr3.arr[i][j] = summa;
        }
    }
    return arr3;
}