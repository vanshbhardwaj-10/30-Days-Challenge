#include <stdio.h>
int main() {
    float expense,total=0,avg;
    float smltot=0,medtot=0,lartot=0;
    int validcnt=0;
    int smlcnt=0,medcnt=0,larcnt=0;

do {
    printf("Enter your expense (0 to stop) : ");
    scanf("%f",&expense);

    if (expense<0){
        printf("Invalid input\n");
    }
    else if (expense>0){
        validcnt++;
        total = total + expense;

        if (expense<100){
            smlcnt++;
            smltot = smltot + expense;
        }
        else if (expense<500){
            medcnt++;
            medtot = medtot + expense;
        }
        else {
            larcnt++;
            lartot = lartot + expense;
        }
    }
}
while (expense!=0);

printf("Number of Valid expenses are : %d\n",validcnt);
printf("Total expenses : %.2f \n",total);

printf("Small Expenses : \n");
printf("Count : %d \n",smlcnt);
printf("Total Rs. : %.2f \n",smltot);

printf("Medium Expenses : \n");
printf("Count : %d \n",medcnt);
printf("Total Rs. : %.2f \n",medtot);

printf("Large Expenses : \n");
printf("Count : %d \n",larcnt);
printf("Total Rs. : %.2f \n",lartot);

if (validcnt>0){
    avg = total/validcnt;
    printf("Average valid expense : %.2f \n",avg);
}
else {
    printf("No valid expenses entered\n");
    printf("Average value cannot be calculated\n");
}
return 0;
}

