/**
* @file main.cpp
* @brief メイン関数
* @author 村上輝
* @date 2023/10/17/15:00
* @details  課題1_3「双方向リストのテンプレート化」
			テキストファイルを読み込み、その内容をリストに格納し、順に表示しています。\n
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"
#include "recordData.h"

int main()
{
	std::ifstream inputFile("Scores.txt"); //ファイル読み込み

	if (!inputFile.is_open()) // ファイルを開けなかったら終了
	{
		std::cerr << "ファイルを開けません。" << std::endl;
		getchar();
		return 0;
	}

	DoublyLinkedList<RecordData> list;

	// ファイルから読み込んだ値を格納する変数
	int score;
	std::string name;

	// ファイルからデータを読み込んでリストに追加
	while (inputFile >> score >> name)
	{
		RecordData data = { score,name };
		list.PushBack(data);
	}

	// ファイルを閉じる
	inputFile.close();

	// リストを格納した順で表示
	for (const RecordData& data : list)
	{
		std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
	}

	getchar();

	return 0;
}