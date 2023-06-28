# Taken from problem 64
def get_continued_fraction_sqrt(N, verbose=False):
    """Return the continued fraction representation of sqrt(n)
    Also, the period is returned.
    """

    if N**0.5 % 1 == 0:
        return None, None

    # sqrt(N) = a0 + 1/(a1 + 1/(a2 + 1/(a3 + ...)))    
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

    repr = f"[{a0}; ({a_n})]"
    return repr, len(a_n)

def get_first_n_convergents(repr, n, verbose=False):
    """Return the first n convergents of the continued fraction representation 
    given as  '[a0; (a1, a2, a3, ...)]'
    """

    # Get the continued fraction representation
    repr = repr[1:-1].split(';')
    a0 = int(repr[0])
    a_n = repr[1].replace(' ', '').replace('(', '').replace(')', '').replace('[', '').replace(']', '').split(',')
    a_n = [int(a) for a in a_n]

    if len(a_n) < n:
        # repeat a_n until we have n elements
        a_n = a_n * (n // len(a_n) + 1)

    # Get the convergents
    p = [a0, a0*a_n[0] + 1]
    q = [1, a_n[0]]
    for i in range(1, n):
        p.append(a_n[i]*p[i] + p[i-1])
        q.append(a_n[i]*q[i] + q[i-1])

    if verbose:
        print(f"p = {p}")
        print(f"q = {q}")

    return p, q

def get_first_convergent_solution(N, repr, verbose=True):
    """Return the first n convergents of the continued fraction representation 
    given as  '[a0; (a1, a2, a3, ...)]'
    """
    if N**0.5 % 1 == 0:
        return None, None

    # Get the continued fraction representation
    repr = repr[1:-1].split(';')
    a0 = int(repr[0])
    a_n = repr[1].replace(' ', '').replace('(', '').replace(')', '').replace('[', '').replace(']', '').split(',')
    a_n = [int(a) for a in a_n]

    # Get the convergents
    p0, p1 = a0, a0*a_n[0] + 1
    q0, q1 = 1, a_n[0]

    # check if p0, q0 is a solution
    if p0**2 - N*q0**2 == 1:
        print(f"Found solution: x = {p0}, y = {q0}")
        return p0, q0

    # check if p1, q1 is a solution
    if p1**2 - N*q1**2 == 1:
        print(f"Found solution: x = {p1}, y = {q1}")
        return p1, q1

    p_prev, q_prev = p0, q0
    p_curr, q_curr = p1, q1
    i = 1
    while True:
        # Get the next convergent
        p_next = a_n[i % len(a_n)]*p_curr + p_prev
        q_next = a_n[i % len(a_n)]*q_curr + q_prev

        if verbose:
            print(f"i = {i} | p = {p_next} | q = {q_next}")

        # check if p_next, q_next is a solution
        if p_next**2 - N*q_next**2 == 1:
            print(f"Found solution: x = {p_next}, y = {q_next}")
            return p_next, q_next
        
        # update the convergents
        p_prev, q_prev = p_curr, q_curr
        p_curr, q_curr = p_next, q_next
        i += 1

def main():
    max_x = -1
    max_x_D = -1
    for D in range(2, 1001):
        if D**0.5 % 1 == 0:
            continue

        print(f"D = {D}")
        repr, _ = get_continued_fraction_sqrt(D, verbose=False)
        x, _ = get_first_convergent_solution(D, repr, verbose=False)
        if x > max_x:
            max_x = x
            max_x_D = D

    print(f"max_x = {max_x} | max_x_D = {max_x_D}")
    
if __name__ == '__main__':
    main()