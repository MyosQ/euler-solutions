

def get_proper_divisors(n: int) -> list:
    """
    Returns the proper divisors of n.
    """
    divisors = []
    for i in range(1, n//2+1):
        if n % i == 0:
            divisors.append(i)

    return divisors

def main():

    no_chain_numbers = set()
    chain_numbers = set()
    max_chain_member = 1_000_000
    
    for k in range(2, 100_000, 2):

        visited = list()
        is_chain = None
        n = k

        while True:
            if n % 2 == 1 or n > max_chain_member:
                is_chain = False
                break
            
            if n in no_chain_numbers:
                is_chain = False
                break

            if n in chain_numbers:
                break
            
            if n in visited:
                break

            visited.append(n)
            divs = get_proper_divisors(n)
            n = sum(divs)
            if n == k:
                is_chain = True
                break

        if is_chain is True:
            print(f"Chain for {k}: {visited}")
            chain_numbers.update(visited)
        elif is_chain is False:
            no_chain_numbers.update(visited)
        


if __name__ == "__main__":
    main()