

// 如果报 _CRT_SECURE_NO_WARNINGS 错误，可以在include前定义这个宏定义解决
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
    /* 
       scanf：  是C语言的输入(类似cin，cin是C++的输出),从标准输入（通常是键盘）输入
       printf： 是C语言的输出(类似cout, cout是C++的输出), 输出文本打印到标准输出（通常是控制台）。
    */
    // 例子：
    int num = 0;
    scanf("%d", &num);                   // 从键盘输入，按照格式化"%d"的形式，输入整数到num
    printf("input number : %d\n", num);  // 将整数num，按照格式化"%d"的形式，输出到控制台


    /*
       sscanf : 与scanf类似，都是用于输入的，只是scanf以键盘(stdin)为输入源，而sscanf以固定字符串为输入源。
       sprintf: 跟printf类似，都是用于输出的, 只是打印的目的地不同而已，sprintf打印到字符串中，printf则直接在控制台上输出
    */
    // sscanf例子
    char str1[10] = "-12345";
    int number1;
    sscanf(str1, "%d", &number1);  // 就是将str1按照"%d"格式化输入到number1中，可以用来将字符串转换成整数
    cout << number1 << endl;

    // sprintf例子
    int number2 = -12345;
    char str2[10];
    sprintf(str2, "%d", number2);  //将number2按照"%d"格式化输出到str2中，可以用来将整数转换成字符串
    cout << str2 << endl;

    return 0;
 
}

