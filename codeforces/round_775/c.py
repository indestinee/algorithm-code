import random

n = random.randint(1, 10)
m = random.randint(1, 10)
print(n, m)


maxi = random.randint(1, 10)
for i in range(n):
    print(random.randint(1, maxi), end=" ")
print("")
for i in range(m):
    print(random.randint(1, maxi), end=" ")
print("")


