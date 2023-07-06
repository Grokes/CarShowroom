#pragma once
#include <iostream>
#include <string>

class Automobile
{
private:
	std::string name;
	size_t price;
	size_t year;
	size_t engine_capacity;

public:
	Automobile(std::string name = "default", size_t price = 0, size_t year = 0, size_t engine_capacity = 0) :
		name{ name }, price{ price }, year{ year }, engine_capacity{ engine_capacity } {}
public:
	friend std::ostream& operator<< (std::ostream& out, const Automobile& obj)
	{
		out << "Модель: " << obj.name << std::endl;
		out << "Цена: " << obj.price << std::endl;
		out << "Год: " << obj.year << std::endl;
		out << "Объём двигателя: " << obj.engine_capacity;
		return out;
	}
	friend class Database;
	friend bool operator>(const Automobile& obj1, const Automobile& obj2)
	{
		return (obj1.name > obj2.name);
	}
	friend bool operator<(const Automobile& obj1, const Automobile& obj2)
	{
		return (obj1.name < obj2.name);
	}
};

