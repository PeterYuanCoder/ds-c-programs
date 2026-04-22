# -*- coding: utf-8 -*-
"""
Created on Mon Feb  2 17:52:53 2026

@author: ASUS
"""

#列表：列表名=[元素1,元素2,元素3,元素4,......元素n]
#元素1下标为0，以此内推
#索引最后一个元素
'''
rhyme=[1,2,3,4,5,'上山打老虎']

length=len(rhyme)    #len求元素长度
print(rhyme[length-1])

print(rhyme[-1])
'''



#列表切片
'''
rhyme=[1,2,3,4,5,'上山打老虎']
print(rhyme[:])
print(rhyme[0:3])
print(rhyme[3:6])
print(rhyme[:3])
print(rhyme[3:])
print(rhyme[:])
print(rhyme[::2])
print(rhyme[::-1])
print(rhyme[::-2])
'''




#列表增添元素
'''
heros=['绿巨人','钢铁侠']
heros.append('黑寡妇')   #列表名.append(元素)  在列表尾部添加一个元素
print(heros)
heros.extend(['鹰眼','灭霸','雷神'])  #列表名.extend([多个元素列表])   在列表尾部添加多个元素
print(heros)
heros.insert(1,'美国队长')   #在指定位置插入元素或列表
print(heros)
heros.remove('美国队长')     #删除元素  用remove或pop或del
print(heros)              #若列表中有多个要删除的则从第一个开始
heros.pop(1)        #括号内为删除对象的下标
print(heros)
del.heros(1)
print(heros)
heros.clear        #清空列表元素
print(heros)
'''




#列表的修改
'''
heros=['蜘蛛侠','绿巨人','黑寡妇','鹰眼','灭霸','雷神']
heros[4]='钢铁侠'
print(heros)
heros[3:]=['武松','林冲','李逵','美国队长']
print(heros)

heros.sort()   #sort用于排序，数字类型按大小排序，汉字按编码值排序
print(heros)   #sort排序是从小到大
heros.reverse()  #调转顺序    reverse
print(heros)

heros.sort(reverse=True)  #先排序后转换   如果是False则只有排序
print(heros)
heros[heros.index('绿巨人')]='神奇女侠'  #index查找元素下标，如果多个相同的元素则返回第一个下标值
'''



#列表的加法和乘法
'''
s=[1,2,3,4]
t=[4,5,7,8,9,10]
print(s+t)
print(s*2)   #指的是重复多少次，不是元素相乘
'''



#嵌套列表
'''
matrix=[[1,2,3],     #也可直放，矩阵形式
        [4,5,6],
        [7,8,9]]
#用嵌套循环访问嵌套列表
for i in matrix:
    for each in i:
        print(each,end=' ')
    print()

print(matrix[0])    #得到以行单位的整个列表
print(matrix[0][0])  #得到第0行第0列的元素
'''



#列表推导式
#列表中元素乘以2
'''
oho=[1,2,3,4,5,6,7]

for i in range(len(oho)):
    oho[i]=oho[i]*2
print(oho)

oho=[i*2 for i in oho]
print(oho)

y=[c*2 for c in 'Fishc']
print(y)
'''
#取中间一列
'''
matrix=[[1,2,3],
        [4,5,6],
        [7,8,9]]
col2=[row[1] for row in matrix]
print(col2)

#取主对角线
diag=[matrix[i][i] for i in range(len(matrix))]
print(diag)

#取副对角线
dige=[matrix[i][len(matrix)-1-i] for i in range(len(matrix))]
print(dige)

s=[[0]*3 for i in range(3)]
print(s)
s[1][1]=1
print(s)

even=[i+1 for i in range(10) if i%2==0]
print(even)    #先执行if语句，在执行for语句，最后是最左侧式子
'''
#筛选F开头的单词
'''
word=['Great','Fishc','Brilliant','Excellent','Fantistic']
fword=[w for w in word if w[0]=='F']
print(fword)
'''