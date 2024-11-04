#include <stdio.h>
#include "unittests.h"

//To heapify a subtree rooted with node i
//which is an index in arr[]
void heapify(int arr[], int n, int i){
    //initialize largest as root
    int largest = i;

    //left index = 2*i + 1
    int l = 2 * i + 1;

    //right index = 2*i + 2
    int r = 2 * i + 2;

    //if left child is larger than the root
    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    //if right child is larget than the largest so fat
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    //if largest is not the root
    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //recursively heapify the affected sub-tree
        heapify(arr,n,largest);
    }
}

//main function to do heapsort
void heapSort(int arr[], int n){
  //build heap(rearrange array)
    if (arr == NULL){
        printf("Array is NULL.\n");
        return;
    }
    if (n <= 0){
        printf("Invalid array size.\n");
        return;
    }
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(arr,n,i);
    }

    //one by one extract an element from heap
    for (int i = n - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //call max heapify on the reduced heap
        heapify(arr,i,0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//main function
/*int main(int argc, char *argv[]){
    int arr[] = {9 , 5, 3 , 20, 34, 22, 1 , 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is: \n");
    printArray(arr,n);

    return 0;
}*/
