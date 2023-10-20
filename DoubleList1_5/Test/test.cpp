/**
* @file		test.cpp
* @brief	自動テストcpp
* @author	村上輝
* @date		2023/10/20/16:30
* @details  課題1_5「スタック・キュー」
*/

#include "pch.h"
#include "test.h"
#include "../DoubleList1_5/queue.h"
#include "../DoubleList1_5/stack.h"

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合の戻り値
			@details	ID:リスト-0\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Empty)
		{
			Stack<int> stack;
			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素をプッシュした後の戻り値
			@details	ID:リスト-1\n
						想定する戻り値：1
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_EQ(1, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素をポップした後の戻り値
			@details	ID:リスト-2\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Pop)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素のプッシュに失敗した後の戻り値
			@details	ID:リスト-3\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push_Failed)
		{
			//メモリアローケーション
		}

		/**********************************************************************************//**
			@brief		プッシュを2回行った後の戻り値
			@details	ID:リスト-4\n
						想定する戻り値：2
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Push_Twice)
		{
			Stack<int> stack;
			EXPECT_TRUE(stack.Push(1));
			EXPECT_TRUE(stack.Push(1));
			EXPECT_EQ(2, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		プッシュを2回行った後、１回ポップした後の戻り値
			@details	ID:リスト-5\n
						想定する戻り値：1
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
			@brief		リストが空である場合に、ポップを行った後の戻り値
			@details	ID:リスト-6\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(StackGetDataNumTest, Test_Empty_Pop)
		{
			Stack<int> stack;
			EXPECT_FALSE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}

		//=================================== プッシュ ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、プッシュした際の挙動
			@details	ID:リスト-8\n
						想定する戻り値：TRUE \n
						リストの末尾に要素が追加される \n
		*//***********************************************************************************/
		TEST(StackPushTest, Test_Empty)
		{
			Stack<int> stack;

			EXPECT_TRUE(stack.Push(1));

			EXPECT_EQ(1, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、プッシュした際の挙動
			@details	ID:リスト-9\n
						想定する戻り値：TRUE \n
						リストの末尾に要素が追加される \n
		*//***********************************************************************************/
		TEST(StackPushTest, Test_Any)
		{
			Stack<int> stack;

			{// 1をpush
				EXPECT_TRUE(stack.Push(1));
				
				EXPECT_EQ(1, stack.GetDataNum());

				// データの確認(1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 2をpush
				EXPECT_TRUE(stack.Push(2));
				
				EXPECT_EQ(2, stack.GetDataNum());

				// データの確認(2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 3をpush
				EXPECT_TRUE(stack.Push(3));
				
				EXPECT_EQ(3, stack.GetDataNum());

				// データの確認(3,2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}
		}


		//=================================== ポップ ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、ポップした際の挙動
			@details	ID:リスト-11\n
						想定する戻り値：FALSE \n
						何も起こらない \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Empty)
		{
			Stack<int> stack;

			EXPECT_FALSE(stack.Pop());

			EXPECT_EQ(0, stack.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、ポップした際の挙動
			@details	ID:リスト-12\n
						想定する戻り値：TRUE \n
						末尾要素が引数経由で渡され、その要素がリストから削除される \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Any_Pop_Once)
		{
			Stack<int> stack;

			// 要素を3つプッシュ
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
			@brief		リストに複数の要素がある場合に、複数回ポップした際の挙動
			@details	ID:リスト-13\n
						想定する戻り値：TRUE \n
						最後に追加した要素から順に引数経由で渡される \n
						追加した順の逆順に取り出されるかチェックし、リストが空になるまで取り出す。 \n
		*//***********************************************************************************/
		TEST(StackPopTest, Test_Any_Pop)
		{
			Stack<int> stack;

			// 要素を3つプッシュ(3,2,1)
			{
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));
				EXPECT_TRUE(stack.Push(3));
				EXPECT_EQ(3, stack.GetDataNum());
			}

			// 先頭要素から取り出していく
			{
				EXPECT_TRUE(stack.Pop());

				EXPECT_EQ(2, stack.GetDataNum());

				// 先頭から取り出されているか確認(2,1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{
				EXPECT_TRUE(stack.Pop());

				EXPECT_EQ(1, stack.GetDataNum());

				// 取り出されているか確認(1)
				DoublyLinkedList<int>::Iterator it = stack.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			// 空になる
			EXPECT_TRUE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());

			// 空なのでFALSE
			EXPECT_FALSE(stack.Pop());
			EXPECT_EQ(0, stack.GetDataNum());
		}


		
		/* キュー */
		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合の戻り値
			@details	ID:リスト1-0\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Empty)
		{
			Queue<int> queue;
			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素をプッシュした後の戻り値
			@details	ID:リスト1-1\n
						想定する戻り値：1
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_EQ(1, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素をポップした後の戻り値
			@details	ID:リスト1-2\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Pop)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		要素のプッシュに失敗した後の戻り値
			@details	ID:リスト1-3\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push_Failed)
		{
			//メモリアローケーション
		}

		/**********************************************************************************//**
			@brief		プッシュを2回行った後の戻り値
			@details	ID:リスト1-4\n
						想定する戻り値：2
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Push_Twice)
		{
			Queue<int> queue;
			EXPECT_TRUE(queue.Push(1));
			EXPECT_TRUE(queue.Push(1));
			EXPECT_EQ(2, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		プッシュを2回行った後、１回ポップした後の戻り値
			@details	ID:リスト1-5\n
						想定する戻り値：1
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
			@brief		リストが空である場合に、ポップを行った後の戻り値
			@details	ID:リスト1-6\n
						想定する戻り値：0
		*//***********************************************************************************/
		TEST(QueueGetDataNumTest, Test_Empty_Pop)
		{
			Queue<int> queue;
			EXPECT_FALSE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());
		}


		//=================================== プッシュ ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、プッシュした際の挙動
			@details	ID:リスト1-8\n
						想定する戻り値：TRUE \n
						リストの末尾に要素が追加される \n
		*//***********************************************************************************/
		TEST(QueuePushTest, Test_Empty)
		{
			Queue<int> queue;

			EXPECT_TRUE(queue.Push(1));

			EXPECT_EQ(1, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、プッシュした際の挙動
			@details	ID:リスト1-9\n
						想定する戻り値：TRUE \n
						リストの末尾に要素が追加される \n
		*//***********************************************************************************/
		TEST(QueuePushTest, Test_Any)
		{
			Queue<int> queue;

			{// 1をpush
				EXPECT_TRUE(queue.Push(1));

				EXPECT_EQ(1, queue.GetDataNum());

				// データの確認(1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 2をpush
				EXPECT_TRUE(queue.Push(2));

				EXPECT_EQ(2, queue.GetDataNum());

				// データの確認(2,1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}

			{// 3をpush
				EXPECT_TRUE(queue.Push(3));

				EXPECT_EQ(3, queue.GetDataNum());

				// データの確認(3,2,1)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it++);
				EXPECT_EQ(2, data);
				data = *(it);
				EXPECT_EQ(1, data);
			}
		}


		//=================================== ポップ ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、ポップした際の挙動
			@details	ID:リスト1-11\n
						想定する戻り値：FALSE \n
						何も起こらない \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Empty)
		{
			Queue<int> queue;

			EXPECT_FALSE(queue.Pop());

			EXPECT_EQ(0, queue.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、ポップした際の挙動
			@details	ID:リスト1-12\n
						想定する戻り値：TRUE \n
						先頭要素が引数経由で渡され、その要素がリストから削除される \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Any_Pop_Once)
		{
			Queue<int> queue;

			// 要素を3つプッシュ
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
			@brief		リストに複数の要素がある場合に、複数回ポップした際の挙動
			@details	ID:リスト1-13\n
						想定する戻り値：TRUE \n
						最初に追加した要素から順に引数経由で渡される \n
						追加した順に取り出されるかチェックし、リストが空になるまで取り出す。 \n
		*//***********************************************************************************/
		TEST(QueuePopTest, Test_Any_Pop)
		{
			Queue<int> queue;

			// 要素を3つプッシュ(3,2,1)
			{
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));
				EXPECT_TRUE(queue.Push(3));
				EXPECT_EQ(3, queue.GetDataNum());
			}

			// 先頭要素から取り出していく
			{
				EXPECT_TRUE(queue.Pop());

				EXPECT_EQ(2, queue.GetDataNum());

				// 先頭から取り出されているか確認(3,2)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it++);
				EXPECT_EQ(3, data);
				data = *(it);
				EXPECT_EQ(2, data);
			}

			{
				EXPECT_TRUE(queue.Pop());

				EXPECT_EQ(1, queue.GetDataNum());

				// 取り出されているか確認(3)
				DoublyLinkedList<int>::Iterator it = queue.GetLinkedList()->begin();
				int data = *(it);
				EXPECT_EQ(3, data);
			}

			// 空になる
			EXPECT_TRUE(queue.Pop());
			EXPECT_EQ(0, queue.GetDataNum());

			// 空なのでFALSE
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