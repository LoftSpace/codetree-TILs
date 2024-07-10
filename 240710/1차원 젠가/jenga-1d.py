n= int(input())
block=[]
for i in range(n):
    block.append(int(input()))

s1,e1 = map(int,input().split())
s2,e2 = map(int,input().split())
temp=[]
for i in range(s1,e1+1):
    block[i-1]=0

j=0
for i in range(n-1,-1,-1):
    if block[i]!=0:
        temp.append(block[i])
    j+=1

block=temp
for i in range(s2,e2+1):
    block[i-1]=0
temp=[]

for i in range(len(block)-1,-1,-1):
    if block[i]!=0:
        temp.append(block[i])
print(len(temp))
for i in temp:
    print(i)