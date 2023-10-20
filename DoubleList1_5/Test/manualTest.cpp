/**
* @file manualTest.h
* @brief �蓮�e�X�gcpp
* @author ����P
* @date		2023/10/20/16:30
* @details  �ۑ�1_5�u�X�^�b�N�E�L���[�v
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_5/doublyLinkedList.h"
#include "../DoubleList1_5/recordData.h"
#include "../DoubleList1_5/queue.h"
#include "../DoubleList1_5/stack.h"


/* stack */

/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-7(�蓮)\n 
				�R���p�C���G���[�ƂȂ�Ȃ���ΐ���\n
*//***********************************************************************************/
TEST(StackManualTest, Test_GetDataNum_WhenConst)
{
#if defined TT_STACK_TEST_GETDATANUM_CONST

	const Stack<int> stack;
	EXPECT_EQ(0, stack.GetDataNum());

#endif //TT_STACK_TEST_GETDATANUM_CONST
	SUCCEED();
}

/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-10(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
*//***********************************************************************************/
TEST(StackManualTest, Test_Push_NotConst)
{
#if defined TT_STACK_TEST_PUSH_CONST

	const Stack<int> stack;
	EXPECT_TRUE(stack.Push(1));

#endif //TT_TEST_PUSH_CONST
	SUCCEED();
}

/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-14(�蓮)\n 
				�R���p�C���G���[�ƂȂ�ΐ���\n
*//***********************************************************************************/
TEST(StackManualTest, Test_Pop_NotConst)
{
#if defined TT_STACK_TEST_POP_CONST

	const Stack<int> stack;
	EXPECT_FALSE(stack.Pop());

#endif //TT_STACK_TEST_POP_CONST
	SUCCEED();
}


/* queue */

/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g1-7(�蓮)\n 
				�R���p�C���G���[�ƂȂ�Ȃ���ΐ���\n
*//***********************************************************************************/
TEST(QueueManualTest, Test_GetDataNum_WhenConst)
{
#if defined TT_QUEUE_TEST_POP_CONST

	const Queue<int> queue;
	EXPECT_EQ(0, queue.GetDataNum());

#endif //TT_QUEUE_TEST_POP_CONST
	SUCCEED();
}

/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g1-10(�蓮)\n
				�R���p�C���G���[�ƂȂ�ΐ���\n
*//***********************************************************************************/
TEST(QueueManualTest, Test_Push_NotConst)
{
#if defined TT_QUEUE_STACK_TEST_PUSH_CONST

	const Queue<int> queue;
	EXPECT_TRUE(queue.Push(1));

#endif //TT_QUEUE_TEST_PUSH_CONST
	SUCCEED();
}

/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g1-14(�蓮)\n
				�R���p�C���G���[�ƂȂ�ΐ���\n
*//***********************************************************************************/
TEST(QueueManualTest, Test_Pop_NotConst)
{
#if defined TT_QUEUE_STACK_TEST_POP_CONST

	const Queue<int> queue;
	EXPECT_FALSE(queue.Pop());

#endif //TT_QUEUE_STACK_TEST_POP_CONST
	SUCCEED();
}