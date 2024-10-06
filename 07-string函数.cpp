
/*
    std::string常用的方法
*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // 1. find: 在 string 字符串中, 从 pos 索引位置(包括该位置索引自身) 开始查找字符串的位置, 如果没有查到就返回 - 1;
    // 第一个参数：要查找的字符串   第二个参数：pos，起始位置开始查找
    string s1 = "Tom And Jerry, Hello World, Tom !";
    int index = s1.find("And", 0);         //find()查找s1中查找And字符串出现的起始下标，这里是4

    // 2. substr:string中截取字符串， 第一个参数：起始下标，第二个参数：截取长度
    string s2 = s1.substr(0, index - 1);   //substr()取字符串，第一个参数：起始下标，第二个参数：截取长度， 这里获取到的是从0开始的3位，是Tom

    //3. 拼接string
    string s3 = "Hello ";
    string s4 = "World";
    s3.append(s4);
    cout << s3 << endl;

    // 4. string类型转换成int
    string s5 = "152";
    int num1 = atoi(s5.c_str());
    cout << num1 << endl;



}


