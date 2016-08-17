/*
 *  Author: Arpit Bhayani
 *  http://arpitbhayani.me
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;

int readline(char *str) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int row = matrixRowSize;
    int col = matrixColSize;

    int zrow = 0;
    int zcol = 0;

    for(int i = 0 ; i < col; i++) {
        if(matrix[0][i] == 0) {
            zrow = 1;
        }
    }

    for(int i = 0 ; i < row; i++) {
        if(matrix[i][0] == 0) {
            zcol = 1;
        }
    }

    for(int i = 1 ; i < row; i++) {
        for(int j = 1 ; j < col; j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = 1 ; i < row; i++) {
        for(int j = 1 ; j < col; j++) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(zrow) {
        for(int i = 0 ; i < col; i++) {
            matrix[0][i] = 0;
        }
    }

    if(zcol) {
        for(int i = 0 ; i < row; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    int row, col;
    scanf("%d%d", &row, &col);

    int **arr = (int **) malloc(row * sizeof(int *));
    for(int i = 0 ; i < row; i++) {
        arr[i] = (int *) malloc(col * sizeof(int));
    }

    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    setZeroes(arr, row, col);

    for(int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
