/**
* @file		test.cpp
* @brief	�����e�X�gcpp
* @author	����P
* @date		2023/10/20/16:30
* @details  �ۑ�1_5�u�X�^�b�N�E�L���[�v
*/

#include "pch.h"
#include "test.h"
#include "../DoubleList1_5/queue.h"
#include "../DoubleList1_5/stack.h"

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̖߂�l
			@details	ID:���X�g-0\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Empty)
		{
			Stack<int> stack;
			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f���v�b�V��������̖߂�l
			@details	ID:���X�g-1\n
						�z�肷��߂�l�F1
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_EQ(1, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f���|�b�v������̖߂�l
			@details	ID:���X�g-2\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Pop)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f�̃v�b�V���Ɏ��s������̖߂�l
			@details	ID:���X�g-3\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push_Failed)
		{
			//�������A���[�P�[�V����
		}

		/**********************************************************************************//**
			@brief		�v�b�V����2��s������̖߂�l
			@details	ID:���X�g-4\n
						�z�肷��߂�l�F2
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push_Twice)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Push(1));
			EXPECT_EQ(2, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�b�V����2��s������A�P��|�b�v������̖߂�l
			@details	ID:���X�g-5\n
						�z�肷��߂�l�F1
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push_Twice_Pop_Once)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Pop());
			EXPECT_EQ(1, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
			@details	ID:���X�g-6\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Empty_Pop)
		{
			Stack<int> stack;
			EXPECT_FALSE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}

		//=================================== �v�b�V�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
			@details	ID:���X�g-8\n
						�z�肷��߂�l�FTRUE \n
						���X�g�̖����ɗv�f���ǉ������ \n
		*//***********************************************************************************/
		TEST(StackPushTest, Test_Empty)
		{
			Stack<int> stack;

			EXPECT_TRUE(stack.Push(1));

			EXPECT_EQ(1, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
			@details	ID:���X�g-9\n
						�z�肷��߂�l�FTRUE \n
						���X�g�̖����ɗv�f���ǉ������ \n
		*//***********************************************************************************/
		TEST(StackPushTest, Test_Any)
		{
			Stack<int> stack;

			{// 1��push
				EXPECT_TRUE(stack.Push(1));
				
				EXPECT_EQ(1, stack.GetDataNum());

				// �f�[�^�̊m�F(1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 2��push
				EXPECT_TRUE(stack.Push(2));
				
				EXPECT_EQ(2, stack.GetDataNum());

				// �f�[�^�̊m�F(2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 3��push
				EXPECT_TRUE(stack.Push(3));
				
				EXPECT_EQ(3, stack.GetDataNum());

				// �f�[�^�̊m�F(3,2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}
		}


		//=================================== �|�b�v ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
			@details	ID:���X�g-11\n
						�z�肷��߂�l�FFALSE \n
						�����N����Ȃ� \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Empty)
		{
			Stack<int> stack;

			EXPECT_FALSE(stack.Pop());

			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
			@details	ID:���X�g-12\n
						�z�肷��߂�l�FTRUE \n
						�����v�f�������o�R�œn����A���̗v�f�����X�g����폜����� \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Any_Pop_Once)
		{
			Stack<int> stack;

			// �v�f��3�v�b�V��
			{
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));
				EXPECT_TRUE(stack.Push(3));
				EXPECT_EQ(3, stack.GetDataNum());
			}

			EXPECT_TRUE(stack.Pop());

			EXPECT_EQ(2, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
			@details	ID:���X�g-13\n
						�z�肷��߂�l�FTRUE \n
						�Ō�ɒǉ������v�f���珇�Ɉ����o�R�œn����� \n
						�ǉ��������̋t���Ɏ��o����邩�`�F�b�N���A���X�g����ɂȂ�܂Ŏ��o���B \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Any_Pop)
		{
			Stack<int> stack;

			// �v�f��3�v�b�V��(3,2,1)
			{
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));
				EXPECT_TRUE(stack.Push(3));
				EXPECT_EQ(3, stack.GetDataNum());
			}

			// �擪�v�f������o���Ă���
			{
				EXPECT_TRUE(stack.Pop());

				EXPECT_EQ(2, stack.GetDataNum());

				// �擪������o����Ă��邩�m�F(2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{
				EXPECT_TRUE(stack.Pop());

				EXPECT_EQ(1, stack.GetDataNum());

				// ���o����Ă��邩�m�F(1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			// ��ɂȂ�
			EXPECT_TRUE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());

			// ��Ȃ̂�FALSE
			EXPECT_FALSE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}


		
		/* �L���[ */
		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̖߂�l
			@details	ID:���X�g1-0\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Empty)
		{
			Queue<int> queue;
			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f���v�b�V��������̖߂�l
			@details	ID:���X�g1-1\n
						�z�肷��߂�l�F1
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_EQ(1, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f���|�b�v������̖߂�l
			@details	ID:���X�g1-2\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Pop)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�f�̃v�b�V���Ɏ��s������̖߂�l
			@details	ID:���X�g1-3\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push_Failed)
		{
			//�������A���[�P�[�V����
		}

		/**********************************************************************************//**
			@brief		�v�b�V����2��s������̖߂�l
			@details	ID:���X�g1-4\n
						�z�肷��߂�l�F2
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push_Twice)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Push(1));
			EXPECT_EQ(2, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�v�b�V����2��s������A�P��|�b�v������̖߂�l
			@details	ID:���X�g1-5\n
						�z�肷��߂�l�F1
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push_Twice_Pop_Once)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Pop());
			EXPECT_EQ(1, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
			@details	ID:���X�g1-6\n
						�z�肷��߂�l�F0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Empty_Pop)
		{
			Queue<int> queue;
			EXPECT_FALSE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());
		}


		//=================================== �v�b�V�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
			@details	ID:���X�g1-8\n
						�z�肷��߂�l�FTRUE \n
						���X�g�̖����ɗv�f���ǉ������ \n
		*//***********************************************************************************/
		TEST(QueuePushTest, Test_Empty)
		{
			Queue<int> queue;

			EXPECT_TRUE(queue.Push(1));

			EXPECT_EQ(1, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
			@details	ID:���X�g1-9\n
						�z�肷��߂�l�FTRUE \n
						���X�g�̖����ɗv�f���ǉ������ \n
		*//***********************************************************************************/
		TEST(QueuePushTest, Test_Any)
		{
			Queue<int> queue;

			{// 1��push
				EXPECT_TRUE(queue.Push(1));

				EXPECT_EQ(1, queue.GetDataNum());

				// �f�[�^�̊m�F(1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 2��push
				EXPECT_TRUE(queue.Push(2));

				EXPECT_EQ(2, queue.GetDataNum());

				// �f�[�^�̊m�F(2,1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 3��push
				EXPECT_TRUE(queue.Push(3));

				EXPECT_EQ(3, queue.GetDataNum());

				// �f�[�^�̊m�F(3,2,1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}
		}


		//=================================== �|�b�v ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
			@details	ID:���X�g1-11\n
						�z�肷��߂�l�FFALSE \n
						�����N����Ȃ� \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Empty)
		{
			Queue<int> queue;

			EXPECT_FALSE(queue.Pop());

			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
			@details	ID:���X�g1-12\n
						�z�肷��߂�l�FTRUE \n
						�擪�v�f�������o�R�œn����A���̗v�f�����X�g����폜����� \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Any_Pop_Once)
		{
			Queue<int> queue;

			// �v�f��3�v�b�V��
			{
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));
				EXPECT_TRUE(queue.Push(3));
				EXPECT_EQ(3, queue.GetDataNum());
			}

			EXPECT_TRUE(queue.Pop());

			EXPECT_EQ(2, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
			@details	ID:���X�g1-13\n
						�z�肷��߂�l�FTRUE \n
						�ŏ��ɒǉ������v�f���珇�Ɉ����o�R�œn����� \n
						�ǉ��������Ɏ��o����邩�`�F�b�N���A���X�g����ɂȂ�܂Ŏ��o���B \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Any_Pop)
		{
			Queue<int> queue;

			// �v�f��3�v�b�V��(3,2,1)
			{
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));
				EXPECT_TRUE(queue.Push(3));
				EXPECT_EQ(3, queue.GetDataNum());
			}

			// �擪�v�f������o���Ă���
			{
				EXPECT_TRUE(queue.Pop());

				EXPECT_EQ(2, queue.GetDataNum());

				// �擪������o����Ă��邩�m�F(3,2)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it);
				EXPECT_EQ(2, data);
			}

			{
				EXPECT_TRUE(queue.Pop());

				EXPECT_EQ(1, queue.GetDataNum());

				// ���o����Ă��邩�m�F(3)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(3, data);
			}

			// ��ɂȂ�
			EXPECT_TRUE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());

			// ��Ȃ̂�FALSE
			EXPECT_FALSE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());
		}


	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}