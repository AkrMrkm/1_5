/**
* @file manualTest.h
* @brief 手動テストcpp
* @author 村上輝
* @date		2023/10/20/16:30
* @details  課題1_5「スタック・キュー」
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_5/doublyLinkedList.h"
#include "../DoubleList1_5/recordData.h"
#include "../DoubleList1_5/queue.h"
#include "../DoubleList1_5/stack.h"


/* stack */

/**********************************************************************************//**
	@brief		constのメソッドであるか
	@details	ID:リスト-7(手動)\n 
				コンパイルエラーとならなければ成功\n
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
	@brief		非constのメソッドであるか
	@details	ID:リスト-10(手動)\n 
				コンパイルエラーとなれば成功\n
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
	@brief		非constのメソッドであるか
	@details	ID:リスト-14(手動)\n 
				コンパイルエラーとなれば成功\n
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
	@brief		constのメソッドであるか
	@details	ID:リスト1-7(手動)\n 
				コンパイルエラーとならなければ成功\n
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
	@brief		非constのメソッドであるか
	@details	ID:リスト1-10(手動)\n
				コンパイルエラーとなれば成功\n
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
	@brief		非constのメソッドであるか
	@details	ID:リスト1-14(手動)\n
				コンパイルエラーとなれば成功\n
*//***********************************************************************************/
TEST(QueueManualTest, Test_Pop_NotConst)
{
#if defined TT_QUEUE_STACK_TEST_POP_CONST

	const Queue<int> queue;
	EXPECT_FALSE(queue.Pop());

#endif //TT_QUEUE_STACK_TEST_POP_CONST
	SUCCEED();
}