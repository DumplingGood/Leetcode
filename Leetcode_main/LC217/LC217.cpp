// LC217.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
/*
217.给一个整数数组nums，任意一个值如果出现超过两次，则返回true，否则返回false。
*/
//哈希表元素
typedef struct Element
{
	unsigned int key;
	int value; //任意类型
			   //char value[1001];
}Element;

typedef struct Node
{
	Element element;
	struct Node* next;
}Node;

typedef struct HashTable
{
	struct Node* head;
	int tablesize;
	int count;
}HashTable;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int iSize = nums.size();
		HashTable* h = InitHashTable(10);
		Element e;
		for (int i = 0; i < iSize; i++)
		{
			e.key = nums[i];
			e.value = nums[i];
			if (!Insert(h, &e))
			{
				return true;
			}
		}
		return false;
	}
	HashTable* InitHashTable(const unsigned int tablesize)
	{
		HashTable* h = (HashTable*)malloc(sizeof(HashTable));
		h->tablesize = tablesize;
		h->head = (Node*)malloc(h->tablesize * sizeof(Node));
		memset(h->head, 0, h->tablesize * sizeof(Node));
		h->count = 0;
		return h;
	}

	int Hash(HashTable* h, unsigned int key)
	{
		return key%h->tablesize;
	}

	Node* Lookup(HashTable* h, unsigned int key)
	{
		int hashcode;
		hashcode = Hash(h, key);
		Node* p = h->head[hashcode].next;
		while (p != NULL && p->element.key != key)
		{
			p = p->next;
		}
		return p;
	}

	int Insert(HashTable* h, Element* e)
	{
		if (h == NULL) return 0;
		//判断新插入元素是否存在，存在则插入失败
		Node* p = Lookup(h, e->key);
		if (p != NULL) {
			//printf("element[%d] is exist\n", e->key);
			return 0;
		}
		Node* q = (Node*)malloc(sizeof(Node));
		memcpy(&q->element, e, sizeof(Element));

		//头插法插入新的元素
		int ind = Hash(h, e->key);
		q->next = h->head[ind].next;
		h->head[ind].next = q;
		h->count++;
		return 1;
	}

	int Delete(HashTable* h, unsigned int key)
	{
		int hashcode;
		hashcode = Hash(h, key);//获取关键key的哈希地址
		Node* p = &h->head[hashcode];
		//遍历单链表 定位到待删除元素的前一个节点p
		while (p->next != NULL && p->next->element.key != key)
		{
			p = p->next;
		}
		if (p->next == NULL) return 0;
		Node* tmp = p->next; //tmp即为待删除的元素 后面需要释放
		p->next = tmp->next;
		free(tmp);
		h->count--;
		return 1;
	}

	void PrintHashTable(HashTable* h)
	{
		printf("HashTable Size:%d\n", h->count);
		for (int i = 0; i < h->tablesize; i++)
		{
			Node* p = h->head[i].next;

			while (p != NULL)
			{
				printf("[%d-%d] ", p->element.key, p->element.value);
				p = p->next;
			}
			printf("\n");
		}
	}

	void FreeHashTable(HashTable* h)
	{
		Node *q, *p;
		for (int i = 0; i < h->tablesize; i++)
		{
			p = h->head[i].next;
			while (p)
			{
				q = p->next;
				free(p);
				p = q;
			}
		}
		free(h->head);
		free(h);
		return;
	}
};


int main()
{
	/*HashTable* hash = InitHashTable(10);
	Element e;
	for (int i = 0; i < 10; i++)
	{
		e.key = 10 + i;
		e.value = 110 + i;
		Insert(hash, &e);
	}

	PrintHashTable(hash);
	for (int i = 0; i < 10; i++)
	{
		e.key = 20 + i;
		e.value = 120 + i;
		Insert(hash, &e);
	}
	PrintHashTable(hash);

	Delete(hash, 12);

	PrintHashTable(hash);
	Node* p = Lookup(hash, 38);
	if (p)
	{
		printf("Lookup key=28 element success, value=%d\n", p->element.value);
	}
	else
	{
		printf("Lookup key=28 element failed\n");
	}
	PrintHashTable(hash);
	FreeHashTable(hash);*/
	Solution sol;
	vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
	printf("%d\n", sol.containsDuplicate(nums));
	system("pause");
    return 0;
}

