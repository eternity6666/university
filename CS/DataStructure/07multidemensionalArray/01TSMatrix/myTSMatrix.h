#ifndef MYTSMATRIX_H
    #define MYTSMATRIX_H
    

#include "TSMatrix.h"

// template <typename int>
class myTSMatrix:public TSMatrix<int>
{
public:
    void getByRand(int display);

    void display(ostream& out);

    void read(istream& in);

    myTSMatrix operator = (myTSMatrix rightS);

    myTSMatrix operator + (myTSMatrix rightS);

    myTSMatrix operator * (myTSMatrix rightS);

};

// template <typename int>
void myTSMatrix::getByRand(int display)
{
    this->clear();

    bool vis[10][10];
    int m[10][10];
    fei(0, 6)
        fej(0, 6)
            vis[i][j] = 0;

    this->rowNum = rand() % 6 + 1;
    this->colNum = rand() % 6 + 1;
    this->totalNum = rand() % (this->rowNum * this->colNum) + 1;

    if(display)
        cout << " 生成了一个包含" << this->totalNum << "个非零元素的" << this->rowNum << "×" <<  this->colNum << "的稀疏矩阵" << endl;

    this->data = new typename TSMatrix<int>::Triple[this->totalNum];
    assert(this->data != 0);

    if(display)
        cout << " 三元组形式如下: " << endl;
    fei(1, this->totalNum)
    {
        int x, y;
        while(1)
        {
            x = rand() % this->rowNum;
            y = rand() % this->colNum;

            if(!vis[x][y])
                break;
        }
        vis[x][y] = 1;
        int w = rand() % 100;
        m[x][y] = w;
        if(display)
        {
            cout << "      " << x << "      " << y;
            if(w < 10)
                cout << "       " << w << endl;
            else
                cout << "      " << w << endl;
        }
    }
    
    if(this->totalNum)
    {
        int k = 0;
        fei(0, this->rowNum - 1)
            fej(0, this->colNum - 1)
                if(vis[i][j])
                {
                    this->data[k].i = i;
                    this->data[k].j = j;
                    this->data[k].e = m[i][j];
                    k++;
                }
    }
    else
        this->data = NULL;
}

// template <typename int>
void myTSMatrix::display(ostream& out)
{
    char xh[] = "[ i] ";

    out << "      ";
    fei(0, this->colNum - 1)
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

    if(this->totalNum)
    {
        int row = 0;
        out << " [ 0] ";
        int prej = 0;
        fei(0, this->totalNum - 1)
        {
            while(row < this->data[i].i)
            {
                out << endl;
                row++;
                out << " ";
                if(row < 10)
                    xh[2] = '0' + row;
                else
                {
                    xh[1] = '0' + i / 10;
                    xh[2] = '0' + i % 10;
                }
                out << xh;
                prej = 0;
            }
            while(prej < this->data[i].j - 1)
            {
                out << "     ";
                prej++;
            }
            out.width(3);
            out.fill(' ');
            out.setf(ios::right, ios::adjustfield);
            out << this->data[i].e << "  ";
            prej = this->data[i].j;
        }
    }
}

// template <typename int>
ostream& operator << (ostream& out, myTSMatrix& s)
{
    s.display(out);
    return out;
}

// template <typename int>
void myTSMatrix::read(istream& in)
{
    this->clear();

    cout << " 请输入行数: ";
    while(in >> this->rowNum)
    {
        if(this->rowNum >= 0)
            break;
        else
            cout << " 请输入大于0的数: " << endl;
    }
    if(this->rowNum == 0)
    {
        cout << " 由于行数为0, 输入结束" << endl;
        return ;
    }

    cout << " 请输入列数: ";
    while(in >> this->colNum)
    {
        if(this->colNum >= 0)
            break;
        else
            cout << " 请输入大于0的数: " << endl;
    }
    if(this->colNum == 0)
    {
        cout << " 由于列数为0, 输入结束" << endl;
        return ;
    }

    cout << " 请输入非零元素的个数: ";
    while(in >> this->totalNum)
    {
        if(this->totalNum >= 0 && this->totalNum <= this->rowNum * this->colNum)
            break;
        else
            cout << " 请输入<0-" << this->rowNum * this->colNum << ">: " << endl;
    }
    cout << endl;

    if(this->totalNum)
    {
        this->data = new typename TSMatrix<int>::Triple[this->totalNum]; 
        assert(this->data != 0);

        fei(1, this->totalNum)
        {
            int x, y, e;
            cout << " 请输入行号: ";
            while(in >> x)
            {
                if(x >= 0 && x < this->rowNum)
                    break;
                else
                    cout << " 请输入<0-" << this->rowNum - 1 << ">: " << endl;
            }

            cout << " 请输入列号: ";
            while(in >> y)
            {
                if(y >= 0 && y < this->colNum)
                    break;
                else
                    cout << " 请输入<0-" << this->colNum - 1 << ">: " << endl;
            }

            cout << " 请输入元素的数据值: ";
            while(in >> e)
            {
                if(e != 0)
                    break;
                else
                    cout << " 请输入非零元素: ";
            }

            this->data[i - 1].i = x;
            this->data[i - 1].j = y;
            this->data[i - 1].e = e;
            cout << endl;
        }
        this->displayTriple();
    }
}

// template <typename int>
istream& operator >> (istream& in, myTSMatrix& s)
{
    s.read(in);
    return in;
}

myTSMatrix myTSMatrix::operator = (myTSMatrix rightS)
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

myTSMatrix myTSMatrix::operator + (myTSMatrix rightS)
{
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    myTSMatrix s;
    myTSMatrix t;

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

myTSMatrix myTSMatrix::operator * (myTSMatrix rightS)
{
    int i, j;

    int k1Max;
    int k2Max;
    int brow;
    
    int *rpos1;
    int *rpos2;

    int *ctemp;
    myTSMatrix s;
    myTSMatrix t;

    if(colNum != rightS.rowNum)
    {
        cout << " 两稀疏矩阵行列不等，无法相乘!" << endl;
        exit(1);
    }

    t.rowNum = s.rowNum = rowNum;
    t.colNum = s.colNum = rightS.colNum;

    if(totalNum * rightS.totalNum)
    {
        rpos1 = new int[rowNum];
        assert(rpos1 != 0);
        calculate_rpos(rpos1, 0);

        rpos2 = new int[rightS.rowNum];
        assert(rpos2 != 0);
        rightS.calculate_rpos(rpos2, 0);

        s.data = new Triple[s.rowNum * s.colNum];
        assert(s.data != 0);
        
        ctemp = new int[s.colNum];
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
#endif
