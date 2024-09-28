
**用strtok函数进行字符串分割**

原型： char *strtok(char *str, const char *delim);

功能：分解字符串为一组字符串。

参数说明：str为要分解的字符串，delim为分隔符字符串。

返回值：从str开头开始的一个个被分割的串。当没有被分割的串时则返回NULL。

其它：strtok函数线程不安全，可以使用strtok_r替代。

示例：

//借助strtok实现split

#include <string.h>

#include <stdio.h>
 
int main()
{

    char s[] = "Golden Global   View,disk * desk";
    
    const char *d = " ,*";
    
    char *p;
    
    p = strtok(s,d);
    
    while(p)
    
    {
    
        printf("%s\n",p);
        
        p=strtok(NULL,d);
        
    }
    
 
    return 0;
    
}




**strcmp比较字符串数组**


#include <iostream>

using namespace std;

#include <iostream>

#include <cstring> // 包含strcmp函数的头文件


int main() {

    //-------------------------------------------------
    // strcmp
    const char* str1 = "Hello";
    
    const char* str2 = "World";
    
    const char* str3 = "Hello";
    

    if (strcmp(str1, str2) < 0) {
    
        std::cout << str1 << " comes before " << str2 << std::endl;
        
    }
    
    else if (strcmp(str1, str2) > 0) {
    
        std::cout << str1 << " comes after " << str2 << std::endl;
        
    }
    
    else {
    
        std::cout << str1 << " is equal to " << str2 << std::endl;
        
    }
    

    // 字符串str1和str3相同，所以输出相等的信息
    
    if (strcmp(str1, str3) == 0) {
    
        std::cout << str1 << " is equal to " << str3 << std::endl;
        
    }
    

    return 0;
}








'
