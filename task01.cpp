#include "header.hpp"
#include <fstream>

// Задание 1
// Реализуйте функцию сохранения массива слов в файл
void saveToFile(const std::string& filename, const std::vector<std::string>& data)
{
	std::ofstream fout(filename);

	if (fout.is_open() == false)
	{
		return;
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		fout << data[i] << "\n";
	}
}


// Реализуйте функцию загрузки массива слов из файла
void loadFromFile(const std::string& filename, std::vector<std::string>& outData)
{
	outData.clear();

	std::ifstream fin(filename);

	if (fin.is_open() == false)
	{
		return;
	}

	std::string line;

	while (std::getline(fin, line))
	{
		// если в файле есть пустые строки, их можно пропустить
		if (line.size() > 0)
		{
			outData.push_back(line);
		}
	}
}
