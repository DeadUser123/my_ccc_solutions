rows, columns = list(map(int, input().split()))
grid = [[0 for _ in range(columns)] for _ in range(rows)]
n = int(input())
for i in range(n):
    row, col = list(map(int, input().split()))
    grid[row - 1][col - 1] = "*"
    
for row in range(0, rows):
    if grid[row][0] == "*":
        break
    grid[row][0] = 1

for column in range(1, columns):
    for row in range(0, rows):
        if grid[row][column] != '*':
            if row != 0 and grid[row - 1][column] != "*":
                grid[row][column] += grid[row - 1][column]
            if grid[row][column - 1] != "*":
                grid[row][column] += grid[row][column - 1]

print(grid[rows - 1][columns - 1])
