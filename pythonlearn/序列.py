# -*- coding: utf-8 -*-
"""
Created on Wed Feb 11 21:10:17 2026

@author: ASUS
"""

'''
列表，元组和字符串的共同点（统称为序列）
1，都可以通过索引获取每一个元素
2，第一个元素索引值都是0
3，都可以通过切片的方法获得一个范围
4，都有很多共同的运算符
'''




'''
#is和is not    用于检测id是否相等从而判断是否是同一个对象
x='FishC'
y='FishC'
print(x is y)


z=[1,2,3]
a=[1,2,3]
print(z is a)
'''

'''
#in和not in  判断是否包含
x='鱼'
y='鱼c'
print(x in y)  #x是否属于y  反之
print(x not in y)
'''


'''
#del 用于删除一个或多个指定的对象
x='FishC'
y=[1,2,3,4,5,6,7]
del x
print(y)   #打印x会报错
del y[1:4]  #也可用切片的方法   y[1:4]=[]
print(y)
'''



'''
#列表，元组和字符串相互转换
#list  转变为列表
print(list('FishC'))
print(list((1,2,3,4,5,6)))   #元组要再套一个括号

#tuple  转元组
print(tuple('FishC'))
print(tuple([1,2,3,4,5,6]))

#str转字符串
print(str([1,2,3,4,5,6]))
print(str((1,2,3,4,5,6)))
'''



'''
#min()和max()   对比传入的参数并且返回最小值和最大值
s=[1,1,2,3,5]
print(min(s))
print(max(s))
#字符串比较编码值    大写字母编码值在小写字母之前
t='FishC'
print(max(t))
#当输入空的对象的时候 用default  否则会报错
a=[]
print(max(a,default='啥都没有，怎么找'))
#直接传参数
print(min(1,2,3,4,5,6,0))
print(max(1,23,4,5,6,7))
'''



'''
#len()和sum()    分别是求长度和求和的
s=[1,2,3,4,5,6,7,8,9]
print(sum(s))
print(len(s))
#sum有一个start参数   用于指定求和的初始值
print(sum(s,start=100))
'''



'''
#sorted()和reversed()    
#列表中有一个.sort 用于对列表进行原地排序   只能处理列表
#用sorted()函数只排序未修改   用.sort()则是直接修改了s
s=[1,2,7,4,8,6]
print(sorted(s))
print(s)
print(s.sort())
print(s)
#reverse  反转
print(sorted(s,reverse=True))
'''



'''
#all()和any()   all判断是否所有元素的值为真  any判断是非存在某个元素的值为真
x=[1,2,0]
y=[1,1,9]
print(all(x))
print(all(y))
print(any(x))
print(any(y))

#enumerate()函数    由下标和元素组成的二元组
seasons=['spring','summer','fall','winter']
print(list(enumerate(seasons)))
print(list(enumerate(seasons,10)))

#zip()函数
s=[1,2,3]
q=[4,5,6]
w=[7,8,9]
zipped=zip(s,q,w)
print(list(zipped))
e='FishC'
print(list(zip(s,q,w,e)))   #若元素个数不同则以小的为准

#map()函数    ord求编码值    pow计算次方
mapped=map(ord,'FishC')
print(list(mapped))
mapped=map(pow,[2,3,10],[5,2,3])
#相当于  print([pow(2,5),pow[3,2],pow[10,3]])
print(list(mapped))
#若元素个数不同以最小的为准
print(list(map(pow,[1,3,5],[1,2,3,4])))

#filter()函数    只返回为真的   .islower判断是否为小写
print(list(filter(str.islower,'FishsC')))
'''



#iter()     将可迭代对象变成迭代器
x=[1,2,3,4,5]
y=iter(x)
print(type(x))      #列表     可迭代对象可以重复迭代
print(type(y))      #列表迭代器   迭代器只可以迭代一次

#next()将迭代器中的元素一个一个拿出来
print(next(y,'没啦，被你掏空了'))
print(next(y,'没啦，被你掏空了'))
print(next(y,'没啦，被你掏空了'))
print(next(y,'没啦，被你掏空了'))
print(next(y,'没啦，被你掏空了'))
print(next(y,'没啦，被你掏空了'))



















