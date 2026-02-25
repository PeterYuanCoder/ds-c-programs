# -*- coding: utf-8 -*-
"""
Created on Fri Feb 13 21:30:51 2026

@author: ASUS
"""

#字典 
#x={键1:值1,键2:值2,键3:值3,}
'''
#创建字典法一
y={'吕布':'奉先','关羽':'云长'}
print(y['吕布'])
#添加一个键
y['刘备']='玄德'
print(y)

#创建字典法二
b=dict(吕布='奉先',关羽='云长',刘备='玄德')   #键上不加引号
print(b)

#创建字典法三
c=dict([('吕布','奉先'),('关羽','云长'),('刘备','玄德')])

#创建字典法四
d=dict({'吕布':'奉先','关羽':'云长','刘备':'玄德'})

#创建字典法五
e=dict({'吕布':'奉先','关羽':'云长'},刘备='玄德')

#创建字典法六
f=dict(zip(['吕布','关羽','刘备'],['奉先','云长','玄德']))

if(y==b==c==d==e==f):
    print('True')
else:
        print('False')
'''

'''
#字典增加元素
#.fromkeys(iterable[,values])
d=dict.fromkeys('Fish',250)
print(d)
d['F']=70
print(d)
d['C']=78
print(d)

#字典中删除元素
#pop(key[,default])
d.pop('F')
print(d)
#若字典中没这个元素
d.pop('狗','没有')  #这样才不会报错

#popitem()   删除最后一个参加的键值
d.popitem()
print(d)

#也可以用del
del d['i']
print(d)
'''



'''
#字典中元素的修改
d=dict.fromkeys('FishC',250)
print(d)
#单键值修改
d['s']=250
print(d)
#多键值修改     .update([other])
d.update({'i':105,'h':104})
print(d)

d.update(F='70',C='67')
print(d)
'''



'''
#查找字典中的元素
d=dict.fromkeys('FishC')
print(d)
print(d['C'])
#get(key[,default])查找指定元素，并指定查不到的时候的返回值
print(d.get('z','这里没有z'))
'''


#字典的嵌套
d={'吕布':{'英语':50,'数学':80,'语文':90},'刘备':{'英语':10,'数学':60,'语文':100}}
print(d['吕布']['数学'])
print(d['吕布'])

f={'吕布':[50,80,90],'刘备':[10,60,100]}
print(f['刘备'][1])














































