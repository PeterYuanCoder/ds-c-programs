# -*- coding: utf-8 -*-
"""
Created on Mon Feb 23 22:08:49 2026

@author: ASUS
"""

#lambda  创建匿名函数
#lambda  语法
'''
变量名=lambda[arg1[,arg2......,argn]]:expression
lambda参数列表：return[表达式]变量
由于lambda 返回的是函数对象(构建的是一个函数对象)，所以需要定义一个变量去接收
'''

#定义生成器  就在函数中用yield表达式来替换return语句
def counter():
    i=0
    while i<=5:
        yield i    #每调用一次提供一个数据
        i+=1
for i in counter():
    print(i)
c=counter()  #那c就是生成器