#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void Menu()
{
	printf("\n\n\n"
		"*************** ϵͳ���ܲ˵� ***************\n"
		"--------------------------------------------\n"
		"	1.����������		2.�����½ڵ�\n"
		"	3.�������		4.��������\n"
		"	5.�ҵ��������е�	6.�ж��Ƿ�ɻ�\n"
		"	7.ɾ���ڵ�ȡֵ		8.��ż��ת\n"
		"	9.��ѯ�����Ƿ��ڱ���	10.����ѭ������\n"
		"	11.�������		12.�˳�ϵͳ\n"
		"--------------------------------------------\n");
}

Status Output(List list)//˳�����������ÿ���ڵ����
{
	Node* p=list;
	if (p) {
		p = p->next;
		printf("��ǰ����Ϊ��");
		if (p) {
			for (;p; p = p->next) {
				printf("%d-->", p->value);
			}
		}
		printf("NULL\n");
		return SUCCESS;
	}
	else {
		printf("��������\n");
		return ERROR;
	}

}

Status CreateLinkList(List* plist,int lens)//����һ���ڵ���Ϊlens������
{
	int i,num;
	Node* pnode;   //�½ڵ�
	*plist = (Node*)malloc(sizeof(Node));//����ͷ�ڵ�
	if (*plist) {
		Node* p = *plist;//ָ�����һ���ڵ�
		if (lens > 0)
		{
			for (i = 1;i <= lens;i++)
			{
				printf("�������%d����:", i);
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

Status Insert(List* plist,int num ,int n) //����һ���ڵ㣨��ֵΪnum������n��λ��
{

	int i=1;
	Node* p=*plist;
	if (n < 1) {
		printf("����ʧ�ܣ������ڵ�%d��λ��\n", n);
		return ERROR;
	}
	else {
		if (n > 1) {
			if (p->next) {
				p = p->next;
				//�ҵ���n-1���ڵ�
				while (p->next && i < n - 1) {
					p = p->next;
					i++;
				}
			}
			if (n > i + 1) {
				printf("����ʧ�ܣ������ڵ�%d��λ��\n", n);
				return ERROR;
			}
		}
		else if (n == 1) { p = *plist; }
		//����һ���½ڵ㲢����
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
	printf("����ɹ�^-^\n");
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
			//�ҵ���n���ڵ�
			while (p->next && cnt < n - 1) {
				p = p->next;
				++cnt;
			}
			if (p->next && p->next->next) {
				//ɾ����n���ڵ�
				q = p->next;
				p->next = q->next;
				num = q->value;
				free(q);
				printf("ɾ���ɹ�^-^");
				return num;
			}
			else if (p->next) {
				num = p->next->value;
				free(p->next);
				p->next = NULL;
				printf("ɾ���ɹ�^-^");
				return num;
			}
			else  (printf("�����ڵ�%d��λ��", n));
		}
		else if (n == 1) {
			q = (*plist);
			*plist = q->next;
			num = q->value;
			free(q);
			printf("ɾ���ɹ�^-^");
			return num;
		}
		else  (printf("�����ڵ�%d��λ��", n));
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

void Reverse(List* plist)//����
{
	List p=*plist,q,r;
	int i;
	//�ж�����ڵ����Ƿ����2
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
	printf("����ɹ�^-^\n");
}

void Reverse_1_2(List* plist)//��ż��ת
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
	printf("��ż��ת�ɹ�^-^\n");
}

int Scanf_d(void) {
	unsigned int ret;
	int scan;
	ret=scanf_s("%d", &scan);
	while (ret != 1) {
		while (getchar() != '\n');
		printf("����������������룺");
		ret = scanf_s("%d", &scan);
	}
	while (getchar() != '\n');
	return scan;
}

void Circle(List* plist) {
	List p=(*plist);
	while (p->next) { p = p->next; }
	p->next = (*plist);
	printf("����ɻ��ɹ�^-^\n");
}

void CircularStatus(List list)
{
	int flag = 1;//�ж������Ƿ�ɻ���־λ						
	if (list->next)	{					
		Node* p = list->next;			
		Node* q = list->next;
		if (p->next) {
			do{
				p = p->next->next;
				if (p == q || p == q->next)
				{
					printf("����ɻ�\n");
					flag = 0;
					break;
				}
				q = q->next;
			} while (p && p->next);
		}
		if(flag){
			printf("�����ɻ�\n");
		}
	}
}

void GetMidNum(List list)//Ѱ���м�ڵ�
{
	if (list->next)						//�ж��Ƿ�Ϊ������
	{
		Node* p = list->next;			//�������ָ��
		Node* q = list->next;
		while (p->next && p->next->next){
			p = p->next->next;			
			q = q->next;				
		} 			
		if (p->next) {//�ڵ���Ϊż�������������е�
			printf("�е�Ѱ�ҳɹ�^-^,�е�Ϊ%d��%d\n", q->value, q->next->value);
		}//�ڵ���Ϊ���������������е�
		else{printf("�е�Ѱ�ҳɹ�^-^,�е�Ϊ%d\n", q->value);}	
	}
	else { printf("������Ϊ�գ����м�ڵ�\n"); }
}

void FindNum(List list, int num)
{
	int cnt=0;//���������������������num�ĸ���
	Node* p = list->next;
	for (;p;p = p->next)
	{
		if (p->value == num){
			cnt++;
		}
	}
	if (cnt) {
		printf("^-^��������%d������Ϊ%d", num, cnt);
	}
	else { printf("δ�ҵ�%d", num); }
	
}

