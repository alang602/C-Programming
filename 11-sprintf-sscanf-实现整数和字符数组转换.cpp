#include <iostream>
using namespace std;

int main()
{
    // 整数转换成字符串
    int number1 = -12345;
    char str1[10];
    sprintf(str1, "%d", number1);
    cout << str1 << endl;

    // 字符串转换成整形
    char str2[10] = "-12345";
    int number2;
    sscanf(str2, "%d", &number2);
    cout << number2 << endl;

    return 0;
}
