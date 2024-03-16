# cook your dish here
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
import sys
sys.setrecursionlimit(10 ** 7)

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    set_ = set(a)
    if len(set_) < 3 or a[0] == a[-1]:
        print('YES')
        continue
    flag = 0
    for i in range(1, n):
        if a[0] == a[i - 1] and a[i] == a[-1]:
            flag = 1
            break
    if flag:
        print('YES')
    else:
        print('NO')
