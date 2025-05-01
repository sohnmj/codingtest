n=int(input())
arr=[]
for i in range(n):
    str=input()
    arr.append(str)

count=0

for i in range(n):
     str=arr[i]
     alpa=[0]*(27)
     jin=True
    
     for j in range(len(str)):
            
            if alpa[ord(str[j])-97]==0 or(alpa[ord(str[j])-97]!=0 and str[j-1]==str[j]):
                 alpa[ord(str[j])-97]+=1
            else:
                 jin=False
                 break
     
     if jin==True:
         count+=1

print(count)
            