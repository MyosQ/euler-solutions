sum = 0
for i in range(1000):
    if i % 3 == 0:
        sum += i
        continue
    elif i % 5 == 0:
        sum += i
        continue

print(f"{sum = }")