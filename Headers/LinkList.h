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
 *	@description : 顺序输出链表中每个节点的数
 *	@param		 : list（链表名字）
 *	@return		 : Status
 *  @notice      : None
 */
Status Output(List list);

/**
 *	@description : 创建一个长度为lens的链表
 *	@param1		 : *list（链表指针）
 *	@param2		 : lens（创建链表的长度）
 *	@return		 : Status
 *  @notice      : None
 */
Status CreateLinkList(List* list, int lens);

/**
 *	@description : 插入一个节点到第n个位置
 *	@param1		 : *list（链表指针）
 * 	@param2		 : num（插入的数据）
 * 	@param3		 : n（插入位置）
 *	@return		 : Status
 *  @notice      : None
 */
Status Insert(List* list, int num, int n);

/**
 *	@description : 删除第n个节点
 *	@param1		 : *list（链表指针）
 * 	@param2		 : n（删除的位置）
 *	@return		 : int
 *  @notice      : None
 */
int Delete(List* list, int n);


/**
 *	@description : 清空链表
 *	@param		 : *plist（链表指针）
 *	@return		 : void
 *  @notice      : None
 */
void Clean(List* plist);

/**
 *	@description : 反向链表
 *	@param		 : *plist（链表指针）
 *	@return		 : void
 *  @notice      : None
 */
void Reverse(List* plist);

/**
 *	@description : 逆转奇偶节点
 *	@param		 : *plist（链表名字）
 *	@return		 : void
 *  @notice      : None
 */
void Reverse_1_2(List* plist);

/**
 *	@description : 检测非法输入，只能输入一个整数
 *	@param		 : 无
 *	@return		 : int
 *  @notice      : None
 */
int Scanf_d(void);

/**
 *	@description : 输出菜单
 *	@param		 : 无
 *	@return		 : void
 *  @notice      : None
 */
void Menu();

/**
 *	@description : 将链表变成循环链表
 *	@param		 : *plist（链表名字）
 *	@return		 : void
 *  @notice      : None
 */
void Circle(List* plist);

/**
 *	@description : 判断链表是否为循环链表
 *	@param		 : list（链表名字）
 *	@return		 : void
 *  @notice      : None
 */
void CircularStatus(List list);

/**
 *	@description : 得到中间节点
 *	@param		 : list（链表名字）
 *	@return		 : void
 *  @notice      : None
 */
void GetMidNum(List list);

/**
 *	@description : 寻找链表中是否有数据num
 *	@param1		 : list（链表名字）
 *  @param2		 : num（要寻找的数据）
 *	@return		 : void
 *  @notice      : None
 */
void FindNum(List list, int num);

#endif 

