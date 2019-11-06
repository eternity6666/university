n = input()
s = "void menu();"
print s
for i in range(n):
    s = "void code" + str(i + 1) + "();"
    print s


