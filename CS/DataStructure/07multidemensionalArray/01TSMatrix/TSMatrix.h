#ifndef TSMATRIX_H
    #define TSMATRIX_H

#include "../../myhead.h"
#include <iomanip>

template <typename elemtype>
class TSMatrix
{
private:
    class
    {
    public:
        int i;
        int j;
        elemtype e;
    };

public:
    void clear();
    
    void calculate_rpos(int *rpos, int display = 0);

    void displayTriple();

    void fastTransposMatrix(TSMatrix<elemtype> &s);

    int getColNum();

    elemtype getDatake(int p);

    int getDataki(int p);

    int getDatakj(int p);

    int getRowNum();

    int getTotalNum();

    bool isEmpty();

    TSMatrix<elemtype> operator = (TSMatrix<elemtype s);

    TSMatrix<elemtype> operator + (TSMatrix<elemtype s);

    TSMatrix<elemtype> operator * (TSMatrix<elemtype s);

    void transposeMatrix(TSMatrix<elemtype &s);

    TSMatrix();

    virtual ~TSMatrix();

    TSMatrix(const TSMatrix<elemtype> &s);

protected:
    int rowNum;
    int colNum;
    int totalNum;
    Triple *data;
};

template<typename elemtype>
void TSMatrix<elmetype>::clear()
{
    if(data)
        delete[] data;
    data = NULL;
    rowNum = colNum = totalNum = 0;
}

template<typename elemtype>
void TSMatrix<elemtype>::calculate_rpos(int* rpos, int display = 0)
{
    int k;
    int cur_i;
    int pre_num;
    int cur_num;
    if(!totalNum)
        return ;

    if(display)
    {
        for(cur_i = 0; cur_i < rowNum; ++cur_i)
            cout << "\t[" << cur_i << "]\t\t" << rpos[cur_i] << endl;
    }
}

template <typename elemtype>
void TSMatrix<elemtype>::displayTriple()
{
    int k;
    char no[] = "[ i]";

    cout << " 该" << rowNum << "*" << colNum << "稀疏矩阵共有";
    cout << totalNum << "个非零元素" << endl;

    cout << " 下标\t行\t列\t值" << endl;
    for(k = 0; k < totalNum; k++)
    {
        cout << " ";
        if(k < 10)
            no[2] = k + '0';
        else
        {
            no[1] = k / 10 + '0';
            no[2] = k % 10 + '0';
        }
        cout << "\t" << no;
        cout.width(7);
        cout.fill(' ');
        cout.setf(ios::right, ios::adjustfield);
        cout << data[k].i;
        cout.width(7);
        cout.fill(' ');
        cout.setf(ios::right, ios::adjustfield);
        cout << data[k].j;
        cout.width(7);
        cout.fill(' ');
        cout.setf(ios::right, ios::adjustfield);
        cout << data[k].e;
        cout << endl;
    }
}

template <typename elemtype>
int TSMatrix<elemtype>::getColNum()
{
    return colNum;
}

template <typename elemtype>
elemtype TSMatrix<elemtype>::getDataKE(int p)
{
    return data[p].e;
}

template <typename elemtype>
int TSMatrix<elemtype>::getDataKI(int p)
{
    return data[p].i;
}

template <typename elemtype>
int TSMatrix<elemtype>::getDataKJ(int p)
{
    return data[p].j;
}

template <typename elemtype>
int TSMatrix<elemtype>::getRowNum()
{
    return rowNum;
}

template <typename elemtype>
int TSMatrix<elemtype>::getTotalNum()
{
    return totalNum;
}

template <typename elemtype>
void TSMatrix<elemtype>::fastTransposeMatrix(TSMatrix<elemtype> &s)
{
    int k1;
    int k2;
    int cur_i;
    int pre_num;
    int cur_num;
    int *rpos;

    s.clear();
    s.rowNum = colNum;
    s.colNum = rowNum;
    s.totalNum = totalNum;

    if(!s.totalNum)
        return ;

    s.data = new Triple[totalNum];
    assert(s != 0);

    rpos = new int[s.rowNum];
    assert(rpos != 0);

    for(cur_i = 0; cur_i < s.rowNum; ++cur_i)
        rpos[cur_i] = 0;

    for(k1 = 0; k1 < totalNum; k1++)
        ++rpos[data[k1].j];

    pre_num = rpos[0];
    rpos[0] = 0;

    for(cur_i = 1; cur_i < colNum; ++cur_i)
    {
        cur_num = rpos[cur_i];
        rpos[cur_i] = rpos[cur_i - 1] + pre_num;
        pre_num = cur_num;
    }

    for(k1 = 0; k1 < totalNum; k1++)
    {
        cur_i = data[k1].j;
        k2 = rpos[cur_i];
        s.data[k2].i = data[k1].j;
        s.data[k2].j = data[k1].i;
        s.data[k2].e = data[k1].e;
        ++rpos[cur_i];
    }
    delete[] rpos;
}

template <typename elemtype>
bool TSMatrix<elemtype>::isEmpty()
{
    return totalNum ? true : false;
}

template <typename elemtype>
TSMatrix<elemtype> TSMatrix<elemtype>::operator = (TSMatrix<elemtype> rightS)
{
    if(this != &rightS)
    {
        clear();

        rowNum = rightS.rowNum;
        colNum = rightS.colNum;
        totalNum = rightS.totalNum;

        if(totalNum)
        {
            data = new Triple[totalNum];
            assert(data != 0);

            for(int k = 0; k < totalNum; k++)
            {
                data[k].i = rightS.data[k].i;
                data[k].j = rightS.data[k].j;
                data[k].e = rightS.data[k].e;
            }
        }
    }
    return *this;
}

template <typename elemtype>
TSMatrix<elemtype> TSMatrix<elemtype>::operator + (TSMatrix<elemtype> rightS)
{
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    TSMatrix s;
    TSMatrix t;

    if(colNum != rightS.colNum || rowNum != rightS.rowNum)
    {
        cout << " 两稀疏矩阵行列不等，无法相加!" << endl;
        exit(1);
    }

    t.rowNum = s.rowNum = rowNum;
    t.colNum = s.colNum = colNum;

    if(totalNum + rightS.totalNum)
    {
        s.data = new Triple[totalNum + rightS.totalNum];
        assert(s.data != 0);

        while(k1 < totalNum && k2 < rightS.totalNum)
        {
            if(data[k1].i < rightS.data[k2].i || data[k1].i == rightS.data[k2].i && data[k1].j < rightS.data[k2].j)
            {
                s.data[k3].i = data[k1].i;
                s.data[k3].j = data[k1].j;
                s.data[k3].e = data[k1].e;
                ++k3;
                ++k1;
            }
            else if(data[k1].i == rightS.data[k2].i && data[k1].j == rightS.data[k2].j)
            {
                if(data[k1].e + rightS.data[k2].e)
                {
                    s.data[k3].i = data[k1].i;
                    s.data[k3].j = data[k1].j;
                    s.data[k3].e = data[k1].e + rightS.data[k2].e;
                    ++k3;
                }
                ++k1;
                ++k2;
            }
            else
            {
                s.data[k3].i = rightS.data[k2].i;
                s.data[k3].j = rightS.data[k2].j;
                s.data[k3].e = rightS.data[k2].e;
                ++k3;
                ++k2;
            }
        }
        
        while(k1 < totalNum)
        { 
            s.data[k3].i = data[k1].i;
            s.data[k3].j = data[k1].j;
            s.data[k3].e = data[k1].e;
            ++k3;
            ++k1;
        }
        
        while(k2 < rightS.totalNum)
        {
            s.data[k3].i = rightS.data[k2].i;
            s.data[k3].j = rightS.data[k2].j;
            s.data[k3].e = rightS.data[k2].e;
            ++k3;
            ++k2;
        }

        t.totalNum = k3;
        t.data = new Triple[t.totalNum];
        assert(t.data != 0);

        for(int k3 = 0; k3 < t.totalNum; k3++)
        {
            t.data[k3].i = s.data[k3].i;
            t.data[k3].j = s.data[k3].j;
            t.data[k3].e = s.data[k3].e;
        }
    }
    return t;
}

template <typename elemtype>
TSMatrix<elemtype> TSMatrix<elemtype>::operator * (TSMatrix<elemtype> rightS)
{
    int i, j;

    int k1Max;
    int k2Max;
    int brow;
    
    int *rpos1;
    int *rpos2;

    elemtype *ctemp;
    TSMatrix s;
    TSMatrix t;

    if(colNum != rightS.rowNum)
    {
        cout << " 两稀疏矩阵行列不等，无法相乘!" << endl;
        exit(1);
    }

    t.rowNum = s.rowNum = rowNum;
    t.colNum = s.colNum = rightS.colNum

    if(totalNum * rightS.totalNum)
    {
        rpos1 = new int[rowNum];
        assert(rpos1 != 0);
        calculate_rpos(rpos1);

        rpos2 = new int[rightS.rowNum];
        assert(rpos2 != 0);
        rightS.calculate_rpos(rpos2);

        s.data = new Triple[s.rowNum * s.colNum];
        assert(s.data != 0);
        
        ctemp = new elemtype[s.colNum];
        assert(ctemp != 0);

        for(i = 0; i < s.rowNum; i++)
        {
            for(j = 0; j < s.colNum; j++)
                ctemp[j] = 0;

            if(i < rowNum - 1)
                k1Max = rpos1[i + 1];
            else
                k1Max = totalNum;

            for(int k1 = rpos1[i]; k1 < k1Max; k1++)
            {
                brow = data[k1].j;
                if(brow < rightS.rowNum - 1)
                    k2Max = rpos2[brow + 1];
                else
                    k2Max = rightS.totalNum;
                for(int k2 = rpos2[brow]; k2 < k2Max; k2++)
                {
                    j = rightS.data[k2].j;
                    ctemp[j] += data[k1].e * rightS.data[k2].e;
                }
            }

            for(j = 0; j < s.colNum; j++)
            {
                if(ctemp[j] != 0)
                {
                    s.data[t.totalNum].i = i;
                    s.data[t.totalNum].j = j;
                    s.data[t.totalNum].e = ctemp[j];
                    ++t.totalNum;
                }
            }
        }
            
        delete[] rpos1;
        delete[] rpos2;

        t.data = new Triple[t.totalNum];
        assert(t.data != 0);
        
        for(int k3 = 0; k3 < t.totalNum; k3++)
        {
            t.data[k3].i = s.data[k3].i;
            t.data[k3].j = s.data[k3].j;
            t.data[k3].e = s.data[k3].e;
        }
    }
    return t;
}

template <typename elemtype>
void TSMatrix<elemtype>::transposeMatrix(TSMatrix<elemtype> &s)
{
    int k1;
    int k2 = 0;
    int i;

    s.clear();

    if(totalNum)
    {
        s.rowNum = colNum;
        s.colNum = rowNum;
        s.totalNum = totalNum;

        s.data = new Triple[totalNum];
        assert(s != 0);

        for(i = 0; i < colNum; i++)
        {
            for(k1 = 0; k1 < totalNum; k1++)
            {
                if(data[k1].j == i)
                {
                    s.data[k2].i = data[k1].j;
                    s.data[k2].j = data[k1].i;
                    s.data[k2].e = data[k1].e;
                    ++k2;
                }
            }
        }
    }
}

template <typename elemtype>
TSMatrix<elemtype>::TSMatrix()
{
    data = NULL;
    rowNum = 0;
    colNum = 0;
    totalNum = 0;
}

template <typename elemtype>
TSMatrix<elemtype>::~TSMatrix()
{
    clear();
}

template <typename elemtype>
TSMatrix<elemtype>::TSMatrix(const TSMatrix<elemtype> &s)
{
    rowNum = s.rowNum;
    colNum = s.colNum;
    totalNum = s.totalNum;

    if(totalNum)
    {
        data = new Triple[totalNum];
        assert(data != 0);

        for(int k = 0; k < totalNum; k++)
        {
            data[k].i = s.data[k].i;
            data[k].j = s.data[k].j;
            data[k].e = s.data[k].e;
        }
    }
    else
        data = NULL;
}
#endif

