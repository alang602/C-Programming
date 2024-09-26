**1. How to create Dynamic Array**

/*
     动态数组示例

     输入：整数n
     处理：创建一维数组array[n]
     输出：打印数组内容
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "please input N:";

    int n;
    cin >> n;

    // Create Dynamic Array
    int* pArray = (int*)malloc(n* sizeof(int));
    if (pArray == NULL) {
        cout << "malloc failed";
        return 1;
    }
    for (int i = 0; i < n; i++) {
        pArray[i] = i;
    }

    //output
    for (int i = 0; i < n; i++) {
        cout << pArray[i] << " ";
    }

    //remember to release memory
    free(pArray);


    return 0;
}




**另一种写法：**

/*
     动态数组示例

     输入：整数n
     处理：创建一维数组array[n]
     输出：打印数组内容
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "please input N:";

    int n;
    cin >> n;

    // Create Dynamic Array
    int* p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    //output
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }

    //remember to release memory
    delete[]p;


    return 0;
}
