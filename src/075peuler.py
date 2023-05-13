# 1. Generate all primitive pythagorean triples up to 1,500,000
# 2. Generate all multiples of the primitive triples found in step 1
# 3. Return the number of triples that sum to less than 1,500,000 and have exactly one solution

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def are_coprime(a, b):
    return gcd(a, b) == 1

def main():
    # 1. Generate all primitive pythagorean triples up to 1,500,000
    # https://en.wikipedia.org/wiki/Pythagorean_triple

    sum_lim = 1_500_000
    count_arr = [0] * (sum_lim + 1)
    m_lim = int(sum_lim**0.5)

    for m in range(1, m_lim):
        for n in range(1, m):

            # check for primitive triples only
            #  - m and n not both odd
            if m & n & 1: # neat trick to check if both are odd
                continue

            #  - m and n are coprime
            if not are_coprime(m, n):
                continue

            a = m**2 - n**2
            b = 2*m*n
            c = m**2 + n**2
            perimeter = a + b + c

            # 2. add to the count array the primitive triple and all its multiples
            k = 1
            while k*perimeter <= sum_lim:
                count_arr[k*perimeter] += 1
                k += 1

    # 3. Count the number of "1"s in the count array
    count = sum([1 for i in count_arr if i == 1])
    print(f"count = {count}")

if __name__ == "__main__":
    main()