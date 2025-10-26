#pragma once
#include <vector>
#include <string>

/// <summary>
/// CSVファイルを扱うクラス
/// </summary>
class CsvReader
{
public:

	CsvReader();
	~CsvReader();

	/// <summary>
	/// CSVファイルのロード
	/// </summary>
	/// <param name="_fileName">ファイル名</param>
	/// <returns>成功→true 失敗→false</returns>
	bool Load(std::string _fileName);

	/// <summary>
	/// 指定した位置のデータを文字列で取得
	/// </summary>
    /// <param name="_x">取得したい位置(横方向)</param>
    /// <param name="_y">取得したい位置(縦方向)</param>
	/// <returns>取得した文字列</returns>
	std::string GetString(DWORD _x, DWORD _y);

    /// <summary>
    /// 指定した位置のデータを整数で取得
    /// </summary>
    /// <param name="_x">取得したい位置(横方向)</param>
    /// <param name="_y">取得したい位置(縦方向)</param>
    /// <returns>取得した整数値</returns>
    int GetIntValue(DWORD _x, DWORD _y);
    int GetIntValue(int   _x, int   _y);

	/// <summary>
	/// ファイルの列数を取得
	/// </summary>
	/// <returns>列数</returns>
	size_t GetWidth();

	/// <summary>
	/// ファイルの行数を取得
	/// </summary>
	/// <returns>行数</returns>
	size_t GetHeight();

    // todo:この関数いらないかも
    /// <summary>
    /// CSVから読み込んだデータを、整数型ですべて取得
    /// </summary>
    /// <returns>CSVの中身すべて(整数型)</returns>
    std::vector<std::vector<int>> GetIntData();
    
private:
	/// <summary>
	/// 読み込んだデータを入れておく2次元配列
	/// </summary>
	std::vector<std::vector<std::string>> data_;

	/// <summary>
	/// 「,」か「改行」までの文字列を取得
	/// </summary>
	/// <param name="_result">結果を入れるアドレス</param>
	/// <param name="_data">もとの文字列データ</param>
	/// <param name="_index">何文字目から調べるか</param>
	void GetToComma(std::string* _result, std::string _data, DWORD* _index);

};

