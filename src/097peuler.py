def main():
    a = 28433
    for _ in range(0, 7830457):
        a = (a<<1) % int(1e10)
    a = a+1
    print(a)

if __name__ == "__main__":
   main()