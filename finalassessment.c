#include<stdio.h>
#include<stdlib.h>
struct student{
int id;
char name[100];
char course[100];
float percentage;
};
struct Admin{
struct student s[10];
};
void read(struct Admin *ptr)
{
    FILE *fptr;
    fptr=fopen("student","r");
    int i=0;
    printf("\n===================student details===================\n");
    printf("\n**********************************************************\nID\tName\tCourse\tPercentage\n**********************************************************\n");
    while(fscanf(fptr,"%d %s %s %f",&ptr->s[i].id,ptr->s[i].name,ptr->s[i].course,&ptr->s[i].percentage)!=EOF)
    {

    printf("%d\t",ptr->s[i].id);
    printf("%s\t",ptr->s[i].name);
    printf("%s\t",ptr->s[i].course);
    printf("%0.2f\n",ptr->s[i].percentage);
     i++;
    }
fclose(fptr);
}
void write(struct Admin *ptr)
{

    int n;
    FILE *fptr;
    fflush(stdin);
    fptr=fopen("student","w");
    printf("Enter the number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter student id : ");
        scanf("%d",&ptr->s[i].id);
        printf("\nEnter student name : ");
        scanf("%s",ptr->s[i].name);
        printf("\nEnter student course : ");
        scanf("%s",ptr->s[i].course);
        printf("\nEnter student percentage : ");
        scanf("%f",&ptr->s[i].percentage);
        fprintf(fptr,"%d %s %s %f\n",ptr->s[i].id,ptr->s[i].name,ptr->s[i].course,ptr->s[i].percentage);
    }
   fclose(fptr);
}


void main()
{
    int ch;
struct Admin a;
struct Admin *ptr=&a;
while(1){

    printf("\n=================\n1.Read details\n2.Write details\n3.Exit\n=================");
    printf("\nEnter your choice: ");
   scanf("%d",&ch);
   switch(ch){
   case 1:read(ptr);
          break;
   case 2:write(ptr);
          break;
   case 3:exit(0);
          break;
   default:printf("invalid choice");
   }
}

}

