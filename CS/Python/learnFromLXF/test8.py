# -*- coding: utf-8 -*-
from collections.abc import Iterable
def normalize(name):
    return name[0].upper() + name[1:].lower()

# 测试:
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)
