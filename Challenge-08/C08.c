#include<stdio.h>
int riskscore[6][6];
int n,t;

int rows(int row);
int rows(int row){
int i,sum=0;
for(i=0;i<n;i++){
    sum=sum+riskscore[row][i];
}
return sum;
}

int cols(int col);
int cols(int col){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum=sum+riskscore[i][col];
    }
    return sum;
}

int riskmax(){
    int i,j;
    int max=riskscore[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(riskscore[i][j]>max){
                max=riskscore[i][j];
            }
        }
    }
    return max;
}

void diagonalsum(){
    int i;
    int firstdiagonal=0,seconddiagonal=0;
    for(i=0;i<n;i++){
        firstdiagonal=firstdiagonal+riskscore[i][i];
        seconddiagonal=seconddiagonal+riskscore[i][n-1-i];
    }

    printf("Sum of the elements of main diagonal is : %d\n",firstdiagonal);
    printf("Sum of the elements of second diagonal is : %d\n",seconddiagonal);

    if (firstdiagonal==seconddiagonal){
        printf("Sum of both diagonal is same ");
    }

}

void outerelements(){
    int i,j,outersum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                outersum=outersum+riskscore[i][j];
            }
        }
    }
    printf("Sum of the outer elements is : %d\n",outersum);
}

int hotspotcheck(int i, int j){
    if (riskscore[i][j]>riskscore[i-1][j] && riskscore[i][j]>riskscore[i+1][j] && riskscore[i][j]>riskscore[i][j-1] && riskscore[i][j]>riskscore[i][j+1] && 
        riskscore[i][j]>=t) {
            return 1;
        }
    else {
        return 0;
    }
}

int main(){
    int i,j;
    int rowhighsum=0,colhighsum=0;
    int max;
    int count=0,hotspotcnt=0;
    printf("Enter the size (3 to 6) : ");
    scanf("%d",&n);

    while (n<3 || n>6){
        printf("Invalid size . please enter again ");
        scanf("%d",&n);
    }

    printf("Enter risk scores : \n");
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d",&riskscore[i][j]);
            while (riskscore[i][j]<0 || riskscore[i][j]>100){
                printf("Invalid score, Enter again : ");
                scanf("%d",&riskscore[i][j]);
            }
        }
    }

    printf("Enter minimum risk score : ");
    scanf("%d",&t);

    while(t<1 || t>100){
        printf("Invalid threshold . Enter again : ");
        scanf("%d",&t);
    }
    for (i=0;i<n;i++){
        if(rows(i)>rowhighsum){
            rowhighsum=rows(i);
        }
    }
    printf("Highest row sum : %d\n",rowhighsum);
    for (i=0;i<n;i++){
        if(rows(i)==rowhighsum){
            printf("Row %d has the highest total : \n",i+1);
        }
    }

    for(j=0;j<n;j++){
        if(cols(j)>colhighsum){
            colhighsum=cols(j);
        }
    }
    printf("Highest column sum : %d\n",colhighsum);
    for (j=0;j<n;j++){
        if(cols(j)==colhighsum){
            printf("Column %d has the highest total : \n",j+1);
        }
    }
    max=riskmax();
    printf("Highest risk score is : %d\n",max);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (riskscore[i][j]==max){
                printf("Position : row - %d column - %d\n",i+1,j+1);
            }
            if (riskscore[i][j]>=t){
                count++;
            }
        }
    }
    printf("Number of cells above threshold : %d\n",count);

    diagonalsum();
    outerelements();

    for (i=1;i<n-1;i++){
        for (j=1;j<n-1;j++){
            if(hotspotcheck(i,j)){
                hotspotcnt++;
                printf("Hotspot at Row %d and column %d \n",i+1,j+1);
            }
        }
    }

    if (hotspotcnt==0){
        printf("No Hotspot found\n");
    }
    if (hotspotcnt>=1){
        printf("Risk Level : Critical\n");
    }
    else if (count>=n){
        printf("Risk level : Warning\n");
    }
    else {
        printf("Risk Level : Normal\n");
    }

    return 0;
}