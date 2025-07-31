# import sys  # 导入sys模块
# sys.setrecursionlimit(3000)  # 将默认的递归深度修改为3000

# myExp = input()
# myExp = eval(myExp)

# myExp = str(myExp)[-4:]
# myExp2 = myExp.lstrip('0')

# print(myExp2)

myExp = input()
terms = myExp.split('+')
ans = 0
for term in terms:
    sub_terms = term.split('*')
    res = 1
    for sub_term in sub_terms:
        res *= int(sub_term)
        res %= 10000
    ans += res
    ans %= 10000
print(ans)

'''
Sample Input 1:
1+1*3+4
Sample Output 1:
8

Sample Input 1:
1+1234567890*1
Sample Output 1:
7891
'''