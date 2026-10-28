#include <stdio.h>

int tickets[15],n,Regno;
int logvalid=1;
int duplicateid,missingid;

void ticketinput(){
int i;

printf("Enter the number of tickets (5 to 15) : ");
scanf("%d",&n);

while(n<5 || n>15){
    printf("Invalid n . Enter again !!: ");
    scanf("%d",&n);
}

for(i=0;i<n;i++){
    printf("Enter the ticket ID : ");
    scanf("%d",&tickets[i]);

    while(tickets[i]<1 || tickets[i]>n){
        printf("Invalid Input. Enter again !! : ");
        scanf("%d",&tickets[i]);
    }
}

printf("Enter the last two digits of your registration number : ");
scanf("%d",&Regno);
}

void duplicatemissing(){
    int i,j,count;
    duplicateid=0;
    missingid=0;
    int missingcnt=0;
    int duplicatecnt=0;

    for(i=1;i<=n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(tickets[j]==i){
                count++;
            }
        }
        if(count==2){
            duplicateid=i;
            duplicatecnt++;
        }

        if(count==0){
            missingid=i;
            missingcnt++;
        }
    }
    if(duplicatecnt==1 && missingcnt==1){
        printf("Duplicate ID is : %d\n",duplicateid);
        printf("Missing ID is : %d\n",missingid);
    }
    else{
        logvalid=0;
        printf("Invalid log!");
    }
}

void outordercnt(){
    int i,j,pairs=0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(tickets[i]>tickets[j]){
                pairs++;
            }
        }
    }

    printf("No. of out of order pairs are : %d\n",pairs);
}

void targetticket(){
    int target,i,cnt=0;
    target=(Regno%n)+1;
    printf("Target ticket ID is : %d\n",target);

    for(i=0;i<n;i++){
        if(tickets[i]==target){
            printf("Position : %d\n", i+1);
            cnt++;
        }
    }
    printf("Occurence count is : %d\n",cnt);
}

int main(){
    int i;
    ticketinput();
    
    printf("Original Ticket sequence : ");
    for(i=0;i<n;i++){
    printf("%d ",tickets[i]);\
    printf("\n")
}

    duplicatemissing();
    if(logvalid==1){
        outordercnt();
        targetticket();
    }

return 0;    
}


