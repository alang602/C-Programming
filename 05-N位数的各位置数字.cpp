
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




      

/*
    求出所有水仙花数

    水仙花数是指一个 3 位数，它的每个数位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153。

*/

#include <iostream>
using namespace std;

int main()
{
    for (int n = 100; n < 1000; n++) {
        int GeWei = n % 10;
        int ShiWei = (n / 10) % 10;
        int BaiWei = (n / 100) %10;

        if (n == (pow(GeWei, 3) + pow(ShiWei, 3) + pow(BaiWei, 3))) {
            cout<<n<<endl;
        }
    }

    return 0;
}







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

    int* pArray = new int[100];
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
