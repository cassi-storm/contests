# cook your dish here
from sys import setrecursionlimit
mod_ = 10 ** 9 + 7
setrecursionlimit(10 ** 7)


def f(i, j, n, m, a, flag, map_):
    if (i, j, flag) in map_:
        return map_[(i, j, flag)]
    if (i, j) == (n - 1, m - 1):
        return a[i][j]
    max_ = a[i][j]
    if i == n - 1:
        max_ = max(max_, f(i, j + 1, n, m, a, 0, map_))
        map_[(i, j, flag)] = max_
        return max_
    if j == m - 1:
        max_ = max(max_, f(i + 1, j, n, m, a, 0, map_))
        map_[(i, j, flag)] = max_
        return max_
    if not flag:
        cur = 0
        if a[i + 1][j] > a[i][j + 1]:
            cur = f(i + 1, j, n, m, a, 1, map_)
        else:
            cur = f(i, j + 1, n, m, a, 1, map_)
        max_ = max(max_, cur)
    else:
        max_ = max(max_, min(
                f(i + 1, j, n, m, a, 0, map_),
                f(i, j + 1, n, m, a, 0, map_)
            )
        )
    map_[(i, j, flag)] = max_
    return max_


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [0] * (n + 1)
    for i in range(n):
        a[i] = list(map(int, input().split())) + [0]
    a[n] = [0] * (m + 1)
    print(f(0, 0, n, m, a, 1, {}))
