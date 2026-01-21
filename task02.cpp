#include "header.hpp"
#include <fstream>

// Задание 2
// Реализуйте функцию сохранения массива книг в файл
void saveToFile(const std::string& filename, const std::vector<Book>& data)
{
	std::ofstream fout(filename);

	if (fout.is_open() == false)
	{
		return;
	}

	// Формат одной строки:
	// Author<TAB>Title<TAB>Year
	for (size_t i = 0; i < data.size(); i++)
	{
		fout << data[i].Author << "\t" << data[i].Title << "\t" << data[i].Year << "\n";
	}
}


// Реализуйте функцию загрузки массива книг из файла
void loadFromFile(const std::string& filename, std::vector<Book>& outData)
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
		if (line.size() == 0)
		{
			continue;
		}

		Book b;

		// Парсим строку по табам
		size_t p1 = line.find('\t');

		if (p1 == std::string::npos)
		{
			continue;
		}

		size_t p2 = line.find('\t', p1 + 1);

		if (p2 == std::string::npos)
		{
			continue;
		}

		b.Author = line.substr(0, p1);
		b.Title = line.substr(p1 + 1, p2 - (p1 + 1));

		std::string yearStr = line.substr(p2 + 1);

		try
		{
			b.Year = std::stoi(yearStr);
		}
		catch (...)
		{
			continue;
		}

		outData.push_back(b);
	}
}
