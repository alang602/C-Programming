/*
    递归思想实现快速排序

    参考：《程序设计基础》 P154页
*/

#include <iostream>
using namespace std;


// zz: 开始下标，  yy: 终止下标
void sort(int arr[], int zz, int yy) {

    if (zz < yy) {
        int z = zz;
        int y = yy;
        int k = arr[zz];
        do {
            // 右边的元素>k，让y向中间移
            while ((z < y) && (arr[y] > k)) {
                y = y - 1;
            }

            // 右边的元素arr[y]<=k, 把arr[y]送给arr[z], 同时让z往中间移
            if (z < y) {
                arr[z] = arr[y];
                z = z + 1;
            }

            // 左边的元素<k，让z向中间移
            while ((z < y) && (arr[z] <= k)) {
                z = z + 1;
            }

            // 左边的元素arr[z] >k,把arr[z]送给arr[y],同时让y往中间移
            if (z < y) {
                arr[y] = arr[z];
                y = y - 1;
            }
        } while (z != y);

        arr[z] = k;           // k已经排到位
        sort(arr, zz, z - 1);   //递推，排左边部分
        sort(arr, z + 1, yy);   //递推，排右边部分
    }
}

int main()
{
    cout << "please input 7 number:" << endl;

    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    sort(arr, 0, 6);

    //print
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

