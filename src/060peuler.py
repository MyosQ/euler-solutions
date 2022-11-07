import time

## Really bad, slow 
def sieve(lim):
    arr = [0]*(lim+1)
    arr[0] = arr[1] = 1
    for a in range(2, lim+1):
        if arr[a] == 0:
            b = a << 1
            while b <= lim:
                arr[b] = 1
                b += a
    return arr

def isPrime(p1, p2, arr):
    prime1 = int(str(p1) + str(p2))
    prime2 = int(str(p2) + str(p1))
    for p in arr[0: 9560]:
        if prime1 % p == 0 or prime2 % p == 0:
            return False
    return True

def concPrimes(p1, p2, siarr, prarr):
    if len(str(p1)+str(p2)) > 8:
        return isPrime(p1, p2, prarr)

    conc1 = (str(p1) + str(p2))
    conc2 = (str(p2) + str(p1))
    if siarr[int(conc1)] == 1:
        return False
    if siarr[int(conc2)] == 1:
        return False
    return True

def main():
    start_t = time.time()
    size = 10**8
    sieveArr = sieve(size)
    ## never primes concatenated ##
    sieveArr[2] = 1
    sieveArr[5] = 1
    ##---------------------------##

    primeArr = []
    for p in range(0, size+1):
        if sieveArr[p] == 0:
            primeArr.append(p)

    #primeArr = primeArr[0:1227]
    lastind = len(primeArr)-1
    lim999 = 166
    lim9999 = 1227
    lim99999 = 4060#38000 ~~9560
    # index less than 1000: 165
    # index less than 10000: 1226
    # index less than 100000: ~9560
    print(primeArr[4060])


    ind1 = 0
    for p1 in primeArr:
        ind1 += 1
        ind2 = ind1-1
        for p2 in primeArr[ind2: lim99999]:
            ind2 += 1
            ind3 = ind2-1
            if concPrimes(p1, p2, sieveArr, primeArr) == False:
                continue

            for p3 in primeArr[ind3: lim99999]:
                ind3 += 1
                ind4 = ind3-1
                if concPrimes(p1, p3, sieveArr, primeArr) == False \
                or concPrimes(p2, p3, sieveArr, primeArr) == False:
                    continue

                for p4 in primeArr[ind4: lim99999]:
                    ind4 += 1
                    ind5 = ind4-1
                    if concPrimes(p1, p4, sieveArr, primeArr) == False \
                    or concPrimes(p2, p4, sieveArr, primeArr) == False \
                    or concPrimes(p3, p4, sieveArr, primeArr) == False:
                        continue

                    for p5 in primeArr[ind5: lim99999]:

                        #print p1, p2, p3, p4, p5
                        if concPrimes(p1, p5, sieveArr, primeArr) == False \
                        or concPrimes(p2, p5, sieveArr, primeArr) == False \
                        or concPrimes(p3, p5, sieveArr, primeArr) == False \
                        or concPrimes(p4, p5, sieveArr, primeArr) == False:
                            continue

                        print(p1, p2, p3, p4, p5)
                        print(p1+p2+p3+p4+p5)




    print("--- %f seconds ---" % (time.time() - start_t))

if __name__ == '__main__':
    main()
