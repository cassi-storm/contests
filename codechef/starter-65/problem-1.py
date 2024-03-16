# cook your dish here
from sys import setrecursionlimit
mod_ = 10 ** 9 + 7
setrecursionlimit(10 ** 7)


def drive():
    n = int(input())
    a = list(map(int, input().split()))
    map_ = {}
    max_ = 0
    for i in a:
        map_[i] = map_.get(i, 0) + 1
        max_ = max(max_, map_[i])
    if max_ > 2:
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        drive()
