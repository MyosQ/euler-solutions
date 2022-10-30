import itertools
l = list(itertools.permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(l[1_000_000 - 1])