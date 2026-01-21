#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <vector>
#include <map>

// Задание 1
// Реализуйте функцию сохранения массива слов в файл
void saveToFile(const std::string& filename, const std::vector<std::string>& data);
// Реализуйте функцию загрузки массива слов из файла
void loadFromFile(const std::string& filename, std::vector<std::string>& outData);

// Задание 2
struct Book
{
	std::string Author;
	std::string Title;
	int Year;
};

// Реализуйте функцию сохранения массива книг в файл
void saveToFile(const std::string& filename, const std::vector<Book>& data);
// Реализуйте функцию загрузки массива книг из файла
void loadFromFile(const std::string& filename, std::vector<Book>& outData);

// Задание 3
enum Score
{
	Unsatisfactorily = 2,
	Satisfactorily,
	Good,
	Excellent
};

struct Student
{
	std::string Name;
	int Year;
	std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;

// Реализуйте функцию сохранения группы в файл
void saveToFile(const std::string& filename, const Groups& groups);
// Реализуйте функцию загрузки группы из файла
void loadFromFile(const std::string& filename, Groups& outGroups);

#endif
