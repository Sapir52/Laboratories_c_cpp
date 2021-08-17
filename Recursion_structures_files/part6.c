#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constants declaration//
#define NO_ERORR 0
#define SIZE 100
// declare function//
void TheFunction(FILE *Fin,FILE *Fout);


/*********************************************/
// main program//
int main(){

	FILE *Fin,*Fout;
	Fin=fopen("numbers.txt","r");
	if(!Fin)
	{
		printf("Can't open file\n");
		exit(0);
	}

	Fout=fopen("statistic.txt","w");
	if(!Fout)
	{
		printf("Can't open file\n");
		fclose(Fin);
		exit(0);
	}
	
	
	TheFunction(Fin,Fout);	

	
	fclose(Fout);
	fclose(Fin);

return NO_ERORR; 
}
/*********************************************/

void TheFunction(FILE *Fin,FILE *Fout)
{
	int frequency=0,mis=0,least=0, count=0,most=0,indMost,indLeast=0,index,min=0, max=0;
	if (fscanf(Fin,"%d", &mis) !=EOF)
	{
		frequency= mis;
		min = max= mis ;
		while (fscanf( Fin, "%d", &mis)!=EOF)
		{
			if(frequency==mis)
			{
				count++;
			}
			if(count>most) //Find the most common number in a file//
			{
				most=count;
				indMost=mis;
			}
			if(count<=least) //Finding the most rare number in a file//
			{

				least=count;
				indLeast=mis;

			}
		 	if (mis > max) //Find the maximum number in a file//
			{
				max = mis;
			}
			else if (mis < min) //Find the minimum number in a file//
			{
				min = mis;
			}
		}
	}
	fprintf(Fout,"%d\n%d\n",indMost,indLeast); //Printing data into a file//
	fprintf(Fout,"%d\n%d\n",max,min);
}

