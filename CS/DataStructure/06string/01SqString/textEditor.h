#ifndef TEXTEDITOR_H
    #define TEXTEDITOR_H
    #include "SqString.h"

/*
 * 设计思路: 
 *     1. 核心思路(文本的储存):
 *            使用顺序串数组储存
 */

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

    textEditor(const textEditor& s);

private:
    void clear();

    bool isEmpty();

    int cacuLenNow();

protected:
    int pCol;

    int pRow;

    int pNum;

    int maxCol;

    int maxRow;

    int maxNum;

    int allRow;

    SqString *text;

};

void textEditor::clear()
{
    fei(1,maxRow)
        text[i - 1].clear();

    pNum = 1;

    pRow = 1;

    pCol = 1;
}

bool textEditor::isEmpty()
{
    fei(1, maxRow)
        if(!text[i - 1].isEmpty())
            return false;
    
    return true;
}

int textEditor::cacuLenNow()
{
    return text[(pNum - 1) * maxRow + pRow - 1].getLength();
}

void texteditor::pdown()
{
    /*
       下移可能出现的情况:
       * 1. 下移后翻页
         * pRow = 1;
         * pNum++;
       * 2. 已到达文本最末行, 无法下移
         * cout << " 已到达文本最末行, 无法下移" << endl;
       * 3. 正常下移
         * pRow++
    */
    if((pRow + 1 + (pNum - 1) * maxRow) <= allRow)
    {
        if((pRow + 1) <= maxRow)
            pRow++;
        else
        {
            pRow = 1;
            pNum++;
        }
        int len = text[pRow - 1].getLength();
        if(pCol > len)
            pCol = len;
    }
    else
    {
        cout << " 已到达文本编辑器的最低端, 光标无法下移" << endl;
        pRow = pRow;
    }
}

void textEditor::pUp()
{
    if((pRow - 1 + (pNum - 1) * maxRow) >= 1)
    {
        if((pRow - 1) >= 1)
            pRow--;
        else
        {
            pRow = maxNum;
            pNum--;
        }
        int len = cacuLenNow(); 
        if(pCol > len)
            pCol = len;
    }
    else
    {
        cout << " 已到达文本编辑器的最顶端, 光标无法上移" << endl;
        pRow = pRow;
    }
}

void textEditor::pLeft()
{
    if(pRow == 1 && pNum == 1 && pCol == 1)
        cout << " 已到达文本编辑器的最左端，光标无法左移" << endl;
    else if(pCol - 1 >= 1)
        pCol--;
    else
    {
        if(pRow == 1)
        {
            pNum--;
            pRow = maxRow;
        }
        else
        {
            pRow--;
        }
        pCol = cacuLenNow(); 
    }
}

void textEditor::pRight()
{

}

void textEditor::deleteText()
{

}

void textEditor::insertText()
{

}

void textEditor::replaceText()
{

}

void textEditor::setText()
{

}

void textEditor::read(istream& in)
{
    clear();
    cout << " 请输入文本: " << endl;
    int n = 0;
    SqString tmp;
    
}

istream& operator << (istream& in, textEditor& s)
{
    s.read(in);
    return in;
}

void textEditor::display(ostream& out) 
{
    if(isEmpty())
        out << " 当前文本为空" << endl;
    else
    {
        out << " 当前文本为: " << endl;
        out << "         " << pNum << "/" << maxNum << "页" << endl;

        int digitX = 0;
        int tmpX = maxRow;
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
        fei(1, maxCol)
            out << i % 10;
        out << endl;

        out << topLeft;
        fei(1, maxCol)
        {
            if(i == pY)
                out << "*";
            else
                out << ' ';
        }
        out << endl;

        fei(1, maxRow)
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
            
            out << text[(pNum - 1) * maxRow + i - 1] << endl;
        }

        SqString tmp;
        this->text[(pNum - 1) * maxRow + pRow - 1].subString(tmp, pCol - 1, 1);
        cout << "  当前字符为: " << tmp << endl;
    }
}

ostream& operator >> (ostream& out, textEditor& s)
{
    s.display(out);
    return out;
}

textEditor::textEditor()
{

}

textEditor::~textEditor()
{
    clear();
}

textEditor::textEditor(const textEditor& s)
{

}

#endif

