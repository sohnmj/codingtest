sum=0
hs=0
for i in range(20):
    s,h,g=map(str,input().split())
    if g=="A+":
        sum+=int(h[0])*4.5
        hs+=int(h[0])
    elif g=="A0":
        sum+=int(h[0])*4.0
        hs+=int(h[0])
    elif g=="B+":
        sum+=int(h[0])*3.5
        hs+=int(h[0])
    elif g=="B0":
        sum+=int(h[0])*3.0
        hs+=int(h[0])
    elif g=="C+":
        sum+=int(h[0])*2.5
        hs+=int(h[0])
    elif g=="C0":
        sum+=int(h[0])*2.0
        hs+=int(h[0])
    elif g=="D+":
        sum+=int(h[0])*1.5
        hs+=int(h[0])
    elif g=="D0":
        sum+=int(h[0])*1.0
        hs+=int(h[0])
    elif g=="F":
        hs+=int(h[0])
if round(sum/hs,6)==0:
    print(float(0))
else:
    print(round(sum/hs,6))
