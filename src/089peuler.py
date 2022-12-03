import sys

## faaak, harder than expected
def getValue(num):
    val = 0
    ind = 0
    length = len(num)
    while ind < length:

        # C can only be placed before D and M.
        if ind < length-1 and num[ind] == 'C' and num[ind+1] == 'D':
            val += 400
            ind += 1
            sys.stdout.write("CD")
        elif ind < length-1 and num[ind] == 'C' and num[ind+1] == 'M':
            val += 900
            ind += 1
            sys.stdout.write("CM")

        # X can only be placed before L and C.
        elif ind < length-1 and num[ind] == 'X' and num[ind+1] == 'L':
            val += 40
            ind += 1
            sys.stdout.write("XL")
        elif ind < length-1 and num[ind] == 'X' and num[ind+1] == 'C':
            val += 90
            ind += 1
            sys.stdout.write("XC")

        # I can only be placed before V and X
        elif ind < length-1 and num[ind] == 'I' and num[ind+1] == 'V':
            val += 4
            ind += 1
            sys.stdout.write("IV")
        elif ind < length-1 and num[ind] == 'I' and num[ind+1] == 'X':
            val += 9
            ind += 1
            sys.stdout.write("IX")

        elif(num[ind] == 'M'):
            val += 1000
            sys.stdout.write("M")
        elif(num[ind] == 'D'):
            val += 500
            sys.stdout.write("D")
        elif(num[ind] == 'C'):
            val += 100
            sys.stdout.write("C")
        elif(num[ind] == 'L'):
            val += 50
            sys.stdout.write("L")
        elif(num[ind] == 'X'):
            val += 10
            sys.stdout.write("X")
        elif(num[ind] == 'V'):
            val += 5
            sys.stdout.write("V")
        elif(num[ind] == 'I'):
            val += 1
            sys.stdout.write("I")

        ind += 1

    return val

def getMinLetters(val):
    letCount = 0

    while val > 0:

        # C can only be placed before D and M.
        if val < 500 and val >= 400:
            val -= 400
            letCount += 2
        elif val < 1000 and val >= 900:
            val -= 900
            letCount += 2

        # X can only be placed before L and C.
        elif val < 50 and val >= 40:
            val -= 40
            letCount += 2
        elif val < 100 and val >= 90:
            val -= 90
            letCount += 2

        # I can only be placed before V and X
        elif val < 5 and val >= 4:
            val -= 4
            letCount += 2
        elif val < 10 and val >= 9:
            val -= 9
            letCount += 2

        # single letters
        elif val >= 1000:
            val -= 1000
            letCount += 1
        elif val >= 500:
            val -= 500
            letCount += 1
        elif val >= 100:
            val -= 100
            letCount += 1
        elif val >= 50:
            val -= 50
            letCount += 1
        elif val >= 10:
            val -= 10
            letCount += 1
        elif val >= 5:
            val -= 5
            letCount += 1
        elif val >= 1:
            val -= 1
            letCount += 1

    return letCount

def main():

    with open("../input_files/089peuler.txt", "r") as f:
        arr = f.readlines()

        # Calc number of letters originally #
        letterSum = 0
        for el in arr:
            letterSum += len(el.rstrip('\n'))

        print("letter sum before: ", letterSum)


        #asd
        letterSum2 = 0
        for el in arr:
            val = getValue(el)
            let = getMinLetters(val)
            letterSum2 += let
            
            sys.stdout.write('\n')
            print(val)
            print("\n")

        print("before: ", letterSum, "after: ", letterSum2, "differance: ", letterSum-letterSum2)
        arr1 = [1, 2, 3]
        print(len(arr1))

if __name__ == '__main__':
    main()
