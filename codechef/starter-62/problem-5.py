# cook your dish here
import sys
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
sys.setrecursionlimit(10 ** 7)


t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    flag = -1
    for i in range(1, n):
        if s[i] != s[0]:
            flag = i
            break
    else:
        print(0)
        continue
    xor_ = int(s[:n - flag], base=2) ^ int(s[flag:], base=2)
    start, end = flag, n
    for i in range(flag, n):
        if start == 0:
            break
        if s[i] == '0':
            start -= 1
            end -= 1
        else:
            break
    xor_ = max(xor_, int(s[start:end], base=2) ^ int(s[flag:], base=2))
    start, end = flag, n
    for i in range(flag, n):
        if start == 0:
            break
        if s[i] == '1':
            start -= 1
            end -= 1
        else:
            break
    xor_ = max(xor_, int(s[start:end], base=2) ^ int(s[flag:], base=2))
    print(xor_ % mod_)
