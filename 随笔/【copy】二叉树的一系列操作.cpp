#include<iostream>
#include<stdlib.h>
using namespace std;

typedef char ElemType;

//二叉树的二叉链表结构，也就是二叉树的存储结构，1个数据域，2个指针域（分别指向左右孩子）

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉树的建立，按前序遍历的方式建立二叉树，当然也可以以中序或后序的方式建立二叉树
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    cin >> ch;
    if (ch == '#')
        *T = NULL;  //保证是叶结点
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        //if (!*T)
            //exit(OVERFLOW); //内存分配失败则退出。
        (*T)->data = ch;//生成结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树    
    }
}
//表示对遍历到的结点数据进行的处理操作,此处操作是将树结点前序遍历输出
void operation1(ElemType ch)
{
    cout << ch << " ";
}
//此处在输出的基础上，并输出层数
void operation2(ElemType ch, int level)
{
       cout << ch << "在第" << level << "层" << endl;
}


//递归方式前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
/*此处表示对遍历的树结点进行的操作，根据你自己的要求进行操作，这里只是输出了结点的数据*/
    //operation1(T->data);
    operation2(T->data, level); //输出了层数

    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

//递归方式中序遍历二叉树

void InOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
InOrderTraverse(T->lchild,level+1);

//operation1(T->data);
operation2(T->data, level); //输出了层数

InOrderTraverse(T->rchild,level+1);
}

//递归方式后序遍历二叉树

void PostOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
PostOrderTraverse(T->lchild,level+1);
PostOrderTraverse(T->rchild,level+1);

//operation1(T->data);
operation2(T->data, level); //输出了层数
}


int main()
{
    int level = 1; //表示层数
    BiTree T = NULL;
    cout << "请以前序遍历的方式输入扩展二叉树："; //类似输入AB#D##C##
    CreateBiTree(&T);// 建立二叉树，没有树，怎么遍历

    cout << "递归前序遍历输出为：" << endl;
    PreOrderTraverse(T, level);//进行前序遍历，其中operation1()和operation2()函数表示对遍历的结点数据进行的处理操作
    cout << endl;

    cout << "递归中序遍历输出为：" << endl;
    InOrderTraverse(T, level);
    cout << endl;

    cout << "递归后序遍历输出为：" << endl;
    PostOrderTraverse(T, level);
    cout << endl;

    return 0;
}
