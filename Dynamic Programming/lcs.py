def lcs(s1,s2,memo):
    try:
        return memo[s1+" "+s2]
    except KeyError:
        pass
    if(s1=="" or s2==""):
        return 0
    if(s1[-1]==s2[-1]):
        memo[s1+" "+s2]=lcs(s1[:-1],s2[:-1],memo)+1
        return memo[s1+" "+s2]
    else:
        memo[s1+" "+s2]=max(lcs(s1[:-1],s2,memo),lcs(s1,s2[:-1],memo))
        return memo[s1+" "+s2]

s1="abcdabcd"
s2="abxc"
memo={}
print(lcs(s1,s2,memo))
