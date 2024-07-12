def in_range(row, col):
  return row >= 0 and row < n and col >= 0 and col < n

def bomb(grid, row, col):
  result = [row[:] for row in grid]
  num = result[row][col]
  
  result[row][col] = 0
  for i in range(num):
    if in_range(row+i, col):
      result[row+i][col] = 0
    if in_range(row-i, col):
      result[row-i][col] = 0
    if in_range(row, col+i):
      result[row][col+i] = 0
    if in_range(row, col-i):
      result[row][col-i] = 0
    
  return result

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

def count_same(grid):
  n = len(grid)
  count = 0
  
  for i in range(n):
    for j in range(n-1):
      if grid[i][j] == grid[i][j+1] and grid[i][j] != 0:
        count += 1
  
  for j in range(n):
    for i in range(n-1):
      if grid[i][j] == grid[i+1][j] and grid[i][j] != 0:
        count += 1
        
  return count
      

n = int(input())
grid = [
  list(map(int, input().split()))
  for _ in range(n)
]

result = 0
for i in range(n):
  for j in range(n):
    temp = bomb(grid, i, j)
    temp = gravity(temp)
    result = max(result, count_same(temp))

print(result)