# Let p(n) represent the number of different ways in which n coins can be separated into piles.
# For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

def main():
    
    n = 100_000
    partitions = [1] + [0] * n
    for i in range(1, n+1):
        for j in range(i, n+1):
            partitions[j] += partitions[j-i]

        print(f"p({i}) = {partitions[i]}")
        if partitions[i] % 1_000_000 == 0:
            break

def get_pentagonal_number(k):
    return k * (3*k - 1) // 2

def yield_sequence():
    # 1, -1, 2, -2, 3, -3, 4, -4, ...
    k = 1
    while True:
        for k_sign in [1, -1]:
            yield k_sign * k
        k += 1

# memoize the function
# https://stackoverflow.com/questions/1988804/what-is-memoization-and-how-can-i-use-it-in-python

def p(n):
    
    if n < 0:
        return 0
    
    if n == 1 or n == 0:
        return 1
    
    p_n = 0

    # loop over k = 1, -1, 2, -2, 3, -3, ... until get_pentagonal_number(k) > n
    k = 1
    for k in yield_sequence():
        
        pent_num = get_pentagonal_number(k)
        if pent_num > n:
            break

        # print(f"k = {k}, pent_num = {pent_num}")
        p_n += (-1)**(k-1) * p(n - pent_num)

    return p_n

def main2():
    #https://en.wikipedia.org/wiki/Pentagonal_number_theorem
    # for i in range(1, 10):
    n = 5
    print(f"p({n}) = {p(n)}")

if __name__ == "__main__":
    main()
    #main2()