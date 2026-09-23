#include <stdio.h>
int main() {
int subject1,subject2,subject3,subject4,subject5,total;
float average,percentage;

printf("Enter the marks for 5 Subjects: \n");
printf("Enter the marks of SUBJECT-1 :  ");
scanf("%d",&subject1);
printf("Enter the marks of SUBJECT-2 :  ");
scanf("%d",&subject2);
printf("Enter the marks of SUBJECT-3 :  ");
scanf("%d",&subject3);
printf("Enter the marks of SUBJECT-4 :  ");
scanf("%d",&subject4);
printf("Enter the marks of SUBJECT-5 :  ");
scanf("%d",&subject5);

total=subject1 + subject2 + subject3 + subject4 + subject5;
average=(total)/5.0;
percentage=(total/500.0)*100;

printf("Total Marks are :  %d  \n",total);
printf("Average is :  %f  \n",average);
printf("Percentage is :  %f  \n",percentage);

return 0;

}