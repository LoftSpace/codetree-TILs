grid = [
  list(map(int, input().split()))
  for _ in range(4)
]
direction = input()

def shift(grid, direction):
  result = [[0]*4 for _ in range(4)]
  if direction == 'L':
    for i in range(4):
      current = 0
      for j in range(4):
        if grid[i][j] != 0:
          result[i][current] = grid[i][j]
          current += 1
  elif direction == 'R':
    for i in range(4):
      current = 3
      for j in range(3, -1, -1):
        if grid[i][j] != 0:
          result[i][current] = grid[i][j]
          current -= 1
  elif direction == 'U':
    for j in range(4):
      current = 0
      for i in range(4):
        if grid[i][j] != 0:
          result[current][j] = grid[i][j]
          current += 1
  elif direction == 'D':
    for j in range(4):
      current = 3
      for i in range(3, -1, -1):
        if grid[i][j] != 0:
          result[current][j] = grid[i][j]
          current -= 1

  return result  

def sum_2048(grid, direction):
  result = [row[:] for row in grid]
  
  if direction == 'L':
    for i in range(4):
      for j in range(0, 3):
        if result[i][j] == result[i][j+1]:
          result[i][j] *= 2
          result[i][j+1] = 0
  elif direction == 'R':
    for i in range(4):
      for j in range(3, 0, -1):
        if result[i][j] == result[i][j-1]:
          result[i][j] *= 2
          result[i][j-1] = 0
  elif direction == 'U':
    for j in range(4):
      for i in range(0, 3):
        if result[i][j] == result[i+1][j]:
          result[i][j] *= 2
          result[i+1][j] = 0
  elif direction == 'D':
    for j in range(4):
      for i in range(3, 0, -1):
        if result[i][j] == result[i-1][j]:
          result[i][j] *= 2
          result[i-1][j] = 0
          
  return result
  
result = shift(grid, direction)
result = sum_2048(result, direction)
result = shift(result, direction)
for row in result:
  print(" ".join(map(str, row)))