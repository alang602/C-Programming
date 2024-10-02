/*
    使用递推反转字符串

    输入：wrewtyu

    输出：uytwerw
*/

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
using namespace std;

void reverse(char arr[], int index) {
    if (index == sizeof(arr)) {
        return;
    }

    reverse(arr, index + 1);
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


