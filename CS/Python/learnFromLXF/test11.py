# -*- coding: utf-8 -*-

def by_name(t):
    return t[0].lower()

def by_score(t):
    return -t[1]

L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
L2 = sorted(L, key=by_name)
L3 = sorted(L2, key=by_score)
print(L3)

