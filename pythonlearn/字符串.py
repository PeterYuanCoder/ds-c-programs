# -*- coding: utf-8 -*-
"""
Created on Wed Feb  4 21:23:44 2026

@author: ASUS
"""

#回文数从左往右和从右往左是一样的
'''
x='12321'
if x==x[::-1]:
    print('是回文数')
else:
    print('不是回文数')
'''    
 
   
'''
x='I love FishC'
#  .capitalize  将单词首字母变成大写其他变成小写
print(x.capitalize())
#  .casefold   将所有字母小写    可以处理其他语言
print(x.casefold())
#   .title    将每个单词的首字母大写
print(x.title())
#    .swapcase   将大写变成小写，小写变成大写
print(x.swapcase())
#    .upper   将所有字母大写
print(x.upper())
#    .lower   将所有字母小写      只能处理英文
print(x.lower())
'''



'''
x='上海自来水来时海上'
#  .count查找指定字符出现的次数
print(x.count('海'))
#方括号说明是可选参数，赋值有新的特性出现
#.count(sub[,start[,end]])  start对应起始位置，end对应结束位置
print(x.count('海',0,5))
#.find(sub[,start[,end]])  从左往右找字符的位置输出下标  
#.rfind(sub[,start[,end]])  从右往左找字符的位置输出下标
#找不到输出-1
print(x.find('海'))
print(x.find('袁'))
print(x.rfind('海'))
'''


'''
x='我爱python'
#.startswith([,start[,end]])判断参数是否出现在起始位置
print(x.startswith('我'))
#.endswith([,start[,end]]) 判断参数是否出现在结束位置
print(x.endswith('python'))

if x.startswith(('你','我','她')):  #使用元组将多个待匹配的字符串写进去
    print('总有人喜欢python')
'''


'''
#加is变为判断
#.istitle()判断字母都是大写字母开头
x='l Love Python'
print(x.istitle())
#.isupper()判断是否都为大写字母
print(x.isupper())
#从左往右依次调用, 先用 .upper()将字符串转换成大写字母，再判断
print(x.upper().isupper())
#.islower()判断是否都为小写  
print(x.islower())
#.isalpha判断自字符串是否只有字母构成
print(x.isalpha())   #空格不是字符串输出False ，使用转义字符就可以了
#.isidentifier()判断字符串是否是合法的python标识符
y='FishC520'
z='520FishC'     #标识符不能以数字开头
print(y.isidentifier())
print(z.isidentifier())
'''

'''
#截取     注意单词特性
#.lstrip()去除左侧的留白
print('    左侧不要留白'.lstrip())
#.retrip()去除右侧留白
print('右侧不要留白    '.rstrip())
#.strip()去除左右留白
print('    去除左右留白    '.strip())
#.removeprefix()删除指定的前缀
print('www.yuansiledashuaige.com'.removeprefix('www.'))
#removesuffix()删除指定的后缀
print('www.yuansiledashuaige.com'.removesuffix('.com'))
'''



'''
#拆分和拼接
#.partition(sep)从左到右找一个分隔符  结果返回一个三元组
print('www.yuansiledashuaige.com'.partition('.'))
#.rpartition(sep)从右到左找一个分隔符  结果返回一个三元组
print('yuansiledashuaige/python'.rpartition('/'))
#.join(iterable)字符串拼接
#用列表和元组包裹都没问题
print('.'.join(['www','yuansiledashuaige','.com']))  
print('^'.join(('F','ish','C')))
#拼接2个一样的字符串
print(''.join(('FoshC','FishC')))
'''




#格式化字符串
#使用花括号表示替换字段真正的放在format后面
year=2010
print('鱼c工作室成立于{}年'.format(year))
print('1+2={},2的平方是{}，3的立方是{}'.format(1+2,2*2,3*3*3))
print('{}看到{}就很激动！'.format('小甲鱼','漂亮的小姐姐'))
#参数中的字符串被当作元组的我元素对待
print('{1}看到{0}就很激动！'.format('小甲鱼','漂亮的小姐姐'))
print('{0}{0}{1}{1}'.format('是','非'))
#关键字参数写法
print('我叫{name}，我爱{fov}'.format(name='小甲鱼',fov='python'))
print('我叫{name},我爱{0}，喜爱{0}的人，运气送不胡太差'.format('python',name='小甲鱼'))
#单纯输出花括号    fotmat后面的逗号是英文的
print('{}，{}，{}'.format(1,'{}',2))
print('{},{{}},{}'.format(1,2))
#强制字符串可用空间居中
#冒号左边是位置或者关键字索引
#冒号右边是格式化选项
print('{:^}'.format(250))
print('{:^10}'.format(250))
print('{1:>10}{0:<10}'.format(520,250))
print('{left:>10}{right:<10}'.format(left=520,right=250))
#符号选项
print('{:+} {:-}'.format(100,200))
#做千分符    位数不足千位不显示
print('{:,}'.format(123456))
print('{:_}'.format(123456))
print('{:,}'.format(123456789))
#f或F的浮点数是限定小数点后显示的多少个位数
print('{:.2f}'.format(3.1415928))
#g或G的浮点数来说，是限定小数点前后一共显示多少个位数
print('{:.2g}'.format(3.1415926))
#对于非数字类型来说，是限定最大字段的大小     整数不能用
print('{:.6}'.format(3.1415928))





















