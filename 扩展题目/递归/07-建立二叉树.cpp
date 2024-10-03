/*
    使用递归建立二叉树

    1) 输入：root = [4,2,7,1,3,6,9]
2) 创建二叉树

        4
   2        7
1    3   6     9

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
    
    return 0;
}

