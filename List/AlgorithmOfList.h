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

/* ��ȡ����������N�����ֵ  */
extern Status getNthItemFromBack(const LinkedList L, int n, ElemType *e);

/* ������ת/���� */
extern Status reverseLinkedList(const LinkedList L);

/* ��ȡ��������м���ֵ */
extern Status getMiddleItemFromLinkedList(const LinkedList L, ElemType *e);

/* ɾ���������е��ظ�Ԫ�� */
extern Status removeDuplicateItemFromLinkedList(const LinkedList L);

/* �жϵ������Ƿ��л����� , ����end���ػ��Ľ������ */
extern int hasLoopInLinkedList(const LinkedList L, LinkedList *end);

/* Ϊ����������*/
extern Status createLoopInLinkedList(LinkedList L, int start);

/* ����������еĻ�*/
extern Status removeLoopInLinkedList(LinkedList L);

/* �ж������������Ƿ��ཻ*/
extern int isTwoLinkeListIntersection(LinkedList A, LinkedList B);

#endif /* _ALGORITHMOFLIST_H_ */
