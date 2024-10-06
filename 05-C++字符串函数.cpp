**字符串数组拼接**



/*  strcat 将两个字符串拼接成一个字符串 */
#include <iostream>
using namespace std;

int main() {
        char str1[50] = "Hello ";
        
        char str2[50] = "World!";
        
        strcat(str1, str2);
        

        std::cout << str1 << std::endl; // 输出: Hello World!
        return 0;
}






**用strtok函数进行字符串分割**

原型： char *strtok(char *str, const char *delim);

功能：按照分隔符分割字符串，分割成一组字符串。

参数说明：str为要分解的字符串，delim为分隔符字符串。

返回值：从str开头开始的一个个被分割的串。当没有被分割的串时则返回NULL。

其它：strtok函数线程不安全，可以使用strtok_r替代。

示例：

//借助strtok实现split
#define _CRT_SECURE_NO_WARNINGS


//需要引入string头文件
#include <string>

#include <stdio.h>
 
int main()
{

    char s[] = "Zhangsan,22222,90,80";
    
    const char* d = ",";
    
    char* p;
    
    p = strtok(s, d);
    
    while (p)
    
    {
    
        printf("%s\n", p);
        
        p = strtok(NULL, d);
        
    }
    
    
 
    return 0;
    
}


输出：
Zhangsan
22222
90
80




**strcmp比较字符串数组**


#include <iostream>

using namespace std;

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





**字符串转换成整数**

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


#include <iostream>



int main() {



    //5. 字符数组转换成int
    char arr[10] = "120";
    int num2 = atoi(arr);
    cout << num2 << endl;

    return 0;
}

输出：

120







'
