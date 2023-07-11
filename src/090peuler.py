import itertools

def add_flipped_six_nine(cube):
    if 6 in cube and 9 not in cube:
        cube = cube + (9,)
    elif 9 in cube and 6 not in cube:
        cube = cube + (6,)
    return cube

def can_form_all_squares(cube_1, cube_2):
    targets = [(0, 1), (0, 4), (0, 9), (1, 6), (2, 5), (3, 6), (4, 9), (6, 4), (8, 1)]
    for target in targets:
        if not (target[0] in cube_1 and target[1] in cube_2) and \
           not (target[1] in cube_1 and target[0] in cube_2):
            return False
    return True

def main():
    available_digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    set_size = 6
    count = 0

    # generate all possible sets of 6 digits, 10 choose 6
    sets_cube_1 = itertools.combinations(available_digits, set_size)
    for cube_1 in sets_cube_1:
        cube_1_modified = add_flipped_six_nine(cube_1)
        sets_cube_2 = itertools.combinations(available_digits, set_size)
        for cube_2 in sets_cube_2:
            cube_2_modified = add_flipped_six_nine(cube_2)
            if can_form_all_squares(cube_1_modified, cube_2_modified):
                count += 1       

    # divide by 2 because we counted each pair twice
    print(count//2)
            
if __name__ == "__main__":
    main()

