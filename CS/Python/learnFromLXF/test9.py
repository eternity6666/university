# -*- coding: utf-8 -*-
from functools import reduce
def prod(L):
    def fn(a, b):
        return a * b
    return reduce(fn, L)

print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
if prod([3, 5, 7, 9]) == 945:
    print('测试成功!')
else:
    print('测试失败!')
