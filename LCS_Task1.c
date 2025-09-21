#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cm{
    int val;
    char dir;
} costmatrix;

void printLCS(int cols,costmatrix cost[][cols],char A[100],int i,int j) {
    if(i==0 || j==0){
        return;
    }
    if(cost[i][j].dir == 'd'){
        printLCS(cols,cost,A,i-1,j-1);
        putchar(A[i-1]);
    }
    else if(cost[i][j].dir == 'u'){
        printLCS(cols,cost,A,i-1,j);
    }
    else{
        printLCS(cols,cost,A,i,j-1);
    }
}


int main()
{
    char A[100],B[100];
    printf("Enter string A:");
    scanf("%s",A);
    printf("Enter string B:");
    scanf("%s",B);
    int m=strlen(A),n=strlen(B);
    costmatrix cost[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                cost[i][j].val=0;
                cost[i][j].dir='h';
            }
            else{
                if(A[i-1]!=B[j-1]){
                    if(cost[i-1][j].val>=cost[i][j-1].val){
                        cost[i][j].val=cost[i-1][j].val;
                        cost[i][j].dir='u';
                    }
                    else{
                        cost[i][j].val=cost[i][j-1].val;
                        cost[i][j].dir='s';
                    }
                }
                else{
                    cost[i][j].val=cost[i-1][j-1].val+1;
                    cost[i][j].dir='d';
                }
            }
        }
    }
    printf("Cost of lcs:%d",cost[m][n].val);
    printf("\nCost Matrix:\n");
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            printf("%d/%c  ",cost[i][j].val,cost[i][j].dir);
        }
        printf("\n");
    }
    int cols=n+1;
    printf("LCS: ");
    printLCS(cols,cost,A,m,n);
    return 0;
}
