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
    void formatText();

protected:
    int pX;
    
    int pY;

    int pNum;

    SqString text;

    int maxX;

    int maxY;

    int maxNum;
};

void textEditor::formatText()
{
    if(text.isEmpty())
        return ;
    else
    {
        SqString tmp;
        tmp.clear();
        int len = text.getLength();
        bool flag = 0;
        fei(1, len)
        {
            SqString x;
            text.subString(x, i, 1);
            char empty[10] = " ";
            // cout << x << x.getLength() << endl;
            /*
            int sl;
            for(int i = 0; empty[i]; ++i)
                sl = i;
            cout << sl << endl;
            */
            // cout << (x == empty) << endl;
            if((x == empty) == 0)
            {
                // cout << 2 << endl;
                if(flag)
                {
                    int len = maxY - tmp.getLength() % maxY;
                    if(len < maxY)
                    {
                        SqString tmp2;
                        fei(1, len)
                            tmp2 = tmp2 + empty;
                        tmp.insert(tmp.getLength() + 1, tmp2);
                        flag = 0;
                    }
                    else
                        continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                // cout << 1 << endl;
                tmp.insert(tmp.getLength() + 1, x);
                flag = 1;
            }
        }
        // cout << tmp << endl;
        text = tmp;
    }

    int len = text.getLength();
    if(len % (maxX * maxY))
        maxNum = len / (maxX * maxY) + 1;
    else
        maxNum = len / (maxX * maxY);
}

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
    {
        if(pNum != maxNum) 
        {
            pNum++;
            pX = 1;
        }
        else
            cout << " 已到达文本最底端, 无法下移" << endl;
    }
    else
        pX = tmp;
}

void textEditor::pUp()
{
    int tmp = pX - 1;
    if(pX == 1)
    {
        if(pNum == 1)
            cout << " 已到达文本最顶端, 无法上移" << endl;
        else
        {
            pNum--;
            pX = maxX;
        }
    }
    else
        pX = tmp;
}

void textEditor::pLeft()
{
    int tmp = pY - 1;
    if(pY == 1)
    {
        if(pX == 1)
        {
            if(pNum != 1)
            {
                pNum--;
                pY = maxY;
                pX = maxX;
            }
            else
                cout << " 已到达文本最左端, 无法左移" << endl;
        }
        else
        {
            pY == maxY;
            pX--;
        }
    }
    else
        pY = tmp;
}

void textEditor::pRight()
{
    int tmp = pY + 1;
    if(pY == maxY)
    {
        if(pX == maxX)
        {
            if(pNum == maxNum)
                cout << " 已到达文本最右端, 无法右移" << endl;
            else
            {
                pNum++;
                pX = 1;
                pY = 1;
            }
        }
        else
        {
            pX++;
            pY = 1;
        }
    }
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

    formatText();
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
        if(len < maxY)
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

    int len = text.getLength();
    if(len % maxX)
        maxNum = n / maxX + 1;
    else
        maxNum = n / maxX;

    formatText();
}

void textEditor::replaceText()
{
    cout << " 请输入要替换的字符顺序串的长度: ";
    int n = this->text.getLength();
    n -= maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY - 1;
    int replaceLen;
    while(cin >> replaceLen)
    {
        if(replaceLen >= 1 && replaceLen <= n)
            break;
        else
            cout << " 你的输入非法, 请输入<1-" << n << ">: ";
    }
    text.strDelete(maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, replaceLen);
    cout << " 请输入替换文本: " << endl;
    SqString tmp;
    tmp.clear();
    SqString tmp2;
    cout << "     ";
    char s[10000];
    while(scanf("%s", s) != EOF)
    {
        tmp2 = s;
        int len = tmp2.getLength();

        int unFullLen = maxY - len % maxY;
        
        /*
        if(len < maxY)
        {
            fei(1, unFullLen)
            {
                char tmp2c[10] = " ";
                tmp2 = tmp2 + tmp2c;
            }
        }
        */
        len = tmp2.getLength();

        tmp = tmp + tmp2;
    }
    text.insert(maxX * maxY * (pNum - 1) + maxY * (pX - 1) + pY, tmp);

    formatText();
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
        out << " 当前文本为空" << endl;
    else
    {
        out << "  当前文本为: " << endl;
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
    if(n % maxX)
        maxNum = n / maxX + 1;
    else
        maxNum = n / maxX;

    formatText();

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

