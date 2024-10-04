/*
    使用递推反转字符串

    输入字符串：wrewtyu

    输出：翻转之后的字符串：uytwerw
*/

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
using namespace std;

void reverse(char arr[], int index) {
    if (index == sizeof(arr)) {
        return;
    }

    // 递归翻转index+1 到结尾的字符
    reverse(arr, index + 1);

    //打印当前index的字符
    cout << arr[index];

    return;
}


int main()
{
    cout << "please input a string:" << endl;

    char str[100] = {};
    scanf("%s", str);

    reverse(str, 0);

    return 0;
}


