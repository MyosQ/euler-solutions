def sieve(lim):
    arr = [0]*(lim+1)
    arr[0] = arr[1] = 1
    for a in range(2, lim+1):
        b = a+a
        while(b <= lim):
            arr[b] = 1
            b += a
    return arr

def main():
    lim = 20000
    primeArrBin = sieve(lim)
    primeArr = []
    for a in range(2, lim):
        if primeArrBin[a] == 0:
            primeArr.append(a)

    squareLim = 7079
    cubeLim = 373
    forthLim = 89
    count = 0
    resultArr = [0] * (5*10**7 + 1) # chosen wisely

    for primeSq in primeArr:
        if primeSq == squareLim:
            break

        for primeCube in primeArr:
            if primeCube == cubeLim:
                break

            for primeForths in primeArr:
                if primeForths == forthLim:
                    break

                tsum = primeSq**2 + primeCube**3 + primeForths**4
                if tsum <= 5*10**7:
                    resultArr[tsum] += 1
                    count += 1


    print("Count one", count)

    # remove equal elements of resultArr #
    for el in resultArr:
        if el >= 2:
            count -= (el - 1)

    print("New Count:", count)


if __name__ == '__main__':
    main()
