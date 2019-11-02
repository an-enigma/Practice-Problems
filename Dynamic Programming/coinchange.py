#code
def change(n,arr,memo,nu,logs):         
    try: 
        return memo[str(n)+" "+str(nu)]
    except KeyError:
        pass
    if(n==0):
        if(nu in logs):
            return 0
        logs.append(nu)  
        return 1
    if(n<0):
        return 0            
    pl=[]
    for i in arr:
        pl.append(change(n-i,arr,memo,nu.add(i),logs)) 
    memo[str(n)+" "+str(nu)]=sum(pl)                         
    return memo[str(n)+" "+str(nu)] 
 
t=int(input())       #number of testcases  
while(t>0):
    nu=set({})
    logs=[]
    memo={}
    no=int(input())       
    arr=list(map(int,input().split()))
    n=int(input())  
    print(change(n,arr,memo,nu,logs))
    t=t-1
    
