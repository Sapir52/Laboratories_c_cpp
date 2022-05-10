#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constants declaration//
#define NO_ERORR 0
#define SIZE 80
#define FALSE 0
#define TRUE 1
typedef enum {false,true} bool;

// declare functions//
int MaxDigit( int num);
int Equal(int number, int sum);
int func(int number);
float NMember( float a,float d, int ind);
float SumNMember(float a,float d, int ind);
int EvenAndOdd(int *arr,int size);
int CheckString(char *str);
int SameTav(char *str1,char *str2);
void func2 (char *string);
bool isAnyOptionToSteal(int n, int *weights,int size_weights);
// main program//
int main(){

/* function num 1*/
	int num;
	printf("Enter num\n");
	scanf("%d",&num);
	printf("The max digit is:%d\n",MaxDigit(num));

/******************************************************/
/* function num 2*/
	int number, sum, result=0;
	printf("Enter number:\n");
	scanf("%d", &number);
	printf("Enter sum:\n");
	scanf("%d",&sum);
	result=Equal(number,sum);
	if(result==0)
		printf("equal or not equal ?: false\n");
	else
		printf("equal or not equal ?: true\n");

/******************************************************/
/*function num 3*/
	int ind;
	float a,d;
	printf( "Enter first organ of the series:\n");
	scanf("%f",&a);
	printf( "Enter difference of the series:\n");
	scanf("%f",&d);
	printf("Enter index  of the series:\n");
	scanf("%d",&ind);
	printf("The %d organ in the siries:%.1f\n",ind,NMember(a,d,ind));
	printf("The organ sum of the series:%.1f\n",SumNMember(a,d,ind));

/******************************************************/
/*function num 4*/
	int *arr=NULL, size,i=0;
	printf("Enter size of array:\n");
	scanf("%d",&size);
	arr=(int*)malloc(size*sizeof(int));
	if(arr==NULL)
	{
		printf("\nNot enouth memory!\n");
		return -1;
	}
	printf("Enter element of array:\n");
	for(i=0;i<size;i++)
	{
		printf("array[%d]:",i);
		scanf("%d",&arr[i]);
	}
	result=EvenAndOdd(arr,size);
	if(result==0)
		printf("even and odd or not ?: false\n");
	else
		printf("even and odd or not ?: true\n");

/******************************************************/
/*function num 5*/
	char str[SIZE];
	int len=strlen(str);
	printf("Enter str:\n");
	getchar();
	fgets(str,SIZE-1,stdin);
	while((str)[i]!='\n')
		i++;
	(str)[i]='\0';
	if(CheckString(str)==0)
		printf("Not ok string ?: false\n");
	if(CheckString(str)==1)
		printf("Ok string ?: true\n");

/******************************************************/
/*function num 6*/

	char str1[SIZE],str2[SIZE];
	printf("Enter string1:\n");
	fgets(str1,SIZE-1,stdin);
	while((str1)[i]!='\n')
		i++;
	(str1)[i]='\0';
	printf("\nEnter string2:\n");
	fgets(str2,SIZE-1,stdin);
	while((str2)[i]!='\n')
		i++;
	(str2)[i]='\0';
	printf("The numbers of same element in two string is:%d", SameTav(str1,str2)-1);

/******************************************************/

	return  NO_ERORR;

}

/******************************************************/
/* function num 1*/
int MaxDigit( int num)
{
	int digit1=0,digit2=0,NewNum=0;
	if(num==0)
	{
		return FALSE;
	}
	else if( num>0)
	{
		digit1=num%10;
		digit2=MaxDigit(num/10);
		if(digit1>digit2)
			return digit1;
		else
			return digit2;
	}
	else // num<0 //
	{
		NewNum=num*(-1);
		digit1=NewNum%10;
		digit2=MaxDigit(NewNum/10);
		if(digit1>digit2)
			return digit1;
		else
			return digit2;
	}
}
/******************************************************/

/* function num 2*/
int Equal(int number, int sum)
{
	if(func(number)==sum)
		return TRUE;
	else
		return FALSE;

}
//A function that returns the sum of digits of Number//
int func(int number)
{
	int count1=0;
	if(number<0)
		return -1;
	else if(number>0)
		count1+=number%10+func(number/10);
}
/******************************************************/

/* function num 3*/
float NMember( float a,float d, int ind)
{
	if(ind==1)
		return a;
	a=a+d;
	ind=ind-1;
	return (NMember(a,d,ind));
}
float SumNMember(float a,float d, int ind)
{
	float num=0,sum=0,totalSum=0;
	if(ind==1)
		return a;
	else if(ind>1)
	{
		num=NMember(a,d,ind);
		sum=SumNMember(a,d,ind-1);
		totalSum=sum+num;
	}
	return totalSum;
}


/******************************************************/

/* function num 4*/
int EvenAndOdd(int *arr,int size)
{
	if(size==1)
		return TRUE;
	int check1=arr[size-1]%2;
	int check2=arr[size-2]%2;
	if(check1 != check2)
		return EvenAndOdd(arr,size-1);
	return FALSE;
}
/******************************************************/

/* function num 5*/
int CheckString(char *str)
{
	if((*str)=='\0')
		return 1;

	if((*str)>='a'&& (*str)<='z')
		return CheckString(++(str));
	if((*str)>='A'&& (*str)<='Z')
		return CheckString(++(str));
	if((*str)<'a'|| (*str)>'z')
		return 0;

}
/******************************************************/

/* function num 6*/
int SameTav(char *str1,char *str2)
{
	int i=0,j=0;
	func2(str1);
	func2(str2);
	if(*str1=='\0' || *str1=='\0')
		return 1;
	if(*str1==*str2)
		return 1+SameTav(str1+1,str2+1);
	else
		SameTav(str1+1,str2+1);
}

//A function that turns all letters in a string into smaller ones//
void func2 (char *string)
{
	int i;
	if((*string)=='\0')
		return;
	if((*string)>='A' && (*string)<='Z')
		(*string)+=('a'-'A');
	func2 (string+1);
}
/******************************************************/
