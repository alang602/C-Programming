**字符串数组拼接**


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

功能：分解字符串为一组字符串。

参数说明：str为要分解的字符串，delim为分隔符字符串。

返回值：从str开头开始的一个个被分割的串。当没有被分割的串时则返回NULL。

其它：strtok函数线程不安全，可以使用strtok_r替代。

示例：

//借助strtok实现split
#define _CRT_SECURE_NO_WARNINGS


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





**字符串转换成整数**

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


#include <iostream>



int main() {



    //-----------------------------------------
    //sscanf()函数将给定的字符串转换为指定的数据类型，比如整数。
    const char* str_num = "555";
    int numdata1;
    sscanf(str_num, "%d", &numdata1);
    cout << str_num << " " << numdata1 << endl;

    return 0;
}

输出：

555 555







'
