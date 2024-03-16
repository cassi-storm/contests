# cook your dish here
from sys import setrecursionlimit
mod_ = 10 ** 9 + 7
setrecursionlimit(10 ** 7)


def drive():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    ct = [[0] * (n + 1) for _ in range(60)]
    for i in range(60):
        bit = 1 << i
        for j, v in enumerate(a, start=1):
            ct[i][j] = ct[i][j - 1] + (v & bit != 0)
    for _ in range(q):
        k, l1, r1, l2, r2 = map(int, input().split())
        ones_1 = ct[k][r1] - ct[k][l1 - 1]
        ones_2 = ct[k][r2] - ct[k][l2 - 1]
        ans = (r2 - l2 + 1 - ones_2) * ones_1 \
            + (r1 - l1 + 1 - ones_1) * ones_2
        print(ans)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        drive()
