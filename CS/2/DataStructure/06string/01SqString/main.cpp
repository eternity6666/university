#include <iostream>
#include "textEditor.h"
#include "SqString.h"
using namespace std;

SqString a;
textEditor x;

void menu();
void code1();
void code2();
void code3();
void code4();
void code5();
void code6();
void code7();
void code8();
void code9();
void code10();
void code11();
void code12();
void code13();
void code14();
void code15();
void code16();
void code17();
void code18();
void code19();
void code20();
void code201();
void code202();
void code203();
void code204();
void code205();
void code206();
void code207();
void code208();
void code209();

int main()
{
    while(1)
    {
        system("clear");
        menu();
        if(a.isEmpty())
            cout << " 当前顺序串为空" << endl;
        else
            cout << " 当前顺序串为: " << a << endl;
        cout << " ----------------------------------------------------------------------- \n";
        cout << " 请选择你要操作的代码<1-20>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code1();
                break;
            case 2:
                code2();
                break;
            case 3:
                code3();
                break;
            case 4:
                code4();
                break;
            case 5:
                code5();
                break;
            case 6:
                code6();
                break;
            case 7:
                code7();
                break;
            case 8:
                code8();
                break;
            case 9:
                code9();
                break;
            case 10:
                code10();
                break;
            case 11:
                code11();
                break;
            case 12:
                code12();
                break;
            case 13:
                code13();
                break;
            case 14:
                code14();
                break;
            case 15:
                code15();
                break;
            case 16:
                code16();
                break;
            case 17:
                code17();
                break;
            case 18:
                code18();
                break;
            case 19:
                code19();
                break;
            case 20:
                code20();
                break;
            default:
                cout << " 结束" << endl;
                return 0;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
    return 0;
}

void code1()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------------------ && 求顺序串的长度 && ------------------------- \n";
    cout << " 当前顺序串的长度为" << a.getLength() << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code2()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ---------------------- && 判断顺序串是否为空 && ----------------------- \n";
    if(a.isEmpty())
        cout << " 当前顺序串为空" << endl;
    else
        cout << " 当前顺序串不为空" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code3()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------------------ && 取顺序串的子串 && ------------------------- \n";
    cout << " 请输入子串开始的字符序号: ";
    int start;
    int n = a.getLength();
    while(cin >> start)
    {
        if(start >= 1 && start <= n)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n << ">: ";
    }
    int len;
    cout << " 请输入子串的长度: ";
    while(cin >> len)
    {
        if(len >= 1 && len <= n - start + 1)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n - start + 1 << ">: ";
    }
    SqString tmp;
    a.subString(tmp, start, len);
    cout << " 当前串从第" << start << "个字符开始长度为" << len << "的子串为" << tmp << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code4()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ---------------- && 在第i个字符前插入另一个顺序串 && ------------------ \n ";
    cout << " 另一个顺序串为: ";
    SqString c;
    cin >> c;
    cout << " 请输入插入另一个顺序串的位置: ";
    int i;
    int n = a.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n << ">: ";
    }
    a.insert(i, c);
    cout << " 在第" << i << "个字符前插入" << c << "后, 当前顺序串为" << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code5()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " --------------- && 删除从第i个字符起长度为len的子串 && ---------------- \n";
    cout << " 请输入删除子串的起始位置: ";
    int start;
    int n = a.getLength();
    while(cin >> start)
    {
        if(start >= 1 && start <= n)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n << ">: ";
    }
    cout << " 请输入删除子串的长度: ";
    int len;
    while(cin >> len)
    {
        if(len >= 1 && len <= n - start + 1)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n - start + 1 << ">: ";
    }
    SqString tmp;
    a.strDelete(start, len);
    cout << " 从第" << start << "个字符开始删除长度为" << len << "的子串为 " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code6()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ---------- && 判断SqString顺序串与C++String顺序串是否相等 && ---------- \n";
    cout << " 请输入一个C++String顺序串: ";
    char c[100];
    cin >> c;
    cout << " 当前的SqString顺序串" << a;
    if((a == c) == 0)
        cout << "等于";
    else
        cout << "不等于";
    cout << "C++String顺序串" << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code7()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ---------- && 判断SqString顺序串与SqString顺序串是否相等 && ---------- \n";
    cout << " 请输入一个SqString顺序串: ";
    SqString c;
    cin >> c;
    // cout << c.getLength() << a.getLength() << endl;
    cout << " 当前的SqString顺序串" << a;
    if((a == c) == 0)
        cout << "等于";
    else
        cout << "不等于";
    cout << "SqString顺序串" << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code8()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ----------- && SqString顺序串与C++String顺序串的加法运算 && ----------- \n";
    cout << " 请输入一个C++String顺序串: ";
    char c[100];
    cin >> c;
    a = a + c;
    cout << " 当前SqString顺序串" << a << "和\n C++String顺序串" << c << "可以连接成" << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code9()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " --------------- && 两个SqString顺序串之间的加法运算 && ---------------- \n";
    cout << " 请输入另一个SqString顺序串: ";
    SqString c;
    cin >> c;
    a = a + c;
    cout << " 当前SqString顺序串\"" << a << "\"和\n C++String顺序串\"" << c << "\"可以连接成\"" << a << "\"" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code10()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " -------------------- && 串的朴素匹配(有回溯查找) && ------------------- \n";
    cout << " ----------- 返回模式串在主串中第pos个字符起第一次出现的位置 ----------- \n";
    cout << " 请输入一个主串: ";
    SqString c, d;
    cin >> c;
    cout << " 请输入一个模式串: ";
    cin >> d;
    cout << " 请输入开始查找的字符的序号(从1开始): ";
    int i;
    int n = c.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n << ">: ";
    }

    int x = c.index(d, i);
    if(x)
    {
        cout << " 模式串" << d << "在主串" << c << "从第1个字符起" << endl;
        cout << " 第一次出现的位置为: " << x << endl;
    }
    else
        cout << " 模式串" << d << "未在主串中匹配到" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code11()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ---------------------- && 求模式串的next数组 && ----------------------- \n";
    cout << " 请输入一个模式串: ";
    SqString c;
    cin >> c;
    int next[100];
    c.get_next(next, 1);
    cout << " ----------------------------------------------------------------------- \n";
}

void code12()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------------ && 模式匹配(无回溯KMP方法查找) && ------------------ \n";
    cout << " ----------- 返回模式串在主串中第pos个字符起第一次出现的位置 ----------- \n";
    cout << " 请输入一个主串: ";
    SqString c, d;
    cin >> c;
    cout << " 请输入一个模式串: ";
    cin >> d;
    cout << " 请输入开始查找的字符的序号(从1开始): ";
    int i;
    int n = a.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " 您的输入非法, 请输入<1-" << n << ">: ";
    }

    int x = c.index_KMP(d, i);
    if(x)
    {
        cout << " 用KMP方法查找子串" << d << "在主串" << c << "\n 从第1个字符起" << endl;
        cout << " 第一次出现的位置为: " << x << endl;
    }
    else
        cout << " 模式串" << d << "未在主串中匹配到" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code13()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ----------- && 赋值运算<SqString顺序串=C++String顺序串> && ------------ \n";
    cout << " C++String顺序串为: ";
    char c[100];
    cin >> c;
    a = c;
    cout << " 当前顺序串被赋值为: " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code14()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------ && 赋值运算<SqString顺序串=SqString顺序串> && ------------ \n";
    SqString c;
    c.getByRand();
    a = c;
    cout << " 另一个SqString顺序串赋值给当前SqString顺序串为: " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code15()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " -------------------------- && 把顺序串置空 && ------------------------- \n";
    cout << " 当前顺序串的长度为: " << a.getLength() << endl;
    a.clear();
    cout << " 把当前顺序串置空后的长度为: " << a.getLength() << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code16()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------------ && 随机生成顺序串(小写英文字母) && ----------------- \n";
    cout << " 随机生成当前字符串顺序串(小写英文字母)为: ";
    a.getByRand();
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code17()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " --------------- && 用C++String顺序串初始化一个顺序串 && --------------- \n";
    cout << " ------------------- && 利用拷贝初始化构造函数 && ---------------------- \n";
    cout << " 请输入一个C++String顺序串: ";
    char c[100];
    cin >> c;
    cout << " 通过拷贝初始化构造函数." << endl;
    SqString d(c);
    cout << " 用上面的C++String顺序串初始化的SqString顺序串为: " << d << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code18()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前顺序串为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " ------------- && 用另一个Sqstring顺序串初始化一个顺序串 && ------------ \n";
    cout << " ------------------- && 利用拷贝初始化构造函数 && ---------------------- \n";
    cout << " 通过拷贝初始化构造函数, 用当前的SqString顺序串\n";
    cout << " 初始化另一个SqString顺序串为: ";
    SqString c(a);
    cout << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code19()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前文本为空." << endl;
    else
        cout << " 当前顺序串为: " << a << endl;
    cout << " -------------------------- && 输入顺序串 && --------------------------- \n";
    cout << " 请输入顺序串: ";
    cin >> a;
    cout << " ----------------------------------------------------------------------- \n";
}

void code20()
{
    while(1)
    {
        system("clear");
        cout << " ----------------- && 简单的文本编辑器(顺序串的应用) && ---------------- \n";
        cout << " 20.1. 光标下移一行\n"
             << " 20.2. 光标上移一行\n"
             << " 20.3. 光标左移一个字符\n"
             << " 20.4. 光标右移一个字符\n"
             << " 20.5. 删除光标处开始的字符串\n"
             << " 20.6. 在光标之前插入一个文本\n"
             << " 20.7. 用一个文本替换光标处开始的len个字符串\n"
             << " 20.8. 页面设置\n"
             << " 20.9. 输入文本\n"
             << " 其他. 结束\n";
        cout << " ----------------------------------------------------------------------- \n";
        cout << x;
        cout << " ----------------------------------------------------------------------- \n";
        cout << " 请选择你要操作的代码<1-9>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code201();
                break;
            case 2:
                code202();
                break;
            case 3:
                code203();
                break;
            case 4:
                code204();
                break;
            case 5:
                code205();
                break;
            case 6:
                code206();
                break;
            case 7:
                code207();
                break;
            case 8:
                code208();
                break;
            case 9:
                code209();
                break;
            default:
                cout << " 结束" << endl;
                return ;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        while(cin >> c)
        {
            if(c == 'n' || c == 'N')
                return ;
            else if(c == 'y' || c == 'Y')
                break;
            else
            {
                cout << " 请输入<Y.继续\tN.结束> ";
                continue;
            }
        }
    }
}

void code201()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && 光标下移一行 && -------------------------- \n";
    x.pDown();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code202()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && 光标上移一行 && -------------------------- \n";
    x.pUp();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code203()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && 光标左移一行 && -------------------------- \n";
    x.pLeft();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code204()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && 光标右移一行 && -------------------------- \n";
    x.pRight();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code205()
{
    system("clear");
    cout << x;
    cout << " --------------------- && 删除光标处开始的字符串 && -------------------- \n";
    x.deleteText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code206()
{
    system("clear");
    cout << x;
    cout << " --------------------- && 在光标之前插入一个文本 && -------------------- \n";
    x.insertText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code207()
{
    system("clear");
    cout << x;
    cout << " ----------- && 用一个文本替换光标处开始的len个字符顺序串 && ----------- \n"; 
    x.replaceText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code208()
{
    system("clear");
    cout << x;
    cout << " ---------------------------- && 页面设置 && --------------------------- \n";
    x.setText();
    cout << " ----------------------------------------------------------------------- \n";
}

void code209()
{
    system("clear");
    cout << x;
    cout << " ---------------------------- && 输入文本 && --------------------------- \n";
    cin >> x;
    cout << " ----------------------------------------------------------------------- \n";
}

void menu()
{
    cout << " ----------------------- && 测试顺序串的操作 && ------------------------ \n";
    cout << "    1. 求顺序串的长度\n"
         << "    2. 判断顺序串是否为空\n"
         << "    3. 取顺序串的子串\n"
         << "    4. 在第 i 个字符前插入另一个顺序串\n"
         << "    5. 删除从第 i 个字符起长度为 len 的子串\n"
         << "    6. 判断是否相等 SqString 顺序串 == C++String顺序串\n"
         << "    7. 判断是否相等 SqString 顺序串 == SqString顺序串\n"
         << "    8. 加法运算 SqString 顺序串 + C++String顺序串\n"
         << "    9. 加法运算 SqString 顺序串 + SqString顺序串\n"
         << "   10. 串的朴素匹配(有回溯查找)\n"
         << "   11. 求模式串的 next 数组\n"
         << "   12. 模式匹配(无回溯KMP方法查找)\n"
         << "   13. 赋值运算 SqString 顺序串 = C++String 顺序串\n"
         << "   14. 赋值运算 SqString 顺序串 = SqString 顺序串\n"
         << "   15. 把顺序串置空\n"
         << "   16. 随机生成顺序串(小写英文字母)\n"
         << "   17. 用 C++String 顺序串初始化一个顺序串(利用拷贝初始化构造函数)\n"
         << "   18. 用 SqString 顺序串初始化一个顺序串(利用拷贝初始化构造函数)\n"
         << "   19. 输入顺序串\n"
         << "   20. 简单的文本编辑器(顺序串的应用)\n";
    cout << " 其他. 结束 " << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

