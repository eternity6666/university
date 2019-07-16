# -*- coding: utf-8 -*-
import math
def quadratic(a, b, c):
    if judge(a):
        raise TypeError('bad operand type')
    if judge(b):
        raise TypeError('bad operand type')
    if judge(c):
        raise TypeError('bad operand type')
    if b * b < 4 * a * c:
        return 'wujie'
    else:
        return (-b + math.sqrt(b * b - 4 * a * c)) / (2 * a), (-b - math.sqrt(b * b - 4 * a * c)) / (2 * a)

def judge(a):
    if not isinstance(a, (int, float)):
        return True
