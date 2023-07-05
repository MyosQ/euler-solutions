import math

def main():

    perimeter_sum = 0
    for a in range(3, 1_000_000_000//3, 2):

        one_more = (a-1) * (3*a + 1)
        if math.sqrt(one_more)**2 == one_more:
            print(f"Almost eq triangle with int area: ({a}, {a}, {a+1})")
            perimeter_sum += 3*a + 1

        one_less = (a+1) * (3*a - 1)
        if math.sqrt(one_less)**2 == one_less:
            print(f"Almost eq triangle with int area: ({a}, {a}, {a-1})")
            perimeter_sum += 3*a - 1

    print(f"Sum of perimeters: {perimeter_sum}")

if __name__ == "__main__":
    main()