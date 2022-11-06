import math
import itertools
import time


def sieve(lim):
    arr = [0]*(lim+1)
    arr[0] = arr[1] = 1
    for a in range(2, lim):
        if arr[a] == 0:
            b = a*2
            while b <= lim:
                arr[b] = 1
                b += a
    return arr

def hasSix(p, sieve, combs):
    p = list(str(p)) 

    #all Cominations (Except 'all' elements)
    for r in combs:
        for c in r:
            count = 0
            testing = p[:]

            #Try digits 0-9
            for n in range(0,10):

                #Replace prime with same digit in indexes
                for ind in c:
                    testing[ind] = str(n)

                #print testing
                #See if number is prime
                if sieve[int(''.join(testing))] == 0 and testing[0] != '0':
                    count += 1

            if count >= 8:
                for ind in c:
                    testing[ind] = '9'
                print(testing)
                return True

    return False

def main():
    start_time = time.time()

    # Get primeSieve an prime array
    primeSieve = sieve(1000000)
    primes = []
    for n in range(10, len(primeSieve)):
        if not primeSieve[n]:
            primes.append(n)

    #get array of combinations of indexes
    sizeOfNum = 6 #size of number being tested
    indexes = []
    for n in range(1, sizeOfNum):
        indexes.append(list(itertools.combinations(range(sizeOfNum), n)))

    #try every prime with size = sizeOfNum
    #print primes[9600]# ~ approx 100000

    for p in primes[9600:]:
            if hasSix(p, primeSieve, indexes):
                print(p)
                break


    print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == '__main__':
    main()
