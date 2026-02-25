# -*- coding: utf-8 -*-
"""
Created on Tue Feb  3 21:54:55 2026

@author: ASUS
"""

#元组(tuple)
'''
rhyme=(1,2,3,4,5,'上山打老虎')   #元组可以不带括号，下标从0开始，元组不可修改
'''

#元组切片
'''
print(rhyme[:3])
print(rhyme[:])
print(rhyme[::2])
'''


#元组查找
'''
nums=(1,6,8,9,5,6,3,7,7,7,7)
#用.count可以查找元素出现多少次
print(nums.count(7))
#.index查找元素下标
heros=('蜘蛛侠','绿巨人','黑寡妇')
print(heros.index('黑寡妇'))
'''



#元组加法和乘法
'''
s=(1,2,3,4,5)
t=(6,7,8,9)
print(s+t)
print(s*3)
'''


#元组的嵌套
'''
e=(110,120,130)
i=(138,7556,9879)
w=e,i
print(w)
#元组的迭代
for each in e:
    print(each)
#用嵌套循环迭代嵌套元组
for q in w:
    for each in q:
        print(each)
'''


#元组的列表推导式
'''
s=(1,2,3,4,5,6)
print([each*2 for each in s])   #注意方括号
#生成只有一个元素的元组
x=(520,)
print(type(x))   # type 查看数据类型
'''


#元组的打包和解包    适应与任何类型
#打包
'''
t=(123,'Fishc',3.1415926)
#解包
x,y,z=t    #注意t要写到右边，左侧数量必须与右侧元素数量一样
print(x)
print(y)
print(z)
'''

#元组不可修改，但是可以修改其中的类型的元素
'''
s=[1,2,3,4]
a=[5,6,7,8]
w=(s,a)
print(w)
w[1][1]=2
print(w)
'''