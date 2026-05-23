# -*- coding: utf-8 -*-
"""
Created on Tue Feb 17 22:38:01 2026

@author: ASUS
"""
'''
#集合(set)      {元素1,元素2,元素3}
#集合中的所有元素都应该是独一无二的并且也是无序的    所以不能用下标索引
#集合推导式
print({s for s in 'FishC'})
print(set('FishC'))

#判断是否有相同的元素
s=[1,1,2,4,6,8,10]
print(len(s)==len(set(s)))

#.copy()拷贝
t=s.copy()
print(t)
'''


'''
#使用运算符左右两边都需要是集合形式
#.isdisjoint()判断是否有交集   有交集为假没交集为真  
s=set('FishC')
print(s)
print(s.isdisjoint('python'))
print(s.isdisjoint('JAVA'))

#.issubset()判断是否为子集    <=
print(s.issubset('FishC.com.cn'))

#.issuperset()判断是否为超集   集合A,B有包含关系   >
print(s.issuperset('Fish'))

#.union()将其并集      支持多参数   |
print(s.union({1,2,3,4}))
print(s.union({1,2,3,4},'python'))

#.intersection()输出交集     支持多参数    &
print(s.intersection('Fish'))

#.difference()输出差集   两集合向差的元素    支持多参数   -
print(s.difference('Fish'))
'''



#frozenset()不可变集合
t=frozenset('FishC')
#set的方法也适用与forzenset

#集合的嵌套
x={1,2,3}
x=frozenset(x)
y={x,7,8}
print(y)

























