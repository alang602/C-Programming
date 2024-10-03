
/*
     汉诺塔（递归）
*/
#include <iostream>
using namespace std;

// 移动N个圆盘，从from到to，借助temp
void MoveHanoi(int N, char from, char temp, char to) {
    if (N == 1) {
        cout << "move " << N << ":" << from << "--->" << to << endl;
        return;
    }
    else {

        MoveHanoi(N - 1, from, to, temp);
        cout << "move " << N << ":" << from << "--->" << to << endl;
        MoveHanoi(N - 1, temp, from, to);
    }
}


int main()
{
    cout << "please input n:";
    int N;
    cin >> N;

    MoveHanoi(N, 'A', 'B', 'C');

}
