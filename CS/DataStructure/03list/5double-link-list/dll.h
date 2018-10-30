template<typename ElemType>
class doubleLinkList
{
public:
    class linkNode
    {
        ElemType data;
        linkNode *next;
        linkNode *prior;
    };
    typedef linkNode * nodeP;

    void clear();

    Status getElem(int i, ElemType & e);

    Status deleteElem(ElemType e);

    nodeP getHead();

    int getLength();

    Status insert(int i, ElemType e);

    bool isEmpty();

    Status locateElem(ElemType find_e, nodeP &r);

    Status nextElem(ElemType e, ElemType &next_e);
    
    doubleLinkList<ElemType> operator = (doubleLinkList<ElemType> rightL);

    Status priorElem(ElemType e, ElemType &prior_e);

    doubleLinkList();

    ~doubleLinkList();

    doubleLinkList(const doubleLinkList<ElemType> &otherL);
};

