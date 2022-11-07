import itertools
globmax = 10000

def trinum(list):
    n = 1
    num = int(n*(n+1)/2)
    while(num < globmax):
        list[num] += 8 #2^3
        n += 1
        num = int(n*(n+1)/2)
    return

def sqnum(list):
    n = 1
    num = n*n
    while(num < globmax):
        list[num] += 16 # 2^4
        n += 1
        num = n*n
    return

def pentnum(list):
    n = 1
    num = int(n*(3*n-1)/2)
    while(num < globmax):
        list[num] += 32 # 2^5
        n += 1
        num = int(n*(3*n-1)/2)
    return

def hexnum(list):
    n = 1
    num = n*(2*n-1)
    while(num < globmax):
        list[num] += 64 # 2^6
        n += 1
        num = n*(2*n-1)
    return

def septnum(list):
    n = 1
    num = int(n*(5*n-3)/2)
    while(num < globmax):
        list[num] += 128 # 2^7
        n += 1
        num = int(n*(5*n-3)/2)
    return

def octnum(list):
    n = 1
    num = int(n*(3*n-2))
    while(num < globmax):
        list[num] += 256 # 2^8
        n += 1
        num = int(n*(3*n-2))
    return


def main():
    list = [0]*globmax
    trinum(list)
    sqnum(list)
    pentnum(list)
    hexnum(list)
    septnum(list)
    octnum(list)

    arr = [4, 5, 6, 7, 8]
    for permarr in itertools.permutations(arr):

        for n1 in range(1000,10000):
            if list[n1] & (1 << 3):
                firstTwo = int(n1/100)

                nextnum = (n1 % 100) * 100
                for n2 in range(nextnum+10, nextnum+100):
                    if list[n2] & (1 << permarr[0]):

                        nextnum = (n2 % 100) * 100
                        for n3 in range(nextnum+10, nextnum+100):
                            if list[n3] & (1 << permarr[1]):

                                nextnum = (n3 % 100) * 100
                                for n4 in range(nextnum+10, nextnum+100):
                                    if list[n4] & (1 << permarr[2]):

                                        nextnum = (n4 % 100) * 100
                                        for n5 in range(nextnum+10, nextnum+100):
                                            if list[n5] & (1 << permarr[3]):

                                                nextnum = (n5 % 100) * 100
                                                for n6 in range(nextnum+10, nextnum+100):
                                                    if list[n6] & (1 << permarr[4]):

                                                        if (n6 % 100) == firstTwo:
                                                            print(f"{firstTwo=}")
                                                            print(f"{n1=}")
                                                            print(f"{n2=}")
                                                            print(f"{n3=}")
                                                            print(f"{n4=}")
                                                            print(f"{n5=}")
                                                            print(f"{n6=}")
                                                            print(f"{n1+n2+n3+n4+n5+n6=}")


if __name__ == '__main__':
    main()
