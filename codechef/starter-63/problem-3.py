# cook your dish here
import sys
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
sys.setrecursionlimit(10 ** 7)


def solve(i, n, a, b, pset_, ans):
    if i == n:
        for v in pset_:
            ans[0] = min(ans[0], abs(v))
        return
    # print(i)
    pos = ((ord(b[i]) - ord(a[i])) + 26) % 26
    neg = ((ord(a[i]) - ord(b[i])) + 26) % 26
    set_ = set()
    for v in pset_:
        if -27 < v - neg < 27:
            set_.add(v - neg)
        if -27 < v + pos < 27:
            set_.add(v + pos)
    solve(i + 1, n, a, b, set_, ans)


t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    b = input()
    ans = [27]
    solve(0, n, a, b, {0}, ans)
    print(ans[0])
