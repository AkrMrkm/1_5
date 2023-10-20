/**
* @file	    queue.inl
* @brief    �L���[����
* @author   ����P
* @date     2023/10/20/16:00
* @details  �ۑ�1_5�u�X�^�b�N�E�L���[�v\n
*/
#pragma once
#include "queue.h"

// �R���X�g���N�^
template<typename DATA>
inline Queue<DATA>::Queue() : m_List(new DoublyLinkedList<DATA>) {}

// �f�X�g���N�^
template<typename DATA>
inline Queue<DATA>::~Queue()
{
	delete m_List;
}

// �f�[�^���̎擾
template<typename DATA>
inline int Queue<DATA>::GetDataNum() const
{
	return m_List->GetDataNum();
}

// �擪�ɗv�f��ǉ�����
template<typename DATA>
inline bool Queue<DATA>::Push(DATA data)
{
	DoublyLinkedList<DATA>::Iterator it = m_List->begin();
	return m_List->Insert(it, data);
}

// �����̗v�f�����o��
template<typename DATA>
inline bool Queue<DATA>::Pop()
{
	DoublyLinkedList<DATA>::Iterator it = m_List->end();
	if (GetDataNum() > 0) --it; // �����̂ЂƂO�̗v�f
	return m_List->Remove(it);
}

// ���X�g�̃|�C���^��Ԃ�
template<typename DATA>
inline DoublyLinkedList<DATA>* Queue<DATA>::GetLinkedList() const
{
	return this->m_List;
}
