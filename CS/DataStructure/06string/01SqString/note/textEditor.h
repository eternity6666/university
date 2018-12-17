#ifndef TEXTEDITOR_H
    #define TEXTEDITOR_H
    #include "SqString.h"

const int initCol = 5;
const int initRow = 5;

class textEditor
{
public:
    bool clear();

    void pDown();

    void pUp();

    void pLeft();

    void pRight();

    void deleteText();

    void insertText();

    void replaceText();

    void setText();

    void read(istream& in);

    void display(ostream& out);

    textEditor();

    virtual ~textEditor();

private:
    SqString add_n(SqString tmp);

protected:
    int pX;
    
    int pY;

    int pNum;

    SqString text;

    int maxX;

    int maxY;

    int maxNum;
};

bool textEditor::clear()
{
    text.clear();
    
    pX = 1;
    
    pY = 1;
    
    pNum = 1;
}

void textEditor::pDown()
{
    int tmp = pX + 1;
    if(pX == maxX)
        pX = 1;
    else
        pX = tmp;
}

void textEditor::pUp()
{
    int tmp = pX - 1;
    if(pX == 0)
        pX = maxX;
    else
        pX = tmp;
}

void textEditor::pLeft()
{
    int tmp = pY - 1;
    if(pY == 0)
        pY = maxY;
    else
        pY = tmp;
}

void textEditor::pRight()
{
    int tmp = pY + 1;
    if(pY == maxY)
        pY = 1;
    else
        pY = tmp;
}

void textEditor::deleteText()
{
    cout << " 请输入要删除串的长度: ";
    int len;
    while(cin >> len)
    {
        if(len >= 0)
            break;
        else
            cout << " 请输入大于0的数: ";
    }
    this->text.strDelete(maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, len);
}

void textEditor::insertText()
{
    cout << " 请输入待插入文本: " << endl;
    SqString tmp;
    cout << "     ";
    char s[10000];
    int n = 0;
    while(scanf("%s", s) != EOF)
    {
        tmp = s;
        // cout << tmp << endl;
        int len = tmp.getLength();
        int unFullLen = maxY - len % maxY;
        if(len)
        {
            fei(1, unFullLen)
            {
                char tmpc[10] = " ";
                tmp = tmp + tmpc;
            }
        }
        // tmp = add_n(tmp);
        len = tmp.getLength();
        n = n + len / maxY;
        this->text.insert(maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, tmp);
        // cout << text << endl;
        cout << "     ";
        tmp.clear();
    }
    cin.clear();
    cout << " 总共" << n << "行" << endl;
}

void textEditor::replaceText()
{
    cout << " 请输入要替换的字符顺序串的长度: ";
    int n = this->text.getLength();
    n -= maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY - 1;
    int len;
    while(cin >> len)
    {
        if(len >= 1 && len <= n)
            break;
        else
            cout << " 你的输入非法，请输入<1-" << n << ">: ";
    }
    this->text.strDelete(maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, len);
    cout << " 请输入替换文本: " << endl;
    SqString tmp;
    cout << "     ";
    char s[10000];
    while(scanf("%s", s) != EOF)
    {
        tmp = s;
        // cout << tmp << endl;
        int len = tmp.getLength();
        int unFullLen = maxY - len % maxY;
        if(len)
        {
            fei(1, unFullLen)
            {
                char tmpc[10] = " ";
                tmp = tmp + tmpc;
            }
        }
        // tmp = add_n(tmp);
        len = tmp.getLength();
        n = n + len / maxY;
        this->text.insert(maxX * maxY * (pNum - 1) + maxY * (pX + n - 1) + pY, tmp);
        // cout << text << endl;
        cout << "     ";
        tmp.clear();
    }
    cin.clear();
    cout << " 总共" << n << "行" << endl;
}

void textEditor::setText()
{
    cout << " 请输入每页的最大行号: ";
    cin >> maxX;
    cout << " 请输入每页的最大列号: ";
    cin >> maxY;
}

void textEditor::display(ostream& out) 
{
    if(text.isEmpty())
        cout << " 当前文本为空" << endl;
    else
    {
        cout << "  当前文本为: " << endl;
        out << "        " << pNum << "/" << maxNum << "页" << endl;

        int digitX = 0;
        int tmpX = maxX;
        do
        {
            tmpX = tmpX / 10;
            digitX++;
        }while(tmpX > 0);

        char tmps[100] = "     ";
        SqString topLeft = tmps;
        fei(1, digitX - 1)
        {
            char tmpc[10] = " ";
            topLeft = topLeft + tmpc;
        }
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

        SqString tmp;

        fei(1, maxX)
        {
            tmp.clear();
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

            this->text.subString(tmp, maxX * maxY * (pNum - 1) + maxY * (i - 1) + 1, maxY);
            cout << tmp << endl;
        }

        this->text.subString(tmp, maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, 1);
        cout << "  当前字符为: " << tmp << endl;
    }
}

ostream& operator << (ostream& out, textEditor &s)
{
    s.display(out);
    return out;
}

void textEditor::read(istream& in)
{
    clear();
    cout << " 请输入文本: " << endl;
    int n = 0;
    SqString tmp;
    cout << "     ";
    char s[10000];
    while(scanf("%s", s) != EOF)
    {
        tmp = s;
        // cout << tmp << endl;
        int len = tmp.getLength();
        int unFullLen = maxY - len % maxY;
        if(unFullLen != maxY)
        {
            fei(1, unFullLen)
            {
                char tmpc[10] = " ";
                tmp = tmp + tmpc;
            }
        }
        // tmp = add_n(tmp);
        len = tmp.getLength();
        n = n + len / maxY;
        this->text = this->text + tmp;
        // cout << text << endl;
        cout << "     ";
        tmp.clear();
    }
    cin.clear();
    cout << " 总共" << n << "行" << endl;
    maxNum = n / maxX + 1;
    display(cout);
}

istream& operator >> (istream& in, textEditor &s)
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

    maxNum = 1;
}

textEditor::~textEditor()
{
    clear();
}

SqString textEditor::add_n(SqString tmp)
{
    int len = tmp.getLength();
    char tmpc[2] = "\n";
    SqString tmps = tmpc;
    fei(1, len - 1)
    {
        tmp.insert(i * maxY + i, tmps); 
    }
    tmp = tmp + tmps;
    return tmp;
}

#endif

