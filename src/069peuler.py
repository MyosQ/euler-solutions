import math
import time

#Easier to just calc 2*3*5*7*11*13*17...

def sieve(lim):
    arr = [0]*(lim+1)
    arr[0] = arr[1] = 1;
    for a in range(2, lim):
        if arr[a] == 0:
            b = a << 1
            while b < lim:
                arr[b] = 1
                b += a
    return arr

def numOfRelPrimes(n, primes):
    phi = n
    for p in primes[0:int(math.sqrt(n))]:
        if int(n/p)*p == n:
            phi *= (1-(1/float(p)))
    return phi

def main():
    start_time = time.time()


    primesSieve = sieve(1000)
    primes = []
    for i in range(1, 1000):
        if primesSieve[i] == 0:
            primes.append(i)

    maxfrac = 0
    for n in range(1, 1000000):

        if n <= 1000 and primesSieve[n] == 0:
            continue

        else:
            count = numOfRelPrimes(n, primes)

        frac = float(n)/float(count)
        if frac > maxfrac:
            maxfrac = frac
            maxn = n


    print("n givin max frac: ", maxn)
    print("that maxfrac: ", maxfrac)
    print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == '__main__':
    main()
