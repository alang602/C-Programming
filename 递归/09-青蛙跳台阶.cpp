/*
青蛙跳台阶问题
青蛙跳台阶问题就是关于一只青蛙再跳台阶时，一次能跳一个台阶或两个台阶，那么求出这只青蛙跳到第n个台阶有几种方法。

阶数  	1	2	3	4	5	6	7
方法数量	1	2	3	5	8	13	21


可以用递归解决：
jump(n) = jump(n-1) + jump(n-2)


*/
#include <iostream>
using namespace std;

int jump(int n) {
    if (1 == n) return 1;
    if (2 == n) return 2;

    return jump(n - 1) + jump(n - 2);
}

int main()
{
    cout << "please input the N:";

    int n;
    cin >> n;
    if (n <= 0) {
        cout << "n must be >0" << endl;
        return 1;
    }

    int ret = jump(n);
    cout << "frog need " << ret << " to reach n" << endl;

    return 0;
}


