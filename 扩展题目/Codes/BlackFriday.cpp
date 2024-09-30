/*
黑色星期五

假定19980101，是周四

输入年份N（N》=1998），比如1998
输出：年份N中，有多少个黑色星期五（13号，还是星期五）

注意：闰年：能被4整除且不能被100整除，或者能被100整除也能被400整除

例如输入1998， 输出3
*/

#include <iostream>
using namespace std;

bool IsLeapYear(int n) {
    if (n % 4 == 0 && n % 100 != 0) { return true; }

    if (n % 100 == 0 && n % 400 == 0) { return true; }

    return false;
}


//闰年
int leap_month_days[12]   = { 31,29,31,30,31,30, 31,31,30,31,30,31 };
//平年
int noleap_month_days[12] = { 31,28,31,30,31,30, 31,31,30,31,30,31 };

int main()
{
    cout << "please a N (N>=1998):";

    int N;
    cin >> N;

    //计算1998到N年1月1号有多少天
    int days = 0;
    for (int i = 1998; i < N; i++) {
        if (IsLeapYear(i)) {
            days = days + 366;
        }
        else {
            days = days + 365;
        }
    }

    //判断N年是闰年还是平年
    int month_days[12] = {};
    if (IsLeapYear(N)) {
        for (int i = 0; i < 12; i++) {
            month_days[i] = leap_month_days[i];
        }
    }
    else {
        for (int i = 0; i < 12; i++) {
            month_days[i] = noleap_month_days[i];
        }
    }

    //19980101 (星期四） ---经过days天 --- N年0101 ---经过12天- N年1月13号 --经过30/31/28-- i月13号
    int init_day = days;
    int cnt = 0;
    for (int i = 0; i <= 12; i++) {
        if (i == 0) {
            init_day = init_day + 12;
            if (init_day % 7 == 1) {    // %7是星期四，+1是星期五
                cnt++;
            }
        }
        else {
            init_day = init_day + month_days[i - 1];
            if (init_day % 7 == 1) {

                cout << i + 1 << " month" << endl;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;

}


