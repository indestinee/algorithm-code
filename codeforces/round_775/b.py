cas = 10
n = 1000000
c = 1000000
print(cas)
for i in range(cas):
    print(n, c)
    print(" ".join(map(str, range(1,n+1))))
    n = n // 10
    n = max(n, 1)

