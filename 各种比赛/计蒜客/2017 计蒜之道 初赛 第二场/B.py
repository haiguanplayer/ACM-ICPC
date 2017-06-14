input()

try:
    ans = eval(input())
    if isinstance(ans,float):
        print('%.6f'%ans)
    else:
        print('%d'%ans)
except:
    print('No Answer')