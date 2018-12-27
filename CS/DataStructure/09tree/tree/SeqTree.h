#ifndef SEQTREE_H
#define SEQTREE_H

#include<stdlib.h>
#include<string.h>
#include<cassert>
using namespace std;



int pow(int a, int b)
{
    if (b == 0)
        return 1;
    int sum = 1;
    for (int i = 1; i <= b; i++)
    {
        sum = sum*a;
    }
    return sum;
}
int high(int a)
{
    int h;
    for (h = 0; pow(2, h) < a + 2; h++);
    return h;
}
template<typename T>
class SeqTree
{
public:
    void clear();
    int getfinalindex();	//取最后一个节点在顺序存储空间中的下标
    T* getinitialaddress();		//返回顺序树首地址
    T getnode(int i);	//取下标为i的结点，即第i+1个结点
    SeqTree<T> operator=(SeqTree<T> rightt);
    void setfinalindex(int i);	//设置最后一个结点在顺序空间下的下标
    void setnode(int i, T value);		//设置下标为i的结点值（i+1个）

    SeqTree();
    ~SeqTree();
    SeqTree(const SeqTree<T> &seqt);
protected:
    T * initialaddress;
    int finalindex;
};

template <typename T>
void SeqTree<T>::clear()
{
    if (initialaddress)
        delete[]initialaddress;
    initialaddress = NULL;
    finalindex = -1;
}
template<typename T>
int SeqTree<T>::getfinalindex()
{
    return finalindex;
}
template<typename T>
T* SeqTree<T>::getinitialaddress()
{
    return initialaddress;
}
template<typename T>
T SeqTree<T>::getnode(int i)
{
    if (i<0 || i>finalindex)
    {
        cerr << " OVERFLOW";
        exit(1);				//!!!!!!!!!!?????????????????
    }
    return initialaddress[i];
}
template<typename T>
SeqTree<T> SeqTree<T>::operator=(SeqTree<T> right)
{
    if (this != &right)
    {
        finalindex = right.finalindex;
        if (finalindex != -1)
        {
            initialaddress = new T[finalindex + 1];
            assert(initialaddress != 0);
            for (int i = 0; i <= finalindex; i++)
                initialaddress[i] = right.initialaddress[i];
        }
    }
    return *this;
}
template<typename T>					//！！！！！！！！！！！！！！！！！！！！
void SeqTree<T>::setfinalindex(int i)
{
    if (!initialaddress || i > finalindex)
    {
        T* p = new T[i + 1];
        for (int j = 0; j <= finalindex; j++)
            p[j] = initialaddress[j];
        delete[]initialaddress;
        initialaddress = p;
        memset(p, 0, i + 1);
    }
    finalindex = i;


}
template<typename T>
void SeqTree<T>::setnode(int i, T value)
{
    initialaddress[i] = value;
    if (i > finalindex&&value != '\0')
        finalindex = i;
}

template<typename T>
SeqTree<T>::SeqTree()
{
    initialaddress = NULL;
    finalindex = -1;
}
template<typename T>
SeqTree<T>::~SeqTree()
{
    clear();
}
template<typename T>
SeqTree<T>::SeqTree(const SeqTree& other)
{
    initialaddress = NULL;
    finalindex = other.finalindex;
    if (finalindex != -1)
    {
        initialaddress = new T[finalindex + 1];
        assert(initialaddress != 0);
        for (int i = 0; i <= finalindex; i++)
            initialaddress[i] = other.initialaddress[i];
    }
}
#endif

