**1. 动态创建一维数组**

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







**2. 动态创建二维数组(m*n)**
/*
      动态创建二维数组(m*n)

      输入： 两个整数(m ,n )
      输出： 二维数组, m行n列

 */

#include <iostream>
using namespace std;

int main()
{
   
    cout << "please input two number(m n):";

    int m;
    int n;
    cin >> m;
    cin >> n;

    //Create m*n
    int** arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    //init
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i * j;
        }
    }

    //output
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //remember to release memory
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
