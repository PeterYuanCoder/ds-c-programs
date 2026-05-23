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


'''
#参数
#位置参数
def myfunc(s,vt,o):
    return ''.join((o,vt,s))
print(myfunc('小甲鱼','打了','我'))

#关键字参数   当参数过多是方便
print(myfunc(o='我',vt='打了',s='小甲鱼'))

#默认参数
#一个默认参数
def myfunc(s,vt,o='小甲鱼'):
    return ''.join((o,vt,s))
print(myfunc('香蕉','吃了'))  #默认香蕉=s，吃了=vt
print(myfunc('香蕉','吃了','不二如是'))   #替换小甲鱼
#两个默认参数
def myfunc(vt,s='苹果',o='小甲鱼'):    #要将被更换的数据写在最前面
    return ''.join((o,vt,s))
print(myfunc('吃了'))
'''

'''
#收集参数（可变参数）   用一个*标记    自动组装为一个typle(元组)
#def 函数名称(*参数)
def myfunc(*args):
    print('有{}个参数'.format(len(args)))  #format用于把变量填进字符串
    print('第二个参数是：{}'.format(args[1]))
print(myfunc('小甲鱼','袁斯乐'))
'''

'''
#关键字参数  用两个*标记   自动组装为一个dict(字典)
def myfunc(**kw):
    print(kw)
print(myfunc(a=1,b=2,c=3))
#同时使用关键字参数和可变参数
def xiaojiayu(a,*b,**c):
    print(a,b,c)
print(xiaojiayu(1,2,3,4,5,x=6,y=7))
'''
'''
#两种参数的解包
args=(1,2,3,4)
kw={'a':1,'b':2,'c':3,'d':4}
def myfunc(a,b,c,d):
    print(a,b,c,d)
print(myfunc(*args))
print(myfunc(**kw))
'''

'''
#局部作用域
def myfunc():
    s=222
    print(s)
print(myfunc())   #直接用print(s)不能调用

#全局作用域       但是局部变量会覆盖全局变量
x=555
def xiaojiayu():
    x=111
    print(x)
print(x)
print(xiaojiayu())
#修改全局变量 global
z=880
def yuansile():
    global z
    z=100
    print(z)
print(yuansile())    #先调用函数修改全局变量
print(z)
'''



#嵌套函数
def  funA():
    x=100
    def funB():
        nonlocal x   #从内部修改外部函数的值  使输出结果变成2个400
        x=400
        print('In funB x=',x)
    funB()
    print('In funA x=',x)
print(funA())















































