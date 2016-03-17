//
//  strassen.c
//  
//
//  Created by Harrison Chase on 3/16/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
typedef struct{
    int nrow,ncol;
    int **mat;
}matrix;


matrix matrix_mult(matrix a,matrix b);
int main(int argc, char *argv[] )
{
    srand(time(NULL));
    
    int n = atoi(argv[1]);
    //http://stackoverflow.com/questions/455960/dynamic-allocating-array-of-arrays-in-c
    matrix mat_a;
    mat_a.ncol=n;
    mat_a.nrow=n;
    mat_a.mat = (int**)malloc(n*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mat_a.mat[i] = (int*)malloc(n*sizeof(int));
    }
    matrix mat_b;
    mat_b.ncol=n;
    mat_b.nrow=n;
    mat_b.mat = (int**)malloc(n*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mat_b.mat[i] = (int*)malloc(n*sizeof(int));
    }
    /*int** second = (int**)malloc(n*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        second[i] = (int*)malloc(n*sizeof(int));
    }
    int** mult = (int**)malloc(n*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult[i] = (int*)malloc(n*sizeof(int));
    }*/
    //int first[n][n];
    //int second[n][n];
    //int mult[n][n];
    int c,d,e,sum;
    for (c =0;c<n;c++){
        for(d=0;d<n;d++){
            mat_a.mat[c][d] = rand() % 2;
            mat_b.mat[c][d] = rand() % 2;
        }
    }
    /*for (c =0;c<n;c++){
        for(d=0;d<n;d++){
            sum = 0;
            for(e=0;e<n;e++){
                sum+=first[c][e]*second[e][d];
            }
            mult[c][d]=sum;
        }
    }*/
    matrix mult = matrix_mult(mat_a,mat_b);
    for (c = 0; c < n; c++) {
        for (d = 0; d < n; d++) {
            printf("%d ", mat_a.mat[c][d]);
        }
        printf("\n");
    }
    for (c = 0; c < n; c++) {
        for (d = 0; d < n; d++) {
            printf("%d ", mat_b.mat[c][d]);
        }
        printf("\n");
    }
    for (c = 0; c < n; c++) {
        for (d = 0; d < n; d++) {
            printf("%d ", mult.mat[c][d]);
        }
        printf("\n");
    }
}
matrix matrix_mult(matrix a,matrix b){
    int c,d,e,n,sum;
    n = a.nrow;
    matrix mult;
    mult.nrow = a.nrow;
    mult.ncol = b.ncol;
    mult.mat = (int**)malloc(b.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult.mat[i] = (int*)malloc(a.ncol*sizeof(int));
    }
    for (c =0;c<a.nrow;c++){
        for(d=0;d<b.ncol;d++){
            sum = 0;
            for(e=0;e<a.ncol;e++){
                sum+=a.mat[c][e]*b.mat[e][d];
            }
            mult.mat[c][d]=sum;
        }
    }
    return mult;
}
matrix matrix_add(matrix a,matrix b){
    int c,d;
    matrix add;
    add.nrow = a.nrow;
    add.ncol = b.ncol;
    add.mat = (int**)malloc(b.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        add.mat[i] = (int*)malloc(a.ncol*sizeof(int));
    }
    for (c =0;c<a.nrow;c++){
        for(d=0;d<b.ncol;d++){
            add.mat[c][d]=a.mat[c][d] + b.mat[c][d];
        }
    }
    return add;
}

matrix make1(matrix a){
    matrix A;
    int n =log(a.nrow)/log(2)
    A.ncol = pow(2,n);
    A.nrow = A.ncol;
    A.mat = (int**)malloc(A.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult.mat[i] = (int*)malloc(A.ncol*sizeof(int));
    }
    int c,d;
    for (c =0;c<A.nrow;c++){
        for(d=0;d<A.ncol;d++){
            A.mat[c][d] = a.mat[c][d];
        }
    }
    return A;
    
}
matrix make2(matrix a){
    matrix A;
    int n = pow(2,log(a.nrow)/log(2))
    A.ncol = a.nrow - n;
    A.nrow = n;
    A.mat = (int**)malloc(A.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult.mat[i] = (int*)malloc(A.ncol*sizeof(int));
    }
    int c,d;
    for (c =0;c<A.nrow;c++){
        for(d=0;d<A.ncol;d++){
            A.mat[c][d] = a.mat[c][n+d];
        }
    }
    return A;
    
}
matrix make3(matrix a){
    matrix A;
    int n = pow(2,log(a.nrow)/log(2))
    A.ncol = n;
    A.nrow = a.ncol - n;
    A.mat = (int**)malloc(A.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult.mat[i] = (int*)malloc(A.ncol*sizeof(int));
    }
    int c,d;
    for (c =0;c<A.nrow;c++){
        for(d=0;d<A.ncol;d++){
            A.mat[c][d] = a.mat[n+c][d];
        }
    }
    return A;
    
}
matrix make4(matrix a){
    matrix A;
    int n = pow(2,log(a.nrow)/log(2))
    A.ncol = a.nrow - n;
    A.nrow = a.ncol - n;
    A.mat = (int**)malloc(A.nrow*sizeof(int*));
    for ( int i = 0; i < n; i++ ) {
        mult.mat[i] = (int*)malloc(A.ncol*sizeof(int));
    }
    int c,d;
    for (c =0;c<A.nrow;c++){
        for(d=0;d<A.ncol;d++){
            A.mat[c][d] = a.mat[n+c][n+d];
        }
    }
    return A;
    
}
void matrix_mult(int n,int **first, int **second,int **mult,matrix a,matrix b){
    if(n<=1){
        matrix_mult(int n,int first[n][n], int second[n][n],int mult[n][n])
    }
    n = n/2;
    matrix A = make1(a);
    matrix B = make2(a);
    matrix C = make3(a);
    matrix D = make4(a);
    matrix E = make1(b);
    matrix F = make2(b);
    matrix G = make3(b);
    matrix H = make4(b);
    
    
}
