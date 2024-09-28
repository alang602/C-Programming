/*
    递归思想实现快速排序
*/

#include <iostream>
using namespace std;



void sort(int arr[], int zz, int yy) {

    if (zz < yy) {
        int z = zz;
        int y = yy;
        int k = arr[zz];
        do {

            while ((z < y) && (arr[y] > k)) {
                y = y - 1;
            }

            if (z < y) {
                arr[z] = arr[y];
                z = z + 1;
            }

            while ((z < y) && (arr[z] <= k)) {
                z = z + 1;
            }

            if (z < y) {
                arr[y] = arr[z];
                y = y - 1;
            }
        } while (z != y);

        arr[z] = k;
        sort(arr, zz, z - 1);
        sort(arr, z + 1, yy);
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

