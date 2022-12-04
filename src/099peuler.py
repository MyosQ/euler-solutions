import math
def main():
    maxN = 0.1
    maxInd = 0

    with open('../input_files/099peuler.txt') as f:
        arr = []
        for line in f:
            arr.append(line.rstrip('\n'))

    for ind in range(0, len(arr)):
        n1 = int(arr[ind].split(',')[0])
        n2 = int(arr[ind].split(',')[1])

        num = n2*math.log10(n1)
        if num > maxN:
            maxN = num
            maxInd = ind

    print(f"linemaxnumber: {maxInd+1}")

if __name__ == '__main__':
    main()