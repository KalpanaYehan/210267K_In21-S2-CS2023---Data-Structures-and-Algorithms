#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; // assume the largest is root
    int left = 2 * root + 1; // left child of root
    int right = 2 * root + 2; // right child of root

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than current largest one
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root then interchange largest and root
    if (largest != root) {
        swap(arr[root], arr[largest]);

        // recursively call the heapify
        heapify(arr, n, largest);
    }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
        // interchange the fist and last element of the current array
        swap(arr[0], arr[i]);

        // call heapify on the reduced heap
        heapify(arr, i, 0);
   }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   //int heap_arr[] = {4,17,3,12,9,6};
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   int n;
   cout<<"Enter the size of the array"<<endl;
   cin>>n;

   srand(time(0)); // seed the random number generator with the current time
   int min = 1; // minimum value of integers
   int max = 100; // maximum value of integers
   int heap_arr[n];

   for (int i = 0; i < n; i++) {
        heap_arr[i] = rand() % (max - min + 1) + min; // generate random integer between min and max
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
