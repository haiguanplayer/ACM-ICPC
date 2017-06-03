'''
51nod-1015
'''
from builtins import int
def check(n):
    res = 0
    s = str(n)
    for i in s:
        res += pow(int(i),len(s))
    if(res == n):
        return True
    else:
        return False

a = int(input())
'''
while(check(a) == False):
    a += 1;
'''
for i in range(0,99999):
    if check(a):
        break
    else:
        a += 1
print (a)