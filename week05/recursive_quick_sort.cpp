#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int input_arr[] = {1000,4000,7000,10000,13000,16000,19000,22000};
    
    for (int count : input_arr) {
        int arr[count];
        long long total_duration = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count; j++) {
                arr[j] = rand() % count;
            }
            auto t_start = chrono::high_resolution_clock::now();
            quickSort(arr, 0, count-1);
            auto t_end = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(t_end - t_start).count();
        }
        double avg_duration = total_duration / 10.0;
        cout << "Size of the array - " << count << endl;
        cout << "Average time taken - " << avg_duration << " µs " << endl;
        
    }
    return 0;
}
