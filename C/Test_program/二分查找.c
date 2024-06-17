#include <stdio.h>  
  
int main() {  
    int nums[] = {1, 3, 5, 7, 9};  // 定义一个升序排列的整数数组  
    int n = sizeof(nums) / sizeof(nums[0]);  // 数组长度  
    int target = 7;  // 目标值  
    int left = 0, right = n - 1;  // 定义左右指针  
    int start = -1, end = -1;  // 开始位置和结束位置的初始值  
  
    while (left <= right) {  
        int mid = (left + right) / 2;  // 计算中间位置  
        if (nums[mid] == target) {  
            start = mid;  // 更新开始位置  
            end = mid;  // 更新结束位置  
            break;  // 找到目标值后跳出循环  
        } else if (nums[mid] < target) {  
            left = mid + 1;  // 目标值在右侧，移动左指针  
        } else {  
            right = mid - 1;  // 目标值在左侧，移动右指针  
        }  
    }  
  
    if (start != -1 && end != -1) {  
        printf("目标值 %d 的开始位置是 %d，结束位置是 %d\n", target, start, end);  
    } else {  
        printf("目标值 %d 不在数组中\n", target);  
    }  
  
    return 0;  
}
