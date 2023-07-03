import math
# let b be the number of blue discs and n be the number of total discs

def main():

    n = 2
    while True:
        s2 = (1 + 2*n*(n-1))
        s = math.isqrt(s2)
        if s**2 == s2:
            b = int((s + 1) / 2)
            print(f"n = {n} | b = {b}")
            if n > 1_000_000_000_000:
                print(f"Solution: {b}")
                break

            n = int(n * 5.8284) # ~5.8284 is the ratio of the next n to the current n

        else:
            n += 1

if __name__ == '__main__':
    main()