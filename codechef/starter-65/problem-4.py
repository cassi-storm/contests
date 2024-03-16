# cook your dish here
from sys import setrecursionlimit
mod_ = 10 ** 9 + 7
setrecursionlimit(10 ** 7)


def drive():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    count = 1
    cnt = [0] * k
    for i in a:
        cnt[i % k] += 1
    for i in range(k // 2 + 1):
        if i == 0 or i + i == k:
            count *= 1 + cnt[i]
        else:
            count *= pow(2, cnt[i], mod_) \
                + pow(2, cnt[k - i], mod_) - 1
        count %= mod_
    print(count)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        drive()
