# -*- coding: utf-8 -*-
"""
Created on Fri Sep 17 10:02:02 2021

@author: lilin
"""

import time
import sys

times = 1000


# 第一组密钥数据
passwords = ["asdfv", "qwert"]

# 模拟第三种登陆过程，假设登录过程没有对正确的密码和猜测的密码的长度进行比较，直接进入比较的程序，
def login(input, password):
    for i in range(0, len(input)):
        if password[i] != input[i]:
            return False
        # 模拟延时
        time.sleep(0.00001)
    return True


# 获取密码验证耗费时间
def getRunTime(input, password):
    t1 = time.time()
    # 多次验证，累计时间
    for i in range(int(times)):
        login(input, password)
    t2 = time.time()
    runTime = t2 - t1
    return runTime

if __name__ == "__main__":
    for password in passwords:
        print(f"测试密码: {password}")
        result = ""
        length = len(password)  # 动态设置密码长度
        for index in range(length):
            # 验证次数随已猜测字符串长度增加而减少
            current_times = times // (index + 1)
            
            # 补充
            max_time = 0
            best_char = ''
            all_rejected = True
            for char in 'abcdefghijklmnopqrstuvwxyz':
                guess = result + char
                run_time = getRunTime(guess, password)
                # print(f"猜测: {guess}, 时间: {run_time:.5f} 秒, 验证次数: {current_times}")
                if run_time > max_time:
                    max_time = run_time
                    best_char = char
                    all_rejected = False
            
            if all_rejected:
                print("所有字符都被拒绝，猜测结束。")
                break
            
            result += best_char
            print(f"猜测的字符串: {result}")
            print(f"验证次数: {current_times}, 猜测时间: {run_time:.5f} 秒")
            print(f"{(index + 1) / length * 100}% 完成")
        
        print(f"密码 {password} 的最终结果: {result}")
        print("\n")
