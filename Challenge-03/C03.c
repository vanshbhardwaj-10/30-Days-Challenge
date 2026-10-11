
#include <stdio.h>

int main() {
    float purchaseamt, discpercent, discamt;
    float amtafterdisc, delicharge, finalamt;
    int customer;
    float distance;

    printf("Enter the purchase amount (in ₹): ");
    scanf("%f", &purchaseamt);

    printf("Enter the customer type\n");
    printf("Enter 1 if Student\n");
    printf("Enter 2 if Regular customer\n");
    scanf("%d", &customer);

    printf("Enter the Distance (in km): ");
    scanf("%f", &distance);

    if (customer == 1 && purchaseamt >= 2000) {
        discpercent = 15;
    }
    else if (customer == 1 && purchaseamt < 2000) {
        discpercent = 10;
    }
    else if (customer == 2 && purchaseamt >= 3000) {
        discpercent = 8;
    }
    else {
        discpercent = 0;
    }

    discamt = purchaseamt * (discpercent / 100);
    amtafterdisc = purchaseamt - discamt;

    if (distance <= 5) {
        delicharge = 40;
    }
    else if (distance <= 15) {
        delicharge = 70;
    }
    else {
        delicharge = 100;
    }

    finalamt = amtafterdisc + delicharge;

    printf("\nPurchase amount: %.2f\n", purchaseamt);
    printf("Discount amount: %.2f\n", discamt);
    printf("Amount after discount: %.2f\n", amtafterdisc);
    printf("Delivery charge: %.2f\n", delicharge);
    printf("Final amount: %.2f\n", finalamt);

    return 0;
}
