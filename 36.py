from itertools import combinations
s1=input()
s2=input()

n=max(len(s1),len(s2))
result=n
d=abs(len(s1)-len(s2))
if len(s1)>len(s2):
    s=s1
    sm=s2
else:
    s=s2
    sm=s1
for ex in combinations(range(n),d):
    
    i=0
    j=0
    c=0
    while j<len(sm):
        if i in ex:
            while i in ex:
                i+=1
        print(s[i],end='')
        if s[i]!=sm[j]:
            
            c+=1
        i+=1
        j+=1
    print()
    if result>c:
        result=c
    print(ex,c)
print(result+d)