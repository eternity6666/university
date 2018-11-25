for i in range(20):
    s = "            case " + str(i + 1) + ":\n"
    s = s + "                code" + str(i + 1) + "();\n"
    s = s + "                break;"
    print s
