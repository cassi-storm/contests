# cook your dish here
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
import sys
sys.setrecursionlimit(10 ** 7)

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if n == 1:
        print("YES")
        continue
    a = [s[0]]
    b = [0]
    for i in s:
        if a[-1] != i:
            b.append(1)
            a.append(i)
        else:
            b[-1] += 1
    flag = True
    for i, j in zip(a, b):
        if i == '1' and j % 2:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")
