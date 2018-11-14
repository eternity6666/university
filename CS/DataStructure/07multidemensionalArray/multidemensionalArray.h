#include "myhead"
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

    for(cur_i = 0; cur_i < rowNum; 
}
