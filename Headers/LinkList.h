#ifndef __LinkList_H__
#define __LinkList_H__

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

typedef struct _node {
	int value;
	struct _node* next;
}Node;

typedef Node* List;

/**
 *	@description : ˳�����������ÿ���ڵ����
 *	@param		 : list���������֣�
 *	@return		 : Status
 *  @notice      : None
 */
Status Output(List list);

/**
 *	@description : ����һ������Ϊlens������
 *	@param1		 : *list������ָ�룩
 *	@param2		 : lens����������ĳ��ȣ�
 *	@return		 : Status
 *  @notice      : None
 */
Status CreateLinkList(List* list, int lens);

/**
 *	@description : ����һ���ڵ㵽��n��λ��
 *	@param1		 : *list������ָ�룩
 * 	@param2		 : num����������ݣ�
 * 	@param3		 : n������λ�ã�
 *	@return		 : Status
 *  @notice      : None
 */
Status Insert(List* list, int num, int n);

/**
 *	@description : ɾ����n���ڵ�
 *	@param1		 : *list������ָ�룩
 * 	@param2		 : n��ɾ����λ�ã�
 *	@return		 : int
 *  @notice      : None
 */
int Delete(List* list, int n);


/**
 *	@description : �������
 *	@param		 : *plist������ָ�룩
 *	@return		 : void
 *  @notice      : None
 */
void Clean(List* plist);

/**
 *	@description : ��������
 *	@param		 : *plist������ָ�룩
 *	@return		 : void
 *  @notice      : None
 */
void Reverse(List* plist);

/**
 *	@description : ��ת��ż�ڵ�
 *	@param		 : *plist���������֣�
 *	@return		 : void
 *  @notice      : None
 */
void Reverse_1_2(List* plist);

/**
 *	@description : ���Ƿ����룬ֻ������һ������
 *	@param		 : ��
 *	@return		 : int
 *  @notice      : None
 */
int Scanf_d(void);

/**
 *	@description : ����˵�
 *	@param		 : ��
 *	@return		 : void
 *  @notice      : None
 */
void Menu();

/**
 *	@description : ��������ѭ������
 *	@param		 : *plist���������֣�
 *	@return		 : void
 *  @notice      : None
 */
void Circle(List* plist);

/**
 *	@description : �ж������Ƿ�Ϊѭ������
 *	@param		 : list���������֣�
 *	@return		 : void
 *  @notice      : None
 */
void CircularStatus(List list);

/**
 *	@description : �õ��м�ڵ�
 *	@param		 : list���������֣�
 *	@return		 : void
 *  @notice      : None
 */
void GetMidNum(List list);

/**
 *	@description : Ѱ���������Ƿ�������num
 *	@param1		 : list���������֣�
 *  @param2		 : num��ҪѰ�ҵ����ݣ�
 *	@return		 : void
 *  @notice      : None
 */
void FindNum(List list, int num);

#endif 

