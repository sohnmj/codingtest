str=input()
re=0
for i in str:
    re=max(re+int(i),re*int(i))
print(re)