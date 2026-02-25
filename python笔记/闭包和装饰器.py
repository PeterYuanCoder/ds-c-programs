# -*- coding: utf-8 -*-
"""
Created on Sun Feb 22 16:29:42 2026

@author: ASUS
"""

'''
#在funA中调用funB
def funA():
    x=800
    def funB():
        print(x)
    return funB
print(funA()())   #两次调用等于调用funB
funny=funA()
print(funny())
'''

'''
#闭包
def power(exp):
    def exp_of(base):
        return base ** exp   #**是幂运算运算符
    return exp_of
square=power(2)
cube=power(3)
print(square(2))
print(cube(2))
'''

#装饰器    带有@符号的方法名
#将一个函数作为另一个函数的参数传入  这就是装饰器的工作原理
'''
def target():
    print('this is target')
def decorator(func):
    func()
    print('this is decorator')
decorator(target)
'''

#会输出结果但是还是有错误
'''
def decorator(func):
    func()
    print('this is decorator')
@decorator    #表示位与下方的方法将作为参数传递到@后面
def target():
    print('this is target')
target()
'''


#装饰器的正确写法
def decorator(func):
    def restructure():
        func()
        print('this is decorator')
    return restructure
@decorator
def target():
    print('this is target')        
target()      
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        























