

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
// 需要注意的是，输入参数pHead在函数中有可能会变，所以传入需要到地址符&
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

// 释放链表，防止内存泄漏
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




    
**有序链表：按照链表节点中的值排序**
#include <iostream>

using namespace std;


// 链表每个节点
struct NumNode {

    int num;
    NumNode* next;
};


// 插入节点
// 需要注意的是，输入参数pHead在函数中有可能会变，所以传入需要到地址符&
void insert(NumNode* &pHead, NumNode* pNode) {

    // 链表为空的情况
    if (pHead == NULL) {
        pHead = pNode;
        return;
    }
    
    //链表不为空，插入节点的num值小于链表头节点的num，表示在表头插入
    if (pNode->num < pHead->num) {
        pNode->next = pHead;
        pHead = pNode;
        return;
    }

    //链表不为空，插入的位置不在表头，需要循环找到插入位置
    NumNode* p = pHead;
    NumNode* q = pHead->next;
    while (q != NULL) {
        // 循环找插入位置
        if (pNode->num < q->num) {
            break;
        }
        // 没找到，继续往后找
        else {
            p = q;
            q = q->next;
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




    
思考题：
/*
    输入：读取nodes.txt，文件内容如下

1 1
3 3
5 5
1 5
3 1

    建立链表，链表节点结构可以定义成：
    struct NumNode {

    int x;
    int y;
    NumNode* next;
};

    链表的(x,y)从nodes.txt每行读取,  链表的每个节点可以用malloc()动态生成：Node* pNode = (Node*)malloc(sizeof(Node)); 
    输出：将链表内容输出。
    
    要求：
    1)  如果插入链表都是从头插入，编写一个程序。

    2)  如果插入链表是按照x升序排序，例如：
        1 1
        1 5
        3 1
        3 3
        5 5
    程序又该怎么写。


    
*/
