#include <stdio.h>

int main(){

int A[100], n, i;
printf("Enter n: "); scanf("%d", &n);
for(i=0; i<n; i++){
    scanf("%d", &A[i]);
}

for(i=0; i<n; i++){
    printf("%d  ", A[i]);
}

    return 0;
}