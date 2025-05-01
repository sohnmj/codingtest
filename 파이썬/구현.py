str=input()
al='nlszdc'
cro=['nj','c=','c-','dz=','d-','lj','s=','z=']
i=0
c=0
while i<len(str):
    if str[i] in al:
        if str[i:i+2] in cro:
            i+=2
            c+=1
        elif str[i:i+3]in cro:
            i+=3
            c+=1
        else:
            c+=1
            i+=1
    else:
        c+=1
        i+=1
print(c)
