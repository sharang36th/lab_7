#include "header.hpp"
#include <fstream>

// Задание 3
// Реализуйте функцию сохранения группы в файл
void saveToFile(const std::string& filename, const Groups& groups)
{
	std::ofstream fout(filename);

	if (fout.is_open() == false)
	{
		return;
	}

	// Формат (всё построчно, чтобы можно было хранить пробелы):
	// countGroups
	// groupId
	// countStudents
	// StudentName
	// StudentYear
	// countRecords
	// subject
	// scoreInt
	// ...

	fout << groups.size() << "\n";

	for (Groups::const_iterator git = groups.begin(); git != groups.end(); ++git)
	{
		fout << git->first << "\n";
		fout << git->second.size() << "\n";

		const std::vector<Student>& st = git->second;

		for (size_t i = 0; i < st.size(); i++)
		{
			fout << st[i].Name << "\n";
			fout << st[i].Year << "\n";
			fout << st[i].RecordBook.size() << "\n";

			for (std::map<std::string, Score>::const_iterator rit = st[i].RecordBook.begin();
				rit != st[i].RecordBook.end();
				++rit)
			{
				fout << rit->first << "\n";
				fout << (int)rit->second << "\n";
			}
		}
	}
}


// Реализуйте функцию загрузки группы из файла
void loadFromFile(const std::string& filename, Groups& outGroups)
{
	outGroups.clear();

	std::ifstream fin(filename);

	if (fin.is_open() == false)
	{
		return;
	}

	std::string line;

	// читаем количество групп
	if (std::getline(fin, line) == false)
	{
		return;
	}

	size_t groupsCount = 0;

	try
	{
		groupsCount = (size_t)std::stoul(line);
	}
	catch (...)
	{
		return;
	}

	for (size_t g = 0; g < groupsCount; g++)
	{
		std::string groupId;

		if (std::getline(fin, groupId) == false)
		{
			return;
		}

		if (std::getline(fin, line) == false)
		{
			return;
		}

		size_t studentsCount = 0;

		try
		{
			studentsCount = (size_t)std::stoul(line);
		}
		catch (...)
		{
			return;
		}

		std::vector<Student> students;

		for (size_t i = 0; i < studentsCount; i++)
		{
			Student s;

			if (std::getline(fin, s.Name) == false)
			{
				return;
			}

			if (std::getline(fin, line) == false)
			{
				return;
			}

			try
			{
				s.Year = std::stoi(line);
			}
			catch (...)
			{
				return;
			}

			if (std::getline(fin, line) == false)
			{
				return;
			}

			size_t recCount = 0;

			try
			{
				recCount = (size_t)std::stoul(line);
			}
			catch (...)
			{
				return;
			}

			for (size_t r = 0; r < recCount; r++)
			{
				std::string subject;

				if (std::getline(fin, subject) == false)
				{
					return;
				}

				if (std::getline(fin, line) == false)
				{
					return;
				}

				int scoreInt = 0;

				try
				{
					scoreInt = std::stoi(line);
				}
				catch (...)
				{
					return;
				}

				Score sc = (Score)scoreInt;
				s.RecordBook[subject] = sc;
			}

			students.push_back(s);
		}

		outGroups[groupId] = students;
	}
}
