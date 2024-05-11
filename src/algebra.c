#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
   Matrix n = create_matrix(a.rows,a.cols);
   if(a.rows!=b.rows||a.cols!=b.cols){
    printf("Error: Matrix a and b must have the same rows and cols.\n");
   }else{
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            n.data[i][j]=a.data[i][j]+b.data[i][j];
        }
    }return n;

   }

    return create_matrix(0, 0);
}

Matrix sub_matrix(Matrix a, Matrix b)
{
   Matrix n= create_matrix(a.rows,a.cols);
   if(a.rows!=b.rows||a.cols!=b.cols){
    printf("Error: Matrix a and b must have the same rows and cols.\n");
   }else{
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            n.data[i][j]=a.data[i][j]-b.data[i][j];
        }
    }return n;

   }
    return create_matrix(0, 0);
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    Matrix n= create_matrix(a.rows,a.cols);
    if(a.rows!=b.rows||a.cols!=b.cols){
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
    }else{
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<a.rows;j++){
                for(int k=0;k<a.rows;k++){
                    n.data[i][j]+=a.data[i][k]*b.data[k][j];
                }
            }
        }return n;
    }
    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix n= create_matrix(a.rows,a.cols);
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            n.data[i][j]=k*a.data[i][j];
        }
    }
    return n;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    int t=0;
    if(a.rows!=a.cols){
        printf("Error: The matrix must be a square matrix.\n");
    }else{
        for(int i=0;i<a.rows;i++){
            t+=a.data[i][i];
        }
    }
    return t;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}