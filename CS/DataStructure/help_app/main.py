#!/usr/bin/env python3
# -*- coding: utf-8 -*-
n = input("请输入菜单栏个数: ")


# print "    while(1)\n    {    system(\"clear\");\n"

w = open("main.cpp", "w")

print >> w,'#include <iostream>'
print >> w,'using namespace std;\n'
print >> w,'void menu();'
for i in range(n):
    s = "void code" + str(i + 1) + "();"
    print >> w,s
print >> w,'\nint main()'
print >> w,'{'
print >> w,'    menu();'
print >> w,'    return 0;'
print >> w,'}\n'

print >> w,'void menu()'
print >> w,'{'
print >> w,"    while(1)"
print >> w,"    {"
print >> w,'        system("clear");'
for i in range(n):
    s = '        '
    if(i == 0):
        s = s + 'cout'
    else:
        s = s +'    '
    s = s + ' << "   '
    if(i + 1 < 10):
        tmp = ' '+ str(i + 1)
    else:
        tmp = str(i + 1)
    s = s + tmp + '. " << endl'
    print >> w,s
print >> w,'             << " 其他. 结束" << endl;'
print >> w,'        cout << " ============================================================== " << endl;'
print >> w,'        // cout << a << endl;'
print >> w,'        cout << " ============================================================== " << endl;'
print >> w,'        cout << " 请选择你要操作的代码<1-%d>: ";' % (n)
print >> w,'        int n;'
print >> w,'        cin >> n;'
print >> w,'        switch(n)'
print >> w,'        {'

for i in range(n):
    s = "            case " + str(i + 1) + ":\n"
    s = s + "                code" + str(i + 1) + "();\n"
    s = s + "                break;"
    print >> w,s

s = "            default:\n"
s = s + "                cout << \" 结束\" << endl;\n"
s = s + "                return ;"
print >> w,s

print >> w,'        }'
print >> w,'        cout << " 还继续吗<Y.继续\tN.结束>?";'
print >> w,'        char c;'
print >> w,'        while(cin >> c)'
print >> w,'        {'
print >> w,"            if(c == 'y' || c == 'Y' || c == 'n' || c == 'N')"
print >> w,'                break;'
print >> w,'            else'
print >> w,'                cout << " 还继续吗<Y.继续\tN.结束>?";'
print >> w,'        }'
print >> w,"        if(c == 'y' || c == 'Y')"
print >> w,'            continue;'
print >> w,'        else'
print >> w,'            return;'
print >> w,"    }"
print >> w,'}'


for i in range(n):
    print >> w,"void code%d()" % (i + 1)
    print >> w,'{\n'
    print >> w,'    cout << " ============================================================== " << endl;'
    print >> w,'}\n'

w.close()

