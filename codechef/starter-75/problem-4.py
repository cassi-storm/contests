# cook your dish here
from functools import lru_cache
mod_ = 10 ** 9 + 7


@lru_cache(maxsize=None)
def f(n):
    if n <= 1:
        return 0
    if n % 2 == 1:
        return f(n // 2)
    return 1 + f(n // 2)


@lru_cache(maxsize=None)
def g(n):
    if n <= 1:
        return 1
    if n % 2 == 1:
        return 2 * g(n // 2)
    return 2 * g(n // 2) + 1


t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    x = 1
    while x <= r:
        x *= 2
    x //= 2
    if l <= x <= r:
        print(f(x) + g(x))
        continue
    ans = [f(i) + g(i) for i in range(l, min(l + 31, r + 1))]
    print(max(ans))
