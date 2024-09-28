/*
题目描述
若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个十进制数
56
将56加65（即把56从右向左读），得到121,121 是一个回文数。

又如：对于十进制数
87

STEP1：
87+78=165

STEP2：
165+561=726


STEP3：
726+627=1353

STEP4：
1353+3531=4884


在这里的一步是指进行了一次N 进制的加法，上例最少用了4 步得到回文数4884
。

写一个程序，给定一个
N（2≤N≤10或N=16）进制数

M（100 位之内），求最少经过几步可以得到回文数。如果在30步以内（包含3030 步）不可能得到回文数，则输出 Impossible!。

输入格式
两行，分别是
N，
M

输出格式
如果能在
30 步以内得到回文数，输出格式形如 STEP=ans，其中ans 为最少得到回文数的步数。

否则输出 Impossible!。


比如输入：
87

输出:
4


*/






#include <iostream>
using namespace std;


// 求n的回文数
int GetHuiWenShu(int n) {

    int p = n;
    int q = 0;
    while (p != 0) {
        q = q * 10 + p % 10;
        p = p / 10;
    }

    return q;
}


int main()
{
    cout << "input N:";
    int n;
    cin >> n;

    int steps = 1;
    int a = n;
    int b = GetHuiWenShu(a);

    while ( (a+b) != GetHuiWenShu(a+b) ) {

        a = a + b;
        b = GetHuiWenShu(a);

        steps++;
    }

    cout << steps << endl;

    return 0;
}


