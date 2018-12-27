#ifndef MYTREE_H
#define MYTREE_H

#include "SqTree.h"

template<typename T>
class myseqtree :public SeqTree<T>
{
public:
    void setInitialAddress(int i);
    void randsqt(int n=-1);			//随机生成！
    void input(istream& in);
    void display();//输出顺序树
    void output(ostream& out);//  cout<<输出树状图
    void setSizeEmptyTree(int max_num);
};

template <typename T>
void myseqtree<T>::setInitialAddress(int i) {
    this->initialaddress=new T[i];
}

template<typename T>
void myseqtree<T>::input(istream& in)
{
    int n; T m;
    cout << "输入最后一个结点在顺序存储空间的下标：";
    in >> n;
    this->setfinalindex(n);
    cout << "请按层次顺序输入树的各结点：（空结点用‘0’表示）" << endl;
    for (int i = 0; i <= n; i++)
    {
        in >> m;
        this->setnode(i, m);
    }
    this->setnode(n + 1, '\0');
    return;
}
template<typename T>
istream& operator >> (istream&in, myseqtree<T>& s)
{
    s.input(in);
    return in;
}
template<typename T>
void myseqtree<T>::output(ostream& out)
{
    int n = this->getfinalindex();
    T* p = this->getinitialaddress();
    cout << "当前二叉树为：" << endl << endl;		//输出顺序树！！！！！！
    if (!p)
    {
        cout << "当前二叉树为空！！" << endl;
        return;
    }
    int h = high(n);
    int t = 3 * pow(2, h - 1);		//第一个起点宽度！
    int i = 0;
    while (i <= n)
    {
        out << setw(t);
        int k = high(i);
        int j;
        for (j = 1; j <= pow(2, k - 1) && i <= n; j++)
        {
            if(p[i]!=' ')
                out << p[i];
            else
                out << " ";
            out << setw(5);
            i++;
        }
        i = i - j + 1;
        out << endl << endl;
        out << setw(t - 1);
        for (int l = 1; l <= pow(2, k - 1) && i <= n; l++)
        {
            if(2 * i + 1 <= n && (p[2 * i + 1] >= '@'||(p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z')))
                out << "/";
            if (2 * i + 2 <= n && (p[2 * i + 2] >= '@'||(p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')))
                out << " \\";
            if ((2 * i + 1>n && 2 * i + 2>n) || (!((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')) && !((p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z'))))
                out << " ";
            out << setw(6);
            i++;

        }
        out << endl << endl;
        t = t - 4;
    }
    out << " " << endl;
}

template<typename T>
ostream& operator<<(ostream& out, myseqtree<T>&s)
{
    s.output(out);
    return out;
}

template<typename T>
void myseqtree<T>::randsqt(int n)
{
    if(n==-1) {
        cout << "输入想要随机生成的个数:";
        cin >> n;
    }
    char v;
    this->setfinalindex(n - 1);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        v = 'A' + rand() % ('Z' - 'A' + 1);
        this->setnode(i, v);
        cout << v;

    }
}
template<typename T>
void myseqtree<T>::display()
{
    int n = this->getfinalindex();
    T* p = this->getinitialaddress();
    cout << "\n该树的顺序存储输出为：" << endl;
    for (int i = 0; i <= n; i++)
    {
        if(i%9==0&&i)cout<<'\n';
        cout << "[ " << i << "]"<<" ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if(i%9==0&&i)cout<<'\n';
        cout << setw(4);
        if(p[i]==' ')cout<<' ';
        else cout << this->getnode(i);
        cout<<" ";
    }
    cout << endl;
}

template <typename T>
void myseqtree<T>::setSizeEmptyTree(int max_num) {
    this->initialaddress=new T[max_num];
    this->finalindex=max_num-1;
}
#endif

