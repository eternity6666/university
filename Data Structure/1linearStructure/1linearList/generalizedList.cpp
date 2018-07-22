/*
 * 这是广义表(Generalized List)
 * 广义表是线性表的推广
 * 对于线性表而言,n个元素都是基本的单元素
 * 广义表中,这些元素不仅可以使单元素也可以是另一个广义表
 */

#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct GNode *GList;
struct GNode{
    int tag;
    union{
        ElementType Data;
        GList SubList;
    }URegion;
    GList Next;
};

int main()
{
    return 0;
}
