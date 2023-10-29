#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAX_SIZE 1000 // 散列表的最大容量  
  
// 散列结构体  
typedef struct HashEntry {  
    char key[20]; // 键  
    int value; // 值  
    struct HashEntry* next; // 指向下一个散列项的指针  
} HashEntry;  
  
// 散列表数组  
HashEntry* table[MAX_SIZE];  
  
// 哈希函数  
int hash(char* key) {  
    unsigned long int hashval = 0;  
    int i = 0;  
    while (*(key + i)) {  
        hashval = (hashval << 5) + *(key + i); // 使用移位和加法运算计算哈希值  
        i++;  
    }  
    return hashval % MAX_SIZE;  
}  
  
// 创建新的散列项并插入到链表中  
void insert(char* key, int value) {  
    int index = hash(key); // 计算哈希值  
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry)); // 创建新的散列项  
    strcpy(newEntry->key, key); // 拷贝键  
    newEntry->value = value; // 设置值  
    newEntry->next = NULL; // 将指向下一个散列项的指针初始化为 NULL  
    if (table[index] == NULL) { // 如果该位置为空，将新散列项插入到该位置并返回  
        table[index] = newEntry;  
        return;  
    }  
    HashEntry* prev = table[index]; // 从链表头开始查找插入位置  
    while (prev->next != NULL && prev->next->key != '\0') { // 查找链表尾部或遇到空位置  
        prev = prev->next;  
    }  
    prev->next = newEntry; // 在链表尾部插入新散列项  
}  
  
// 在链表中查找给定的键值对，返回对应的值，如果未找到则返回 -1  
int find(char* key) {  
    int index = hash(key); // 计算哈希值  
    HashEntry* curr = table[index]; // 从该散列位置的链表头开始查找  
    while (curr != NULL && strcmp(curr->key, key) != 0) { // 查找链表尾部或遇到空位置  
        curr = curr->next;  
    }  
    if (curr == NULL) { // 如果未找到，返回 -1 表示未找到  
        return -1;  
    } else { // 如果找到了，返回对应的值  
        return curr->value;  
    }  
}  
  
// 主函数入口点  
int main() {  
    // 测试代码，插入两个键值对并查找它们  
    insert("key1", 10);  
    insert("key2", 20);  
    int value1 = find("key1");  
    int value2 = find("key2");  
    printf("Value for key1: %d\n", value1); // 应输出: Value for key1: 10  
    printf("Value for key2: %d\n", value2); // 应输出: Value for key2: 20  
    return 0;  
}
