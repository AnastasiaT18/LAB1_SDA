#include <stdio.h>


//The function which checks whether all the sums of pairs of consecutive 
//elements are equal
int checksums(int *array, int n){
    int status, i;
    for(i=0;i<n-3;i+=2){
        if(*(array+i)+*(array+i+1)==*(array+i+2)+*(array+i+3)){
           status = 1;
        }
        else{
            status = 0;
            return status;
        }
    }
    return status;
}


//The function which sorts the elements descendingly
//if the sums ARE the same (insertion sort)
void insertiondescend(int *array, int n){
    int i,j, t;
    for(i=1;i<n;i++){
      t = *(array+i);
      for(j=i-1;j>=0;j--){
        if(t > *(array+j)){
            *(array+j+1)=*(array+j);
            *(array+j) = t;
        }
      }
    }
}

//The function which sorts the elements ascendingly
//if the sums are NOT the same (merge sort)
void mergeascend(int *array, int a, int m, int b){
    int i,j,k, n1, n2;
    n1 = m-a+1;
    n2=b-m;
    int L[n1], R[n2];

    for(i=0;i<n1;i++){
        L[i]=array[a+i];
    }
    for(j=0;j<n2;j++){
        R[j]=array[m+1+j];
    }

    i=0; j=0; k=a;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            array[k]=L[i];
            i++;
        }
        else{
            array[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        array[k]=L[i];
        k++;
        i++;
    }

    while(j<n2){
        array[k]=R[j];
        k++;
        j++;
    }

}

//The function which divides the original array into smaller subarrays which would be merged
void dividemerge(int *array,int a, int b){
    int m;
    if(a<b){
      m=(a+b)/2;
      dividemerge(array, a,m);
      dividemerge(array, m+1, b);
      mergeascend(array, a,m ,b);

    }

}

int main(){

int A[100], n, i, copy[100];

//Reading the number of elements for the vector
printf("Enter n: "); scanf("%d", &n);


//Reading the actual vector elements and copying them 
//in another vector
for(i=0; i<n; i++){
    scanf("%d", &A[i]);
    copy[i]=A[i];
}


//Calling the checksums function
int status = 1;
status = checksums(A, n);


//The conclusion (whether the sums are equal or not)
//is displayed on the screen
if(status == 1){
    printf("All sums are equal.\n ");
}
else {
    printf("Not all sums are equal.\n ");
}


//If the sums are equal(status=1), I had to sort a copy
//of the original vector descendingly, using insertion sort.
//If the opposite is true (status = 0), I had to sort the actual vector
//ascendingly using merge sort
if(status==1){
    insertiondescend(copy, n);
    printf("Descending sorting using insertion sort:\n");
    for(i=0; i<n; i++){
    printf("%d  ", copy[i]);//the sorted copy of the vector is printed
}
} else{
    dividemerge(A,0,n-1);
    printf("Ascending sorting using merge sort:\n");
    for(i=0; i<n; i++){
    printf("%d  ", A[i]); //the sorted original vector is printed
}}


   return 0; 

}
