# cook your dish here
import sys
from math import *
from bisect import *
mod_ = 10 ** 9 + 7
sys.setrecursionlimit(10 ** 7)

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print('YES')
        continue
    a.sort()
    map_ = {}
    i, j = 0, 2 * n - 1
    while i < j:
        k = a[j] - a[i]
        map_[k] = map_.get(k, 0) + 1
        i, j = i + 1, j - 1
    max_ = map_.get(0, 0)
    keys = list(map_.keys())
    for i in keys:
        if i == 0:
            continue
        k = map_[i]
        map_[i] = k - k // 2
        map_[-i] = k // 2
        max_ = max(max_, map_[i], map_[-i])
    if max_ <= n // 2 + n % 2:
        print('YES')
    else:
        print('NO')
