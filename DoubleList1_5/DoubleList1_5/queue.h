/**
* @file	    queue.h
* @brief    �L���[�w�b�_�[
* @author   ����P
* @date     2023/10/20/16:00
* @details  �ۑ�1_5�u�X�^�b�N�E�L���[�v\n
*/
#pragma once
#include "doublyLinkedList.h"

/**
* @brief  �L���[�N���X
* @tparam DATA ���X�g���i�[����f�[�^
*/
template <typename DATA>
class Queue
{
private:

	//! ���X�g�̃|�C���^
	DoublyLinkedList<DATA>* m_List;

public:

	/**
	* @brief �R���X�g���N�^
	*/
	inline Queue();

	/**
	* @brief �f�X�g���N�^
	*/
	inline ~Queue();

	/**
	* @brief �f�[�^���̎擾
	*/
	inline int GetDataNum() const;

	/**
	* @brief	   �擪�ɗv�f��ǉ�����
	* @param[in]   data �ǉ�����f�[�^
	* @return bool �ǉ��ɐ��������true,���s����false
	*/
	inline bool Push(DATA data);

	/**
	* @brief  �����̗v�f�����o��
	* @return bool �폜�ɐ��������true,���s����false
	*/
	inline bool Pop();

	/**
	* @brief  �����o�̃��X�g�̃|�C���^��Ԃ�
	*/
	inline DoublyLinkedList<DATA>* GetLinkedList() const;
};

#include "queue.inl"