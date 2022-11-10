import math

def fac(n):
    facs = {
        0: 1,
        1: 1,
        2: 2,
        3: 6,
        4: 24,
        5: 120,
        6: 720,
        7: 5040,
        8: 40320,
        9: 362880
    }
    return facs.get(n, -1)


def main():
    arr = [0]*10**7
    arr[1], arr[2], arr[145], arr[40585] = 1, 1, 1, 1
    arr[169], arr[363601], arr[1454] = 3, 3, 3
    arr[871], arr[45361] = 2, 2
    arr[872], arr[45362] = 2, 2

    sixtyCount = 0
    for n in range(1, 1000000):
        count = 0
        num = n
        memoryArr = [num]

        while(1):
            if arr[num] == 0:
                nextNum = 0
                for k in list(str(num)):
                    nextNum += fac(int(k))
                num = nextNum
                count += 1
                memoryArr.append(num)

            else:
                count += arr[num]
                if count == 60:
                    sixtyCount += 1
                #print  n, num, count
                break

        # add number to array #
        aftercount = count
        for num in memoryArr:
            arr[num] = aftercount
            aftercount -= 1

    print(sixtyCount)


if __name__ == '__main__':
    main()
