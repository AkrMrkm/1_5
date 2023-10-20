/**
* @file	    stack.h
* @brief    スタックヘッダー
* @author   村上輝
* @date     2023/10/20/16:00
* @details  課題1_5「スタック・キュー」\n
*/
#pragma once
#include "doublyLinkedList.h"

/**
* @brief  スタッククラス
* @tparam DATA リストが格納するデータ
*/
template <typename DATA>
class Stack
{
private:

	//! リストのポインタ
	DoublyLinkedList<DATA>* m_List;

public:

	/**
	* @brief コンストラクタ
	*/
	inline Stack();

	/**
	* @brief デストラクタ
	*/
	inline ~Stack();

	/**
	* @brief データ数の取得
	*/
	inline int GetDataNum() const;

	/**
	* @brief	   先頭に要素を追加する
	* @param[in]   data 追加するデータ
	* @return bool 追加に成功すればtrue,失敗だとfalse
	*/
	inline bool Push(DATA data);

	/**
	* @brief  先頭の要素を取り出す
	* @return bool 削除に成功すればtrue,失敗だとfalse
	*/
	inline bool Pop();

	/**
	* @brief  メンバのリストのポインタを返す
	*/
	inline DoublyLinkedList<DATA>* GetLinkedList() const;
};

#include "stack.inl"