n, m = map(int, input().split())
grid = [
  list(map(int, input().split()))
  for _ in range(n)
]
bombs = [
  int(input())
  for _ in range(m) 
]

def in_range(row, col):
  return row >= 0 and row < n and col >= 0 and col < n

def bomb(grid, row, col):
  num = grid[row][col]
  
  grid[row][col] = 0
  for i in range(num):
    if in_range(row+i, col):
      grid[row+i][col] = 0
    if in_range(row-i, col):
      grid[row-i][col] = 0
    if in_range(row, col+i):
      grid[row][col+i] = 0
    if in_range(row, col-i):
      grid[row][col-i] = 0
    
  return grid

def gravity(grid):
  result = [
    [0] * n
    for _ in range(n)
  ]
  
  for i in range(n):
    li = [row[i] for row in grid]

    count = n-1
    for j in range(len(li)-1, -1, -1):
      if li[j] != 0:
        result[count][i] = li[j]
        count -= 1
  
  return result

result = [row[:] for row in grid]
for b in bombs:
  row, col = 0, b-1
  for i in range(n):
    if result[i][col] != 0:
      row = i
      break
  result = bomb(result, row, col)
  result = gravity(result)

for row in result:
  print(" ".join(map(str, row)))