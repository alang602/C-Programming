

#include <iostream>
using namespace std;


/*
      插入排序：

      将第一个作为已经排好序的数组，然后将第2个元素插入到已经排好序的元素中，依次类推（插入排序最好的情况就是数组已经有序了）

      1） 5 4 9 3   --> 4 5 9 3  // 插入4
      2)  4 5 9 3  -->           // 插入9
      3)  4 5 9 3  --> 3 4 5 9   // 插入3

*/
void InsertSort(int array[], int len) {

    for (int i = 1; i < len; i++) {
        int key = array[i];
        int j = i - 1;

        while (j>=0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j-1;
        }

        array[j + 1] = key;
    }
}



// Bubble Sort(参考章节6.4 ）
/*
       5 4 9 3
1)     5 4 9 3 --> 4 5 9 3  --> 4 5 3 9      // 一趟循环下来，最大数9移到最后
2)     4 5 3 9 --> 4 3 5 9                   // 第二大的数5移动倒数第二
3)     4 3 5 9 --> 3 4 5 9                   // 第三大的数4到位
*/
void BubbleSort(int array[] , int len) {

    //变量i仅代表比较的趟数（n-1）趟
    for (int i = 0; i < len-1; i++) {
        //每一趟，从0号数字，开始比较相邻的两个数字
        for (int j = 0; j < len -1 - i; j++) {
            //大的数字后移，象冒泡一样浮起
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    return;
}

int main()
{
    cout << "Please input 4 numbers:";

    // Create Array
    int numberArray[4] = {};
    for (int i = 0; i < 4; i++) {
        cin >> numberArray[i];
    }

    // Sort
    //BubbleSort(numberArray, 4);
    InsertSort(numberArray, 4);

    //Print
    for (int i = 0; i < 4; i++) {
        cout << numberArray[i] << " ";
    }
    cout << endl;

    return 0;


}

