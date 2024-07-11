n= int(input())
grid=[[0]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    a=list(map(int,input().split()))
    for j in range(1,n+1):
        grid[i][j]=a[j-1]


r,c= map(int,input().split())

k= grid[r][c]
grid[r][c]=0
for i in range(1,k):
    if c-i >0:
        grid[r][c-i]=0
    if c+i <n+1:
        grid[r][c+i]=0
    
    grid[r-i][c]=0
    grid[r+i][c]=0

for i in range(1,n+1):
    temp=[]
    for j in range(n,0,-1):
        if grid[j][i]!=0:
            temp.append(grid[j][i])
    zero=n-len(temp)
    for _ in range(zero):
        temp.append(0)
    for j in range(n,0,-1):
        grid[j][i]=temp[n-j]

for i in range(1,n+1):
    print(*grid[i][1:])