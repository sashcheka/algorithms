n, m = map(int, input().split())
ans = -1
for len1 in range(28, 32):
    k = m + 7
    if k > len1:
        k -= len1
    for len2 in range(28, 32):
        n_calc = k + 7
        if n_calc > len2:
            n_calc -= len2
        if n_calc == n:
            ans = k
            break
    if ans != -1:
        break
print(ans)