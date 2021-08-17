#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constants declaration//
#define SIZE 30
#define SZ 6
#define size 20
#define siz 9
#define NO_ERORR 0
/********************************/

// declare structs//
typedef struct{

	int day,month, year;

}Date;

/********************************/

typedef struct{
	char NumbPassport[siz];
	char Name[SIZE], LastName[SIZE];

}Passenger;

/********************************/

typedef struct{
	char FlightCode[SZ];
	char* distination;
	Date Flig;
	Passenger* Passeng;
	int NumbPasseng;

}Flight;

/********************************/

// declare functions//
void InitDate( Date* Pdata);
void InitPassenger( Passenger* Ppasseng);
void InitFlight( Flight	*PFlig);
void PassengersOfFlight(Flight *PFlig,int NumbF,int dayF,int monthF,int yearF);
char* PopularDestination(Flight *PFlig,int NumbF);
int FlightsByYear(Flight *PFlig,int NumbF,int TheYear);

/********************************/

// main program//
int main(){

	Flight *PFlig=NULL;
	int NumbF,i;
	int TheYear, dayF, monthF,yearF;

	printf("Enter number of Flights:\n");
	scanf("%d",&NumbF);

	PFlig=(Flight*)malloc(NumbF* sizeof(Flight));
	if(PFlig==NULL)
	{
		printf("\nNot enouth memory!\n");
		return -1;
	}

	for(i=0;i<NumbF;i++)
	{
		InitFlight(&PFlig[i]);
	}
	//for function PassengersOfFlight//
	printf("Enter day Flight:\n");
	scanf("%d",&dayF);
	printf("Enter month Flight:\n");
	scanf("%d",&monthF);
	printf("Enter year Flight:\n");
	scanf("%d",&yearF);
	PassengersOfFlight(PFlig,NumbF,dayF, monthF,yearF);

	/********************************/
	//for function PopularDestination//
	printf("\nThe popular destination is:%s",PopularDestination(PFlig,NumbF));

	/********************************/
	//for function FlightsByYear//
	printf("\nEnter choich your year:");
	scanf("%d",&TheYear);
	printf("The count flight is:%d",FlightsByYear(PFlig,NumbF,TheYear));

	/********************************/

	//Memory relese//
	for(i=0;i<NumbF;i++)
	{
		free(PFlig[i].distination);
		PFlig[i].distination=NULL;

		free(PFlig[i].Passeng);
		PFlig[i].Passeng=NULL;
	}
	free(PFlig);
	PFlig=NULL;

	return NO_ERORR; 
}

/*********************************************************/

//A function that initializes a date structure//
void InitDate( Date* Pdata)
{

	printf("\nEnter day:\n");
	scanf("%d",&Pdata->day);

	if((Pdata->day)>30)
	{
		do{
			printf("Enter anter day:\n");
			scanf("%d",&Pdata->day);
		}while((Pdata->day)>30);
	}

	printf("\nEnter month:\n");
	scanf("%d",&Pdata->month);

	printf("\nEnter year:\n");
	scanf("%d",&Pdata->year);

	if((Pdata->year)<=2000)
	{
		do{
			printf("Enter anter year:\n");
			scanf("%d",&Pdata->year);
		}while((Pdata->year)<=2000);
	}

}

/*********************************************************/

//A function that initializes a passenger structure//
void InitPassenger( Passenger* Ppasseng)
{
	printf("\nEnter number passport of passenger:\n");
	getchar();
	scanf("%s",Ppasseng->NumbPassport);

	printf("\nEnter element of name:\n");
	getchar();
	scanf("%s",Ppasseng->Name);

	printf("\nEnter element of last name:\n");
	getchar();
	scanf("%s",Ppasseng->LastName);
}

/*********************************************************/
//A function that initializes a flight structure//
void InitFlight( Flight *PFlig)
{
	int i,j,k,len;
	char buffer[SZ],buffer1[size];

	printf("\nEnter element of Flight Code:\n");
	getchar();
	scanf("%s",buffer);
	for(i=0;i<SZ;i++)
	{
		if((buffer[i]>='a') && (buffer[i]<='z'))
		{
			do{
				printf("\nEnter anter element of Flight Code:\n");
				getchar();
				scanf("%s",buffer);
			}while((buffer[i]>='a' && buffer[i]<='z'));
		}
	}
	strcpy(	PFlig->FlightCode,buffer);
 	/******************************/

	printf("\nEnter element of distination:\n");
	getchar();
	fgets(buffer1,size-1,stdin);
	if(len>0 && buffer1[len-1]=='\n')
		buffer1[len-1]='\0';
	len=strlen(buffer1);

	for(j=0;j<len;j++)
	{
		if((buffer1[j]>='a') && (buffer1[j]<='z'))
		{
			do{
				printf("\nEnter anter element of distination:\n");
				getchar();
				fgets(buffer1,size-1,stdin);
			}while((buffer1[j]>='a') && (buffer1[j]<='z'));
		}
	}


	PFlig->distination=(char*)malloc((len+1)*sizeof(char));
	if(PFlig->distination==NULL)
	{
		printf("\nNot enougth memory!\n");
		exit(1);
	}
	strcpy(PFlig->distination,buffer1);
	/******************************/

	InitDate(&PFlig->Flig);

	printf("\nEnter number of passenger:\n");
	scanf("%d",&PFlig->NumbPasseng);

	PFlig->Passeng=(Passenger*)malloc((PFlig->NumbPasseng)*sizeof(Passenger));
	for(k=0; k<PFlig->NumbPasseng; k++)
	{
		InitPassenger(&PFlig->Passeng[k]);
	}

}

/*********************************************************/

//A function that prints information about passengers on a particular date//
void PassengersOfFlight(Flight *PFlig,int NumbF,int dayF,int monthF,int yearF)
{
	int i,j;
	for(i=0;i<NumbF;i++)
	{
		for(j=0; j<PFlig[i].NumbPasseng; j++)
		{
			if((PFlig[i].Flig.day==dayF)&&(PFlig[i].Flig.month==monthF)&&(PFlig[i].Flig.year==yearF))	
			{
				printf("The name:%s\n",PFlig[i].Passeng[j].Name);
				printf("The last name:%s\n",PFlig[i].Passeng[j].LastName);
				printf("The number passport:%s\n",PFlig[i].Passeng[j].NumbPassport);
				printf("The flight code:%s\n",PFlig[i].FlightCode);
				printf("The distination:%s\n",PFlig[i].distination);
				
			}

		}
	}
}

				
/*********************************************************/
//A function that returns a most popular target//
char* PopularDestination(Flight *PFlig,int NumbF)
{
	int i,j,count=0, maxcount=0,ind=0;
	for(i=0;i< NumbF;i++)
	{
		for(j=i+1;j<NumbF;j++)
		{
			if(strcmp(PFlig[i].distination,PFlig[j].distination)==0)
				count++;
		}
		if(count>maxcount)
		{
			maxcount=count;
			ind=i;
		}

	}
	return PFlig[ind].distination;
}

/*********************************************************/
//A function that returns the amount of flights each year//
int FlightsByYear(Flight *PFlig,int NumbF,int TheYear)
{
	int i, count=0;
	for(i=0;i< NumbF;i++)
	{
		if((PFlig)[i].Flig.year==TheYear)
		{
			count++;
		}
	}
	return count;

}

/*********************************************************/
