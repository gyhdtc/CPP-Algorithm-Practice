#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

enum Color { red, black };

template <class T>
struct BNode
{
    // BNode() = default;
    // BNode(T x, Color c) : data(x), color(c) {}
    // BNode(T x, Color c, BNode<T>* root) : data(x), parent(root), color(c) {}
    T data;
    BNode<T>* lchild = NULL;
    BNode<T>* rchild = NULL;
    BNode<T>* parent = NULL;
    Color color;
};

template <class T>
class BTree
{
public:
    BTree() = default;
    ~BTree() { _Release(_root); }

    // void Create() { _root = _Create(_root, NULL); }
    void PreOrder() { _PreOrder(_root); }    //前序遍历
    void InOrder() { _InOrder(_root); }      //中序遍历
    void PostOrder() { _PostOrder(_root); }  //后序遍历
    void LevelOrder() { _LevelOrder(_root); }  //层次遍历

    bool BFind(T target) { return _BFind(_root, target); }
    bool BInsert(T x) { return _BInsert(_root, x); }
    bool BInsert(initializer_list<T> il);
    bool BDelete(T x) { return _BDelete(_root, x); }
    T getmin(BNode<T>* bt) { return _getmin(bt); }

private:
    BNode<T>* _root = NULL;
    // BNode<T>* _Create(BNode<T>*, BNode<T>*);

    void _Release(BNode<T>*);
    void _PreOrder(BNode<T>*);
    void _InOrder(BNode<T>*);
    void _PostOrder(BNode<T>*t);
    void _LevelOrder(BNode<T>*);

    bool _BFind(BNode<T>*, T);

    /* 待修改 */
    bool _BInsert(BNode<T>* & , T);
    /* 待修改 */

    bool _BDelete(BNode<T>*, T);
    T _getmin(BNode<T>*);

    /* 待补充 */
    void _Handler(BNode<T>*);
    void _LeftTurn(BNode<T>*);
    void _RightTurn(BNode<T>*);
    /* 待补充 */

    BNode<T>* _Auncle(BNode<T>*);
    BNode<T>* _Grandp(BNode<T>*);
    Color _AuncleColor(BNode<T>*);
    Color _GrandpColor(BNode<T>*);
};
/*
** 创建 红黑树
** 通过输入创建
** 输入顺序为前序遍历
*/
// template <class T>
// BNode<T>* BTree<T>::_Create(BNode<T>* bt, BNode<T>* parent)
// {
//     T ch;
//     cin >> ch;
//     if (ch == 0) bt = NULL;
//     else
//     {
//         bt = new BNode<T>;
//         bt->data = ch;
//         bt->parent = parent;
//         bt->lchild = _Create(bt->lchild, bt);
//         bt->rchild = _Create(bt->rchild, bt);
//     }
//     return bt;
// }
/*
** 析构 红黑树
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
        cout << bt->data << (bt->color == red ? "[R]" : "[B]") << " ";
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
    else
    {
        _InOrder(bt->lchild);
        cout << bt->data << (bt->color == red ? "[R]" : "[B]") <<" ";
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
    else
    {
        _PostOrder(bt->lchild);
        _PostOrder(bt->rchild);
        cout << bt->data << (bt->color == red ? "[R]" : "[B]") << " ";
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
            cout << temp->data << (temp->color == red ? "[r]" : "[b]") << " ";
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
/*
** 红黑树查找
*/
template <class T>
bool BTree<T>::_BFind(BNode<T>* bt, T target)
{
    if (bt == NULL) return false;
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
        return true;
    }
}
/*
** 红黑树插入
*/
template <class T>
bool BTree<T>::_BInsert(BNode<T>* &bt, T x)
{
    if (bt == NULL)
    {
        bt = new BNode<T>;
        bt->data = x;
        bt->color = red;
        bt->parent = NULL;
        _Handler(bt);
        return true;
    }
    if (x < bt->data)
    {
        if (bt->lchild == NULL)
        {
            // cout << 1;
            bt->lchild = new BNode<T>;
            bt->lchild->data = x;
            bt->lchild->color = red;
            bt->lchild->parent = bt;
            /* 处理函数 */
            _Handler(bt->lchild);
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
            bt->rchild->color = red;
            bt->rchild->parent = bt;
            /* 处理函数 */
            _Handler(bt->rchild);
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
** 红黑树插入 节点处理函数
*/
template <class T>
void BTree<T>::_Handler(BNode<T>* bt)
{
    // case 0 直接返回
    if (bt == NULL)
    {
        return;
    }
    // case 1 bt 是根节点
    if (bt == _root)
    {
        // cout << "R";
        bt->color = black;
        return;
    }
    // case 2 父节点是 黑
    if (bt->parent->color == black)
    {
        // cout << 2;
        return;
    }
    // case 3 父节点是 红色，叔节点是 红色
    if (bt->parent->color == red && _AuncleColor(bt) == red)
    {
        bt->parent->color = black;
        _Auncle(bt)->color = black;
        _Grandp(bt)->color = red;
        _Handler(_Grandp(bt));
    }
    // case 4 父节点是 红色，叔节点是 黑色
    if (bt->parent->color == red && _AuncleColor(bt) == black)
    {
        // case 4.1 直线型
        /* case 4.1.1 左直线 */
        if (bt == bt->parent->lchild && bt->parent == _Grandp(bt)->lchild)
        {
            _RightTurn(_Grandp(bt));
        }
        /* case 4.1.2 右直线 */
        else if (bt == bt->parent->rchild && bt->parent == _Grandp(bt)->rchild)
        {
            _LeftTurn(_Grandp(bt));
        }
        // case 4.2 三角形
        /* case 4.2.1 左三角 */
        else if (bt == bt->parent->rchild && bt->parent == _Grandp(bt)->lchild)
        {
            BNode<T>* grandp = _Grandp(bt);
            _LeftTurn(bt->parent);
            _RightTurn(grandp);
        }
        /* case 4.2.2 右三角 */
        else if (bt == bt->parent->lchild && bt->parent == _Grandp(bt)->rchild)
        {
            BNode<T>* grandp = _Grandp(bt);
            _RightTurn(bt->parent);
            _LeftTurn(grandp);
        }
        else
        {
            return;
        }
    }
}
/*
** 左旋             
*/
template <class T>
void BTree<T>::_LeftTurn(BNode<T>* bt)
{
    if (bt == NULL) return;
    if (bt == _root) _root = bt->rchild;
    BNode<T>* btp = bt->parent;
    BNode<T>* btr = bt->rchild;
    BNode<T>* btrl = bt->rchild->lchild;
    bt->color = red;
    btr->color = black;
    bt->rchild = btrl;
    bt->parent = btr;
    btr->lchild = bt;
    btr->parent = btp;
    if (btrl != NULL) btrl->parent = bt;
    if (btp != NULL)
    {
        if (btp->lchild == bt)
            btp->lchild = btr;
        else if (btp->rchild == bt)
            btp->rchild = btr;
        else
            return;
    }
}
/*
** 右旋            
*/
template <class T>
void BTree<T>::_RightTurn(BNode<T>* bt)
{
    if (bt == NULL) return;
    if (bt == _root) _root = bt->lchild;
    BNode<T>* btp = bt->parent;
    BNode<T>* btl = bt->lchild;
    BNode<T>* btlr = bt->lchild->rchild;
    bt->color = red;
    btl->color = black;
    bt->lchild = btlr;
    bt->parent = btl;
    btl->rchild = bt;
    btl->parent = btp;
    if (btlr != NULL) btlr->parent = bt;
    if (btp != NULL)
    {
        if (btp->lchild == bt)
            btp->lchild = btl;
        else if (btp->rchild == bt)
            btp->rchild = btl;
        else
            return;
    }
}
/*
** 获得叔节点颜色
*/
template <class T>
Color BTree<T>::_AuncleColor(BNode<T>* bt)
{
    BNode<T>* temp = _Auncle(bt);
    return (temp != NULL) ? temp->color : black;
}
/*
** 获得叔节点指针
*/
template <class T>
BNode<T>* BTree<T>::_Auncle(BNode<T>* bt)
{
    if (bt == NULL || bt->parent == bt || bt->parent == NULL || bt->parent->parent == NULL)
    {
        return NULL;
    }
    else
    {
        if (bt->parent == bt->parent->parent->lchild)
        {
            return bt->parent->parent->rchild ? (bt->parent->parent->rchild) : NULL;
        }
        else if(bt->parent == bt->parent->parent->rchild)
        {
            return bt->parent->parent->lchild ? (bt->parent->parent->lchild) : NULL;
        }
        else
        {
            return NULL;
        }
    }
}
/*
** 获得祖父节点颜色
*/
template <class T>
Color BTree<T>::_GrandpColor(BNode<T>* bt)
{
    BNode<T>* temp = _Grandp(bt);
    return (temp != NULL) ? temp->color : black;
}
/*
** 获得祖父节点指针
*/
template <class T>
BNode<T>* BTree<T>::_Grandp(BNode<T>* bt)
{
    if (bt == NULL || bt->parent == bt || bt->parent == NULL || bt->parent->parent == NULL)
    {
        return NULL;
    }
    else
    {
        return (bt->parent->parent);
    }
}
/*
** 红黑树插入 {数组}
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
// template <class T>
// bool BTree<T>::_BDelete(BNode<T>* bt, T x)
// {
//     if (bt == NULL) return false;
//     if (x < bt->data)
//     {
//         return _BDelete(bt->lchild, x);
//     }
//     else if (x > bt->data)
//     {
//         return _BDelete(bt->rchild, x);
//     }
//     else
//     {
//         if (bt->lchild == NULL && bt->rchild == NULL)
//         {
//             if (bt == bt->parent->lchild)
//                 bt->parent->lchild = NULL;
//             if (bt == bt->parent->rchild)
//                 bt->parent->rchild = NULL;
//             delete bt;
//         }
//         else if (bt->lchild == NULL && bt->rchild != NULL)
//         {
//             if (bt == bt->parent->lchild)
//                 bt->parent->lchild = bt->rchild;
//             if (bt == bt->parent->rchild)
//                 bt->parent->rchild = bt->rchild;
//             delete bt;
//         }
//         else if (bt->lchild != NULL && bt->rchild == NULL)
//         {
//             if (bt == bt->parent->lchild)
//                 bt->parent->lchild = bt->lchild;
//             if (bt == bt->parent->rchild)
//                 bt->parent->rchild = bt->lchild;
//             delete bt;
//         }
//         else
//         {
//             T min_in_rchild = _getmin(bt->rchild);
//             bt->data = min_in_rchild;
//             _BDelete(bt->rchild, min_in_rchild);
//         }
//         return true;
//     }
// }
/*
** 红黑树删除
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
** 查找 bt下最小值
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

template <class T>
void output(BTree<T>& gyh2)
{
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    gyh2.PreOrder();
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    gyh2.InOrder();
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    gyh2.LevelOrder();
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
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
    // gyh.BInsert(50);
    // gyh.BInsert(40);
    // gyh.BInsert(30);
    // gyh.BInsert(20);
    // gyh.BInsert(10);
    output<int>(gyh);
    return 0;
}