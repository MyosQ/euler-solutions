def get_continued_fraction_sqrt(N, verbose=False):
    """Return the continued fraction representation of sqrt(n)
    Also, the period is returned.
    """
    a = a0 = int(N**0.5)
    m = -a
    d = 1
    i = 0
    a_n = []

    while a != 2*a0:
        d = (N - m**2) // d
        a = int((N**0.5 - m) / d)
        m = -m - d*a

        if verbose:         
            print(f"iter:{i} --- a_{i} = {a} | frac = {a} + (sqrt({N}) - {-m})/{d}")
        
        a_n.append(a)
        i += 1

    repr = f"[{a0}; {a_n}]"
    return repr, len(a_n)


def main():
    N_lim = 10_000
    num_odd_periods = 0
    for N in range(2, N_lim+1):
        if N**0.5 % 1 == 0:
            continue
        
        repr, period = get_continued_fraction_sqrt(N, verbose=False)
        print(f"sqrt({N}) = {repr} | period = {period}")
        if period % 2 == 1:
            num_odd_periods += 1

    print(f"Number of odd periods: {num_odd_periods}")
    

if __name__ == '__main__':
    main()