
**输入： 一个4为整数， 输出： 各位数字**

/*
      输入： 一个4为整数
      输出： 各位数字
 */

 
#include <iostream>

using namespace std;

int main()
{
    
    cout << "please input a 4-digital number:";

    int n;
    cin >> n;

    int thousand = n / 1000;
    int hundred = (n / 100) % 10;
    int ten = (n / 10) % 10;
    int one = n % 10;

    cout << thousand << " " << hundred << " " << ten << " " << one << " "<<endl;

    return 0;
}


output:

please input a 4-digital number:8534

8 5 3 4








**输入： 一个N位整数，不确定N,输出： 各位数字**


/*
      输入： 一个N位整数，不确定N
      输出： 各位数字
 */

 
#include <iostream>

using namespace std;

int main()
{
    
    cout << "please input a N-digital number:";

    int n;
    cin >> n;
    if (n <= 0) {
        cout << "N need > 0" << endl;
        return 1;
    }

    int* pArray = new int[n];
    int pos = 0;
    do{
        int c = n % 10;
        pArray[pos] = c;
        pos++;

        n = (n - c)/10;
    } while (n > 0);

    //output
    for (int i = pos - 1; i >= 0; i--) {
        cout << pArray[i] << " ";
    }

    //free
    free(pArray);

    return 0;
}

please input a N-digital number:5544

5 5 4 4
