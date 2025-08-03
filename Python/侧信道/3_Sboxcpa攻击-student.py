# -*- coding: utf-8 -*-
"""
Created on Fri Sep 17 16:17:44 2021

@author: lilin
已知能量迹取值，以及测量能量迹所用的随机明文，猜测所有可能的密钥，计算每个密钥对应的相关系数，取相关系数的最大值即为对应的正确猜测密钥
"""
import math
import random

S_Box= [ [14, 4,  13, 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7],
         [0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8],
	     [4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0],
	     [15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13]]

#补充plaintext取值列表（十进制），与仿真阶段取值一样  
# plaintext = [random.randint(0, 255) for _ in range(n)]
n = 16
plaintext = [142, 197, 156, 182, 89, 63, 106, 121, 27, 39, 189, 167, 49, 76, 208, 194]


#补充power_std列表，由仿真阶段得到的汉明重量向量
# power_std = [random.randint(0, 8) for _ in range(n)]
power_std = [3, 1, 2, 2, 2, 1, 4, 2, 0, 1, 2, 1, 2, 1, 4, 1]


def to_bin(value, num):#十进制数据，二进制位宽
	bin_chars = ""
	temp = value
	for i in range(num):
		bin_char = bin(temp % 2)[-1]
		temp = temp // 2
		bin_chars = bin_char + bin_chars
	return bin_chars.upper()
    
    
def HWfun(num):#计算汉明重量
    # 统计输入num的汉明重量并返回
    return bin(num).count('1')


def Meanfun(n,num):
    total=0
    for i in range(0,n):
        total=total+num[i]
    return total/n

def sboxout(n,P,key):
    pxork=0
    cv=0#列
    rv=0#行
    bpxork=0
    sout=[]
    for i in range(0,n):
        pxork=P[i]^key
        bpxork=str(to_bin(pxork,8))[2:]
        cv=2*int(bpxork[0])+int(bpxork[5])
        rv=8*int(bpxork[1])+4*int(bpxork[2])+2*int(bpxork[3])+int(bpxork[4])
        sout.append(S_Box[cv][rv])
    return sout



def Corrfun(n,pstd,ptest):#计算相关系数
    # 补充相关系数函数，返回两个向量的相关系数值
    # 计算均值
    mean_pstd = Meanfun(n, pstd)
    mean_ptest = Meanfun(n, ptest)
    # 分子部分
    numerator = sum((pstd[i] - mean_pstd) * (ptest[i] - mean_ptest) for i in range(n))
    # 分母部分
    denominator = math.sqrt(sum((pstd[i] - mean_pstd) ** 2 for i in range(n)) 
                            * sum((ptest[i] - mean_ptest) ** 2 for i in range(n)))
    # 防止分母为0
    return numerator / denominator if denominator != 0 else 0

    
if __name__ == "__main__":
    # 遍历所有可能密钥，计算每个猜测密钥对应的相关系数，求最大系数对应的猜测密钥
    # 猜测密钥  
    results = []  # 用于存储每个密钥和其相关系数
    max_corr = -1
    best_key = -1
    for key in range(64):
        sbox_outputs = sboxout(len(plaintext), plaintext, key)
        hw_outputs = [HWfun(output) for output in sbox_outputs]
        corr = Corrfun(len(plaintext), power_std, hw_outputs)
        results.append((key, corr))

    # 排序,取前五个最大值
    results.sort(key=lambda x: x[1], reverse=True)
    
    print("相关系数分析:")
    print("前五个最大相关系数和对应的密钥：")
    for i in range(5):
        key, corr = results[i]
        print(f"密钥: {key}, 相关系数: {corr:.2f}")
    
