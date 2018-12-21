#ifndef MYTSMATRIX_H
    #define MYTSMATRIX_H
    

#include "TSMatrix.h"

template <typename elemtype>
class myTSMatrix<elemtype>:public TSMatrix<elemtype>
{
public:
    void display(ostream& out);

    void read(istream& in);

};

template <typename elemtype>
void myTSMatrix<elemtype>::display(ostream& out)
{
    out << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
    out << "  ";
    char xh[] = "[ i] ";
    int col = getColNum();
    int row = getRowNum();

    out << "      ";
    fei(0, row)
    {
        if(i < 10)
            xh[2] = '0' + i;
        else
        {
            xh[1] = '0' + i / 10;
            xh[2] = '0' + i % 10;
        }
        out << xh;
    }
    out << endl;
    
    fei(0, col)
    {
        if(i < 10)
            xh[2] = '0' + i;
        else
        {
            xh[1] = '0' + i / 10;
            xh[2] = '0' + i % 10;
        }
        out << xh;


    }
    out << "  ";
}

template <typename elemtype>
ostream& operator << (ostream& out, myTSMatrix<elemtype>& s)
{
    s.display(out);
    return out;
}

template <typename elemtype>
void myTSMatrix<elemtype>::read(istream& in)
{

}

template <typename elemtype>
istream& operator >> (istream& in, myTSMatrix<elemtype>& s)
{
    s.read(in);
    return in;
}
#endif
