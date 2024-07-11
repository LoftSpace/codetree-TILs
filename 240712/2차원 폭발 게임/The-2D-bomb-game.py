def explore(bombs, m):
  result = []
  length = len(bombs)
  
  if m == 1:
    return result
  
  if length <= 1:
    result = bombs[:]
    return result
  
  current = bombs[0]
  num = 1
  for i in range(1, length):
    if bombs[i] == current:
      num += 1
    elif bombs[i] != current and num < m:
      result.extend([current]*num)
      current = bombs[i]
      num = 1
    else:
      current = bombs[i]
      num = 1
      
    if i == length - 1 and num < m:
      result.extend([current]*num)
  
  return result

def bomb(grid, m):
  temp = [row[:] for row in grid]    
  temp = rotate(temp)
  
  result = []
  for row in temp:
    r = explore(row, m)
    if len(r) != len(grid):
      num = len(grid) - len(r)
      r.extend([0]*num)
    result.append(r)
    
  result = rotate(result)
  result = rotate(result)
  result = rotate(result)
  
  return result

def rotate(grid):
  result = []
  for i in range(len(grid)):
    temp = [row[i] for row in grid]
    result.append(temp[::-1])
  
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
        
def show_grid(grid):
  for row in grid:
    print(" ".join(map(str, row)))
    
def count_grid(grid, n):
  count = 0
  
  for i in range(n):
    for j in range(n):
      if grid[i][j] != 0:
        count += 1
        
  return count

n, m, k = map(int, input().split())
grid = [
  list(map(int, input().split()))
  for _ in range(n)
]

result = [row[:] for row in grid]


for _ in range(k):
  result = bomb(result, m)
  # show_grid(result)
  result = rotate(result)
  result = gravity(result)
  # print("--------------")

result = bomb(result, m)
  
print(count_grid(result, n))