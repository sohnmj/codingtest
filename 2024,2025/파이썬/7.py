score=input()
s1=0
s2=0
for i in range(len(score)):
    if i<len(score)//2:
        s1+=int(score[i]) 
    else :
        s2+=int(score[i])
if s1==s2:
    print("LUCKY")
else:
    print("READY")