import math

def nth_root(N,k):
    "Return greatest integer x such that x**k <= N"
    x = int(N**(1/k))
    return x


count = 0
for base in range(1,10):

    for exp in range(1, 22):
        if (int)(math.log10(base**exp))+1 == exp :
            print(base, exp)
            count += 1

print(count)
