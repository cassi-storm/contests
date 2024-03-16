# cook your dish here
from sys import setrecursionlimit
mod_ = 10 ** 9 + 7
setrecursionlimit(10 ** 7)


def drive():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if n == 1:
        print('Yes') if a[0] == k else print('No')
        return
    flag = False
    for i in a[:-1]:
        if i == k:
            flag = True
            break
    print('Yes') if flag else print('No')


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        drive()
