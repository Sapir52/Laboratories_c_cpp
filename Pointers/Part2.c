#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <stdlib.h>
//declare functions//
void PrintMatrix(int** matrix,int row,int column);
void BuildMatrix(int*** matrix,int row,int column);
void FreeMatrix(int*** matrix,int row);
void AddColumn(int*** matrix,int row,int* column,int* newCol,int rows);
int** multiPlyMatrixes(int** a,int** b,int size1,int size2,int size3);
//maim program//
int main()
{
	 int **m;
	 int column, row;
	 BuildMatrix(&m,row,column);
	 FreeMatrix(&m,row);
	 free(m);
	 m=NULL;

	 int** matrix=NULL;
	 PrintMatrix(matrix,row,column);

	 int* newCol;
	 AddColumn(&matrix,row,&column,newCol,rows);
	 int** a=NULL;
	 int** b=NULL;
	 int** result=NULL;
	 int rows,cols,cols2,i=0,j=0;
	 printf(" Matrix Multiplication \n");
	 printf("\n matrix 1\n");
	 printf("Enter num rows:");
	 scanf("%d",&rows);
	 printf("Enter num columns:");
	 scanf("%d",&cols);
	 a=(int**)malloc(rows*sizeof(int*));
	 printf("\nEnter First Matrix Of %d * %d \n" ,rows,cols);
	 for (i = 0; i < rows; i++)
	{
		  a[i]=(int*)malloc(cols*sizeof(int));
		  for (j = 0; j < cols; j++)
		  {
			   if (a[i] == NULL)
			   {
				   printf("Not enoufh memory");
				   exit(1);
			   }
		  scanf("%d",&a[i][j]);
		  }
	}
	 printf("\nMatrix 2\n");
	 printf("Enter num columns:");
	 scanf("%d",&cols2);
	 b=(int**)malloc(cols2*sizeof(int*));
	 printf("\nEnter Second Matrix Of %d * %d \n" ,cols,cols2);
	 for (i = 0; i < cols; i++)
	 {
		  b[i]=(int*)malloc(cols2*sizeof(int));
		  for (j = 0; j < cols2; j++)
		  {
			scanf("%d",&b[i][j]);
		  }
	}
	 result=multiPlyMatrixes(a,b,rows,cols,cols2);
	 printf("Multiplication of matrix:\n");
	 for (i = 0; i < rows; i++)
	 {
		  for (j = 0; j < cols2; j++)
		  {
			   if (a[i] == NULL)
			   {
				   printf("Not enoufh memory");
				   exit(1);
			   }
			   printf("%d ",result[i][j]);
		  }
		 printf("\n");
	}
	 free(result);
	 result=NULL;
	 return 0;
}
//a function that assigns memory and fills the memory matrix with values//
void BuildMatrix(int*** matrix,int row,int column)
{
		 int i=0,j=0;
		 printf("Enter num rows:");
		 scanf("%d",&row);
		 printf("Enter num columns:");
		 scanf("%d",&column);
		 printf("Enter matrix\n");
		 *matrix=(int**)malloc(row*sizeof(int*));
		 for (i = 0; i < row; i++)
		 {
			  (*matrix)[i]=(int*)malloc(column*sizeof(int*));
			  for (j = 0; j < column; j++)
			  {
				   if ((*matrix)[i] == NULL)
				   {
					   printf("Not enoufh memory");
					   exit(1);
				   }
			  scanf("%d",&(*matrix)[i][j]);
		  }
	 }
}
//a function that receives a pointer and frees memory//
void FreeMatrix(int*** matrix,int row)
{
	 int i;
	 for(i=0;i<row;i++)
	 {
		 free(*matrix);
		 *matrix=NULL;
	 }
}
//a function that accept a two dimensional array and prints the matrix elements in a table shape//
void PrintMatrix(int** matrix,int row,int column)
{
	 int i,j,t;
	 printf("Enter num of rows:\n");
	 scanf("%d",&row);
	 printf("Enter num of column:\n");
	 scanf("%d",&column);
	 matrix=(int**)malloc(row*sizeof(int*));
	 if (matrix == NULL)
	 {
		  printf("Not enoufh memory");
		  exit(1);
	 }
	 printf("Enter num metrix\n");
	 for(i=0;i<row;i++)
	 {
		  matrix[i]=(int*)malloc(column*sizeof(int));
		  if (matrix[i] == NULL)
		  {
			  printf("Not enoufh memory");
			  exit(1);
		  }
		 for(j=0;j<column;j++)
			scanf("%d",&matrix[i][j]);
	 }
	 for(i=0;i<row;i++)
	 {
		  for(j=0;j<column;j++)
			printf("%d ",matrix[i][j]);
		 printf("\n");
	 }
	  for(i=0;i<row;i++)
	 {
		  free(matrix[i]);
		  matrix[i]=NULL;
		  free(matrix);
		  matrix=NULL;
	 }
}
// a function that sorts the array in ascending order//
void AddColumn(int*** matrix,int row,int* column,int* newCol,int rows)
{
	 (*column)++;
	 int k=0,i=0,j=0;
	 for(i=0;i<row;i++)
	 {
		  (*matrix)[i]=realloc((*matrix),1*sizeof(int));
		  for(i=0;i<row;i++)
		  {
			   for(j=(*column)-1;j<(*column);j++)
			   {
				   (*matrix)[i][j]=newCol[k];
				   k++;
				   j++;
			   }
		  }
	 }
}
//a function creates a new matrix is a multiplication of two other matrices//
int** multiPlyMatrixes(int** a, int** b,int size1,int size2,int size3)
{
	 int** multiplication=(int**)malloc(size1*sizeof(int*));
	 if (size2 == size2)
	 {
		  for (int row = 0; row < size1; row++)
		  {
			   multiplication[row]=(int*)malloc(size3*sizeof(int));
			   for (int colIndex = 0; colIndex <size3; colIndex++)
			   {
					for (int col = 0; col <size2; col++)
					{
						multiplication[row][colIndex] = multiplication[row][colIndex] + a[row][col] * b[col][colIndex];
					}
			   }
		  }
	 }
	return multiplication;
	free(a);
	a=NULL;
	free(b);
	b=NULL;
}


