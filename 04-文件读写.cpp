**文件读写**


/*
     
     文件读写
     
     输入： chat.in 文件
     
     输出： chat.out 
     
     处理:  读取chat.in中的每一行聊天记录，每行加上说话的人，一人说一句，输出到chat.out
     
*/

#define _CRT_SECURE_NO_WARNINGS


#include \<iostream\>

#include <fstream.h>


using namespace std;


int main()
{

    // Open
    ifstream fin("chat.in");
    if (!fin) {
        cout << "open chat.in failed" << endl;
        return 1;
    }

    ofstream fout("chat.out");
    if (!fout) {
        cout << "open chat.out failed" << endl;
        return 1;
    }

    // Read line from chat.in and Add header for each line
    int count = 0;
    char A[100] = "A: ";
    char B[100] = "B: ";
    while (!fin.eof()) {
        char str_line[100];
        fin.getline(str_line, 100);
        
        count++;
        if (count % 2 == 1) {
            fout << strcat(A, str_line) << endl;;
        }
        else {
            fout << strcat(B, str_line) << endl;;
        }
    }

    // Close
    fin.close();
    fout.close();


    return 0;
}
