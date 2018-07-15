#ifdef MYQUENE_H
#define MYQUENE_H

class MyQuene
{
public:
    MyQuene(int queneCapacity);
    virtual ~MyQuene();
    void clearQuene();
    bool QueneEmpty() const;
    int QueneLength() const;
    bool EnQuene(int element);
    bool DeQuene(int &element);
    void QueneTraverse();
private:
    int *m_pQuene;
    int m_iQueneLen;
    int m_iQueneCapacity;
}

#endif