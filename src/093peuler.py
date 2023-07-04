import itertools

def get_num_consecutive_ints_in_list(nums: list) -> int:
    """Return the number of consecutive integers in a list of integers."""
    nums = sorted(nums)
    if nums[0] != 1:
        return 0
    
    if len(nums) == 1:
        return 1

    consec = 1
    for i in range(len(nums)-1):
        if nums[i+1] - nums[i] == 1:
            consec += 1
        else:
            return consec
        
    return consec

def get_result_for_digit_set(digits: list, verbose: bool = False) -> int:
    operations = ['+', '-', '*', '/']
    
    digits_perm = itertools.permutations(digits)
    op_perms = itertools.product(operations, repeat=3)

    target_nums = set()
    for d in digits_perm:
        op_perms = itertools.product(operations, repeat=3) # reset op_perms
        for op in op_perms:
            for order in [0, 1]:
                sum = d[0]
                for i in range(3):
                    
                    if order == 0:
                        if op[i] == '/' and d[i+1] == 0: # division by zero
                            break
                        sum = eval(f"{sum} {op[i]} {d[i+1]}")
                    else:
                        if op[i] == '/' and sum == 0: # division by zero
                            break
                        sum = eval(f"{d[i+1]} {op[i]} {sum}")
                else:

                    if sum % 1 != 0 or sum <= 0: # discard non-integers and negative numbers
                        continue
                    
                    sum = int(sum)
                    target_nums.add(sum)

                    if verbose:
                        if order == 0:
                            print(f"((( {d[0]} {op[0]} {d[1]} ) {op[1]} {d[2]} ) {op[2]} {d[3]} ) = {sum}")
                        else:
                            print(f"( {d[0]} {op[0]} ( {d[1]} {op[1]} ( {d[2]} {op[2]} {d[3]} ))) = {sum}")            

    num_consecutive = get_num_consecutive_ints_in_list(list(target_nums))
    print(f"Digits: {sorted(digits)}")
    print(f"Target numbers: {target_nums}")
    print(f"Number of consecutive integers: {num_consecutive}\n")
    return num_consecutive

def main():
    max_num_consecutive = 0
    max_num_consecutive_d = None
    digits = (1, 2, 3, 4, 5, 6, 7, 8, 9)
    digits_combs = itertools.combinations(digits, 4)
    for d in digits_combs:
        longest = get_result_for_digit_set(d, verbose=False)
        if longest > max_num_consecutive:
            max_num_consecutive = longest
            max_num_consecutive_d = d

    print(f"--- Max ---")
    get_result_for_digit_set(max_num_consecutive_d, verbose=True)
    print(f"Answer: {''.join([str(i) for i in max_num_consecutive_d])}")
    

if __name__ == '__main__':
    main()