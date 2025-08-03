# -*- coding: utf-8 -*-
"""
Created on Fri Sep 17 16:17:44 2021

@author: lilin
已知能量迹取值，以及测量能量迹所用的随机明文，猜测所有可能的密钥，计算每个密钥对应的相关系数，取相关系数的最大值即为对应的正确猜测密钥
"""
import math
import numpy as np
import random

S_Box= [ [14, 4,  13, 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7],
         [0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8],
	     [4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0],
	     [15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13]]

#补充plaintext 
plaintext = [222, 111, 198, 118, 221, 149, 138, 102, 102, 120, 27, 229, 148, 140, 2, 25]
#补充power_std
power_std = [1, 3, 2, 1, 3, 3, 2, 3, 3, 3, 1, 2, 3, 0, 2, 3]


def to_bin(value, num):      #十进制数据，二进制位宽
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

    
def Meanfun(num):
    total=0
    n = len(num)
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


def DPAfun(n,pstd,ptest):
    L_list=[]
    H_list=[]
    med = Meanfun(ptest)
    for i in range(n):
        if ptest[i] <= med:
            L_list.append(pstd[i])
        else:
            H_list.append(pstd[i])
    return Meanfun(H_list) - Meanfun(L_list)

if __name__ == "__main__":
    results = []  # 用于存储每个密钥和其相关系数
    max_corr = -1
    best_key = -1
    for key in range(64):
        sbox_outputs = sboxout(len(plaintext), plaintext, key)
        hw_outputs = [HWfun(output) for output in sbox_outputs]
        corr = DPAfun(len(plaintext), power_std, hw_outputs)
        results.append((key, corr))

    # 排序,取前五个最大值
    results.sort(key=lambda x: x[1], reverse=True)
    
    print("前五个最大相关系数和对应的密钥：")
    for i in range(5):
        key, corr = results[i]
        print(f"密钥: {key}, 相关系数: {corr:.2f}")
     
    
    
    






