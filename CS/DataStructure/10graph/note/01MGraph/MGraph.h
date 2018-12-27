#ifndef MGRAPH_H
    #define MGRAPH_H
    #include "../../myhead.h"

const int MAX_VERTEX_NUM = 20;
const int INFINITY = 10000;

class shortestPathInformation
{
public:
    bool node[MAX_VERTEX_NUM];

    int distance;
};

template <typename elemtype1, typename elemtype2>
class MGraph
{
public:
    bool isEmpty();

    void miniSpanTreeKruskal();

    void miniSpanTreePrim(elemtype1 vertex);

    void shortestPath_DIJ(elemtype1 vertex);

    void shortestPath_FLOYD(shortestPathInformation sp[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int display = 1);

protected:
    int kind;

    int vexNum;

    elemtype1 verxs[MAX_VERTEX_NUM];

    int arcNum;

    elemtype2 arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
};

template <typename elemtype1, typename elemtype2>
bool MGraph::isEmpty()
{

}

template <typename elemtype1, typename elemtype2>
void MGraph::miniSpanTreeKruskal()
{

}

template <typename elemtype1, typename elemtype2>
void MGraph::miniSpanTreePrim(elemtype1 vertex)
{

}

template <typename elemtype1, typename elemtype2>
void MGraph::shortestPath_DIJ(elemtype1 vertex)
{

}

template <typename elemtype1, typename elemtype2>
void MGraph::shortestPath_FLOYD(shortestPathInformation sp[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int display = 1)
{

}

#endif

