def SubsetSum(arr,n, s) : 
    if (s == 0) : 
        return True
    if (n == 0 and s != 0) : 
        return False
        
    if (arr[n - 1] > s) : 
        return SubsetSum(arr, n - 1, s); 
   
    return SubsetSum(arr, n-1, s) or SubsetSum(arr, n-1, s-arr[n-1]) 
t=int(input())
while(t>0):
    n=int(input())
    arr=list(map(int,input().split()))
    s=int(input())
    if(SubsetSum(arr,n,s)):
        print("YES")
    else:
        print("NO")
    t=t-1
