#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constants declaration//
#define NO_ERORR 0
#define SIZE 80
// declare functions//
char* EvenStr(char *str);
void Remove(char* In, char* Ou);
char* IndEven(char*);
// main program//
int main(){
	char *str=NULL, buffer[SIZE],*res=NULL,*res2=NULL;
	int i,len;
	printf("Enter string\n");
	fgets(buffer,SIZE-1,stdin);
	strlen(buffer);
	str=(char*)malloc(len+1);
	if(str==NULL)
	{
		printf("Not enoufh memory\n");	
		exit(1);
	}
	strcpy(str,buffer);
	res=EvenStr(str);
	printf("The New string is:%s\n",res);

	Remove(str,str);
	res2=IndEven(str);
        printf("index even string is :%s\n",res2);
	free(str);
	str=NULL;
	return NO_ERORR;
}

//A function that accepts a string, and creates and returns a string containing only words of even length//
char* EvenStr(char *str)
{
	char *even=NULL;
	int i,j,k,p=0,countEeven=0, len=strlen(str);
	for(i=0, j=0; j<len; j++)
	{
		if(str[j]==' ' || j==len-1)
		{
			if(j<len)
			{
				k=j-i; 
				if(k%2==0) 
					countEeven++;
				
			}
			i=j+1;
		}
	
	}	
	if(countEeven==0)
		return NULL;
	even=(char*)malloc((countEeven)*sizeof(char));
	if(even==NULL)
	{
		printf("Not enoufh memory\n");	
		exit(1);
	}
	

	for(i=0, j=0; j<len; j++)
	{
		if(str[j]==' ' || j==len-1)
		{
			if(j<len)
			{
				k=j-i;
				for(;k%2==0 && i<j+1;i++)
				{
					even[p++]=str[i];
					if(k%2!=0)
						i--;
				}
			i=j+1;
			}
		}
	
	}
	return even;

}

//A function that accepts a string and returns words that are even in the parameter//
char* IndEven(char* str)
{
	int i,p=0, j=0,Count1=0,Count2=0;
	char buffer[SIZE];
	for(i=0; i<strlen(str)+1;i++)
	{
		if(str[i]!= ' ' && str[i]!= '\0')
		{
			buffer[j++]=str[i];
			Count1++;
		}
		else
		{
			Count2++;
			if(Count2%2!=0)
			{
				if(str[i]=='\0')
				{
					if(str[i]=='\0')
					{
						for(int p=(j-Count2);p<=j;p++)
							buffer[p]=0;
					}
				}

				j=j-Count1;
				Count1=0;
			}
			else
			{
				buffer[j++]=' ';
				Count1=0;
			}
		}
	}
	char* NewStr=(char*)malloc(strlen(buffer)+1);

	if(NewStr==NULL)
	{
		printf("Not enoufh memory\n");	
		exit(1);
	}
	strcpy(NewStr,buffer);
	return NewStr;
}

//A function that eliminates unnecessary spaces in a string//
void Remove(char* In, char* Ou)

{
	int IndIn= 0,IndOu = 0;    
	while(In[IndIn] != '\0')
	{
		Ou[IndOu] =  In[IndIn];
		if(In[IndIn] == ' ')
		{
			while(In[IndIn + 1] == ' ')
				IndIn++;
		}
		IndOu++;
		IndIn++; 
	}
	Ou[IndOu] = '\0';

}

