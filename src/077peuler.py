def is_prime(n):
    if n < 2:
        return False

    if n == 2:
        return True

    if n & 1 == 0:
        return False

    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            return False

    return True

def get_prime_partitions(n, highest_prime=None):
    # get all the sum-partitions of n where each part is a prime number.
    # return a list of lists, where each list is a partition of n.

    if n == 2:
        return [[2]]
    
    partitions = [[n]] if is_prime(n) else []
    highest_prime = highest_prime or 2
    for i in range(highest_prime, (n//2)+1):
        if not is_prime(i):
            continue

        partitions.extend([[i] + p for p in get_prime_partitions(n-i, i)])

    return partitions


def get_num_of_prime_partitions(n):
    return len(get_prime_partitions(n))

def main():
    n = 10
    num_of_partitions = 0
    while num_of_partitions < 5_000:
        n += 1
        num_of_partitions = get_num_of_prime_partitions(n)
        print(f"n = {n}, num_of_partitions = {num_of_partitions}")

if __name__ == "__main__":
    main()