

**链表的简单操作：在链表头插入节点**
/* 链表的操作 */

#include <iostream>

using namespace std;

// 链表每个节点

struct NumNode {

    int num;
    NumNode* next;
};

// 插入节点

void insert(NumNode*& pHead, NumNode* pNode) {

    // 链表为空的情况
    if (pHead == NULL) {
        pHead = pNode;
        return;
    }

    //链表不为空，插入位置在链表头
    if (pHead != NULL) {
        pNode->next = pHead;
        pHead = pNode;
        return;
    }

    return;
}

// 打印

void print(NumNode* pHead) {

    NumNode* p = pHead;
    while (p != NULL) {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;

    return;
}

// 释放链表

void release(NumNode* pHead) {

    NumNode* p = pHead;
    NumNode* q = NULL;

    while (p != NULL) {
        q = p->next;

        free(p);
        p = q;
    }

    return;
}



int main() {

    NumNode* pHead = NULL;
    NumNode* pNode = NULL;

    // Create List
    pNode = new NumNode();
    pNode->num = 5;
    pNode->next = NULL;
    insert(pHead, pNode);


    pNode = new NumNode();
    pNode->num = 10;
    pNode->next = NULL;
    insert(pHead, pNode);

    pNode = new NumNode();
    pNode->num = 3;
    pNode->next = NULL;
    insert(pHead, pNode);

    pNode = new NumNode();
    pNode->num = 8;
    pNode->next = NULL;
    insert(pHead, pNode);


    //Print List
    print(pHead);


    //release memory
    release(pHead);

    return 0;
}

运行结果：
8 3 10 5

**链表有序操作：按照链表值排序**





#include <iostream>

using namespace std;


// 链表每个节点

struct NumNode {

    int num;
    NumNode* next;
};


// 插入节点

void insert(NumNode* &pHead, NumNode* pNode) {

    // 链表为空的情况
    if (pHead == NULL) {
        pHead = pNode;
        return;
    }
    
    //链表不为空，插入位置在链表头
    if (pNode->num < pHead->num) {
        pNode->next = pHead;
        pHead = pNode;
        return;
    }

    //链表不为空，插入位置不在表头
    NumNode* p = pHead;
    NumNode* q = pHead->next;
    while (q != NULL) {
        // 循环找插入位置
        if (pNode->num > q->num) {
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

// 打印

void print(NumNode* pHead) {

    NumNode* p = pHead;
    while (p != NULL) {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;

    return;
}


// 释放链表

void release(NumNode* pHead) {

    NumNode* p = pHead;
    NumNode* q = NULL;

    while (p != NULL) {
        q = p->next;

        free(p);
        p = q;
    }

    return;
}


// 删除num值的节点

void del(NumNode* &pHead, int num) {

    // 空链表
    if (pHead == NULL) {
        return;
    }

    // 删除的是头节点
    if (pHead->num == num) {
        NumNode* p = pHead;
        pHead = pHead->next;

        free(p);
        return;
    }

    //删除的不是头节点
    NumNode* p = pHead;
    NumNode* q = pHead->next;
    while (q != NULL) {
        //寻找删除的节点
        if (num == q->num) {
            break;
        }
        else {
            p = q;
            q = q->next;
        }
    }

    //删除位置在q
    if (q != NULL) {
        p->next = q->next;
        free(q);
    }

    return;
}



int main()
{

    NumNode* pHead = NULL;
    NumNode* pNode = NULL;
    
    // Create List
    pNode = new NumNode();
    pNode->num = 5;
    pNode->next = NULL;
    insert(pHead, pNode);


    pNode = new NumNode();
    pNode->num = 10;
    pNode->next = NULL;
    insert(pHead, pNode);

    pNode = new NumNode();
    pNode->num = 3;
    pNode->next = NULL;
    insert(pHead, pNode);

    pNode = new NumNode();
    pNode->num = 8;
    pNode->next = NULL;
    insert(pHead, pNode);


    //Print List
    print(pHead);

    // delete a node
    del(pHead, 5);
    print(pHead);

    //release memory
    release(pHead);

    return 0;

}


输出：

3 5 8 10

3 8 10



/*
    输入：读取nodes.txt，文件内容如下

1 1
3 3
5 5
1 5
3 1

    建立链表，链表的(x,y)从nodes.txt每行读取, 
    输出：将链表内容输出。
    
    要求：如果插入链表都是从头插入，编写程序。

    另外，如果插入链表是按照x升序排序，例如：
        1 1
        1 5
        3 1
        3 3
        5 5
    程序又该怎么写。


    
*/
