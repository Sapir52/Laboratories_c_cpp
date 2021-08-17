#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constants declaration//
#define NO_ERORR 0

// declare functions//
int init(int ***vectors, int **sizes, int size);
int Set( int **vectors,int *sizes, int index, int *tmp, int tmp_size);
int append(int **vectors, int *sizes, int index, int *tmp,int tmp_size);
int drop(int **vectors, int *sizes, int index, int num);
void print(int **vectors, int *sizes, int size);
void free_all(int ***vectors, int **sizes, int size);
void Choich(int** vectors,int* sizes,int size,int choich);
// main program//
int main(){

	int **vectors=NULL, *sizes=NULL, size, choich ,num;
	printf("Enter number of vecturs:\n");
	scanf("%d", &size);
	do{
		init(&vectors,&sizes,size);
	}while(num<=1 && num>0);

	printf("\nEnter choich:\n1-set\n2-append\n3-drop\n4-print\n5-quit\n");
	scanf("%d",&choich);
	Choich(vectors,sizes,size,choich);
	while(choich==5)
	{
		Choich(vectors,sizes,size,choich);
	}

	do{
		printf("\nEnter choich:\n1-set\n2-append\n3-drop\n4-print\n5-quit\n");
		scanf("%d",&choich);
		Choich(vectors,sizes,size,choich);

		while(choich==5)
		{
			Choich(vectors,sizes,size,choich);
		}

	}while(*sizes!=0 || choich!=5);
	
	return NO_ERORR;
}

//A punction to iullstrat switch//
void Choich(int** vectors,int* sizes,int size,int choich)
{
	int index, num,i,tmp_size, *tmp=NULL;
	switch(choich) //Switch that work accotding to the option//
	{
		case 1:
		{
			printf("Enter size of array\n");
			scanf("%d",& tmp_size);
			printf("Enter array\n");
			tmp= (int*)malloc((tmp_size)* sizeof (int));
			if(tmp==NULL)
			{
				printf("\nNot enouth memory!\n");
				exit(1);
			}
			for(i=0;i<tmp_size;i++)
			{
				scanf("%d",&tmp[i]);
			}
			if(index<=size)
			{
				printf("Enter index\n");
				scanf("%d",&index);
			}
			else
			{
				do{
					printf("Enter index\n");
					scanf("%d",&index);
				}while(index>size);
			}

			Set(vectors,sizes,index,tmp,tmp_size);
			print(vectors,sizes,size);
			break;
		}
		case 2:
		{
			printf("Enter size of array\n");
			scanf("%d",& tmp_size);
			printf("Enter array\n");
			tmp= (int*)malloc((tmp_size)* sizeof (int));
			if(tmp==NULL)
			{
				printf("\nNot enouth memory!\n");
				exit(1);
			}
			for(i=0;i<tmp_size;i++)
			{
				scanf("%d",&tmp[i]);
			}
			if(index<=size)
			{
				printf("Enter index\n");
				scanf("%d",&index);
			}
			else
			{
				do{
					printf("Enter index\n");
					scanf("%d",&index);
				}while(index>size);
			}
			append(vectors,sizes,index,tmp,tmp_size);
			print(vectors,sizes,size);
			break;

		}

		case 3:
		{
			printf("Enter num\n");
			scanf("%d",&num);
			if(index<=size)
			{
				printf("Enter index\n");
				scanf("%d",&index);
			}
			else
			{
				do{
					printf("Enter index\n");
					scanf("%d",&index);
				}while(index>size);
			}
					
			drop(vectors, sizes,  index, num);
			print(vectors,sizes,size);
			break;
		}

		case 4:
		{
			
			print(vectors,sizes,size);
			break;
		}

		case 5:
		{
			free(tmp);
			tmp=NULL;
			free_all(&vectors,&sizes,size);
			break;
		}

	}

}

//A function that creates an array of zeros and a array of pointers to NULL//
int init(int ***vectors, int **sizes, int size)
{
	int  i;
	(*sizes)= (int*)malloc((size)* sizeof (int));
	
	if(*sizes==NULL)

	{
		printf("\nNot enouth memory!\n");
		exit(1);
	}
	for(i=0;i<size;i++)
	{
		(*sizes)[i]=0;
		printf("%d\n",(*sizes)[i]);
	}	

	
	(*vectors)=(int**)malloc((size) * sizeof(int));
	if(*vectors==NULL)
	{
		printf("\nNot enouth memory!\n");
		exit(1);
	}
	
	for(i=0;i<size;i++)
	{
		(*vectors)[i]=NULL;
	}

}	
	
//A function that releases a vector instead of an index and creates a new vector//	
int Set( int **vectors,int *sizes, int index, int *tmp, int tmp_size)
{
	int i=0;
	if(vectors[index]!=NULL)
	{
		free(vectors[index]);
		vectors[index]=NULL;
	}
	vectors[index]=(int*)malloc(tmp_size*sizeof(int));
	for(i=0;i<tmp_size+1;i++)
	{
		vectors[index][i]=tmp[i];
	}
	sizes[index]=tmp_size;
}

// A function that adds an array to the end of a vector rather than an index//
int append(int **vectors, int *sizes, int index, int *tmp,int tmp_size)
{
	int i,j=0;
	(vectors)[index]=realloc((*vectors),tmp_size*sizeof(int));
	for(i=sizes[index];i<sizes[index]+tmp_size;i++)
	{
		vectors[index][i]=tmp[j++];
	}
	sizes[index]=sizes[index]+tmp_size;
}

//A function that deletes the num number from a vector rather than an index//
int drop(int **vectors, int *sizes, int index, int num)
{
	int i=0,j,flag=0;
	for(i=0;i<sizes[index]-1;i++)
	{
		if(vectors[index][i]==num)
		{
			flag=1;
			j=i;
			break;
		}
	}
	for(;i<sizes[index]-1;i++)
	{
		if(flag==1)
		{
		
			sizes[index]=sizes[index]-1;
			for(i=j;i<sizes[index];i++)
			{

			vectors[index][i]=vectors[index][i+1];
			}
		
		}

	}
	
}

//A function that prints all vectors//
void print(int **vectors, int *sizes, int size)
{


	int i,j;
	for(i=0;i<size;i++)
	{
		printf("[%d]={",i);
		if(vectors[i]!=NULL)
		{
				
				for(j=0;j<sizes[i];j++)
				{
					printf("%d",(vectors)[i][j]);
				
				}
			
		}
		printf("}\n");
	}
}

//A function that releases all the dynamic memory of the arrays//
void free_all(int ***vectors, int **sizes, int size)
{
	int i,j;
	free(*vectors);
	*vectors=NULL;
	
	free(*sizes);
	(*sizes)=NULL;
}




