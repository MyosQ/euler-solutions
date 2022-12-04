import decimal
from decimal import Decimal
decimal.getcontext().prec = 110

def is_square(n):
    return int(n**0.5)**2 == n

def main():

    total_digit_sum = 0
    for n in range(2, 101):
        if is_square(n):
            continue
        decimals = str(Decimal(n).sqrt()).replace('.', '')[:100]
        digit_sum = sum([int(d) for d in decimals])
        total_digit_sum += digit_sum

    print(total_digit_sum)

if __name__ == "__main__":
    main()