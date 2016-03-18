//
//  strass.c
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


int ** regular_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim);
int ** strassen_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim);
int ** regular_add(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim,int sub);
int main(int argc, char *argv[] )
{
    srand(time(NULL));
    int dim = atoi(argv[1]);
    //read file into array
    int i,j;
    int act_dim = pow(2,ceil(log(dim)/log(2)));
    // Initialize the matrixes
    int **mat_a = (int**)malloc(act_dim*sizeof(int*));
    for ( int i = 0; i < act_dim; i++ ) {
        mat_a[i] = (int*)malloc(act_dim*sizeof(int));
    }
    int **mat_b = (int**)malloc(act_dim*sizeof(int*));
    for ( int i = 0; i < act_dim; i++ ) {
        mat_b[i] = (int*)malloc(act_dim*sizeof(int));
    }
    // Read in the matrices
    for (i = 0; i < act_dim; i++){
        for(j =0;j < act_dim; j++){
            mat_a[i][j] = rand() % 2;
            mat_b[i][j] = rand() % 2;
        }
    }
    /*for (i = 0; i < act_dim; i++) {
        for (j = 0; j < act_dim; j++) {
            printf("%d ", mat_a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < act_dim; i++) {
        for (j = 0; j < act_dim; j++) {
            printf("%d ", mat_b[i][j]);
        }
        printf("\n");
    }*/
    // Matrix multiplication
    clock_t begin, end;
    double time_spent;
    
    begin = clock();
    int ** mat_c = strassen_mult(mat_a,mat_b,0,0,0,0,act_dim);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Strassen took: %f\n",time_spent);
    begin = clock();
    int ** mat_d = regular_mult(mat_a,mat_b,0,0,0,0,act_dim);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Regular took: %f\n",time_spent);
    for (i = 0; i < act_dim; i++) {
        for (j = 0; j < act_dim; j++) {
            if(mat_c[i][j]!=mat_d[i][j]){
                printf("hi");
                printf("\n");
            }
        }
    }
    /*for (i = 0; i < act_dim; i++) {
        for (j = 0; j < act_dim; j++) {
            printf("%d ", mat_d[i][j]);
        }
        printf("\n");
    }*/
    
}

int ** regular_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim){
    int **mat_c = (int**)malloc(dim*sizeof(int*));
    for ( int i = 0; i < dim; i++ ) {
        mat_c[i] = (int*)malloc(dim*sizeof(int));
    }
    int i,j,k,sum;
    for (i = 0; i < dim; i++){
        for(j =0;j < dim; j++){
            sum = 0;
            for(k =0;k < dim; k++){
                sum += mat_a[row_a+i][col_a+k]* mat_b[row_b+k][col_b+j];
            }
            mat_c[i][j] = sum;
        }
    }
    return mat_c;
}
int ** regular_add(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim,int sub){
    int **mat_c = (int**)malloc(dim*sizeof(int*));
    for ( int i = 0; i < dim; i++ ) {
        mat_c[i] = (int*)malloc(dim*sizeof(int));
    }
    int i,j;
    for (i = 0; i < dim; i++){
        for(j =0;j < dim; j++){
            mat_c[i][j] = mat_a[row_a+i][col_a+j]+ sub* mat_b[row_b+i][col_b+j];
        }
    }
    return mat_c;
}

int ** strassen_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim){
    if (dim <=1){
        return regular_mult(mat_a,mat_b,row_a,col_a,row_b,col_b, dim);
    }
    else{
        int n = dim/2;
        int** p1= regular_add(mat_b,mat_b,row_b,col_b+n,row_b+n,col_b+n,n,-1);
        p1 = strassen_mult(mat_a,p1,row_a,col_a,0,0,n);
        int** p2 = regular_add(mat_a,mat_a,row_a,col_a,row_a,col_a+n,n,1);
        p2 = strassen_mult(p2,mat_b,0,0,row_b+n,col_b+n,n);
        int** p3 = regular_add(mat_a,mat_a,row_a+n,col_a,row_a+n,col_a+n,n,1);
        p3 = strassen_mult(p3,mat_b,0,0,row_b,col_b,n);
        int** p4= regular_add(mat_b,mat_b,row_b+n,col_b,row_b,col_b,n,-1);
        p4 = strassen_mult(mat_a,p4,row_a+n,col_a+n,0,0,n);
        int** p5a= regular_add(mat_a,mat_a,row_a,col_a,row_a+n,col_a+n,n,1);
        int** p5b= regular_add(mat_b,mat_b,row_b,col_b,row_b+n,col_b+n,n,1);
        int** p5 = strassen_mult(p5a,p5b,0,0,0,0,n);
        int** p6a= regular_add(mat_a,mat_a,row_a,col_a+n,row_a+n,col_a+n,n,-1);
        int** p6b= regular_add(mat_b,mat_b,row_b+n,col_b,row_b+n,col_b+n,n,1);
        int** p6 = strassen_mult(p6a,p6b,0,0,0,0,n);
        int** p7a= regular_add(mat_a,mat_a,row_a,col_a,row_a+n,col_a,n,-1);
        int** p7b= regular_add(mat_b,mat_b,row_b,col_b,row_b,col_b+n,n,1);
        int** p7 = strassen_mult(p7a,p7b,0,0,0,0,n);
        int** q1 = regular_add(p5,p4,0,0,0,0,n,1);
        q1 = regular_add(q1,p2,0,0,0,0,n,-1);
        q1 = regular_add(q1,p6,0,0,0,0,n,1);
        int** q2 = regular_add(p1,p2,0,0,0,0,n,1);
        int** q3 = regular_add(p3,p4,0,0,0,0,n,1);
        int** q4 = regular_add(p5,p1,0,0,0,0,n,1);
        q4 = regular_add(q4,p3,0,0,0,0,n,-1);
        q4 = regular_add(q4,p7,0,0,0,0,n,-1);
        int **mat_c = (int**)malloc(dim*sizeof(int*));
        for ( int i = 0; i < dim; i++ ) {
            mat_c[i] = (int*)malloc(dim*sizeof(int));
        }
        int i,j;
        for (i = 0; i < n; i++){
            for(j =0;j < n; j++){
                mat_c[i][j] = q1[i][j];
            }
        }
        for (i = 0; i < n; i++){
            for(j =0;j < n; j++){
                mat_c[i][j+n] = q2[i][j];
            }
        }
        for (i = 0; i < n; i++){
            for(j =0;j < n; j++){
                mat_c[i+n][j] = q3[i][j];
            }
        }
        for (i = 0; i < n; i++){
            for(j =0;j < n; j++){
                mat_c[i+n][j+n] = q4[i][j];
            }
        }
        return mat_c;
        
    }
}
