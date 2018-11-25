for i in range(9):
    s = "            case " + str(i + 1) + ":\n"
    s = s + "                code 20" + str(i + 1) + "();\n"
    s = s + "                break;"
    print s
