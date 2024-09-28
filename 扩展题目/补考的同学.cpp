/*
补考的同学


输入描述
输入文件中每行为一个同学的成绩，格式如下：
姓名 学号 成绩
姓名是一个由大小写字母组成的长度小于30的字符串；
学号是一个由10位数字组成的字符串；
成绩是一个0-100之间的整数。
输入的最后一行是一个字符“#”，表示输入结束。

输出描述
按从小到大顺序每行输出一个需要补考的同学的学号，最后以一行“#”结束。


样例输入
maweizhi 2014222222 60
qiaoyuchen 2014111111 59
#


样例输出
2014111111
#


*/



#define _CRT_SECURE_NO_WARNINGS

// 链表每个节点
struct RejudgeStudent {

    char name[30];
    char no[10];
    int  score;

    RejudgeStudent* next;
};

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;




// 插入节点
void insert(RejudgeStudent*& pHead, RejudgeStudent* pNode) {
    // 链表为空的情况
    if (pHead == NULL) {
        pHead = pNode;
        return;
    }

    //链表不为空，插入位置在链表头
    if (strcmp(pHead->no, pNode->no) > 0) {
        pNode->next = pHead;
        pHead = pNode;
        return;
    }

    //链表不为空，插入位置不在表头
    RejudgeStudent* p = pHead;
    RejudgeStudent* q = pHead->next;
    while (q != NULL) {
        // 循环找插入位置
        if (strcmp(pNode->no, q->no) > 0)
        {
            p = q;
            q = q->next;
        }
        // 找到插入位置
        else {
            break;
        }
    }
    //插入位置在p/q之间
    pNode->next = q;
    p->next = pNode;

    return;
}


// 释放链表
void release(RejudgeStudent* pHead) {
    RejudgeStudent* p = pHead;
    RejudgeStudent* q = NULL;

    while (p != NULL) {
        q = p->next;

        free(p);
        p = q;
    }

    return;
}




int main()
{
    // Open
    ifstream fin("grade.txt");
    if (!fin) {
        cout << "open grade.txt failed" << endl;
        return 1;
    }

    ofstream fout("rejudge.txt");
    if (!fout) {
        cout << "open rejudge.txt failed" << endl;
        return 1;
    }

    // 读输入
    RejudgeStudent* pHead = NULL;
    const char* delimitor = " ";      //分隔符
    while (!fin.eof()) {
        char str_line[100];
        fin.getline(str_line, 100);
        if ( strcmp(str_line, "#") == 0 ) {
            break;
        }

        RejudgeStudent* pNode = (RejudgeStudent*)malloc(sizeof(RejudgeStudent));
        if (pNode == NULL) {
            cout << "malloc failed";
            return 1;
        }
        pNode->next = NULL;

        char* p;
        p = strtok(str_line, delimitor);
        strcpy(pNode->name, p);

        p = strtok(NULL, delimitor);
        strcpy(pNode->no, p);

        p = strtok(NULL, delimitor);
        sscanf(p, "%d", &pNode->score);

        if (pNode->score < 60) {
            insert(pHead, pNode);
        }
    }

    //写输出
    RejudgeStudent* p = pHead;
    while (p != NULL) {
        fout << p->no << endl;

        p = p->next;
    }
    fout << "#";


    //release
    release(pHead);


    // Close
    fin.close();
    fout.close();

    return 0;
}


