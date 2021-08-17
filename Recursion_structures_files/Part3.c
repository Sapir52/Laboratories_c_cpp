#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define size 8
//prodram related files//
// Structure declarations //
typedef struct
{
 long licens_plate;
 char model[SIZE];
 int year_of_prod, price;
} cars;
 cars car1;
 cars* cars_date;

//maim program//
int main(){
 FILE* fp;
 int i;
 fp=fopen("cars.txt","r");
 if(fp==NULL)
 {
  printf(" unable to open file \n");
  exit(1);
 }
 cars*cars_date =(cars*)malloc(size*sizeof(cars));

 for(i=0;i<size;i++)
 {
 fscanf(fp,"%ld %s %d %d \n",&cars_date[i].licens_plate, cars_date[i].model, &cars_date[i].year_of_prod,&cars_date[i].price);
 }

 printf("Enter choice model\n");
 scanf("%s",car1.model);
 printf("Enter choice year\n");
 scanf("%d",&car1.year_of_prod);
 printf("Enter choice price\n");
 scanf("%d",&car1.price);
 
 for(i=0;i<size;i++)
 {
 if((strcmp(car1.model,cars_date[i].model)==0) && car1.price>=cars_date[i].price && car1.year_of_prod<=cars_date[i].year_of_prod)
  {
  printf("%ld %s %d %d\n",cars_date[i].licens_plate, cars_date[i].model, cars_date[i].year_of_prod, cars_date[i].price);
  }
 else
   printf("Not car");
   break;
 }
 fclose(fp);
 return 0;
}
