# -*- coding: utf-8 -*-
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def str2float(s):
    flag = 0
    for i in range(len(s)):
        if s[i] == '.':
            flag = i
            break
    s = s.replace('.', '')

    def fn(x):
        return DIGITS[x]
    result = map(fn, s)

    def f(x, y):
        return x * 10 + y
    result = reduce(f, result)

    for i in range(len(s)-flag):
        result = result / 10
    return result



print('str2float(\'123.456\') =', str2float('123.456'))
if abs(str2float('123.456') - 123.456) < 0.00001:
    print('测试成功!')
else:
    print('测试失败!')
