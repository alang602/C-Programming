/*
4
a 64 46
275 125
c 11 99
b 46 64


64+46=110
9
275+125=400
11
11*99=1089
10
46-64=-18
9




*/



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>     // strlen需要的头文件
using namespace std;


// 计算并打印算式(比较简单的方法)
void ComputeAndPrint2(char oper, int x, int y) {
    char result[100];

    if ('a' == oper) {
        sprintf(result, "%d+%d=%d", x, y, x + y);
    }
    else if ('b' == oper) {
        sprintf(result, "%d-%d=%d", x, y, x - y);
    }
    else if ('c' == oper) {
        sprintf(result, "%d*%d=%d", x, y, x * y);
    }

    cout << result << endl;
    cout << strlen(result) << endl;

 }






int main()
{
    int n;
    cin >> n;

    char oper[20] = { 0 };
    int x;
    int y;
    char prev_oper;
    
    for (int i = 0; i < n; i++) {
        cin >> oper;

        // 格式： oper x y 
        if ('a' == oper[0] || 'b' == oper[0] || 'c' == oper[0]) {
            cin >> x >> y;
            ComputeAndPrint2(oper[0], x, y);

            prev_oper = oper[0];
        }
        else {  //  格式：  x y 

            // 第一个数据不是oper，是算数，字符串转换成整形   
            sscanf(oper, "%d", &x);

            cin >> y;

            ComputeAndPrint2(prev_oper, x, y);

        }
    }

    return 0;
}

