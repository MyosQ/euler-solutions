# define class for one "cell" in the grid. Each cell has a value and a "min path" value
class Cell:
    def __init__(self, value):
        self.value = value
        self.min_path = -1  # -1 means not yet calculated

def main():
    with open(f"../input_files/081peuler.txt", "r") as f:
        arr, r = [], 0
        for line in f.readlines():
            arr.append([])
            for cell in line.strip().split(","):
                arr[r].append(Cell(int(cell)))
            r += 1               
    arr[0][0].min_path = arr[0][0].value # starting cell
    num_rows, num_cols = len(arr), len(arr[0])

    while True:
        was_updated = False
        for r in range(num_rows):
            for c in range(num_cols):
                # check left
                if c > 0 and  arr[r][c-1].min_path != -1:
                    if arr[r][c].min_path == -1 or arr[r][c-1].min_path + arr[r][c].value < arr[r][c].min_path:
                        arr[r][c].min_path = arr[r][c-1].min_path + arr[r][c].value
                        was_updated = True
                # check up
                if r > 0 and arr[r-1][c].min_path != -1:
                    if arr[r][c].min_path == -1 or arr[r-1][c].min_path + arr[r][c].value < arr[r][c].min_path:
                        arr[r][c].min_path = arr[r-1][c].min_path + arr[r][c].value
                        was_updated = True
                # check right
                if c + 1 < num_cols and arr[r][c+1].min_path != -1:
                    if arr[r][c].min_path == -1 or arr[r][c+1].min_path + arr[r][c].value < arr[r][c].min_path:
                        arr[r][c].min_path = arr[r][c+1].min_path + arr[r][c].value
                        was_updated = True
                # check down
                if r + 1 < num_rows and arr[r+1][c].min_path != -1:
                    if arr[r][c].min_path == -1 or arr[r+1][c].min_path + arr[r][c].value < arr[r][c].min_path:
                        arr[r][c].min_path = arr[r+1][c].min_path + arr[r][c].value
                        was_updated = True

        if not was_updated:
            break

    print(arr[num_rows-1][num_cols-1].min_path)

if __name__ == "__main__":
    main()