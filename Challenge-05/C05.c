#include <stdio.h>
#include <math.h>
int main() {
    int choice ,n ,i ,fact;
    float a, b, c, x, D, x1, x2;
    
    do {
        printf("1. Linear Equation \n");
        printf("2. Factorial \n");
        printf("3. Quadratic Equation \n");
        printf("4. Exit \n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {

            case 1: 
            printf("Enter a : \n");
            printf("Enter b : \n");
            scanf("%f",&a);
            scanf("%f",&b);

            if (a!=0){
                x = -b/a;
                printf("x = %.2f \n",x);
            }
            else if (a==0){
                printf("Infinitely many solutions ! \n");
            }
            else {
                printf("No solution ! \n");
            }
            break;

            case 2:
            printf("Enter n (0 to 12) : ");
            scanf("%d",&n);

            if (n<0 || n>12) {
                printf("Invalid Input");
            }

            else {
                fact = 1;
                for (i=1;i<=n;i++){
                    fact = fact * i;
                }
                printf("Factorial = %d \n",fact);
            }
            break;

            case 3:
            printf("Enter a : ");
            scanf("%f",&a);

            printf("Enter b : ");
            scanf("%f",&b);

            printf("Enter c : ");
            scanf("%f",&c);

            if (a==0){
                printf("Not a Quadratic equation ! ");
            }
            else {
                D = (b*b) - (4*a*c);

                if (D>0){
                    x1 = (-b + sqrt(D))/(2*a);
                    x2 = (-b - sqrt(D))/(2*a);

                    printf("Two distinct real roots \n");
                    printf("Root 1 = %.2f \n",x1);
                    printf("Root 2 = %.2f \n",x2);-
                }
                else if (D==0){
                    x1 = -b/(2*a);

                    printf("Two equal real roots ! \n");
                    printf("Root = %.2f \n",x1);
                }
                else {
                    printf("No real roots ! \n");
                }
            }
            break;

            case 4:
            printf("Program Ended ! \n");
            break;

            default:
            printf("Invalid Choice \n");
            
        }
    }

    while (choice!=4);

    return 0;
}