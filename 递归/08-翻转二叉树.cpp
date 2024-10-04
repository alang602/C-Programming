/*
    使用递归建立二叉树

    1) 输入：root = [4,2,7,1,3,6,9]
2) 创建二叉树

        4
   2        7
1    3   6     9




     使用递归翻转二叉树：
1) 输入：root = [4,2,7,1,3,6,9]

使用"7. 建立二叉树"，创建二叉树
        4
   2        7
1    3   6     9

翻转二叉树
输出：二叉树
        4
   7        2
9    6   3     1
*/

#include <iostream>
using namespace std;


// Tree
struct Tree {
    int data;

    Tree* Left;
    Tree* Right;
};

// 插入节点
void insert(Tree* &pRoot, Tree* pNode) {
    if (pRoot == NULL) {
        pRoot = pNode;
        return;
    }

    // 如果小于等于根节点，插入左子树
    if (pNode->data <= pRoot->data) {
        insert(pRoot->Left, pNode);
    }
    else {  //否则插入右子树
        insert(pRoot->Right, pNode);
    }

    return;
}


//打印树
void print(Tree* pRoot) {
    if (pRoot == NULL) {
        return;
    }

    print(pRoot->Left);
    cout << pRoot->data << endl;
    print(pRoot->Right);

    return;
}




//翻转二叉树
void reverse(Tree* pRoot) {
    if (pRoot == NULL) {
        return;
    }

    // 前序遍历
    Tree* p = pRoot->Left;
    pRoot->Left = pRoot->Right;
    pRoot->Right = p;

    if (pRoot->Left != NULL) {
        reverse(pRoot->Left);
    }

    if (pRoot->Right != NULL) {
        reverse(pRoot->Right);
    }
}

int main()
{
    cout << "Please input a value(-1 means end):";
    int temp;
    cin >> temp;
    Tree* pRoot = NULL;

    while (temp != -1) {
        Tree* pNode = new Tree();
        pNode->data = temp;
        pNode->Left = NULL;
        pNode->Right = NULL;

        insert(pRoot, pNode);

        cout << "Please input a value(-1 means end):";
        cin >> temp;
    }

    if (pRoot == NULL) {
        cout << "This is empty Tree" << endl;
    }
    else {
        print(pRoot);
    }

    // 翻转二叉树后，打印
    cout << "==== after reverse ============" << endl;
    reverse(pRoot);
    if (pRoot == NULL) {
        cout << "This is empty Tree" << endl;
    }
    else {
        print(pRoot);
    }
    
    return 0;
}



运行结果

Please input a value(-1 means end):4
Please input a value(-1 means end):2
Please input a value(-1 means end):7
Please input a value(-1 means end):1
Please input a value(-1 means end):3
Please input a value(-1 means end):9
Please input a value(-1 means end):6
Please input a value(-1 means end):-1
1
2
3
4
6
7
9
==== after reverse ============
9
7
6
4
3
2
1
