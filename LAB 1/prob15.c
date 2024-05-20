#include <stdio.h>


//The function which checks whether the elements are 
//the same two by two
int checkpairs(int a, int b, int c, int d){ 
  if (a==c && b==d){
    return 1;
  }
  else {
    return 0;
  }
}


//The function which sort the elements descendingly
//if the elements ARE the same two by two (bubble sort)
void bubblesort(int array[], int n){
    int i, j, t;
    for(i=0; i<n; i++){
        for(j=i;j<n-i-1;j++){
           if (array[j]<array[j+1]){
              t = array[j];
              array[j]=array[j+1];
              array[j+1]=t;
           }
        }
    }
}


//The function which sorts the elements ascendingly
//if they are NOT the same two by two (selection sort)
void selectionsort(int array[], int n){
     int i, j, min, minind;
     for(i=0;i<n;i++){
       min = array[i];
       minind=i;
       for(j=i;j<n;j++){
          if (array[j]<min){
            min = array[j];
            minind = j;
          }
       }
       array[minind]=array[i];
       array[i]=min;
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

//This block of code traverses the array and calls the checkpairs function
//which compares each pair of consecutive elements with the next pairs
int status = 1;
int k=0;
for(i=0; i<n-2; i+=2){
    for (k=i+2; k<n;k+=2){
       status = checkpairs(A[i], A[i+1],A[k], A[k+1]);
       if (status == 0){
        break;
       }
    }
    if (status == 0){
        break;
       }

}

//The conclusion (whether the elements are equal two by two or not)
//is displayed on the screen
if(status == 1){
    printf("All elements are equal two by two.\n");
}
else {
    printf("Not all elements are equal two by two.\n");
}


//If the elements of the vectors are the same two by two (status=1), I had to sort a copy
//of the original vector descendingly, using bubble sort.
//If the opposite is true (status = 0), I had to sort the actual vector
//ascendingly using selection sort

if (status==1){
    bubblesort(copy, n);
    printf("Descending sorting using bubble sort:\n");
    for(i=0; i<n; i++){
    printf("%d  ", copy[i]); //the sorted copy of the vector is printed
}
}
else {
   selectionsort(A, n);
    printf("Ascending sorting using selection sort:\n");
   for(i=0; i<n; i++){
    printf("%d  ", A[i]); //the sorted vector is printed
    }
}


   return 0; 

}
