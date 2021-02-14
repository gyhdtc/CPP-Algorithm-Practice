#include <iostream>
using namespace std;

template <class DataType>
struct BiNode
{
    DataType data;
    BiNode<DataType>* lchild, *rchild, *parent;
};
template <class DataType>
class BiTree
{
public:
    BiTree() { root = Create(root, NULL); }
    ~BiTree() { Release(root); }

    void PreOrder() { PreOrder(root); }    //前序遍历
    void InOrder() { InOrder(root); }      //中序遍历
    void PostOrder() { PostOrder(root); }  //后序遍历

    BiNode<DataType>* BiFind(DataType target) { return BiFind(root, target); }
    bool BiInsert(DataType x) { return BiInsert(root, x); }
    bool BiDelete(DataType x) { return BiDelete(root, x); }
private:
    BiNode<DataType>* root;

    BiNode<DataType>* Create(BiNode<DataType> *bt, BiNode<DataType> *parent);

    void Release(BiNode<DataType> *bt);
    void PreOrder(BiNode<DataType> *bt);
    void InOrder(BiNode<DataType> *bt);
    void PostOrder(BiNode<DataType> *bt);

    BiNode<DataType>* BiFind(BiNode<DataType> *, DataType);
    bool BiInsert(BiNode<DataType> *, DataType);
    bool BiDelete(BiNode<DataType> *, DataType);
};
/*
** 创建 二叉树
** 通过输入创建
** 输入顺序为前序遍历
*/
template <class DataType>
BiNode<DataType>* BiTree<DataType>::Create(BiNode<DataType> *bt, BiNode<DataType> *parent)
{
    DataType ch;
    cin >> ch;
    if (ch == 0) bt = NULL;
    else
    {
        bt = new BiNode<DataType>;
        bt->data = ch;
        bt->parent = parent;
        bt->lchild = Create(bt->lchild, bt);
        bt->rchild = Create(bt->rchild, bt);
    }
    return bt;
}
/*
** 析构 二叉树
*/
template <class DataType>
void BiTree<DataType>::Release(BiNode<DataType> *bt)
{
    if(bt != NULL){
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}
/*
** 前序遍历
*/
template <class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *bt)
{
    if (bt == NULL) return;
    else
    {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
/*
** 中序遍历
*/
template <class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType> *bt)
{
    if(bt == NULL) return;
    else{
        InOrder(bt->lchild);
        cout << bt->data <<" ";
        InOrder(bt->rchild);
    }
}
/*
** 后序遍历
*/
template <class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType> *bt)
{
    if(bt == NULL) return;
    else{
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << " ";
    }
}
/*
** 二叉树查找
*/
template <class DataType>
BiNode<DataType>* BiTree<DataType>::BiFind(BiNode<DataType> *bt,DataType target)
{
    if (bt == NULL) return NULL;
    if (target < bt->data)
    {
        return BiFind(bt->lchild, target);
    }
    else if (target > bt->data)
    {
        return BiFind(bt->rchild, target);
    }
    else
    {
        return bt;
    }
}
/*
** 二叉树插入
*/
template <class DataType>
bool BiTree<DataType>::BiInsert(BiNode<DataType> *bt, DataType x)
{
    if (bt == NULL)
    {
        bt = new BiNode<DataType>;
        bt->data = x;
        return true;
    }
    if (x < bt->data)
    {
        if (bt->lchild == NULL)
        {
            BiNode<DataType>* temp = new BiNode<DataType>;
            temp->data = x;
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->parent = bt;
            bt->lchild = temp;
            return true;
        }
        else
        {
            return BiInsert(bt->lchild, x);
        }
    }
    else if (x > bt->data)
    {
        if (bt->rchild == NULL)
        {
            BiNode<DataType>* temp = new BiNode<DataType>;
            temp->data = x;
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->parent = bt;
            bt->rchild = temp;
            return true;
        }
        else
        {
            return BiInsert(bt->rchild, x);
        }
    }
    else
    {
        return false;
    }
}
/*
** 二叉树删除
*/
template <class DataType>
bool BiTree<DataType>::BiDelete(BiNode<DataType> *bt, DataType x)
{
    if (bt == NULL) return false;
    if (x < bt->data)
    {
        return BiDelete(bt->lchild, x);
    }
    else if (x > bt->data)
    {
        return BiDelete(bt->rchild, x);
    }
    else
    {
        if (bt->lchild == NULL && bt->rchild == NULL)
        {
            if (bt == bt->parent->lchild)
                bt->parent->lchild = NULL;
            if (bt == bt->parent->rchild)
                bt->parent->rchild = NULL;
            delete bt;
        }
        else if (bt->lchild == NULL && bt->rchild != NULL)
        {
            if (bt == bt->parent->lchild)
                bt->parent->lchild = bt->rchild;
            if (bt == bt->parent->rchild)
                bt->parent->rchild = bt->rchild;
            delete bt;
        }
        else if (bt->lchild != NULL && bt->rchild == NULL)
        {
            if (bt == bt->parent->lchild)
                bt->parent->lchild = bt->lchild;
            if (bt == bt->parent->rchild)
                bt->parent->rchild = bt->lchild;
            delete bt;
        }
        else
        {

        }
        return true;
    }
}

int main() {
    BiTree<int> gyh;
    gyh.InOrder();
    cout << endl;
    BiNode<int>* shit;
// test find
    shit = gyh.BiFind(8);
    if (shit != NULL)
    {
        cout << "Find OK " << shit->parent->data << endl;
    }
    else
    {
        cout << "Find NO" << endl;
    }
// test insert
    if (gyh.BiInsert(11))
    {
        cout << "Insert OK " << endl;
    }
    else
    {
        cout << "Insert NO" << endl;
    }
// test delete
    if (gyh.BiDelete(9))
    {
        cout << "Delete OK" << endl;
    }
    else
    {
        cout << "Delete NO" << endl;
    }
    if (gyh.BiDelete(10))
    {
        cout << "Delete OK" << endl;
    }
    else
    {
        cout << "Delete NO" << endl;
    }
    gyh.InOrder();
    return 0;
}
/*
20
8
5
3
0
0
7
0
0
10
9
0
0
0
0
*/