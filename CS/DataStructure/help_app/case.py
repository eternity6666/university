# -*- coding: utf-8 -*-
print "输入case总数: "
n = input()
for i in range(n):
    s = "            case " + str(i + 1) + ":\n"
    s = s + "                code" + str(i + 1) + "();\n"
    s = s + "                break;"
    print s

s = "            default:\n"
s = s + "                cout << \" 结束\" << endl;\n"
s = s + "                return ;"
print s

