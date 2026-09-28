#include <stdio.h>
int main() { 
int totaldistance, mileage, fuelprice, fuelrequired, totalcost;

printf("Enter the total distance (in km) :  ");
scanf("%d",&totaldistance);
printf("Enter the mileage (in km/litre) : ");
scanf("%d",&mileage);
printf("Enter the Fuel price (₹/litre) : ");
scanf("%d",&fuelprice);

fuelrequired=totaldistance/mileage;
totalcost=fuelrequired*fuelprice;

printf("----------------------------------------------------------\n");
printf("Total Distance (in km) : %d \n",totaldistance);
printf("Mileage (in km/litre) : %d \n",mileage);
printf("Fuel price (in ₹/litre) : %d \n",fuelprice);
printf("Fuel Required : %d L \n",fuelrequired);
printf("Total Cost : ₹%d \n",totalcost);

return 0;
}

