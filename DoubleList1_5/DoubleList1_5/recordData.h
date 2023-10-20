/**
* @file recordData.h
* @brief 成績データ
* @author 村上輝
* @date 2023/10/19/11:30
* @details  課題1_3「双方向リストのテンプレート化」\n
*			課題でリストに格納する成績データの構造体です\n
*/

#pragma once

/**
* @brief 成績データ構造体
*/
struct RecordData
{
	//! スコア
	int m_score;

	//! 名前
	std::string m_name;
};