# -*- coding: utf-8 -*-
"""
Created on Fri Sep 17 17:50:09 2021

@author: lilin
用真实密钥,随机明文,得到S盒输出,输出转为汉明重量,即对应了泄露的采样的能量迹

"""
import random

S_Box= [ [14, 4,  13, 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7],
         [0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8],
        [4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0],
        [15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13]]        # DES的密码S盒
 
#补充n：明文个数
#补充plaintext取值列表（十进制）
#补充keyTrue取值（十进制） 
n = 16
plaintext = [random.randint(0, 255) for _ in range(n)]
keyTrue = 32


def to_bin(value, num):#十进制数据，二进制位宽
	bin_chars = ""
	temp = value
	for i in range(num):
		bin_char = bin(temp % 2)[-1]
		temp = temp // 2
		bin_chars = bin_char + bin_chars
	return bin_chars.upper()


def sboxout(n, P, key):
    pxork=0
    cv=0#列
    rv=0#行
    bpxork=0
    sout=[]
    for i in range(0, n):
        pxork=P[i]^key
        bpxork=str(to_bin(pxork,8))[2:]
        cv=2*int(bpxork[0])+int(bpxork[5])
        rv=8*int(bpxork[1])+4*int(bpxork[2])+2*int(bpxork[3])+int(bpxork[4])
        sout.append(S_Box[cv][rv])
    return sout


def HWfun(num):
    #统计输入num的汉明重量并返回  
    return bin(num).count('1')

if __name__ == "__main__":
    # 补充：S盒输出对应汉明重量列表 
    sbox_outputs = sboxout(n, plaintext, keyTrue)
    hw_vector = [HWfun(output) for output in sbox_outputs]
    print("输入:",plaintext)
    print("S盒输出对应的汉明重量列表:", hw_vector)













