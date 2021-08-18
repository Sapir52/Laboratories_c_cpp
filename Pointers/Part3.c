#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 80
//declare functions//
char** getallnames( int* countNames);
void FreeAllNames(char***names,int countNames);
void PrintAllNames(char** names,int countNames);
void UpdateAllNames(char** names,int countNames);
void SortAllNames(char*** names,int countNames);
//maim program//
int main()
{
	 int countNames;
	 char** names;
	 names=getallnames(&countNames);
	 printf("The array is:%s\n",*names);
	 FreeAllNames(&names,countNames);
	 UpdateAllNames(names,countNames);
	 printf("the update array:\n");
	 PrintAllNames(names,countNames);
	 SortAllNames(&names,countNames);
	 printf("The sort is:\n");
	 PrintAllNames(names,countNames);

	 return 0;
}
//a function that creates an array//
char** getallnames( int* countNames)
{
	 int i,j;
	 char** names=NULL;
	 char num, p;
	 printf("how many names do you want");
	 scanf("%d",&(*countNames));
	 names=(char**)malloc((*countNames +1)*sizeof(char*));
	 for(i=0;i<*countNames;i++)
		names[i]=(char*)malloc(sizeof(char)*80);
	  for(i=0;i<*countNames;i++)
	  {
		  j=0;
		  printf("enter last & first name %d;",i+1);
		  p=getchar();
		  while((num=getc(stdin))!='\n')
		  {
				if(j==0&& p!='\n')
					names[i][j++]=p;
				names[i][j++]=num;
		  }
			names[i][j]='\0';
	  }
	  return names;
}
//a function that frees memory//
void FreeAllNames(char***names,int countNames)
{
	 int i;
	 for(i=0;i<countNames;i++)
	 {
		 free((*names)[i]);
		 (*names)[i]=NULL;
		 free(*names);
		 *names=NULL;
	 }
}
//a function that an array of names//
void PrintAllNames(char** names,int countNames)
{
	 names=NULL;
	 char num, p;
	 int i=0, j=0;
	 printf("how many names do you want?");
	 scanf("%d",&countNames);
	 names=(char**)malloc((countNames +1)*sizeof(char));
	 for(i=0;i<countNames;i++)
		names[i]=(char*)malloc(sizeof(char)*80);
	 for(i=0;i<countNames;i++)
	 {
		  j=0;
		  printf("enter last & first name %d:\n",i+1);
		  p=getchar();
		  while((num=getc(stdin))!='\n')
		  {
				if(j==0&& p!='\n')
					names[i][j++]=p;
				names[i][j++]=num;
		  }
		  names[i][j]='\0';
	      printf("%s\n",names[i]);
	 }
}
//a function that deletes spaces//
void UpdateAllNames(char** names,int countNames)
{
	 char num, p;
	 int i=0, j=0;

	 printf(" how many names do you want?");
	 scanf("%d",&(countNames));
	 names=(char**)malloc((countNames +1)*sizeof(char*));
	 for(i=0;i<countNames;i++)
		names[i]=(char*)malloc(sizeof(char)*80);
	 for(i=0;i<countNames;i++)
	 {
		  printf("enter last & first name %d:\n",i+1);
		  p=getchar();
		  while((num=getc(stdin))!='\n')
		   {
				if(j==0 && p!='\n')
					names[i][j++]=p;
				names[i][j++]=num;
		   }
			names[i][j]='\0';
	  }

	  while (names[i] != '\0')
	  {
		   if (names[i][j] ==' ')
				countNames++;
		   i++;
	  }
	 countNames++;
	 printf("%s\n",names[i]);

}
//a function that sorts the array in ascending order//
void SortAllNames(char*** names,int countNames)
{
		int i,j,p,min=0;
		char arr[80];
		int num, l_num;
		for(i=0;i<countNames-1;i++)
		{
			 for(j=0;j<countNames;j++)
			  {
				  l_num=(*names)[i][0];
				  num=(*names)[i+1][0];
				  if(l_num>num)
				  {
					  strcpy(arr,(*names)[i]);
					  strcpy((*names)[i],(*names)[i+1]);
					  strcpy((*names)[i+1],arr);
				  }
				  else
					   if(l_num==num)
					   {
						   if(strlen((*names)[i+1])<strlen((*names)[i]))
						   {
								min=strlen((*names)[i+1]);
						   }
						   else
						   {
								min=strlen((*names)[i]);
						   }
						   for(p=0;p<min;p++)
						   {
							   l_num=(*names)[i][p];
							   num=(*names)[i+1][p];
							   if(l_num>num)
							   {
									  strcpy(arr,(*names)[i]);
									  strcpy((*names)[i],(*names)[i+1]);
									  strcpy((*names)[i+1],arr);
									  p=min;
							  }
						  }
					  }
			  }
		}
}
