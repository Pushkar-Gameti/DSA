#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[10]={3,12,23,35,39,45,56,74,84,98};
    int num,start=0,mid,last=9;
    printf("\nEnter the number: ");
    scanf("%d",&num);
    while(start<=last){
        mid=(start+last)/2;
        if (num>a[mid])
        {
            start=mid+1;
        }
        else if(num<a[mid]){
            last=mid-1;
        }
        else{
            if(num==a[mid])
            printf("\n%d is found at %d position",num,mid+1);
            return 0;
        }
    }
    printf("\n%d is not found!",num);
    return 0;
}