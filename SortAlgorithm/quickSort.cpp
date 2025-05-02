#include <iostream>
#include <vector>
#include <algorithm>

/**分区函数，将数组分为两部分，左边小于基准，右边大于基准 */
int partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];  // 最后一个元素作为基准

    int left = start - 1;
    for(int right = start ; right < end ; right++) {    // 统计所以小于基准元素的值
        if(arr[right] <= pivot) {
            left++;
            std::swap(arr[left] , arr[right]);
        }
    }
    std::swap(arr[left + 1], arr[end]); // 放置基准元素
    return left+1; // 返回基准元素的位置
}



// 快速排序函数，递归地对数组进行排序
void quickSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}