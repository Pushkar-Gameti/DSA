#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[10]={2,5,3,9,4,1,7,8,6,10};
    int num;
    printf("\nEnter the number: ");
    scanf("%d",&num);
    for (int  i = 0; i < 10; i++)
    {
        if (num==a[i])
        {
            printf("\nNumber is found at %d position",i+1);
            exit(0);
        }
        
    }

    printf("\n%d is not found!",num);
    
    return 0;
}