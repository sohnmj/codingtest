str=input()
re=0
for i in range(1,len(str)):
    if str[i]!=str[i-1]:
        re+=1
print((re+1)//2)