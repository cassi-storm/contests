# cook your dish here
mod_ = 10 ** 9 + 7


def ncr(n, r, p):
    num = den = 1 
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p

t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    b = input()
    same, diff = 0, 0
    for i, j in zip(a, b):
        if i == j:
            same += 1
        else:
            diff += 1
    if diff % 2:
        print(0)
    else:
        n2 = n // 2
        x = pow(2, same, mod_) * ncr(diff, diff // 2, mod_)
        print(x % mod_)
