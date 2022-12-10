from sys import stdin, stdout
input, print = stdin.readline, stdout.write
from collections import OrderedDict
 
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    a = [*map(int, input().split())]
    h1 = {}
 
    for i in range(n):
        x = a[i]
        if x in h1:
            h1[x].append(i)
        else:
            h1[x] = [i]
 
    h2 = h1.copy()
 
    for key in h2:
        ar = h2[key].copy()
        m = len(ar)
        ar.append(0)
        for i in reversed(range(m)):
            ar[i] = n - ar[i] + ar[i + 1]
        h2[key] = ar
 
    res = 0
    for key in h1:
        suf = h2[key]
        ar = h1[key]
        m = len(ar)
        # print(str(len(ar)))
        # print(' ')
        # print(str(len(suf)))
        # print('\n')
        # print((str(len(ar)), str(len(suf)))
        for i in range(m):
            x = ar[i] + 1
            y = suf[i + 1]
            # print(str(type(x)))
            # print('\n')
            # print(str(type(y)))
            # print('\n')
            # print(str(x))
            # print('\n')
            # print(str(y))
            # print('\n')
            res += int(x)*int(y)
 
    print(str(res))
    # print(' '.join(map(str, arr)))
    print('\n')