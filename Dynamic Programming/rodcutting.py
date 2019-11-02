#code
import sys
sys.setrecursionlimit(4200)
def seg(n,x,y,z,memo):
    try:
        return memo[n]
    except KeyError:
        pass
    if(n==0):
        return 0
    if(n<0):
        return -99999
    memo[n]=max(seg(n-x,x,y,z,memo)+1,seg(n-y,x,y,z,memo)+1,seg(n-z,x,y,z,memo)+1)
    return memo[n]
t=int(input())   #number of test cases
while(t>0):
    memo={}
    n=int(input())
    l=list(map(int,input().split()))
    print(seg(n,l[0],l[1],l[2],memo))
    t=t-1
