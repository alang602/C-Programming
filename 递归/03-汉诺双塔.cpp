
/*
3.  汉诺双塔
试题来源
　　NOIP2007 普及组
问题描述
　　给定A、B、C三根足够长的细柱，在A柱上放有2n个中间有孔的圆盘，共有n个不同的尺寸，每个尺寸都有两个相同的圆盘，注意这两个圆盘是不加区分的（下图为n=3的情形）。现要将这些圆盘移到C柱上，在移动过程中可放在B柱上暂存。要求：
　　（1）每次只能移动一个圆盘；
　　（2）A、B、C三根细柱上的圆盘都要保持上小下大的顺序；
　　任务：设An为2n个圆盘完成上述任务所需的最少移动次数，对于输入的n，输出An。

输入格式
　　一个正整数n，表示在A柱上放有2n个圆盘。
输出格式
　　仅一行，包含一个正整数, 为完成上述任务所需的最少移动次数An。
样例输入
1
样例输出
2
样例输入
2
样例输出
6
数据规模和约定
　　对于50%的数据，1<=n<=25
　　对于100%的数据，1<=n<=200
提示
设法建立An与An-1的递推关系式。
注：
（如果没学高精度，可以不用考虑后50%的数据）

*/
#include <iostream>
using namespace std;

int moveTimes = 0;

void MoveDoublePlateHanoi(int n, char from, char temp, char to) {
    if (n == 2) {
        cout << "Move " << n - 1 << " : " << from << "--->" << to << endl;
        moveTimes++;

        cout << "Move " << n - 1 << " : " << from << "--->" << to << endl;
        moveTimes++;
    }
    else {
        MoveDoublePlateHanoi(n - 2, from, to, temp);

        cout << "Move " << n/2 << " : " << from << "--->" << to << endl;
        moveTimes++;

        cout << "Move " << n/2 << " : " << from << "--->" << to << endl;
        moveTimes++;

        MoveDoublePlateHanoi(n - 2, temp, from, to);
    }
}

int main()
{
    cout << "please input N:";
    int n;
    cin >> n;

    MoveDoublePlateHanoi(n*2, 'A', 'B', 'C');
    cout << "Move Times:" << moveTimes << endl;
}


