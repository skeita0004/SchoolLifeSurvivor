#include <Windows.h>
#include "CsvReader.h"

CsvReader::CsvReader()
{
	data_.clear();
}

CsvReader::~CsvReader()
{
	//全データを開放
	for (int y = 0; y < data_.size(); y++)
	{
		for (int x = 0; x < data_[y].size(); x++)
		{
			data_[y][x].clear();
		}
	}
}

bool CsvReader::Load(std::string _filename)
{
	//ファイルを開く
	HANDLE hFile;
	hFile = CreateFile(_filename.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	//開けなかった
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::string message = "「" + _filename + "」が開けません。\n開いている場合は閉じてください。";
		MessageBox(nullptr, message.c_str(), "BaseProjDx9エラー", MB_OK);

		return false;
	}

	//ファイルのサイズ（文字数）を調べる
	DWORD fileSize = GetFileSize(hFile, nullptr);

	//すべての文字を入れられる配列を用意
	char* temp;
	temp = new char[fileSize];

	//ファイルの中身を配列に読み込む
	DWORD dwBytes = 0;
    if (ReadFile(hFile, temp, fileSize, &dwBytes, nullptr))
    {
        return false;
    }

	//開いたファイルを閉じる
	CloseHandle(hFile);

	//1行のデータを入れる配列
	std::vector<std::string>	line;

	//調べる文字の位置
	DWORD index = 0;

	//最後の文字まで繰り返す
	while (index < fileSize)
	{
		//index文字目から「,」か「改行」までの文字列を取得
		std::string val;
		GetToComma(&val, temp, &index);

		//文字数が0だったということは行末
		if (val.length() - 1 == 0)
		{
			//_dataに1行分追加
			data_.push_back(line);

			//1行データをクリア
			line.clear();

			//index++;
			continue;
		}

		//1行分のデータに追加
		line.push_back(val);
	}

	//読み込んだデータは開放する
	delete[] temp;

	//成功
	return true;
}

void CsvReader::GetToComma(std::string* _result, std::string _data, DWORD* _index)
{
	//「,」まで一文字ずつresultに入れる
	while (_data[*_index] != ',' && _data[*_index] != '\n'&& _data[*_index] != '\r')
	{
		*_result += _data[*_index];
		(*_index)++;
	}

	//最後に「\0」を付ける
	*_result += '\0';
	(*_index)++;
}

std::string CsvReader::GetString(DWORD _x, DWORD _y)
{
    if (_x < 0 || _x >= GetWidth() || _y < 0 || _y >= GetHeight())
    {
		return "";
    }

	return data_[_y][_x];
}

int CsvReader::GetIntValue(DWORD _x, DWORD _y)
{
    return atoi(GetString(_x, _y).c_str());
}
int CsvReader::GetIntValue(int _x, int _y)
{
    return GetIntValue(static_cast<DWORD>(_x), static_cast<DWORD>(_y));
}

size_t CsvReader::GetWidth()
{
	return data_[0].size();
}

size_t CsvReader::GetHeight()
{
	return data_.size();
}

std::vector<std::vector<int>> CsvReader::GetIntData()
{
    std::vector<std::vector<int>> retVal(0, std::vector<int>(0));

    for (int y = 0; y < data_.size(); y++)
    {
        for (int x = 0; x < data_[y].size(); x++)
        {
            retVal[y][x] = GetIntValue(y, x);
        }
    }

    return retVal;
}
