/**
* @file main.cpp
* @brief ���C���֐�
* @author ����P
* @date 2023/10/17/15:00
* @details  �ۑ�1_3�u�o�������X�g�̃e���v���[�g���v
			�e�L�X�g�t�@�C����ǂݍ��݁A���̓��e�����X�g�Ɋi�[���A���ɕ\�����Ă��܂��B\n
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"
#include "recordData.h"

int main()
{
	std::ifstream inputFile("Scores.txt"); //�t�@�C���ǂݍ���

	if (!inputFile.is_open()) // �t�@�C�����J���Ȃ�������I��
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
		getchar();
		return 0;
	}

	DoublyLinkedList<RecordData> list;

	// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
	int score;
	std::string name;

	// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
	while (inputFile >> score >> name)
	{
		RecordData data = { score,name };
		list.PushBack(data);
	}

	// �t�@�C�������
	inputFile.close();

	// ���X�g���i�[�������ŕ\��
	for (const RecordData& data : list)
	{
		std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
	}

	getchar();

	return 0;
}