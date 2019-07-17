# -*- coding: utf-8 -*-
from collections.abc import Iterable
def findMinAndMax(L):
    if not isinstance(L, Iterable):
        return False
    if L == []:
        return (None, None)
    x = L[0]
    y = L[0]
    for v in L:
        if x < v:
            x = v
        if y > v:
            y = v
    return (y, x)

 # 测试
if findMinAndMax([]) != (None, None):
    print('测试失败!')
elif findMinAndMax([7]) != (7, 7):
    print('测试失败!')
elif findMinAndMax([7, 1]) != (1, 7):
    print('测试失败!')
elif findMinAndMax([7, 1, 3, 9, 5]) != (1, 9):
    print('测试失败!')
else:
    print('测试成功!')

