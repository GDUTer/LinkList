#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void Menu()
{
	printf("\n\n\n"
		"*************** 系统功能菜单 ***************\n"
		"--------------------------------------------\n"
		"	1.创建新链表		2.插入新节点\n"
		"	3.输出链表		4.将链表反向\n"
		"	5.找到单链表中点	6.判断是否成环\n"
		"	7.删除节点取值		8.奇偶反转\n"
		"	9.查询数据是否在表中	10.构造循环链表\n"
		"	11.清空链表		12.退出系统\n"
		"--------------------------------------------\n");
}

Status Output(List list)//顺序输出链表中每个节点的数
{
	Node* p=list;
	if (p) {
		p = p->next;
		printf("当前链表为：");
		if (p) {
			for (;p; p = p->next) {
				printf("%d-->", p->value);
			}
		}
		printf("NULL\n");
		return SUCCESS;
	}
	else {
		printf("链表不存在\n");
		return ERROR;
	}

}

Status CreateLinkList(List* plist,int lens)//创建一个节点数为lens的链表
{
	int i,num;
	Node* pnode;   //新节点
	*plist = (Node*)malloc(sizeof(Node));//生成头节点
	if (*plist) {
		Node* p = *plist;//指向最后一个节点
		if (lens > 0)
		{
			for (i = 1;i <= lens;i++)
			{
				printf("请输入第%d个数:", i);
				pnode = (Node*)malloc(sizeof(Node));
				if (pnode)
				{
					num=Scanf_d();
					pnode->value = num;
					p->next = pnode;
					p = pnode;
				}
				else { return ERROR; }
			}
			p->next = NULL;
		}
	}
	else { return ERROR; }
	return SUCCESS;
}

Status Insert(List* plist,int num ,int n) //插入一个节点（数值为num）到第n个位置
{

	int i=1;
	Node* p=*plist;
	if (n < 1) {
		printf("插入失败，不存在第%d个位置\n", n);
		return ERROR;
	}
	else {
		if (n > 1) {
			if (p->next) {
				p = p->next;
				//找到第n-1个节点
				while (p->next && i < n - 1) {
					p = p->next;
					i++;
				}
			}
			if (n > i + 1) {
				printf("插入失败，不存在第%d个位置\n", n);
				return ERROR;
			}
		}
		else if (n == 1) { p = *plist; }
		//创建一个新节点并插入
		Node* pnode = (Node*)malloc(sizeof(Node));
		if (pnode) {
			pnode->value = num;
			if (p) {
				pnode->next = p->next;
				p->next = pnode;
			}
			else {
				pnode->next = NULL;
				if (p) { p->next = pnode; }
				else return ERROR;
			}
		}
		else return ERROR;
	}
	printf("插入成功^-^\n");
	return SUCCESS;
}

int Delete(List* plist, int n)
{
	int cnt = 1;
	Node *p= ( * plist)->next;
	Node* q;
	if (p) {
		int num;
		if (n > 1) {
			//找到第n个节点
			while (p->next && cnt < n - 1) {
				p = p->next;
				++cnt;
			}
			if (p->next && p->next->next) {
				//删除第n个节点
				q = p->next;
				p->next = q->next;
				num = q->value;
				free(q);
				printf("删除成功^-^");
				return num;
			}
			else if (p->next) {
				num = p->next->value;
				free(p->next);
				p->next = NULL;
				printf("删除成功^-^");
				return num;
			}
			else  (printf("不存在第%d个位置", n));
		}
		else if (n == 1) {
			q = (*plist);
			*plist = q->next;
			num = q->value;
			free(q);
			printf("删除成功^-^");
			return num;
		}
		else  (printf("不存在第%d个位置", n));
	}
	return ERROR;
}

void Clean(List* plist) 
{
	List p, q;
	p = (*plist)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*plist)->next = NULL;
}

void Reverse(List* plist)//反向
{
	List p=*plist,q,r;
	int i;
	//判断链表节点数是否大于2
	for (i = 0;p->next&&i<3;i++){
		p = p->next;
	}
	if (i == 2) {
		p->next = (*plist)->next;
		(*plist)->next = p;
		p->next->next = NULL;
	}
	if (i == 3) {
		p = (*plist)->next;
		q = p->next;
		r = q->next;
		while (r) {
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		(*plist)->next->next = NULL;
		(*plist)->next = q;
	}
	printf("反向成功^-^\n");
}

void Reverse_1_2(List* plist)//奇偶反转
{
	List p = *plist;
	int a;
	while (p->next && p->next->next)
	{
		a = p->next->value;
		p->next->value = p->next->next->value;
		p->next->next->value = a;
		p = p->next->next;
	}
	printf("奇偶反转成功^-^\n");
}

int Scanf_d(void) {
	unsigned int ret;
	int scan;
	ret=scanf_s("%d", &scan);
	while (ret != 1) {
		while (getchar() != '\n');
		printf("输入错误，请重新输入：");
		ret = scanf_s("%d", &scan);
	}
	while (getchar() != '\n');
	return scan;
}

void Circle(List* plist) {
	List p=(*plist);
	while (p->next) { p = p->next; }
	p->next = (*plist);
	printf("链表成环成功^-^\n");
}

void CircularStatus(List list)
{
	int flag = 1;//判断链表是否成环标志位						
	if (list->next)	{					
		Node* p = list->next;			
		Node* q = list->next;
		if (p->next) {
			do{
				p = p->next->next;
				if (p == q || p == q->next)
				{
					printf("链表成环\n");
					flag = 0;
					break;
				}
				q = q->next;
			} while (p && p->next);
		}
		if(flag){
			printf("链表不成环\n");
		}
	}
}

void GetMidNum(List list)//寻找中间节点
{
	if (list->next)						//判断是否为空链表
	{
		Node* p = list->next;			//定义快慢指针
		Node* q = list->next;
		while (p->next && p->next->next){
			p = p->next->next;			
			q = q->next;				
		} 			
		if (p->next) {//节点数为偶数，则有两个中点
			printf("中点寻找成功^-^,中点为%d和%d\n", q->value, q->next->value);
		}//节点数为奇数，则有两个中点
		else{printf("中点寻找成功^-^,中点为%d\n", q->value);}	
	}
	else { printf("该链表为空，无中间节点\n"); }
}

void FindNum(List list, int num)
{
	int cnt=0;//计数器，用来记入查找数num的个数
	Node* p = list->next;
	for (;p;p = p->next)
	{
		if (p->value == num){
			cnt++;
		}
	}
	if (cnt) {
		printf("^-^存在数据%d，个数为%d", num, cnt);
	}
	else { printf("未找到%d", num); }
	
}

