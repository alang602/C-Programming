/* 当 cin 读取数据时，它会传递并忽略任何前导白色空格字符（空格、制表符或换行符）。一旦它接触到。
为了解决这个问题，可以使用一个叫做 getline 的 C++ 函数。此函数可读取整行，包括前导和嵌入的空格，并将其存储在字符串对象中。


cin : 从第一个非空格字符即开始阅读，当它读取到下一个空白字符时，它将停止读取。 为了读取整行，可以使用一个叫做 getline 的 C++ 函数
getline() : 可以从cin读取一行
gets_s 用于从cin读取一行字符串 */

#include <iostream>
#include <sstream>     // getline需要的头文件
using namespace std;

int main()
{
    // gets_s
    char str[20];
    cout << "input a string:";
    gets_s(str);
    cout << "the string is:" << str << endl;


    //getline: 读取整行
    //输入单词
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    cout << word << endl;

    // 读取一段话
    // 读取一行输入,以逗号隔开
    string inputLine;
    cout << "Enter a line of data separated by commas: ";
    getline(cin, inputLine);
    cout << inputLine << endl;

    //以逗号分割字符串
    stringstream ss(inputLine);
    string targetWord;
    while (getline(ss, targetWord, ',') ){
        cout << targetWord << " ";
    }

}

