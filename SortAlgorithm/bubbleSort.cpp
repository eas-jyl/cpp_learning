#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0 ; i < n ; i++) { // 比较的轮数
        for(int j = 0 ; j < n - i - 1 ; j++) {  // 一轮比较的次数
            if(arr[j] > arr[j+1]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}