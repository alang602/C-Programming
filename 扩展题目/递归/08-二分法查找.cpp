/*
     二分法查找

     递归实现
*/
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int targetNum) {
    if (left > right) {
        return -1;
    }

    int mid = (right - left) / 2 + left ;
    if (arr[mid] == targetNum) {
        return mid;
    }
    else if (arr[mid] > targetNum) {
        return BinarySearch(arr, left, mid - 1, targetNum);
    }
    else if (arr[mid] < targetNum) {
        return BinarySearch(arr, mid + 1, right, targetNum);
    }
}

int main()
{
    // 有序数组
    int arr[10] = { 1 , 4 , 7,  8, 20, 33, 55, 65, 99 ,100 };

    int targetNum = 33;

    int targetIndex = -1;;
    targetIndex = BinarySearch(arr, 0, 9, targetNum);
    if (targetIndex >= 0) {
        cout << "Found the targetNum:" << targetNum << ", the index is :" <<targetIndex << endl;
    }

    return 0;
}


