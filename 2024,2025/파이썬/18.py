
w=input()
def division(w):
    if w=='':
        return w
    
    l=0
    r=0
    d=0
    jin=True
    for i in range(len(w)):
        if w[i]=='(':
                l+=1
        if w[i]==')':
            r+=1
        if l<r:
            jin=False

        if r==l and r>0:
            d=i
            break
    u=w[:d+1]
    
    if d==len(w):
        v=''
    else:
        v=w[d+1:]
    v=division(v)
    
    
    if jin==True:
        u+=v
        return u
    else:
        str=''
        str='('+str
        str+=v
        str=str+')'
        lu=len(u)
        u=u[1:lu-1]
        lu-=2
        nstr=list(u)
        for j in range(lu):
            if nstr[j]=='(':

                nstr[j]=')'
            else:

                nstr[j]='('
        u=''.join(nstr)
        str+=u   
        return str


print(division(w))