#include<iostream>
#include<stdlib.h>
using namespace std;

typedef char ElemType;

//�������Ķ�������ṹ��Ҳ���Ƕ������Ĵ洢�ṹ��1��������2��ָ���򣨷ֱ�ָ�����Һ��ӣ�

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�������Ľ�������ǰ������ķ�ʽ��������������ȻҲ��������������ķ�ʽ����������
void CreateBiTree(BiTree *T)
{
    ElemType ch;
    cin >> ch;
    if (ch == '#')
        *T = NULL;  //��֤��Ҷ���
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        //if (!*T)
            //exit(OVERFLOW); //�ڴ����ʧ�����˳���
        (*T)->data = ch;//���ɽ��
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������    
    }
}
//��ʾ�Ա������Ľ�����ݽ��еĴ������,�˴������ǽ������ǰ��������
void operation1(ElemType ch)
{
    cout << ch << " ";
}
//�˴�������Ļ����ϣ����������
void operation2(ElemType ch, int level)
{
       cout << ch << "�ڵ�" << level << "��" << endl;
}


//�ݹ鷽ʽǰ�����������
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
        return;
/*�˴���ʾ�Ա������������еĲ������������Լ���Ҫ����в���������ֻ������˽�������*/
    //operation1(T->data);
    operation2(T->data, level); //����˲���

    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

//�ݹ鷽ʽ�������������

void InOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
InOrderTraverse(T->lchild,level+1);

//operation1(T->data);
operation2(T->data, level); //����˲���

InOrderTraverse(T->rchild,level+1);
}

//�ݹ鷽ʽ�������������

void PostOrderTraverse(BiTree T,int level)
{
if(T==NULL)
return;
PostOrderTraverse(T->lchild,level+1);
PostOrderTraverse(T->rchild,level+1);

//operation1(T->data);
operation2(T->data, level); //����˲���
}


int main()
{
    int level = 1; //��ʾ����
    BiTree T = NULL;
    cout << "����ǰ������ķ�ʽ������չ��������"; //��������AB#D##C##
    CreateBiTree(&T);// ������������û��������ô����

    cout << "�ݹ�ǰ��������Ϊ��" << endl;
    PreOrderTraverse(T, level);//����ǰ�����������operation1()��operation2()������ʾ�Ա����Ľ�����ݽ��еĴ������
    cout << endl;

    cout << "�ݹ�����������Ϊ��" << endl;
    InOrderTraverse(T, level);
    cout << endl;

    cout << "�ݹ����������Ϊ��" << endl;
    PostOrderTraverse(T, level);
    cout << endl;

    return 0;
}
