/**
* @file	    stack.inl
* @brief    �X�^�b�N����
* @author   ����P
* @date     2023/10/20/16:00
* @details  �ۑ�1_5�u�X�^�b�N�E�L���[�v\n
*/
#pragma once
#include "stack.h"

// �R���X�g���N�^
template<typename DATA>
inline Stack<DATA>::Stack() : m_List(new DoublyLinkedList<DATA>) {}

// �f�X�g���N�^
template<typename DATA>
inline Stack<DATA>::~Stack()
{
	delete m_List;
}

// �f�[�^���̎擾
template<typename DATA>
inline int Stack<DATA>::GetDataNum() const
{
	return m_List->GetDataNum();
}

// �擪�ɗv�f��ǉ�����
template<typename DATA>
inline bool Stack<DATA>::Push(DATA data)
{
	DoublyLinkedList<DATA>::Iterator it = m_List->begin();
	return m_List->Insert(it, data);
}

// �擪�̗v�f�����o��
template<typename DATA>
inline bool Stack<DATA>::Pop()
{
	DoublyLinkedList<DATA>::Iterator it = m_List->begin();
	return m_List->Remove(it);
}

// ���X�g�̃|�C���^��Ԃ�
template<typename DATA>
inline DoublyLinkedList<DATA>* Stack<DATA>::GetLinkedList() const
{
	return this->m_List;
}
