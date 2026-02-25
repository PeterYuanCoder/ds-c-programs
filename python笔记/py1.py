# -*- coding: utf-8 -*-
"""
Created on Tue Jan 20 16:09:24 2026

@author: ASUS
"""
'''
import random
answer = random.randint(1,10)
counts = 3

while counts > 0:
    
    temp = input('不妨猜一下小甲鱼现在心里想的事哪个数字：')
    guess = int(temp)
    if guess == answer:
        print('你是小甲鱼心里的蛔虫吗？！')
        print('哼，猜中了也没奖励！')
        break
    else:
        if guess < answer:
            print('小啦')
        else:
            print('大啦')
        counts = counts - 1
print('游戏结束，不玩啦')
'''
    
    
    
'''        支持中文字符作变量名
幸运数 = 100
print(幸运数)
'''



#交换变量
'''
y=3
x=5
x,y=y,x
print(x,y)
'''



#转移字符
#输出    D:\therr\two\one\now
'''
print(r'D:\therr\two\one\now')     #r表示输出原始字符
print('D:\\therr\\two\\one\\now')
'''



#要输出图形每一行\n后面要接\表示未完
'''
print( "        \n\
      *         \n\
     ***        \n\5
    *****        \n\  "  )
'''    



#精确浮点数
#0.2+0.1!=0.3
'''
import decimal      #导入模块
a = decimal.Decimal('0.1')
b = decimal.Decimal('0.2')
print(a+b)
'''



#复数
'''
x=1 + 2j
print(x.real)    #real输出实部
print(x.imag)    #imag输出虚部
'''



#求地板除和余数用divmod
#divmod是内置函数，不是模块，不用import调用
'''
result=divmod(3,2)
print(result)
'''



#abs取绝对值，若为复数则为模
#pow(x,y)  计算x的y次方
#x**y       计算x的y次方



#分支和循环
'''
age=16
if age<16:
    print('未满十八，禁止访问')
elif 16<=age<18:
    print('可以访问部分')
else:
    print('可以访问')
'''



'''
z=input('输入一个数字：')
y=input('输入另一个数字：')
if z<y:
    small=z
else:
    small=y
'''



'''
i=1
while i<=9:
    j=1
    while j<=9:
        print(f'{j}*{i}={i*j}\t',end=' ')
        j=j+1
    print()
    i=i+1
'''      



'''
sum=0
i=1
while i<=100:
    sum=sum+i
    i=i+1
print(sum)
'''



#range函数左闭右开，三个量分别是开头，结尾，和步长
'''
sum=0
for i in range(101):
    sum=sum+i
print(sum)
'''



#找出10以内的所有素数
'''
for n in range(2,10):
    for x in range(2,n):
        if n%x==0:
            print(n,'=',x,'*',n//x)
            break
    else:
            print(n,'是一个素数')
'''          