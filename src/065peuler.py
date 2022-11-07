def main():

    numer = [0,2,3]
    k = 2

    for n in range(3, 101):
        if n % 3 == 0:
            numer.append(k * numer[n-1] + numer[n-2])
            k += 2
        else:
            numer.append(numer[n-1] + numer[n-2])


    print(numer)
    print(sum([int(x) for x in (list(str(numer[100])))]))



if __name__ == '__main__':
    main()
