#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
	
    srand(time(0));
    
    int n = 25; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    cout << "Original Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    clock_t time_req = clock();
    
    quickSort(arr, 0, n - 1);
    
    time_req = clock() - time_req;
    
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Time taken: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

