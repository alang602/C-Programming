/*
     二分法查找
     输入：一个已经排好序的数组，和一个待查找的整数n
     输出：如果找到, 输出数组下标。没找到输出-1

     递归实现
*/
#include <iostream>
using namespace std;

// 二分法查找：先比较中间的节点和要查找的整数的大小：
//  1)  如果相等，结束递归。 
//  2)  如果待查找的数小于中间的节点值，递推查找前半部分数组
//  3)  如果待查找的数大于中间的节点值，递推查找后半部分数组
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


