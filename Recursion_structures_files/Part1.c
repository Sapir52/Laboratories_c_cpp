#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size1 80
//declare functions//
void print(int begin,int end,int skip);
void latin_letters(char* str);
int lettle_latin(char* str);
int one_mis(char* str);
int positAndNeg(int* arr,int k);
int fibonacci(int* arr,int size2);
int odd_num(long num);
//maim program//
int main(){ 
 
	 char str[size1];
	 printf("Enter string:\n");
	 fgets(str,size1-1,stdin);
	 puts(str);

	 int begin,end,skip;
	 printf("Enter nums of begin, end,skip\n");
	 scanf("%d%d%d",&begin,&end,&skip);
	 print(begin,end,skip);
 
	 latin_letters(str);
	 lettle_latin(str);
	 printf("\nlettel latin is:%d\n",lettle_latin(str));
	 one_mis(str);
	 printf("one mis is:%d\n",one_mis(str));

	 int size2,k,i;
	 int* arr=NULL;
	 printf("Enter size");
	 scanf("%d",&size2);
	 printf("%d\n",size2);
	 printf("Enter array");
	 arr=(int*)malloc(size2*(sizeof(int)));
	 for(i<=0 && i>0; i<size2;i++)
	 {
		  if(arr==NULL)
		  {
			   printf("No enoufh memory");
			   exit(1);
		  }
		 scanf("%d",&arr[i]);
		 printf("%d\n",arr[i]);
	 }
	 fibonacci(arr,size2);
	 printf("the array is fibonacci?%d\n",fibonacci(arr,size2));
	 positAndNeg(arr,k);
	 printf("the array is pos&neg?%d\n",positAndNeg(arr,k));

	 long num;
	 int index;
	 printf("Enter num");
	 scanf("%ld",&num);
	 printf("%ld\n",num);
	 odd_num(num);
	 printf("sum odd num is:%d\n",odd_num(num));

	 free(arr);
	 arr=NULL;
	 return 0;
}
//Program for recursion function num 1//
void print(int begin,int end,int skip)
{
	 printf("%d",begin);
	 begin=begin+skip;
	 if(begin<=end)
	 {
		  printf(",");
		  print(begin,end,skip);
	 }
}
//Program for recursion function num 2//
void latin_letters(char* str)
{ 
	 int i=0;
	 if(((*str)>='a' && (*str)<='z') || ((*str)>='A' && (*str)<='Z'))
	 {
		  printf("latin letters:%s\n",str);
	 }
	 if((*str)=='\n')
	 {
		 latin_letters(str);
	 }
}
//Program for recursion function num 3//
int lettle_latin(char* str)
{
	 if((*str)=='\n')
	 {
		return 1;
	 }
	 if((*str)<'a' || (*str)>'z')
	 {
		return 0;
	 }
	 lettle_latin(++(str));
}
//Program for recursion function num 4//
int one_mis(char* str)
{
	 if((*str)==('\n'))
	 {
		return 0;
	 }
	 if((*str)<'a'|| (*str)>'z')
	 {
		return 1;
	 }
	 one_mis(++(str));
}
//Program for recursion function num 5//
int fibonacci(int* arr,int size2)
{
	 if(size2<=2)
	 {
		return 1;
	 }
	 if(arr[size2-1]-arr[size2-2]==arr[size2-3])
	 {
		fibonacci(arr,size2-1);
	 }
	 else
	 {
		return 0;
	 }
}
//Program for recursion function num 6//
int positAndNeg(int* arr,int k)
{
	 if(arr[k]>0 && arr[k+1]<0)
	 {
		return 1;
	 }
	 else if(arr[k]<0 && arr[k+1]>0)
	 {
		return 1;
	 }
	 else
	 {
		return 0;
	 }
}
//Program for recursion function num 7//
int odd_num(long num)
{
	 int index =0;
	 if(num<=index)
	 {
		return index;
	 }
	 if((num%2)==1)
	 {
		return (num%10+odd_num(num/10));
	 }
	 else
	 {
		return (odd_num(num/10));
	 }
}


