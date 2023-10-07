# Euler Problem #68: Magic 5-gon ring

# Example of a magic 3-gon ring:
# 1 - 6
# 4,3,2; 6,2,1; 5,1,3. is a solution
# 4,3,2; 6,_,1; 5,_,_. is a compressed solution
# look for permutation of 1,2,3,4,5,6 such that
# A[0] + A[1] + A[2] = sum, 
# A[3] + A[2] + A[4] = sum,
# A[5] + A[4] + A[1] = sum,
# A[0] < A[3]
# A[0] < A[5]
# A[0] must then be less than or equal to 4

import itertools

def max_3_gon_num():
    print("--- max_3_gon_num ---")
    numbers = list(range(1, 6+1))
    max_3_gon_number = 0

    for p in itertools.permutations(numbers):
        # check order is correct
        if not (p[0] < p[3] and p[0] < p[5]):
            continue
        
        # check sums are equal
        if not (
            p[0] + p[1] + p[2] == \
            p[3] + p[2] + p[4] == \
            p[5] + p[4] + p[1]):
            continue
        
        # print solution set and compute resulting number
        uncompressed_solution = [p[0],p[1],p[2],p[3],p[2],p[4],p[5],p[4],p[1]]
        print(f"Solution set: {(','.join([str(x) for x in uncompressed_solution]))}")
        number = int(''.join([str(x) for x in uncompressed_solution]))
        if number > max_3_gon_number:
            max_3_gon_number = number

    print(f"max 3-gon number: {max_3_gon_number}\n")

# magic 5-gon ring:
# 1 - 10
# a - f
# a,b,c; d,c,e; f,e,g; h,g,i; j,i,b. is a solution
# a,b,c; d,_,e; f,_,g; h,_,i; j,_,_. is a compressed solution
# look for permutation of 1,2,3,4,5,6,7,8,9,10 such that
# a + b + c = sum
# d + c + e = sum
# f + e + g = sum
# h + g + i = sum
# j + i + b = sum
# a < d, a < f, a < h, a < j
# a must then be less than or equal to 6

def max_5_gon_num():
    print("--- max_5_gon_num ---")
    nums = list(range(1, 10+1))
    max_5_gon_num = 0

    for p in itertools.permutations(nums):
        # check order is correct
        if not (p[0] < p[3] and p[0] < p[5] and \
                p[0] < p[7] and p[0] < p[9]):
            continue
            
        # check sums are equal
        if not (p[0] + p[1] + p[2] == \
                p[3] + p[2] + p[4] == \
                p[5] + p[4] + p[6] == \
                p[7] + p[6] + p[8] == \
                p[9] + p[8] + p[1]):
            continue
        
        uncompressed_solution = [p[0],p[1],p[2],p[3],p[2],p[4],p[5],p[4],p[6],p[7],p[6],p[8],p[9],p[8],p[1]]
        print(f"Solution set: {(','.join([str(x) for x in uncompressed_solution]))}")
        number = int(''.join([str(x) for x in uncompressed_solution]))
        if len(str(number)) == 16 and number > max_5_gon_num:
            max_5_gon_num = number

    print(f"max (16-digit) 5-gon number: {max_5_gon_num}\n")

if __name__ == "__main__":
    max_3_gon_num()
    max_5_gon_num()
