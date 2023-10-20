/**
* @file	    stack.inl
* @brief    スタック実装
* @author   村上輝
* @date     2023/10/20/16:00
* @details  課題1_5「スタック・キュー」\n
*/
#pragma once
#include "stack.h"

// コンストラクタ
template<typename DATA>
inline Stack<DATA>::Stack() : m_List(new DoublyLinkedList<DATA>) {}

// デストラクタ
template<typename DATA>
inline Stack<DATA>::~Stack()
{
	delete m_List;
}

// データ数の取得
template<typename DATA>
inline int Stack<DATA>::GetDataNum() const
{
	return m_List->GetDataNum();
}

// 先頭に要素を追加する
template<typename DATA>
inline bool Stack<DATA>::Push(DATA data)
{
	DoublyLinkedList<DATA>::Iterator it = m_List->begin();
	return m_List->Insert(it, data);
}

// 先頭の要素を取り出す
template<typename DATA>
inline bool Stack<DATA>::Pop()
{
	DoublyLinkedList<DATA>::Iterator it = m_List->begin();
	return m_List->Remove(it);
}

// リストのポインタを返す
template<typename DATA>
inline DoublyLinkedList<DATA>* Stack<DATA>::GetLinkedList() const
{
	return this->m_List;
}
