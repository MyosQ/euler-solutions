def main():
    closest = 10**6 # something
    therow = -1
    thecol = -1

    for rows in range(15, 86):
        for cols in range(rows, 86):
            sumRect = 0

            for r in range(1, rows+1):
                for c in range(1, cols+1):
                    sumRect += (rows - r +1)*(cols - c + 1)

            if abs(sumRect - 2*10**6) < closest:
                closest = abs(sumRect - 2*10**6)
                therow = rows
                thecol = cols

    print(closest, therow, thecol, therow*thecol)

if __name__ == '__main__':
    main()
