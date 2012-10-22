/*
 * AlgorithmOfList.h
 *
 *  Created on: 2012-10-20
 *      Author: Administrator
 */

#ifndef _ALGORITHMOFLIST_H_
#define _ALGORITHMOFLIST_H_

#include "../CommonFlag.h"
#include "LinkedList.h"

/* Algorithm of ArrayList */



/* Algorithm of LinkedList */

/* 获取单链表倒数第N个结点值  */
extern Status getNthItemFromBack(const LinkedList L, int n, ElemType *e);

/* 单链表反转/逆序 */
extern Status reverseLinkedList(const LinkedList L);

/* 获取单链表的中间结点值 */
extern Status getMiddleItemFromLinkedList(const LinkedList L, ElemType *e);

/* 删除单链表中的重复元素 */
extern Status removeDuplicateItemFromLinkedList(const LinkedList L);

/* 判断单链表是否有环存在 , 并用end返回环的结束结点 */
extern int hasLoopInLinkedList(const LinkedList L, LinkedList *end);

/* 为单链表创建环*/
extern Status createLoopInLinkedList(LinkedList L, int start);

/* 解除单链表中的环*/
extern Status removeLoopInLinkedList(LinkedList L);

/* 判断两个单链表是否相交*/
extern int isTwoLinkeListIntersection(LinkedList A, LinkedList B);

#endif /* _ALGORITHMOFLIST_H_ */
