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
    gcd_ = 0
    for i in a:
        gcd_ = gcd(gcd_, i)
    count = 0
    for i in a:
        if i == gcd_:
            count += 1
    print(n - count)
