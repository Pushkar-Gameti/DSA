#include<stdio.h>
#include<stdlib.h>

void bubblesort(int list[], int n){
    int i, j, k, temp;

     for (i = 0; i < n - 1; i++) {
        // Inner loop for comparisons
        for (j = 0; j < n - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                // Swap if elements are in the wrong order
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

}

int binary(int a[], int n){
    int num,start=0,mid,last=n-1;
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
            exit(0);
        }
    }
    return num;
}

int main(){
    int n;
    printf("\nEnter the number of input: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the arr: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    int num = binary(a,n);
    printf("\n%d is not found!",num);
    return 0;
}