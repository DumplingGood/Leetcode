// LC217.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
/*
217.��һ����������nums������һ��ֵ������ֳ������Σ��򷵻�true�����򷵻�false��
*/
//��ϣ��Ԫ��
typedef struct Element
{
	unsigned int key;
	int value; //��������
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
		//�ж��²���Ԫ���Ƿ���ڣ����������ʧ��
		Node* p = Lookup(h, e->key);
		if (p != NULL) {
			//printf("element[%d] is exist\n", e->key);
			return 0;
		}
		Node* q = (Node*)malloc(sizeof(Node));
		memcpy(&q->element, e, sizeof(Element));

		//ͷ�巨�����µ�Ԫ��
		int ind = Hash(h, e->key);
		q->next = h->head[ind].next;
		h->head[ind].next = q;
		h->count++;
		return 1;
	}

	int Delete(HashTable* h, unsigned int key)
	{
		int hashcode;
		hashcode = Hash(h, key);//��ȡ�ؼ�key�Ĺ�ϣ��ַ
		Node* p = &h->head[hashcode];
		//���������� ��λ����ɾ��Ԫ�ص�ǰһ���ڵ�p
		while (p->next != NULL && p->next->element.key != key)
		{
			p = p->next;
		}
		if (p->next == NULL) return 0;
		Node* tmp = p->next; //tmp��Ϊ��ɾ����Ԫ�� ������Ҫ�ͷ�
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

