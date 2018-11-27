template <typename elemtype>
void Josephus(circularLinkList<elemtype> l, int start, int i)
{
    int times = 0;
    elemtype e;
    if(l.isEmpty())
    {
        cout << " 约瑟夫环为空, 无法出列" << endl;
        return ;
    }

    l.moveHead(start);
    while(!l.isEmpty())
    {
        l.deleteElem(i, e);
        cout << "\n 第" << ++times << "次出列的结点为" << e << ", 出列后的约瑟夫环为";
        if(!l.isEmpty())
        {
            cout << ":\n";
            l.display();
        }
        else
            cout << "空." << endl;
    }
}

