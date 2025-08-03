# -*- coding: utf-8 -*-
"""
Created on Fri Sep 17 11:01:37 2021
@author: lilin
"""
import random
import time

# 字符串长度
length = 8000000    #值太小会出现计时偏差错误


# 模拟第一种登录过程
def different_time_compare(Stringright, Stringguess):
    """
    存在计时攻击的字符串比较方法
    """
    t1 = time.time()
    #1、补充判断密码和猜测的密码的长度是否相同
    if len(Stringright) != len(Stringguess):
      return False, time.time() - t1
    
    #2、利用基本的字符串比较方法，补充登录密码的比较程序
    for i in range(len(Stringright)):
        if Stringright[i] != Stringguess[i]:
            return False, time.time() - t1

    t2 = time.time()
    runTime = t2 - t1
    return True,runTime


# 模拟第二种登录过程
def constant_time_compare(Stringright, Stringguess):
    """
    防止计时攻击的字符串比较方法
    """
    t1 = time.time()
    #3、补充判断密码和猜测的密码的长度是否相同
    if len(Stringright) != len(Stringguess):
        return False, time.time() - t1
    
    #4、补充登录密码的比较程序
    result = 0
    for i in range(len(Stringright)):
        result |= ord(Stringright[i]) ^ ord(Stringguess[i])
    
    t2 = time.time()
    runTime = t2 - t1
    return result == 0, runTime


# 生成字符串  
seed = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+=-"
str1 = []
for i in range(length):
  str1.append(random.choice(seed))
Stringright = ''.join(str1)


str2 = []
for i in range(length):
  str2.append(random.choice(seed))
Stringguess = ''.join(str2)

# 测试函数
def test_compare_functions():
    # 比较相同字符串
    same_result_diff, same_time_diff = different_time_compare(Stringright, Stringright)
    same_result_const, same_time_const = constant_time_compare(Stringright, Stringright)

    print("比较相同字符串")
    print(f"存在计时攻击: {same_time_diff:.6f} 秒")
    print(f"改进算法: {same_time_const:.6f} 秒")

    # 比较不同字符串
    diff_result_diff, diff_time_diff = different_time_compare(Stringright, Stringguess)
    diff_result_const, diff_time_const = constant_time_compare(Stringright, Stringguess)

    print("比较不同字符串")
    print(f"存在计时攻击: {diff_time_diff:.6f} 秒")
    print(f"改进算法: {diff_time_const:.6f} 秒")

# 运行测试
test_compare_functions()
