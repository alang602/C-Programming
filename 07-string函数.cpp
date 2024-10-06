
/*
    std::string常用的方法
*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // 1. find(): 在 string 字符串中, 从 pos 索引位置(包括该位置索引自身) 开始查找字符串的位置, 如果没有查到就返回 - 1;
    // 第一个参数：要查找的字符串   第二个参数：pos，起始位置开始查找
    string s1 = "Tom And Jerry, Hello World, Tom !";
    int index = s1.find("And", 0);         //从s1的0位置开始查找And字符串出现的起始下标，这里是4
    cout << index << endl;

    // 2. substr:截取字符串， 第一个参数：起始下标，第二个参数：截取长度
    string s2 = s1.substr(0, index - 1);   //这里是从0开始的3位，是Tom
    cout << s2 << endl;

    // 3. rfind()：从右开始查找
    index = s1.rfind("Tom");  //这里返回第二个Tom的下标
    cout << index << endl;   


    //4. 拼接string
    string s3 = "Hello ";
    string s4 = "World";
    s3.append(s4);
    cout << s3 << endl;

    // 5. string类型转换成int
    string s5 = "152";
    int num1 = atoi(s5.c_str());
    cout << num1 << endl;

    //6. 字符数组转换成int
    char arr[10] = "120";
    int num2 = atoi(arr);
    cout << num2 << endl;




}


