// PracticalWork9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <wtypes.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	cout << "Введите путь к файлу: ";
	getline(cin, filename);

	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Не удалось открыть файл." << endl;
	}

	map<string, int> wordCount;
	string word;
	while (file >> word)
	{
		while (!word.empty() && !isalnum(word.back()))
		{
			word.pop_back();
		}

		transform(word.begin(), word.end(), word.begin(), tolower);

		wordCount[word]++;
	}

	vector<pair<string, int>> wordCountVec(wordCount.begin(), wordCount.end());
	sort(wordCountVec.begin(), wordCountVec.end(), [](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.second > b.second;
		});

	cout << "Список слов и количество вхождений: " << endl;
	for (const auto& pair : wordCountVec)
	{
		cout << pair.first << " : " << pair.second << endl;
	}

	return 0;
}