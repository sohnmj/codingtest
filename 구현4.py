k=int(input())
i=1
while(i<k):
    k-=i
    i+=1

if i%2==0:
    j=1
    m=i
    for h in range(k-1):
        j+=1
        m-=1
elif i%2==1:
    j=i
    m=1
    
    for h in range(k-1):
        j-=1
        m+=1
        
print(str(j)+'/'+str(m))