#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

int main()
{
	int lens,scan;//检测输入时所用变量
	int flag = 0,cflag=0;//flag：是否创建链表的标志位   cflag：链表是否成环标志位
	List list1=NULL;//链表名为list1
	Menu();//输出菜单
	while (1) {
		printf("\n请选择菜单编号:");
		scan = Scanf_d();//检测输入的菜单编号
		if (!(scan < 13 && scan >0)) {//输入不合法菜单编号时，提示
			printf("请输入正确的菜单编号\n");
		}
		else if (scan == 12) { //输入12时，清空显示并退出系统
			system("cls");
			return 0;
		}
		else if (scan < 13 && scan >0)//如果输入合法菜单编号
		{
			if(scan==1){//创建一个新链表
				if (flag)//已存在链表
				{
					while (1)
					{
						printf("已存在链表，是否覆盖（请输入0.返回 1.覆盖）：");
						scan=Scanf_d();
						if (scan == 1) {//选择1.覆盖
							printf("请输入创建链表的长度:");
							while (1)//创建成功时退出，输入错误时提示
							{
								lens=Scanf_d();
								if (lens >= 0) {
									CreateLinkList(&list1, lens);
									printf("创建成功\n");
									Output(list1);
									flag = 1;
									break;
								}
								else { printf("创建长度不能为负数，请重新输入："); }
							}	
							break;
						}
						else if (scan == 0) {//选择0.返回
							break;
						}
						else { printf("无输入选项%d，请重新输入\n", scan); }//输入不合法，提示
					}
				}
				else {//链表还未生成
					printf("请输入创建链表的长度:");
					while (1) {
						lens=Scanf_d();
						if (lens >= 0) {
							CreateLinkList(&list1, lens);
							printf("创建成功\n");
							Output(list1);
							flag = 1;
							break;
						}
						else { printf("创建长度不能为负数，请重新输入："); }//输入不合法，提示
					}
				}
			}
			if (flag) {//判断链表是否存在，链表存在才能进行以下操作
				if (scan == 6) {//读入6时，判断链表是否成环
					CircularStatus(list1);
				}
				else {
					if (cflag) { printf("链表已成环，无法进行此操作"); }//在链表成环时，以下操作无法进行
					else {//在链表不成环时，可以进行以下操作
						if (scan == 2) {//插入一个数
							int num, n;
							Output(list1);
							printf("您要插入的数是：");
							num = Scanf_d();
							printf("将要插入到链表的位置（第几个）是：");
							n = Scanf_d();
							Insert(&list1, num, n);
							Output(list1);
						}
						else if (scan == 3) {//显示链表
							Output(list1);
						}
						else if (scan == 4) {//反向链表操作
							Reverse(&list1);
							Output(list1);
						}
						else if (scan == 5) {//输出中间节点
							GetMidNum(list1);
						}
						else if (scan == 7) {//删除链表中的一个结点
							int n, num;
							Output(list1);
							printf("将要删除的节点是（第几个）：");
							n = Scanf_d();
							num = Delete(&list1, n);
							Output(list1);
						}
						else if (scan == 8) {//奇偶反向操作
							Reverse_1_2(&list1);
							Output(list1);
						}
						else if (scan == 9) {//查询链表中是否有数字num
							printf("请输入要查找的数据:");
							int num = Scanf_d();
							FindNum(list1,num);
						}
						else if (scan == 10) {//链表成环操作
							Circle(&list1);
							cflag = 1;
						}
						else if (scan == 11) {//清空链表除头节点外所有结点
							Clean(&list1);
							printf("链表清除成功^-^");
							Output(list1);
						}
					}
				}
			}
			else { printf("暂无链表，请先创建一个链表"); }//若不存在链表，提示
		}
	}
}
//
//void Menu()
//{
//	printf("\n\n\n"
//		"*************** 系统功能菜单 ***************\n"
//		"--------------------------------------------\n"
//		"	1.创建新链表		2.插入新节点\n"
//		"	3.输出链表		4.将链表反向\n"
//		"	5.找到单链表中点	6.判断是否成环\n"
//		"	7.删除节点取值		8.奇偶反转\n"
//		"	9.查询数据是否在表中	10.构造循环链表\n"
//		"	11.清空链表		12.退出系统\n"
//		"--------------------------------------------\n");
//}
//
//Status Output(List list)//顺序输出链表中每个节点的数
//{
//	Node* p=list;
//	if (p) {
//		p = p->next;
//		printf("当前链表为：");
//		if (p) {
//			for (;p; p = p->next) {
//				printf("%d-->", p->value);
//			}
//		}
//		printf("NULL\n");
//		return SUCCESS;
//	}
//	else {
//		printf("链表不存在\n");
//		return ERROR;
//	}
//
//}
//
//Status CreateLinkList(List* plist,int lens)//创建一个节点数为lens的链表
//{
//	int i,num;
//	Node* pnode;   //新节点
//	*plist = (Node*)malloc(sizeof(Node));//生成头节点
//	if (*plist) {
//		Node* p = *plist;//指向最后一个节点
//		if (lens > 0)
//		{
//			for (i = 1;i <= lens;i++)
//			{
//				printf("请输入第%d个数:", i);
//				pnode = (Node*)malloc(sizeof(Node));
//				if (pnode)
//				{
//					num=Scanf_d();
//					pnode->value = num;
//					p->next = pnode;
//					p = pnode;
//				}
//				else { return ERROR; }
//			}
//			p->next = NULL;
//		}
//	}
//	else { return ERROR; }
//	return SUCCESS;
//}
//
//Status Insert(List* plist,int num ,int n) //插入一个节点（数值为num）到第n个位置
//{
//
//	int i=1;
//	Node* p=*plist;
//	if (n < 1) {
//		printf("插入失败，不存在第%d个位置\n", n);
//		return ERROR;
//	}
//	else {
//		if (n > 1) {
//			if (p->next) {
//				p = p->next;
//				//找到第n-1个节点
//				while (p->next && i < n - 1) {
//					p = p->next;
//					i++;
//				}
//			}
//			if (n > i + 1) {
//				printf("插入失败，不存在第%d个位置\n", n);
//				return ERROR;
//			}
//		}
//		else if (n == 1) { p = *plist; }
//		//创建一个新节点并插入
//		Node* pnode = (Node*)malloc(sizeof(Node));
//		if (pnode) {
//			pnode->value = num;
//			if (p) {
//				pnode->next = p->next;
//				p->next = pnode;
//			}
//			else {
//				pnode->next = NULL;
//				if (p) { p->next = pnode; }
//				else return ERROR;
//			}
//		}
//		else return ERROR;
//	}
//	printf("插入成功^-^\n");
//	return SUCCESS;
//}
//
//int Delete(List* plist, int n)
//{
//	int cnt = 1;
//	Node *p= ( * plist)->next;
//	Node* q;
//	if (p) {
//		int num;
//		if (n > 1) {
//			//找到第n个节点
//			while (p->next && cnt < n - 1) {
//				p = p->next;
//				++cnt;
//			}
//			if (p->next && p->next->next) {
//				//删除第n个节点
//				q = p->next;
//				p->next = q->next;
//				num = q->value;
//				free(q);
//				printf("删除成功^-^");
//				return num;
//			}
//			else if (p->next) {
//				num = p->next->value;
//				free(p->next);
//				p->next = NULL;
//				printf("删除成功^-^");
//				return num;
//			}
//			else  (printf("不存在第%d个位置", n));
//		}
//		else if (n == 1) {
//			q = (*plist);
//			*plist = q->next;
//			num = q->value;
//			free(q);
//			printf("删除成功^-^");
//			return num;
//		}
//		else  (printf("不存在第%d个位置", n));
//	}
//	return ERROR;
//}
//
//void Changedate(List* plist,int num, int n)//修改链表中第n个节点的数值为num
//{
//	int cnt = 1;
//	Node* p = *plist;
//	//找到第n个节点
//	while (p->next && cnt < n) {
//		p = p->next;
//		cnt++;
//	}
//	p->value = num;
//}
//
//void Clean(List* list) 
//{
//	List p, q;
//	p = (*list)->next;
//	while (p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	(*list)->next = NULL;
//}
//
//void Reverse(List* plist)//反向
//{
//	List p=*plist,q,r;
//	int i;
//	//判断链表节点数是否大于2
//	for (i = 0;p->next&&i<3;i++){
//		p = p->next;
//	}
//	if (i == 2) {
//		p->next = (*plist)->next;
//		(*plist)->next = p;
//		p->next->next = NULL;
//	}
//	if (i == 3) {
//		p = (*plist)->next;
//		q = p->next;
//		r = q->next;
//		while (r) {
//			q->next = p;
//			p = q;
//			q = r;
//			r = r->next;
//		}
//		q->next = p;
//		(*plist)->next->next = NULL;
//		(*plist)->next = q;
//	}
//	printf("反向成功^-^\n");
//}
//
//void Reverse_1_2(List* plist)//奇偶反转
//{
//	List p = *plist;
//	int a;
//	while (p->next && p->next->next)
//	{
//		a = p->next->value;
//		p->next->value = p->next->next->value;
//		p->next->next->value = a;
//		p = p->next->next;
//	}
//	printf("奇偶反转成功^-^\n");
//}
//
//int Scanf_d(void) {
//	unsigned int ret;
//	int scan;
//	ret=scanf_s("%d", &scan);
//	while (ret != 1) {
//		while (getchar() != '\n');
//		printf("输入错误，请重新输入：");
//		ret = scanf_s("%d", &scan);
//	}
//	while (getchar() != '\n');
//	return scan;
//}
//
//void Circle(List* plist) {
//	List p=(*plist);
//	while (p->next) { p = p->next; }
//	p->next = (*plist);
//	printf("链表成环成功^-^\n");
//}
//
//void CircularStatus(List list)
//{
//	int flag = 1;//判断链表是否成环标志位						
//	if (list->next)	{					
//		Node* p = list->next;			
//		Node* q = list->next;
//		if (p->next) {
//			do{
//				p = p->next->next;
//				if (p == q || p == q->next)
//				{
//					printf("链表成环\n");
//					flag = 0;
//					break;
//				}
//				q = q->next;
//			} while (p && p->next);
//		}
//		if(flag){
//			printf("链表不成环\n");
//		}
//	}
//}
//
//void GetMidNum(List list)//寻找中间节点
//{
//	if (list->next)						//判断是否为空链表
//	{
//		Node* p = list->next;			//定义快慢指针
//		Node* q = list->next;
//		while (p->next && p->next->next){
//			p = p->next->next;			
//			q = q->next;				
//		} 			
//		if (p->next) {//节点数为偶数，则有两个中点
//			printf("中点寻找成功^-^,中点为%d和%d\n", q->value, q->next->value);
//		}//节点数为奇数，则有两个中点
//		else{printf("中点寻找成功^-^,中点为%d\n", q->value);}	
//	}
//	else { printf("该链表为空，无中间节点\n"); }
//}
//
//void FindNum(List list, int num)
//{
//	int cnt=0;//计数器，用来记入查找数num的个数
//	Node* p = list->next;
//	for (;p;p = p->next)
//	{
//		if (p->value == num){
//			cnt++;
//		}
//	}
//	if (cnt) {
//		printf("^-^存在数据%d，个数为%d", num, cnt);
//	}
//	else { printf("未找到%d", num); }
//	
//}
//
