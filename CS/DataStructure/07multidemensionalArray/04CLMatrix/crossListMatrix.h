#ifndef CROSSLISTMATRIX_H
    #define CROSSLITMATRIX_H
    #include "../../myhead.h"
template <typename elemtype>
class crossListMatrix
{
private:
    class node
    {
    public:
        int i;
        int j;
        elemtype e;
        class node *right, *down;
    };
    typedef node * nodeP;
public:
    void clear();

    int getColNum();

    nodeP getRowHead(int i);

    int getRowNum();

    int getTotalNum();

    bool isEmpty();

    crossListMatrix<elemtype> operator = (crossListMatrix<elemtype> rightS);

    crossListMatrix<elemtype> operator - (crossListMatrix<elemtype> rightS);

    crossListMatrix();

    virtual crossListMatrix();

    crossListMatrix(const crossListMatrix<elemtype>& otherS);

protected:
    int rowNum;
    int colNum;
    int totalNum;
    nodeP *rowHead, *colHead;
};

template <typename elemtype>
void crossListMatrix<elemtype>::clear()
{
    if(rowHead)
        delete[] rowHead;

    if(colHead)
        delete[] colHead;

    rowHead = NULL;
    colHead = NULL;
    rowNum = 0;
    colNum = 0;
    totalNum = 0;
}

template <typename elemtype>
int crossListMatrix<elemtype>::getColNum()
{
    return colNum;
}

template <typename elemtype>
typename crossListMatrix<elemtype>::nodeP crossListMatrix<elemtype>::getRowHead(int i)
{
    return rowHead[i];
}

template <typename elemtype>
int crossListMatrix<elemtype>::getRowNum()
{
    return rowNum;
}

template <typename elemtype>
int crossListMatrix<elemtype>::getTotalNum()
{
    return totalNum;
}

template <typename elemtype>
bool crossListMatrix<elemtype>::isEmpty()
{
    return totalNum ? false : true;
}

template <typename elemtype>
crossListMatrix<elemtype> crossListMatrix<elemtype>::operator = (crossListMatrix<elemtype> rightS)
{
    nodeP p1;
    nodeP rq1;
    nodeP *cq1;
    nodeP p2;

    if(this != &rightS)
    {
        clear();

        rowNum = rightS.rowNum;
        colNum = rightS.colNum;
        totalNum = rightS.totalNum;

        rowHead = new nodeP[rowNum];
        assert(rowHead != 0);
        for(int cur_i = 0; cur_i < rowNum; ++cur_i)
            rowHead[cur_i] = NULL;

        colHead = new nodeP[colNum];
        assert(colHead != 0);
        for(int cur_i = 0; cur_i < colNum; ++cur_i)
            colHead[cur_i] = NULL;

        if(totalNum)
        {
            cq1 = new nodeP[colNum];
            assert(cq1 != 0);
            for(int cur_j = 0; cur_j < colNum; ++cur_j)
                cq1[cur_j] = colHead[cur_j] = NULL;

            for(int cur_i = 0; cur_i < colNum; ++cur_i)
            {
                for(p2 = rightS.rowHead[cur_i]; p2; p2 = p2->right)
                {
                    p1 = new node;
                    assert(p1 != 0);

                    p1->i = p2->i;
                    p1->j = p2->j;
                    p1->e = p2->e;
                    p1->right = NULL;
                    p1->down = NULL;

                    if(!rowHead[cur_i])
                    {
                        rowHead[cur_i] = p1;
                    }
                    else
                    {
                        rq1->right = p1;
                    }
                    rq1 = p1;

                    cur_j = p1->j;

                    if(!colHead[cur_j])
                    {
                        colHead[cur_j] = p1;
                    }
                    else
                    {
                        cq1[cur_j]->down = p1;
                    }
                    cq1[cur_j] = p1;
                }
            }
            delete[] cq1;
        }
    }
    return *this;
}

template <typename elemtype>
crossListMatrix<elemtype> crossListMatrix<elemtype>::operator + (crossListMatrix<elemtype> rightS)
{
    nodeP p1;
    nodeP p2;
    nodeP p3;
    nodeP rq3;
    nodeP *cq3;

    crossListMatrix T;

    if(colNum != rightS.colNum || rowNum != rightS.rowNum)
    {
        cout << " 两稀疏矩阵行列不等，无法相加!" << endl;
        exit(1);
    }
    T.rowNum = rowNum;
    T.colNum = colNum;
    T.totalNum = 0;
    T.rowHead = new nodeP[T.rowNum];
    assert(T.rowHead != 0);
    for(int cur_i = 0; cur_i < T.rowNum; ++cur_i)
        T.rowHead[cur_i] = NULL;

    if(totalNum + rightS.totalNum)
    {
        cq3 = new nodeP[T.colNum];
        assert(cq3 != 0);

        for(int cur_j = 0; cur_j < T.colNum; ++cur_j)
            cq3[cur_j] = colHead[cur_j] = NULL;

        for(cur_i = 0; cur_i < T.rowNum; ++cur_i)
        {
            p1 = rowHead[cur_i];
            p2 = rightS.rowHead[cur_i];
            rq3 = NULL;
            while(p1 || p2)
            {
                if(p1 && p2 && p1->j == p2->j && p1->e + p2->e == 0)
                {
                    p1 = p1->right;
                    p2 = p2->right;
                }
                else
                {
                    p3 = new node;
                    assert(p3 != 0);

                    p3->right = NULL;
                    p3->down = NULL;

                    if(p1 && (!p2 || p1->j < p2->j))
                    {
                        p3->i = p1->i;
                        p3->j = p1->j;
                        p3->e = p1->e;
                        p1 = p1->right;
                    }
                    else if(p2 && (!p1 || p2->j < p1->j))
                    {
                        p3->i = p2->i;
                        p3->j = p2->j;
                        p3->e = p2->e;
                        p2 = p2->right;   
                    }
                    else if(p1->j == p2->j && p1->e + p2->e)
                    {
                        p3->i = p1->i;
                        p3->j = p1->j;
                        p3->e = p1->e + p2->e;
                        p1 = p1->right;
                        p2 = p2->right;
                    }
                }
                if(!T.rowHead[cur_i])
                {
                    T.rowHead[cur_i] = p3;
                }
                else
                {
                    rq3->right = p3;
                }
                rq3 = p3;

                cur_j = p3->j;
                if(!T.colHead[cur_j])
                {
                    T.colHead[cur_j] = p3;
                }
                else
                {
                    cq3[cur_j]->down = p3;
                }
                
                cq3[cur_j] = p3;
                ++T.totalNum;
            }
        }
        delete[] cq3;
    }
    return T;
}

template <typename elemtype>
crossListMatrix<elemtype>::crossListMatrix()
{
    rowNum = 0;
    colNum = 0;
    totalNum = 0;

    rowHead = NULL;
    colHead = NULL;
}

template <typename elemtype>
crossListMatrix<elemtype>::~crossListMatrix()
{
    clear();
}

template <typename elemtype>
crossListMatrix<elemtype>::crossListMatrix(const crossListMatrix<elemtype>& otherS)
{
    nodeP p1;
    nodeP rq1;
    nodeP *cq1;
    nodeP p2;

    rowNum = otherS.rowNum;
    colNum = otherS.colNum;
    totalNum = otherS.totalNum;

    rowHead = new nodeP[rowNum];
    assert(rowHead != 0);
    for(int cur_i = 0; cur_i < rowNum; ++cur_i)
        rowHead[cur_i] = NULL;

    colHead = new nodeP[colNum];
    assert(colHead != 0);
    for(int cur_j = 0; cur_j < colNum; ++cur_j)
        colHead[cur_j] = NULL;

    if(totalNum)
    {
        cq1 = new nodeP[colNum];
        assert(cq1 != 0);
        for(int cur_j = 0; cur_j < colNum; ++cur_j)
            cq1[cur_j] = colHead[cur_j] = NULL;

        for(int cur_i; cur_i < otherS.rowNum; ++cur_i)
        {
            for(p2 = otherS.rowHead[cur_i]; p2; p2 = p2->right)
            {
                p1 = new node;
                assert(p1 != 0);
                p1->i = p2->i;
                p1->j = p2->j;
                p1->e = p2->e;
                
                p1->right = NULL;
                p1->down = NULL;

                if(!rowHead[cur_i])
                {
                    rowHead[cur_i] = p1;
                }
                else
                {
                    rq1->right = p1;
                }
                rq1 = p1;

                cur_j = p1->j;
                if(!colHead[cur_j])
                {
                    colHead[cur_j] = p1;
                }
                else
                {
                    cq1[cur_j]->down = p1;
                }
                cq1[cur_j] = p1;
            }
        }
        delete[] cq1;
    }
}
#endif

