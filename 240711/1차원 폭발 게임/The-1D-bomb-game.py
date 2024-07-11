n,m=map(int,input().split())

bombs=[]
for i in range(n):
    bombs.append(int(input()))

def check():
    l=len(bombs)
    for i in range(l):
        j=i
        while(j<l and bombs[i]==bombs[j]):
            j+=1
            if j-i >=m:
                return 1
    return -1

while(check()==1):
    l=len(bombs)
    for i in range(l):
        j=i
        if bombs[i]==0:
            continue
        count=0
        while(j<l and (bombs[i]==bombs[j] or bombs[j]==0)):
            
            if bombs[j]!=0:
                count+=1
            j+=1
        if count>=m:
            for _ in range(i,j):
                bombs[_]=0
            #print(bombs)
    temp=[]
    for i in range(l):
        if bombs[i]!=0:
            temp.append(bombs[i])
    bombs=temp
length=len(bombs)
if length==0:
    print(0)
else:
    print(length)
    for i in(bombs):
        print(i)