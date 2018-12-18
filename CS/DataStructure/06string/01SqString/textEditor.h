#ifndef TEXTEDITOR_H
    #define TEXTEDITOR_H
    #include "SqString.h"

/*
 * 设计思路: 
 *     1. 核心思路(文本的储存):
 *            使用顺序串数组储存
 */

const int firstSize = 10;

class textEditor
{
public:
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
    void clear();

    bool isEmpty();

    int cacuLenNow();
    
    void removeEmpty();

protected:
    int pX;

    int pY;

    int pNum;

    int maxX;
    
    int allNum;

    int maxY;

    int maxNum;

    int editorSize;

    SqString *text;
};

void textEditor::clear()
{
    fei(1, allNum)
        text[i].clear();

    allNum = 0;
    pX = 1;
    pY = 1;
    pNum = 1;
}

bool textEditor::isEmpty()
{
    fei(1, allNum)
        if(text[i].isEmpty())
            continue;
        else
            return false;
    return true;
}

void textEditor::removeEmpty()
{
    int n = 0;
    fei(1, allNum)
        if(text[i - 1].isEmpty())
            n++;

    SqString tmp;

    tmp = new SqString[allNum - n];
    assert(tmp != 0);

    int j = 0;
    fei(1, allNum)
    {
        if(text[i - 1].isEmpty())
            continue;
        else
        {
            tmp[j] = text[i - 1];
            j++;
        }
    }

    delete[] text;

    text = new SqString [allNum - n];
    assert(text != 0);

    fei(1, allNum - n)
        text[i - 1] = tmp[i - 1];

    delete[] tmp;

    allNum = allNum - n;
}

int textEditor::cacuLenNow()
{
    return text[(pNum - 1) * maxX + pX - 1].getLength();
}

void textEditor::pDown()
{
    /*
       下移可能出现的情况:
       * 1. 下移后翻页
         * pX = 1;
         * pNum++;
       * 2. 已到达文本最末行, 无法下移
         * cout << " 已到达文本最末行, 无法下移" << endl;
       * 3. 正常下移
         * pX++
    */
    if((pX + 1 + (pNum - 1) * maxX) <= allNum)
    {
        if((pX + 1) <= maxX)
            pX++;
        else
        {
            pX = 1;
            pNum++;
        }
        int len = text[pX - 1].getLength();
        if(pY > len)
            pY = len;
    }
    else
    {
        cout << " 已到达文本编辑器的最低端, 光标无法下移" << endl;
        pX = pX;
    }
}

void textEditor::pUp()
{
    if((pX - 1 + (pNum - 1) * maxX) >= 1)
    {
        if((pX - 1) >= 1)
            pX--;
        else
        {
            pX = maxNum;
            pNum--;
        }
        int len = cacuLenNow(); 
        if(pY > len)
            pY = len;
    }
    else
    {
        cout << " 已到达文本编辑器的最顶端, 光标无法上移" << endl;
        pX = pX;
    }
}

void textEditor::pLeft()
{
    if(pX == 1 && pNum == 1 && pY == 1)
        cout << " 已到达文本编辑器的最左端，光标无法左移" << endl;
    else if(pY - 1 >= 1)
        pY--;
    else
    {
        if(pX == 1)
        {
            pNum--;
            pX = maxX;
        }
        else
        {
            pX--;
        }
        pY = cacuLenNow(); 
    }
}

void textEditor::pRight()
{
    int len = cacuLenNow();
    if(pY == len)
    {
        // 光标在文本最后一行
        if(pX + maxY * (pNum - 1) == allNum)
            cout << " 已到达文本最右端，光标无法右移" << endl;
        // 光标在翻页前最后一行
        else if(pX == maxX)
        {
            pNum++;
            pY = 1;
            pX = 1;
        }
        // 光标不翻页
        else
        {
            pY = 1;
            pX++;
        }
    }
    else
        pY++;
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
            cout << " 请输入大于0的数: " << endl;
    }


    removeEmpty();
}

void textEditor::insertText()
{

}

void textEditor::replaceText()
{

}

void textEditor::setText()
{
    cout << " 请输入每页的最大行号: ";
    cin >> maxX;
    cout << " 请输入每行的最大(字符数)列号: ";
    cin >> maxY;
}

void textEditor::read(istream& in)
{
    cout << " 请输入文本: " << endl;

    char leftString[10] = "     ";

    int n;

    // input()
    char s[1000000];
    cout << leftString;
    while(scanf("%s", s) != EOF)
    {
        SqString tmp = s;

        int len = tmp.getLength();
        int x;
        if(len % maxX)
            x = len / maxX + 1;
        else
            x = len / maxX;


        n = n + x;
    }

    cout << " 总共" << n << "行" << endl;
    allNum = n;

    display(cout);
}

istream& operator >> (istream& in, textEditor& s)
{
    s.read(in);
    return in;
}

void textEditor::display(ostream& out)
{
    if(isEmpty())
        out << " 当前文本为空. " << endl;
    else
    {
        out << " 当前文本为: " << endl;
        out << "         " << pNum << "/" << maxNum << endl;
        
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

        int nowXNum = 0;
        if((allNum - (pNum - 1) * maxX) < maxX)
            nowXNum = allNum - (pNum - 1) * maxX;
        else
            nowXNum = maxX;

        SqString tmp;
        fei(1, nowXNum)
        {
            tmp.clear();
            if(i == pX)
                out << " *";
            else
                out << "  ";

            int xw = 0;
            int tmpi = i;
            do
            {
                tmpi = tmpi / 10;
                xw++;
            }while(tmpi > 0);
            fei(1, digitX - xw)
                out << ' ';
            out << i << ": ";
            
            out << text[(pNum - 1) * maxX + pX - 1] << endl;
        }

        tmp.clear();
        text[(pNum - 1) * maxX + pX - 1].subString(tmp, pY, 1);
        cout << " 当前字符为: " << tmp << endl;
    }
}

ostream& operator << (ostream& out, textEditor& s)
{
    s.display(out);
    return out;
}

textEditor::textEditor()
{
    text = new SqString[firstSize];
    assert(text != 0);

    editorSize = firstSize;

    pX = 1;
    pY = 1;
    pNum = 1;
    maxX = 10;
    allNum = 0;
    maxY = 10;
    maxNum = editorSize / maxX;
    if(editorSize % maxX)
        maxNum++;

    char tmp[100] = "1232131";
    text[0] = tmp;
    text[1] = tmp;
    allNum = 2;
}

textEditor::~textEditor()
{
    clear();
}

#endif
