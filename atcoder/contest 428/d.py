import math

def bs(arr, x):
    l = 0
    r = len(arr) - 1
    while l <= r:
        m = (l + r) // 2
        if arr[m] <= x:
            l = m + 1
        else:
            r = m - 1
    return l

t = int(input())
powers = [1]
for i in range(1, 20): powers.append(powers[i - 1] * 10)

ans = []
for _ in range(t):
    c, d = map(int, input().split())

    l_min = bs(powers, c + 1)
    l_max = bs(powers, c + d)

    res = 0
    for l in range(l_min, l_max + 1):
        xl = powers[l - 1] - c
        xr = powers[l] - 1 - c

        lo = max(1, xl)
        hi = min(d, xr)
        if lo > hi: continue

        base = c * (powers[l] + 1)
        a = base + lo
        b = base + hi

        sl = math.isqrt(a)
        if sl * sl < a:
            sl += 1
        sr = math.isqrt(b)
        if sl <= sr:
            res += (sr - sl + 1)

    ans.append(str(res))

print(*ans, sep='\n')