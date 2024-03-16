# cook your dish here
import sys
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
sys.setrecursionlimit(10 ** 7)

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    gcd_ = gcd(a, b)
    prev = b + 1
    while prev != b:
        prev = b
        b //= gcd_
        gcd_ = gcd(gcd_, b)
    if b == 1:
        print('YES')
    else:
        print('NO')
