n = int(input())
m = input()


x, y, z = -1, -1, -1

for i in range(n//2-1, -1, -1):
    if m[i] != '0':
        x = i
        break


for i in range(n-n//2, n):
    if m[i] != '0':
        y = i
        break

if n % 2 == 1 and m[n//2] != '0':
    z = n//2

ans = int(m)

for xx in [x, y, z]:
    if xx == -1:
        continue

    try:
        ans = min(ans, int(m[:xx]) + int(m[xx:]))
    except:
        pass

print(ans)
