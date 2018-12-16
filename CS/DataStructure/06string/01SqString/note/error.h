/*
// textEditor.read(istream& in)
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
        {
            char tmpc[10] = " ";
            tmp = tmp + tmpc;
        }
    }
    else
    {
        int lenNum = len / maxY;
        if(len % maxY)
            lenNum++;
        fei(1, maxY * lenNum - len)
        {
            char tmpc[10] = " ";
            tmp = tmp + tmpc;
        }
    }
    text = text + tmp;
}
cout << "  总共输入了" << n  << "行" << endl << endl;
display(cout);
*/
/*
bool isXEnd();

bool isYEnd();

bool isNumEnd();

bool isXBegin();

bool isYBegin();

bool isNumBegin();
*/
/*
void textEditor::pDown()
{
if(isYEnd())
    cout << " 光标已到最底端，无法下移一行!\n";
else
    pY++;
}

void textEditor::pUp()
{
if(isYBegin())
    cout << " 光标已到最上端，无法上移一行\n";
else
    pY--;
}

void textEditor::pLeft()
{
if(isXBegin())
    cout << " 光标已到最左端，无法上移一行\n";
else
    pX--;
}

void textEditor::pRight()
{
if(isXEnd())
    cout << " 光标已到最右端，无法下移一行!\n";
else
    pX++;

}

void textEditor::deleteText(int len)
{
int tmpX = pX;
int tmpY = pY;
int tmpNum = pNum;
int flag = 0;


}

void textEditor::insertText()
{

}

void textEditor::replaceText()
{

}

void textEditor::setText(int x, int y)
{
clear();
maxX
}

void textEditor::read(istream& in)
{

}

textEditor::textEditor()
{
pX = pY = pNum = 1;

maxNum = maxX = maxY = maxn;
}

textEditor::~textEditor()
{
clear();
}

bool textEditor::isXEnd()
{
return pX == maxX;
}

bool textEditor::isYEnd()
{
return pY == maxY;
}

bool textEditor::isNumEnd()
{
return pNum == maxNum;
}

bool textEditor::isXBegin()
{
return pX == 1;
}

bool textEditor::isYBegin()
{
return pY == 1;
}

bool textEditor::isNumBegin()
{
return pNum == 1;
}

bool clear()
{
pX = pY = pNum = 0;
text.clear();
}
*/
