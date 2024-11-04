#include "unity.h"
#include "unittests.h"
#include <time.h>
#include <stdlib.h>

/*int add(int a, int b){
    return a + b;
}
*/
void setUp(void){}
void tearDown(void){}

/*void test_add(void){
    TEST_ASSERT_EQUAL(4, add(2,2));
    TEST_ASSERT_EQUAL(23, add(18,5));
}
*/

int* generateRandomArray(int size){
  int *array = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++){
    array[i] = rand() % 10000;
  }
  return array;
}

void test_positive_array(void){
  int  arr[] = {3, 1, 34, 59, 13, 5};
  int  n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);
  int expected[] = {1, 3, 5, 13, 34, 59};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr,n);

}

void test_negative_array(void){
    int *arr = NULL;

    heapSort(arr,5);
}

void test_heapSort_small_array(void){
  int size = 10;
  int *arr = generateRandomArray(size);

  clock_t start = clock();
  heapSort(arr,size);
  clock_t stop = clock();

  double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
  printf("Time taken for small array: %f seconds\n", time_taken);

  free(arr);
}

void test_heapSort_medium_array(void){
  int size = 1000;
  int *arr = generateRandomArray(size);


  clock_t start = clock();
  heapSort(arr,size);
  clock_t stop = clock();

  double time_taken = ((double)(stop - start))/CLOCKS_PER_SEC;
  printf("Time taken for medium array: %f seconds.\n",time_taken);

free(arr);
}

void test_heapSort_large_array(void){
  int size = 10000;
  int *arr = generateRandomArray(size);

  clock_t start = clock();
  heapSort(arr,size);
  clock_t stop = clock();

  double time_taken = ((double)(stop - start))/CLOCKS_PER_SEC;
  printf("Time taken for large array: %f seconds\n",time_taken);

  free(arr);
}

void test_single_array(void){
  int arr[] = {1};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);

  int expected[] = {1};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,n);
}

void test_duplicate_array(void){
  int arr[] = {1, 1, 3, 4, 5, 3, 4, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);

  int expected[] = {1, 1, 1, 3, 3, 4, 4, 5};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,n);
}

void test_sorted_array(void)
{
  int arr [] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);

  int expected[] = {1, 2, 3, 4, 5, 6};


  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,n);
}


void test_rsorted_array(void)
{
  int arr [] = {6, 5, 4, 3, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);

  int expected[] = {1, 2, 3, 4, 5, 6};


  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,n);
}

void test_idempotency(void)
{
  int arr [] = {6, 5, 4, 3, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr,n);
  heapSort(arr,n);
  heapSort(arr,n);
  heapSort(arr,n);
  heapSort(arr,n);
  heapSort(arr,n);

  int expected[] = {1, 2, 3, 4, 5, 6};


  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,n);
}



int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_positive_array);
    RUN_TEST(test_negative_array);
    RUN_TEST(test_heapSort_small_array);
    RUN_TEST(test_heapSort_medium_array);
    RUN_TEST(test_heapSort_large_array);
    RUN_TEST(test_single_array);
    RUN_TEST(test_sorted_array);
    RUN_TEST(test_rsorted_array);
    RUN_TEST(test_idempotency);
    return UNITY_END();
}
