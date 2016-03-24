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

int break_point = 100;
int max_dim;
int ** regular_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim);
int ** strassen_mult(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim);
int ** regular_add(int ** mat_a,int** mat_b, int row_a, int col_a,int row_b, int col_b, int dim,int sub);
int get_padding(int actual_size, int Q);
int main(int argc, char *argv[] )
{
    srand(time(NULL));
    FILE *myFile;
    myFile = fopen(argv[3], "r");
    int dim = atoi(argv[2]);
    int act_dim = get_padding(dim,break_point);
    //for(int multiply = 0;multiply<=1;multiply++){
    //double time_spent = 0.;
    //double time_spent1 = 0.;
    //clock_t begin, end;
    //break_point=break_point+10;
    //printf("%d",break_point);
    //for(int adam =0; adam<1;adam++){
    //read file into array
    int i,j;
    int **mat_a = (int**)malloc(act_dim*sizeof(int*));
    for ( int i = 0; i < act_dim; i++ ) {
        mat_a[i] = (int*)malloc(act_dim*sizeof(int));
    }
    int **mat_b = (int**)malloc(act_dim*sizeof(int*));
    for ( int i = 0; i < act_dim; i++ ) {
        mat_b[i] = (int*)malloc(act_dim*sizeof(int));
    }
    // Read in the matrices
    /*for (i = 0; i < act_dim; i++){
     for(j =0;j < act_dim; j++){
     mat_a[i][j] = rand() % 2;
     mat_b[i][j] = rand() % 2;
     }
     }*/
    for (i = 0; i < act_dim; i++){
        for(j =0;j < act_dim; j++){
            if(i<dim & j<dim){
                fscanf(myFile, "%1d", &mat_a[i][j]);
            }
            else{
                mat_a[i][j]=0;
            }
        }
    }
    for (i = 0; i < act_dim; i++){
        for(j =0;j < act_dim; j++){
            if(i<dim & j<dim){
                fscanf(myFile, "%1d", &mat_b[i][j]);
            }
            else{
                mat_b[i][j]=0;
            }
        }
    }
    
    //dim = 0;
    //for(int adam = 0;adam<1;adam++){
    //for(int adam = 0;adam<1;adam++){
    //dim=dim+50;
    //act_dim = get_padding(dim,break_point);
    //act_dim = pow(2,ceil(log(dim)/log(2)));
    //begin = clock();
    //int ** mat_d = regular_mult(mat_a,mat_b,0,0,0,0,act_dim);
    //end = clock();
    //time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    //free(mat_d);
    //begin = clock();
    //printf("%d",act_dim);
    //fflush(stdout);
    int ** mat_c = strassen_mult(mat_a,mat_b,0,0,0,0,act_dim);
    //end = clock();
    //time_spent1 = (double)(end - begin) / CLOCKS_PER_SEC;
    for (i = 0; i < dim; i++){
        printf("%d\n",mat_c[i][i]);
    }
    printf("\n");
    //printf("%f,",time_spent1);
    
    //}
    //printf("Regular took: %f\n",time_spent);
    /*time_spent=0.;
     for(int adam = 0;adam<1000;adam++){
     begin = clock();
     int ** mat_c = strassen_mult(mat_a,mat_b,0,0,0,0,act_dim);
     end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
     free(mat_c);
     }*/
    //printf("Strassen took: %f\n",time_spent1);
    free(mat_a);
    free(mat_b);
    free(mat_c);
    //int act_dim = pow(2,ceil(log(dim)/log(2)));
    /*
     //printf("%d",act_dim);
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
     }*/
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
    
    
    /*begin = clock();
     int ** mat_c = strassen_mult(mat_a,mat_b,0,0,0,0,act_dim);
     end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
     //free(mat_a);
     //free(mat_b);
     free(mat_c);
     //}
     printf("Strassen took: %f\n",time_spent);
     //}*/
    /*for(break_point = 16;break_point<512;break_point=break_point*2){
     
     }*/
    
    /*begin = clock();
     int ** mat_d = regular_mult(mat_a,mat_b,0,0,0,0,act_dim);
     end = clock();
     time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("Regular took: %f\n",time_spent);*/
    /*for (i = 0; i < dim; i++) {
     for (j = 0; j < dim; j++) {
     if(mat_c[i][j]!=mat_d[i][j]){
     printf("hi");
     printf("\n");
     }
     }
     }*/
    /*for (i = 0; i < act_dim; i++) {
     for (j = 0; j < act_dim; j++) {
     printf("%d ", mat_c[i][j]);
     }
     printf("\n");
     }
     for (i = 0; i < act_dim; i++) {
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
            /*k = 0;
             while((k<dim)&(row_a+i<max_dim)&(col_a+k<max_dim)){*/
            for(k=0;k<dim;k++){
                sum += mat_a[row_a+i][col_a+k]* mat_b[row_b+k][col_b+j];
                //k++;
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
    if (dim <=break_point){
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
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
        free(p5a);
        free(p5b);
        free(p6);
        free(p6a);
        free(p6b);
        free(p7);
        free(p7a);
        free(p7b);
        free(q1);
        free(q2);
        free(q3);
        free(q4);
        return mat_c;
        
    }
}
int get_padding(int actual_size, int Q) {
    int cnt = 0;
    float n = actual_size*1.;
    while(n > Q) {
        cnt++;
        n /= 2;
    }
    //printf("%d\n",cnt);
    //printf("%d\n",(1<<cnt));
    
    // result should be smallest value such that:
    // result >= actual_size AND
    // result % (1<<cnt) == 0
    
    /*if (actual_size % (1<<cnt) == 0) {
     return actual_size;
     } else {
     return actual_size + (1<<cnt) - actual_size % (1<<cnt);
     }*/
    return ceil(n)*(1<<cnt);
}

