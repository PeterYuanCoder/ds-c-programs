# -*- coding: utf-8 -*-
"""
Created on Thu Feb 19 23:36:06 2026

@author: ASUS
"""

#创建和调用函数   用def来定义函数
'''
def myfunc():    #myfunc是创建的函数
    pass        # 函数体
'''
'''
def myfunc():
    for i in range(3):
        print('I LOVE FishC')
print(myfunc())
'''


#函数的参数实现功能的定制
'''
#更改返回内容
def myfunc(name):
    for i in range(2):
        print(f'I LOVE {name}')    #注意前面的f
print(myfunc('python'))


#用times来控制次数变化
def myfunc(name,times):
    for i in range(times):
        print(f'I LOVE {name}')    #注意前面的f
print(myfunc('python',1))   #不是交互式环境不能直接调用  必定返回None



#函数的返回值
def div(x,y):
    if y==0:
        return '除数不能为0'
    else:
        z=x/y
    return z
print(div(4,2))
print(div(4,0))
'''




#参数
#位置参数
def myfunc(s,vt,o):
    return ''.join((o,vt,s))
print(myfunc('小甲鱼','打了','我'))

#关键字参数   当参数过多是方便
print(myfunc(o='我',vt='打了',s='小甲鱼'))

#默认参数













