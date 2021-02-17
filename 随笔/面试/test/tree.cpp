#include <iostream>
using namespace std;

template <class T>
struct BNode
{
    BNode() = default;
    BNode(T x) : data(x), lchild(NULL), rchild(NULL), parent(NULL) {}
    BNode(T x, BNode<T>* root) : data(x), lchild(NULL), rchild(NULL), parent(root) {}
    T data;
    BNode<T>* lchild, *rchild, *parent;
};

template <class T>
class BTree
{
public:
    BTree() = default;
    ~BTree() { _Release(_root); }

    void Create() { _root = _Create(_root, NULL); }
    void PreOrder() { _PreOrder(_root); }    //前序遍历
    void InOrder() { _InOrder(_root); }      //中序遍历
    void PostOrder() { _PostOrder(_root); }  //后序遍历

    BNode<T>* BFind(T target) { return _BFind(_root, target); }
    bool BInsert(T x) { return _BInsert(_root, x); }
    bool BInsert(initializer_list<T> il);
    bool BDelete(T x) { return _BDelete(_root, x); }
    T getmin(BNode<T>* bt) { return _getmin(bt); }

private:
    BNode<T>* _root;
    BNode<T>* _Create(BNode<T>* bt, BNode<T>* parent);

    void _Release(BNode<T>* bt);
    void _PreOrder(BNode<T>* bt);
    void _InOrder(BNode<T>* bt);
    void _PostOrder(BNode<T>* bt);

    BNode<T>* _BFind(BNode<T>*, T);
    bool _BInsert(BNode<T>* &, T);
    bool _BDelete(BNode<T>*, T);
    T _getmin(BNode<T>*);
};
/*
** 创建 二叉树
** 通过输入创建
** 输入顺序为前序遍历
*/
template <class T>
BNode<T>* BTree<T>::_Create(BNode<T>* bt, BNode<T>* parent)
{
    T ch;
    cin >> ch;
    if (ch == 0) bt = NULL;
    else
    {
        bt = new BNode<T>;
        bt->data = ch;
        bt->parent = parent;
        bt->lchild = _Create(bt->lchild, bt);
        bt->rchild = _Create(bt->rchild, bt);
    }
    return bt;
}
/*
** 析构 二叉树
*/
template <class T>
void BTree<T>::_Release(BNode<T>* bt)
{
    if(bt != NULL){
        _Release(bt->lchild);
        _Release(bt->rchild);
        delete bt;
    }
}
/*
** 前序遍历
*/
template <class T>
void BTree<T>::_PreOrder(BNode<T>* bt)
{
    if (bt == NULL) return;
    else
    {
        cout << bt->data << " ";
        _PreOrder(bt->lchild);
        _PreOrder(bt->rchild);
    }
}
/*
** 中序遍历
*/
template <class T>
void BTree<T>::_InOrder(BNode<T>* bt)
{
    if(bt == NULL) return;
    else{
        _InOrder(bt->lchild);
        cout << bt->data <<" ";
        _InOrder(bt->rchild);
    }
}
/*
** 后序遍历
*/
template <class T>
void BTree<T>::_PostOrder(BNode<T>* bt)
{
    if(bt == NULL) return;
    else{
        _PostOrder(bt->lchild);
        _PostOrder(bt->rchild);
        cout << bt->data << " ";
    }
}
/*
** 二叉树查找
*/
template <class T>
BNode<T>* BTree<T>::_BFind(BNode<T>* bt, T target)
{
    if (bt == NULL) return NULL;
    if (target < bt->data)
    {
        return _BFind(bt->lchild, target);
    }
    else if (target > bt->data)
    {
        return _BFind(bt->rchild, target);
    }
    else
    {
        return bt;
    }
}
/*
** 二叉树插入
*/
template <class T>
bool BTree<T>::_BInsert(BNode<T>* &bt, T x)
{
    if (bt == NULL)
    {
        bt = new BNode<T>(x, bt);
        return true;
    }
    if (x < bt->data)
    {
        if (bt->lchild == NULL)
        {
            bt->lchild = new BNode<T>(x, bt);
            return true;
        }
        else
        {
            return _BInsert(bt->lchild, x);
        }
    }
    else if (x > bt->data)
    {
        if (bt->rchild == NULL)
        {
            bt->rchild = new BNode<T>(x, bt);
            return true;
        }
        else
        {
            return _BInsert(bt->rchild, x);
        }
    }
    else
    {
        return false;
    }
}
/*
** 二叉树插入 {数组}
*/
template <class T>
bool BTree<T>::BInsert(initializer_list<T> il)
{
    for (auto i : il)
    {
        if (!_BInsert(_root, i))
        {
            return false;
        }
    }
    return true;
}
/*
** 二叉树删除
*/
template <class T>
bool BTree<T>::_BDelete(BNode<T>* bt, T x)
{
    if (bt == NULL) return false;
    if (x < bt->data)
    {
        return _BDelete(bt->lchild, x);
    }
    else if (x > bt->data)
    {
        return _BDelete(bt->rchild, x);
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
            T min_in_rchild = _getmin(bt->rchild);
            bt->data = min_in_rchild;
            _BDelete(bt->rchild, min_in_rchild);
        }
        return true;
    }
}
/*
** 查找root下最小值
*/
template <class T>
T BTree<T>::_getmin(BNode<T>* bt)
{
    if (bt == NULL)
    {
        return T(NULL);
    }
    if (bt->lchild == NULL)
    {
        return bt->data;
    }
    else
    {
        return _getmin(bt->lchild);
    }
}

int main() {
    BTree<int> gyh;
    gyh.BInsert({10,8,5,3,9,15,11,20}) ? cout << "ok" << endl : cout << "no" << endl;

    BNode<int>* shit = gyh.BFind(8); // 这样不能运行，只能运行到 265 行，甚至连插入都运行不成。
    gyh.BFind(8);                    // 这样可以运行
                                     // 去掉这一行也可以运行
    // gyh.BFind(8);
    // shit != NULL ? cout << "Find OK " << shit->parent->data << endl : cout << "Find NO" << endl;
// test delete
    if (gyh.BDelete(10))
    {
        cout << "Delete OK" << endl;
    }
    else
    {
        cout << "Delete NO" << endl;
    }

    gyh.PreOrder();
    cout << endl;
    gyh.InOrder();
    cout << endl;
    gyh.PostOrder();
    return 0;
}
/*
          10
        /    \
       8     15 
     /  \   /  \
    5   9  11   20
  /
3    
*/