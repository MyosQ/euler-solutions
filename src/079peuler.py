import sys
import itertools


def isOk(passcode, code):
    num = str(passcode)
    length = len(num)
    passindex = 0
    codeindex = 0
    while(passindex < length):
        if(num[passindex] == code[codeindex]):
            codeindex += 1
            passindex += 1
        else:
            passindex += 1

        if codeindex == 3:
            return True

def main():
    with open('../input_files/079peuler.txt','r') as f:
        arr = []
        for line in f:
            arr.append(line.rstrip('\n'))

    passcode = [0,1,2,3,6,7,8,9]

    for p in itertools.permutations(passcode):
        t = True
        for code in arr[0:len(arr)]:
            if not isOk(p, code):
                t = False
                break

        if t == True:
            print(p)
            break


if __name__ == '__main__':
    main()








#print lines
