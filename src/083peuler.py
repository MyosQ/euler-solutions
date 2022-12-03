INPUT_PATH = f"../input_files/081peuler.txt"

# define class for one "cell" in the grid. Each cell has a value and a "min path" value
class Cell:
    def __init__(self, value):
        self.value = value
        self.min_path = -1  # -1 means not yet calculated

def main():
    arr = []
    with open(INPUT_PATH, "r") as f:
        lines = f.readlines()
        r = 0
        for line in lines:
            arr.append([])
            for cell in line.strip().split(","):
                arr[r].append(Cell(int(cell)))
            r += 1               
    arr[0][0].min_path = arr[0][0].value

    was_updated = False
    while True:
        was_updated = False
        for r in range(len(arr)):
            for c in range(len(arr[r])):
                # check left
                if c > 0:
                    if arr[r][c-1].min_path != -1:
                        if arr[r][c].min_path == -1 or arr[r][c-1].min_path + arr[r][c].value < arr[r][c].min_path:
                            arr[r][c].min_path = arr[r][c-1].min_path + arr[r][c].value
                            was_updated = True
                # check up
                if r > 0:
                    if arr[r-1][c].min_path != -1:
                        if arr[r][c].min_path == -1 or arr[r-1][c].min_path + arr[r][c].value < arr[r][c].min_path:
                            arr[r][c].min_path = arr[r-1][c].min_path + arr[r][c].value
                            was_updated = True
                # check right
                if c < len(arr[r]) - 1:
                    if arr[r][c+1].min_path != -1:
                        if arr[r][c].min_path == -1 or arr[r][c+1].min_path + arr[r][c].value < arr[r][c].min_path:
                            arr[r][c].min_path = arr[r][c+1].min_path + arr[r][c].value
                            was_updated = True
                # check down
                if r < len(arr) - 1:
                    if arr[r+1][c].min_path != -1:
                        if arr[r][c].min_path == -1 or arr[r+1][c].min_path + arr[r][c].value < arr[r][c].min_path:
                            arr[r][c].min_path = arr[r+1][c].min_path + arr[r][c].value
                            was_updated = True
                
        if not was_updated:
            break

    print(arr[len(arr)-1][len(arr[len(arr)-1])-1].min_path)
    return

if __name__ == "__main__":
    main()