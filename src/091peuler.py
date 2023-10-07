# Project Euler Problem 91
# Right triangles with integer coordinates

import itertools
import numpy as np

def has_right_triangle(v1, v2, v3) -> bool:
    """
        Returns True if any two vectors are orthogonal, False otherwise.
    """
    if np.dot(v1, v2) == 0:
        return True
    if np.dot(v2, v3) == 0:
        return True
    if np.dot(v3, v1) == 0:
        return True
    return False

def main():
    num_integer_right_triangles = 0
    min_xy_coord, max_xy_coord = 0, 50
    grid_points = [
        np.array([x, y])
        for x in range(min_xy_coord, max_xy_coord+1)
        for y in range(min_xy_coord, max_xy_coord+1)
        if (x, y) != (0, 0)
    ]

    for points in itertools.combinations(grid_points, 2):
        if has_right_triangle(points[0], points[1], points[1] - points[0]):
            num_integer_right_triangles += 1

    print(f"Number of integer right triangles for {min_xy_coord} <= x,y <= {max_xy_coord}: {num_integer_right_triangles}")

if __name__ == '__main__':
    main()