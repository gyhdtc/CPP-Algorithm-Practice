#include <vector>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
struct BNode
{
    T data;
    BNode<T>* lchild = NULL;
    BNode<T>* rchild = NULL;
};
template <class T>
class BTree
{
public:
    BTree() = default;
    ~BTree() { _Release(_root); }
    void LevelOrder() { _LevelOrder(_root); }  //层次遍历
    void FanLevelOrder() { _FanLevelOrder(_root); }  //层次遍历
    bool BInsert(T x) { return _BInsert(_root, x); }
private:
    BNode<T>* _root = NULL;
    void _Release(BNode<T>*);
    void _PreOrder(BNode<T>*);
    void _InOrder(BNode<T>*);
    void _PostOrder(BNode<T>*t);
    void _LevelOrder(BNode<T>*);
    void _FanLevelOrder(BNode<T>*);
    bool _BInsert(BNode<T>* & , T);
};

template <class T>
void BTree<T>::_Release(BNode<T>* bt)
{
    if(bt != NULL)
    {
        _Release(bt->lchild);
        _Release(bt->rchild);
        delete bt;
    }
}
/*
** 层次遍历
*/
template <class T>
void BTree<T>::_LevelOrder(BNode<T>* root)
{
    queue<BNode<T>*> que;
    BNode<T>* temp = root;
    if(!root)
    {
        return;
    }
    que.push(temp);
    while(!que.empty())
    {
        queue<BNode<T>*> que_next;
        while(!que.empty())
        {
            temp = que.front();
            cout << temp->data << " ";
            que.pop();
            if(temp->lchild)
                que_next.push(temp->lchild);
            if(temp->rchild)
                que_next.push(temp->rchild);
        }
        cout << endl;
        que = que_next;
    }
}
template <class T>
void BTree<T>::_FanLevelOrder(BNode<T>* root)
{
    queue<BNode<T>*> que;
    BNode<T>* temp = root;
    if(!root)
    {
        return;
    }
    que.push(temp);
    while(!que.empty())
    {
        queue<BNode<T>*> que_next;
        while(!que.empty())
        {
            temp = que.front();
            cout << temp->data << " ";
            que.pop();
            if(temp->lchild)
                que_next.push(temp->lchild);
            if(temp->rchild)
                que_next.push(temp->rchild);
        }
        cout << endl;
        que = que_next;
    }
}
template <class T>
bool BTree<T>::_BInsert(BNode<T>* &bt, T x)
{
    if (bt == NULL)
    {
        bt = new BNode<T>;
        bt->data = x;
        return true;
    }
    if (x < bt->data)
    {
        if (bt->lchild == NULL)
        {
            bt->lchild = new BNode<T>;
            bt->lchild->data = x;
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
            bt->rchild = new BNode<T>;
            bt->rchild->data = x;
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
int main() {
    BTree<int> gyh;
    for (int i = 0; i < 10; ++i)
    {
        int t = rand()%100;
        cout << "insert : " << t;
        if (gyh.BInsert(t))
            cout << " ...... ok" << endl;
        else
            cout << " ...... no" << endl;
    }
    gyh.LevelOrder();
    return 0;
}