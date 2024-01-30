/*Each Step of the bubble sort process for the array[5, 2, 8, 1, 3]:

1. Easy: Understanding Bubble Sort

Manually sort the array [5, 2, 8, 1, 3] using the bubble sort technique.writedown each step of the process.

step 1:-in the case of array [5,2,8,1,3] 5 is greater than 2.so the 5 takes the position of 2 and
        the array becomes [2,5,8,1,3].
step 2:- now array [2,5,8,1,3]  5 is smaller than 8 so the array remains same.
step 3:-[2,5,8,1,3] now compare next two 8 and 1 now 8>1 so the swapping happens now 8 takes the
        position of 1 and array becomes [2,5,1,8,3].
step 4:-[2,5,1,8,3] 8 is greater than 3 so 8 takes the postion of 3 it becomes [2,5,1,3,8]
        1st iteration is completed so we need to start second iteration of sorting. 

step 5:-in array [2,5,1,3,8] 2<5 so we dont need to swap and compare 5 and 1 where 5>1 we need to 
        swap now array becomes [2,1,5,3,8]
step 6:-[2,1,5,3,8] now 5>3 swap 5 and 3 it becomes [2,1,3,5,8] and compare 5 and 8 where 5<8 no 
       need to swap.
step 7:-2nd iteration is completed we need to start 3rd iteration array is[2,1,5,3,8] where 2>1 so we
        need to swap 2 in position of 1 so the array becomes [1,2,5,3,8].
step 8:- array [1,2,5,3,8] now compare 2 and 5 where 2<5 we dont need to swap. now compare 5 and 3
         5>3 so we need to swap so array becomes [1,2,3,5,8]
  */ 

/*Tracing the bubble sort algorithm step by step for the unsorted array[7, 4, 2, 9, 1]:

2. Intermediate: Trace the Bubble Sort
    
    array=[7,4,2,9,1]
    first pass:-
    the largest element is placed at the end of the array
                7>4 swapping  [4,7,2,9,1]
                7>2 swapping  [4,2,7,9,1]
                7<9 no swapping [4,2,7,9,1]
                9>1 swapping [4,2,7,1,9]

    second pass:-
    the second largest element is placed at the end now array is [4,2,7,1,9]
               4>2 swapping [2,4,7,1,9]
               4<7 no swapping [2,4,7,1,9]
               7>1 swapping [2,4,1,7,9]
               7<9 no swapping [2,4,1,7,9]
    
    Third pass:-
      Now the array is [2,4,1,7,9]
              2<4 no swapping [2,4,1,7,9]
              4>1 swapping [2,1,4,7,9]
              
    Fourth Pass:-
       Now the array is [2,1,4,7,9]
          where 2>1 swapping [1,2,4,7,9]

*/

/*3. Intermediate: Code Implementation*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 3, 6, 1, 8, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    cout << "Sorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}


/*
Optimization:
------------ -

4. Advanced: Optimization Challenge

The key idea is to keep track of whether any swaps are made in each pass.If no swaps are made in a pass, it means that the array is already sorted up to that point, and we can terminate the sorting process early.


#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool isSorted; // Flag to track if the array is already sorted
    for (int i = 0; i < size - 1; ++i) {
        isSorted = true; // Initialize isSorted to true at the beginning of each pass
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false; // Set isSorted to false if a swap is made
            }
        }
        // If the array is already sorted up to this point, break out of the outer loop
        if (isSorted) {
            break;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Sort the array using optimized bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    cout << "Sorted array:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}


*/



/*

5. Advanced: Comparison with Other Sorting Algorithms

Bubble Sort :

Advantages:
Simple implementation : Bubble sort is easy to understand and implement.
No additional space : It operates in - place, requiring only a constant amount of extra memory.

Disadvantages :
    Inefficiency : Bubble sort has poor time complexity, making it inefficient for large datasets, especially when compared to other sorting algorithms like quicksort and mergesort.
    O(n ^ 2) time complexity : Bubble sort has a time complexity of O(n ^ 2) in the worst case, which can be prohibitive for large datasets.

    Scenarios for use:
        Bubble sort may be suitable for small datasets or situations where simplicity and ease of implementation are prioritized over efficiency.
            It can also be useful when dealing with nearly sorted arrays, as it performs well in such cases due to its adaptive nature.

            Quicksort :

            Advantages :
            Efficiency : Quicksort has excellent average - case time complexity of O(n log n) and performs well on large datasets.
            In - place sorting : It can be implemented to sort the array in - place, requiring only a logarithmic amount of additional memory.
            Adaptive : Quicksort adapts well to nearly sorted arrays and performs efficiently in practice.

            Disadvantages :
            Not stable : Quicksort is not stable, meaning it may change the relative order of equal elements.
            Worst - case time complexity : While its average - case time complexity is good, the worst - case time complexity of quicksort can be O(n ^ 2), though this is rare with good pivot selection strategies.


            Scenarios for use:
                Quicksort is ideal for large datasets or situations where high performance is required.
                    It is commonly used in practice due to its efficiency and effectiveness in a wide range of scenarios.


                    Mergesort :

                    Advantages :
                    Stable : Mergesort is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
                    Predictable performance : It has a consistent time complexity of O(n log n) regardless of the input data, making it suitable for scenarios where predictable performance is important.
                    Parallelizable : Mergesort can be easily parallelized, allowing for efficient sorting on multi - core or distributed systems.


                    Disadvantages :
                    Additional space : Mergesort requires additional memory proportional to the size of the input array, making it less suitable for memory - constrained environments.
                    Scenarios for use :
                    Mergesort is well - suited for scenarios where stable sorting and consistent performance are required.
                    It is often used in external sorting applications, such as sorting large files that do not fit into memory.
*/
