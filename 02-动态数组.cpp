**1. 动态创建一维数组**

/*
     动态数组示例

     功能：有时候题目是要求的数组的长度是根据输入N决定的,
          比如用户输入整数N，程序创建一个长度为N的数组。 
          这样动态创建数组的时候，需要会使用下面代码。
     输入：整数n
     处理：创建一维数组array[n]，并给每个元素赋值
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
    // pArray指向数组头，数组长度是n，每个元素大小是sizeof(int)
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


运行结果：
please input N:4
0 1 2 3


     


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
    // 使用new
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

      功能：根据用户输入两个整数m,n，程序创建一个长度为M*N的二维数组。
            可以用在矩阵等问题
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

    // Create m*n 数组（m行，n列）
    // 先创建二维数组的头指针arr, 指向二维数组int**
    // 再创建每行的一维数组的指针arr[i], 指向一维数组int*
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


运行结果：
please input two number(m n):3 4
0 0 0 0
0 1 2 3
0 2 4 6






