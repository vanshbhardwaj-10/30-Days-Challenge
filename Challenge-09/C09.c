#include <stdio.h>
#define ROWS 5
#define COLS 8

int seat[5][8];

void seatset();
void seatshow();
int booking();
int bookingrem();
int grpbook();
void reportshow();

int row, col, grpsize;
int i, j, k;

int main(){
    int choice;
    seatset();

    do{
        printf("1. Display Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Group Reservation\n");
        printf("5. Occupancy Report\n");
        printf("6. Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            seatshow();
            break;

            case 2:
            printf("Enter row (1-5): ");
            scanf("%d", &row);

            printf("Enter seat (1-8): ");
            scanf("%d", &col);

            if(row < 1 || row > 5 || col < 1 || col > 8){
                printf("Invalid row or seat!\n");
            }
            else if(booking()){
                printf("Seat booked successfully!\n");
            }
            else{
                printf("Seat already booked!\n");
            }
            break;

            case 3:
            printf("Enter row (1-5): ");
            scanf("%d", &row);

            printf("Enter seat (1-8): ");
            scanf("%d", &col);

            if(row < 1 || row > 5 || col < 1 || col > 8){
                printf("Invalid row or seat!\n");
            }
            else if(bookingrem()){
                printf("Booking cancelled!\n");
            }
            else{
                printf("Seat is not booked!\n");
            }
            break;

            case 4:
            printf("Enter group size (2-8): ");
            scanf("%d", &grpsize);

            if(grpsize < 2 || grpsize > 8){
                printf("Invalid group size!\n");
            }
            else if(grpbook()){
                printf("Group reservation successful!\n");
            }
            else{
                printf("No consecutive seats available!\n");
            }
            break;

            case 5:
            reportshow();
            break;

            case 6:
            printf("Thank you for using SEATSMART!\n");
            break;

            default:
            printf("Invalid choice!\n");

        }
    }
    while(choice != 6);

    return 0;
}

void seatset(){
    for (i=0;i<ROWS;i++){
        for (j=0;j<COLS;j++){
            seat[i][j]=0;
        }
    }
}

void seatshow(){
    for (j=0;j<COLS;j++){
        printf("%d ",j+1);
    }
    printf("\n");
    for (i=0;i<ROWS;i++){
        printf("Row %d ",i+1);

        for (j=0;j<COLS;j++){
            if (seat[i][j]==0){
                printf("A ");
            }
            else{
                printf("B ");
            }
        }
        printf("\n");
    }
}

int booking(){
    if (seat[row-1][col-1]==0){
        seat[row-1][col-1]=1;
        return 1;
    }
    return 0;
}

int bookingrem(){
    if (seat[row-1][col-1]==1){
        seat[row-1][col-1]=0;
        return 1;
    }
    return 0;
}

int grpbook(){
    int cnt;
    for (i=0;i<ROWS;i++){
        for (j=0;j<=COLS-grpsize;j++){
            cnt=0;
            for (k=0;k<grpsize;k++){
                if (seat[i][j+k]==0){
                    cnt++;
                }
            }
            if (cnt==grpsize){
                for (k=0;k<grpsize;k++){
                    seat[i][j+k]=1;
                }
                printf("Booked in row %d , seats %d to %d\n",i+1,j+1,j+grpsize);
                return 1;
            }
        }
    }
    return 0;
}

void reportshow(){
    int booked=0,available=0;
    int rowcount[ROWS]={0};
    int busiest=0;
    float perc;

    for (i=0;i<ROWS;i++){
        for (j=0;j<COLS;j++){
            if (seat[i][j]==1){
                booked++;
                rowcount[i]++;
            }
            else{
                available++;
            }
        }
    }

    perc=(booked/40.0)*100;

    for (i=0;i<ROWS;i++){
        if (rowcount[i]>busiest){
            busiest=rowcount[i];
        }
    }

    printf("Total seats: 40\n");
    printf("Booked seats: %d\n",booked);
    printf("Available seats: %d\n",available);
    printf("Occupancy: %.2f\n",perc);

    printf("Busiest row(s): ");

    if (busiest==0){
        printf("None");
    }
    else{
        for (i=0;i<ROWS;i++){
            if (rowcount[i]==busiest){
                printf("%d ",i+1);
            }
        }
    }

    printf("\n");
}







