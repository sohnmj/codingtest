words=["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries=["?????","??"]
def bisect(q,jin):
    st=0
    ls=len(q)-1
    mid=(st+ls)//2
    while st<=ls:
        mid=(st+ls)//2
        if jin==1:
            if q[mid]!='?'and q[mid-1]=='?':
                return mid
            elif q[mid]!='?':
                ls=mid-1
            else:
                st=mid+1
        else:
            if q[mid]!='?'and q[mid+1]=='?':
                return mid
            elif q[mid]!='?':
                st=mid+1
            else:
                ls=mid-1

def bisect_l(arr,q,s,l):
    if len(arr)==0:
        return -1

    st=0
    ls=len(arr)-1
    while st<=ls:
        mid=(st+ls)//2
      
        if arr[mid][s:l+1]==q and(mid==0 or arr[mid-1][s:l+1]!=q):
            return mid
        elif arr[mid][s:l+1]==q or arr[mid][s:l+1]>q:
            ls=mid-1
        else:
            st=mid+1
    return -1
def bisect_r(arr,q,s,l):
    if len(arr)==0:
        return -1
    st=0 
    ls=len(arr)-1
    while st<=ls:
        mid=(st+ls)//2
        if arr[mid][s:l+1]==q and(mid==len(arr)-1 or arr[mid+1][s:l+1]!=q):
            return mid
        elif arr[mid][s:l+1]==q or arr[mid][s:l+1]<q:
            st=mid+1
        else:
            ls=mid-1
    return -1

def solution(words, queries):
    stls=[[0,0] for _ in range(len(queries))]
    answer = []
    arr=[[] for _ in range(10001)]
    rarr=[[] for _ in range(10001)]
    for i in words:
        arr[len(i)].append(i)
        rarr[len(i)].append(i[::-1])
    for i in range(10001):
        arr[i].sort()
        rarr[i].sort()
    for i in range(len(queries)):
        count=0
        query=queries[i]
        if len(query)==1:
            for j in words:
                if len(j)==1:
                    count+=1
            answer.append(count)
            continue
        if query[0]=='?':
            if query[-1]=='?':
                count=len(arr[len(query)])
            else:
                stls[i][1]=len(query)-1
                stls[i][0]=bisect(query,1)
                d=stls[i][1]-stls[i][0]
                print(query[::-1][0:d+1])
                count=bisect_r(rarr[len(query)],query[::-1][0:d+1],0,d)-bisect_l(rarr[len(query)],query[::-1][0:d+1],0,d)
                if bisect_l(rarr[len(query)],query[::-1][0:d+1],0,d)>=0:
                    count+=1

        else:
            stls[i][0]=0
            stls[i][1]=bisect(query,0)
            print(query[stls[i][0]:stls[i][1]+1],bisect_l(arr[len(query)],query[stls[i][0]:stls[i][1]+1],stls[i][0],stls[i][1]))
            count=bisect_r(arr[len(query)],query[stls[i][0]:stls[i][1]+1],stls[i][0],stls[i][1])-bisect_l(arr[len(query)],query[stls[i][0]:stls[i][1]+1],stls[i][0],stls[i][1])
            if bisect_l(arr[len(query)],query[stls[i][0]:stls[i][1]+1],stls[i][0],stls[i][1])>=0:
                count+=1

        answer.append(count)
        
    
    return answer



print(solution(words,queries))
