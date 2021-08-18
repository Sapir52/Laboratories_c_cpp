#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//declare functions//
char* CreateString(char* string1,char* string2);
int* BuildArray(int* size);
void PrintArray(int* group,int Size);
int* MergeTwoArrays(int* arr1,int size1,int* arr2,int size2,int* size3);
//maim program//
int main()
{
		 char* string1;
		 char* string2;
		 char* tmp;
		 int size1,size2,i=0,j=0,p=0,k=0;
		 printf("Enret number 1 of ints\n");
		 scanf("%d", &size1);
		 string1=(char*)malloc(size1*sizeof(int));
		 if (string1 == NULL)
		 {
				  printf("Not enoufh memory");
				  exit(1);
		 }
		 printf("enter string1\n");
		 scanf("%s",string1);
		 printf("Enret number 2 of ints\n");
		 scanf("%d", &size2);
		 string2=(char*)malloc(size2*sizeof(int));
		 if (string2 == NULL)
		 {
			  printf("Not enoufh memory");
			  exit(1);
		 }
		 printf("enter string2\n");
		 scanf("%s",string2);
		 tmp=CreateString(string1,string2);
		 for(i=0;i<size1;i++)
		 {
			 printf("%c%s",string1[i],tmp);
		 }
		 free(string1);
		 string1=NULL;
		 free(string1);
		 string1=NULL;

		 int size,s=0;
		 int* array=NULL;
		 array=BuildArray(&size);
		 printf("%d\n",array[s]);
		 free(array);
		 array=NULL;

		 int* group;
		 int Size;
		 PrintArray(group,Size);

		 printf("\nEinter size1");
		 scanf("%d",&size1);
		 int* arr1=NULL;
		 arr1=(int*)malloc((size1)*sizeof(int));
		 if(arr1==NULL)
		 {
			 printf("Not enoufh memory");
			 exit(1);
		 }
		 printf("Enter array1\n");
		 scanf("%d",&arr1[i]);
		 printf("\nEinter size2");
		 scanf("%d",&size2);
		 int* arr2=NULL;
		 arr2=(int*)malloc((size2)*sizeof(int));
		 if(arr2==NULL)
		 {
			 printf("Not enoufh memory");
			 exit(1);
		 }
		 printf("Enter array2\n");
		 scanf("%d",&arr2[j]);
		 int size3;
		 size3=size1+size2;
		 int* arr3=NULL;
		 arr3=MergeTwoArrays(arr1,size1,arr2,size2,&size3);
		 printf("enter marge array:");
		 printf("%d\n",arr3[k]);
		 free(arr1);
		 arr1=NULL;
		 free(arr2);
		 arr2=NULL;

		 return 0;
}
//a function that accept two strings and creates a new string//
char* CreateString(char* string1,char* string2)
{
		 int p;
		 char* tmp=(char*)malloc(sizeof(int)*(strlen(string2)+1));
		 for(;*string2!='\0';string2++,p++)
		  *(tmp+p)=*string2;
		 string2=tmp;
		 return tmp;
		 free(tmp);
		 tmp=NULL;
}
//a function that recevies an array and return it//
int* BuildArray(int* size)
{
		 int s=0;
		 printf("\nEinter size");
		 scanf("%d",size);
		 int* array;
		 array=(int*)malloc((*size)*sizeof(int));
		 if(array==NULL)
		 {
			 printf("Not enoufh memory");
			 exit(1);
		 }
		 printf("Enter array\n");
		 scanf("%d",&array[s]);
		 return array;
}

//a function presses the array elements//
void PrintArray(int* group,int Size)
{
		 int i;
		 printf("Einter size");
		 scanf("%d",&Size);
		 group=(int*)malloc(Size*sizeof(int));
		 if(group==NULL)
		 {
			 printf("Not enoufh memory");
			 exit(1);
		 }
		 if(Size==0)
		 {
			  printf("()");
		 }
		 else
		 {
			 printf("Enter array");
			 scanf("%d",&group[i]);
			 printf("(");
			 for(i=0;i<Size-1;i++)
			 {
				   printf("%d",i+1);
				   printf(",");
			 }
			 printf("%d)",Size);
		 }
}
//a function that returns a new array //
int* MergeTwoArrays(int* arr1,int size1,int* arr2,int size2,int* size3)
{
		 int i,j,k;
		 int* arr3=NULL;
		 arr3=(int*)malloc((*size3)*sizeof(int));
		 k=j=i=0;

		 while(i<size1 && j<size2)
		 {
			 if(arr1[i]<=arr2[j])
			  {
				  arr3[k]=arr1[i];
				  i++;
				  k++;
			  }
			  else
			  {
				   arr3[k]=arr2[j];
				   j++;
				   k++;
			  }
		 }
	 while(i<size1)
	 {
		  arr3[k]=arr1[i];
		  i++;
		  k++;
	 }
	 while(j<size2)
	 {
		  arr3[k]=arr2[j];
		  j++;
		  k++;
	 }

	 return arr3;
}
