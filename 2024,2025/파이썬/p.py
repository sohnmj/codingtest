l=[1,2,3,4]
def sum(l):
    global s
    for i in l:
        s+=i

for i in range(5):
    s=0
    sum(l)
    print(s)