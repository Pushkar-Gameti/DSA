#include <stdio.h>

int count=0;

void towerOfHanoi(int n, char src, char helper, char dest) {
    if (n == 1) {
        count++;
        printf("Pass %d: Transfer disk %d from %c to %c\n",count,  n, src, dest);
        return;
    }
    towerOfHanoi(n - 1, src, dest, helper);
    count++;
    printf("Pass %d: Transfer disk %d from %c to %c\n",count,  n, src, dest);
    towerOfHanoi(n - 1, helper, src, dest);
}


int main() {
    int n ;  // Number of disks

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'S', 'H', 'D');  // S = Source, H = Helper, D = Destination

    return 0;
}
