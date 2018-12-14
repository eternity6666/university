#ifndef TEXTEDITOR_H
    #define TEXTEDITOR_H
    #include "SqString.h"

const int initCol = 10 + 5;
const int initRow = 10 + 5;

class textEditor
{
public:
    bool clear();

    void pDown();

    void pUp();

    void pLeft();

    void pRight();

    void deleteText(int len);

    void insertText(SqString tmp);

    void replaceText();

    void setText();

    void read(istream& in);

    textEditor();

    virtual ~textEditor();

protected:
    int pX;
    
    int pY;

    int pNum;

    SqString text;

    int maxX;

    int maxY;

    int maxNum;
};
bool textEditor::clear();
{
    text.clear();
    
    pX = 1;
    
    pY = 1;
    
    pNum = 1;
}

void textEditor::pDown()
{

}

void textEditor::pUp()
{

}

void textEditor::pLeft()
{

}

void textEditor::pRight()
{

}

void textEditor::deleteText(int len)
{

}

void textEditor::insertText(SqString tmp)
{

}

void textEditor::replaceText()
{

}

void textEditor::setText()
{
    cout << " 请输入每页的最大行号: ";
    cin >> pX;
    cout << " 请输入每页的最大列号: ";
    cin >> pY;
}
void textEditor::display(ostream& out)
{
    out << "    " << pNum << "/" << maxNum << "页" << endl;

    int digitX = 0;
    int tmpX = maxX;
    do
    {
        tmpX = tmpX / 10;
        digitX++;
    }while(tmpX > 0);

    SqString topLeft ="     "; 
    fei(1, digitX)
        topLeft = topLeft + ' ';

    out << topLeft;
    fei(1, maxY)
        out << i % 10;
    out << endl;

    out << topLeft;
    fei(1, maxY)
    {
        if(i == pY)
            out << "*";
        else
            out << ' ';
    }
    out << endl;

    fei(1, maxX)
    {
        if(i == pX)
            out << " *";
        else
            out << "  ";
        
        if(i < 10)
            fei(1, digitX - 1)
                out << ' ';
        else if(i < 100)
            fei(1, digitX - 2)
                out << ' ';
        else 
            fei(1, digitX - 3)
                out << ' ';
        out << i << ": ";

        SqString tmp;

        subString(tmp, maxX * maxY * (pNum - 1) + maxY * (pX - 1), maxY);
        cout << tmp << endl;

        subString(tmp, maxX * maxY * (pNum - 1) + maxY * (pX - 1), 1);
        cout << "  当前字符为: " << tmp << endl << endl;
    }
}

ostream operator << (ostream& out, textEditor &s)
{
    s.display(out);
    return out;
}

void textEditor::read(istream& in)
{
    clear();
    cout << "  请输入文本: " << endl;
    cout << "  请输入文本总行数: ";
    int n;
    while(cin >> n)
    {
        if(n >= 0)
            break;
        else
            cout << "  非法输入，请输入大于0的数: ";
    }
    int rearlyN = n;
    fei(1, n)
    {
        cout << "     ";
        SqString tmp;
        cin >> tmp;
        int len = tmp.getLength();
        if(len <= maxY)
        {
            fei(1, maxY - len)
                tmp = tmp + ' ';
        }
        else
        {
            int lenNum = len / maxY;
            if(len % maxY)
                lenNum++;
            fei(1, maxY * lenNum - len)
                tmp = tmp + ' ';
        }
        text = text + tmp;
    }
    cout << "  总共输入了" << n  << "行" << endl << endl;
    cout << "  当前文本为: " << endl;
    display(cout);

}

istream operator >> (istream& in, textEditor &s)
{
    s.read(in);
    return in;
}

textEditor::textEditor()
{
    pX = 1;

    pY = 1;

    pNum = 1;

    maxX = initRow;

    maxY = initCol;
}

textEditor::~textEditor()
{
    clear();
}
#endif

