#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20

// Structures declarations //
 typedef struct{
	int day, month,year;
}date;

 typedef struct{
	 char* name;
	 date birthdate;
	 int num_of_courses;
	 char** courses;
}lecturer;

// Functions declarations //
void course_lecturers(lecturer *lect1,char* N_cours,int mis);
void common(lecturer *lect1,char* lect_1, char* lect_2,int mis);

//maim program//
int main(){
	 int mis,i;
	 printf("How many  numbers lect");
	 scanf("%d",&mis);
	 char buffer[SIZE];
	 lecturer *lect1=NULL;
	 lect1=(lecturer*)malloc(mis*sizeof(lecturer));
	 if(lect1==NULL){exit(1);}
	 getchar();
	 for(i=0;i<mis;i++)
	 {
		  printf("\nEnter num (char) lect: \n");
		  fgets(buffer,SIZE-1,stdin);
		  int len=strlen(buffer);
		  if(buffer[len-1]=='\n')
				buffer[len-1]='\0';
		  (*lect1).name=(char*)malloc(len*sizeof(char)+1);
		  strcpy((*lect1).name,buffer);
		  printf("\nlect num is:%s\n",(*lect1).name);
		  printf("the date birthdate is:\n");
		  scanf("%d%d%d",&(*lect1).birthdate.day, &(*lect1).birthdate.month, &(*lect1).birthdate.year);
		  printf("\nEnter number of courses: ");
		  scanf("%d",&(*lect1).num_of_courses);
		  printf("%d\n",(*lect1).num_of_courses);
		  int p;
		  (*lect1).courses=(char**)malloc(sizeof(char*)*SIZE);
		  if((*lect1).courses==NULL)
				{exit(1);}
		  getchar();
		  for(p=0;p<(*lect1).num_of_courses;p++)
		  {
			  printf("\nEnter num (char) of course: \n");
			  fgets(buffer,SIZE-1,stdin);
			  int len=strlen(buffer);
			  if(buffer[len-1]=='\n')
					buffer[len-1]='\0';
			  (*lect1).courses[p]=(char*)malloc(len*sizeof(char)+1);
			  strcpy((*lect1).courses[p],buffer);
			  printf("\nthe name course %d:",p+1); 
			  printf( "%s\n",(*lect1).courses[p]);
		  }
	}
	  int len;
	  char* N_cours;
	  char buffer2[SIZE];
	  printf("\nEnter N_cours:\n");
	  fgets(buffer2,SIZE-1,stdin);
	  len=strlen(buffer2);
	  if(buffer2[len-1]=='\n')
			buffer2[len-1]='\0';
	  N_cours=(char*)malloc(len*sizeof(char)+1);
	  if(N_cours==NULL)
			{exit(1);}
	  strcpy((N_cours),buffer2);
	  printf("\nN_cours is:%s\n",N_cours);
	  course_lecturers(lect1,N_cours,mis);
  	//--------------------------------------------------------------//
	  char*lect_1, *lect_2;
	  char buffer3[SIZE];
	  char buffer4[SIZE];
	  printf("\nEnter num lect_1\n"); 
	  fgets(buffer3,SIZE-1,stdin);
	  len=strlen(buffer3);
	  if(buffer3[len-1]=='\n')
			buffer3[len-1]='\0';
	  lect_1=(char*)malloc(len*sizeof(char)+1);
	  if(lect_1==NULL)
			{exit(1);}
	  strcpy((lect_1),buffer3);
	  printf("\nlect_1:%s\n",lect_1);
	  printf("\nEnter num lect_2\n");
	  fgets(buffer4,SIZE-1,stdin);
	  len=strlen(buffer4);
	  if(buffer4[len-1]=='\n')
			buffer4[len-1]='\0';
	  lect_2=(char*)malloc(len*sizeof(char)+1);
	  if(lect_2==NULL)
			{exit(1);}
	  strcpy((lect_2),buffer4);
	  printf("\nlect_2:%s\n",lect_2);
	  common(lect1,lect_1, lect_2, mis);
 	//--------------------------------------------------------------//
	  free((lect1)[i].name);
	  (lect1)[i].name=NULL;
	  free((lect1)[i].courses);
	  (lect1)[i].courses=NULL;
	  free (lect1);
	  lect1=NULL;
	  return 0;
}

//punction num 1//
void course_lecturers(lecturer *lect1,char* N_cours,int mis)
{
	 int i,j;
	 for( i=0;i<mis;i++)
	 {
		  for(j=0;j<lect1[i].num_of_courses;j++)
		  {
			   if(strcmp(N_cours,(lect1)[i].courses[j])==0)
					printf("\n%s the lect1:%s\n",(lect1)[i].name,N_cours);
		  }
	 }
} 
//punction num 2//
void common(lecturer *lect1,char* lect_1, char* lect_2,int mis)
{
	 int i,j;
	 for( i=0;i<mis;i++)
	 {
		  for(j=0;j<lect1[i].num_of_courses;j++)
		  {
			   if(strcmp(lect_1,(lect1)[i].courses[j])==strcmp(lect_2,(lect1)[i].courses[j])==0)
					printf("\n courses name is:%s\n",(lect1)[i].courses[j]);
		  }
	 }
}

