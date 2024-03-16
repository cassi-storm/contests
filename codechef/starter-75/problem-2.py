# cook your dish here
mod_ = 10 ** 9 + 7


t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    s = [[a[0], 0]]
    for i in a:
        if i == s[-1][0]:
            s[-1][1] += 1
        else:
            s.append([i, 1])
    if s[0][0] == '0':
        max_ = 0
        for k, v in s:
            if k == '1':
                max_ = max(max_, v)
        print(max_)
    else:
        max_ = 0
        for k, v in s[1:]:
            if k == '1':
                max_ = max(max_, v)
        print(max_ + s[0][1])
