

/*
扶老奶奶过街问题 (提示： 逻辑思维解题 + 枚举法）
一共有5个红领巾，编号分别为A、B、C、D、E，老奶奶被他们其中一个扶过了马路。

　　五个红领巾各自说话：

　　A ：我和E都没有扶老奶奶

　　B ：老奶奶是被C和E其中一个扶过大街的

　　C ：老奶奶是被我和D其中一个扶过大街的

　　D ：B和C都没有扶老奶奶过街

　　E ：我没有扶老奶奶


　　已知五个红领巾中有且只有２个人说的是真话，请问是谁扶这老奶奶过了街？

　　若有多个答案，在一行中输出，编号之间用空格隔开
*/


#include <iostream>
using namespace std;




void solution() {

    // (0..4) 表示(A..E)每个人
    for (int i = 0; i < 5; i++) {

        // sum用来记录说真话胡数量
        int sum = 0;
        if (i != 0 && i != 4) { sum = sum + 1; }
        if (i == 2 || i == 4) { sum = sum + 1; }
        if (i == 2 || i == 3) { sum = sum + 1; }
        if (i != 1 && i != 2) { sum = sum + 1; }
        if (i != 4) { sum = sum + 1; }

        if (sum == 2) {
            cout << char(65 + i) << endl;;
        }
    }
}



/*
     扶老奶奶过街问题
*/

int main()
{

    solution();

    return 0;
}
