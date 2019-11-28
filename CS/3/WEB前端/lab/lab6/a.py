s1 = 'function '
s2 = '(){\nif(inputId==="0"){\ninputId="'
s3 = 'else{\ninputId = inputId +"'
s4 = '";}\n'
for x in range(10):
    print(s1+"number"+str(x)+s2+str(x)+s4+s3+str(x)+s4+'}')

lis = ['e', 'tan', 'sin', 'cos', 'sqrt', '*', '+', '-', '/']
for x in lis:
    print(s1+'fh'+x+s2+x+s4+s3+x+s4+'}')
