#pragma once
#include "Automobile.h"
#include <algorithm>
#include <list>

class Database
{
private:
	std::list<Automobile> base;

public:
	Database() = default;
	void add(std::string name = "default", size_t price = 0, size_t year = 0, size_t engine_capacity = 0)
	{
		base.emplace_back(name, price, year, engine_capacity);
	}
	void del(std::list<Automobile>::iterator& iter)
	{
		base.erase(iter);
	}
	void show()
	{
		std::for_each(base.begin(), base.end(), [](auto& el) {std::cout << el << std::endl; });
	}
	auto find(const char* param, const char* value)
	{
		if (param == "name")
		{
			std::string temp = value;
			return std::find_if(std::begin(base), std::end(base), [&](auto& el) {return el.name == temp; });
		}
		else if (param == "price")
		{
			int temp = std::stoi(value);
			return std::find_if(std::begin(base), std::end(base), [&](auto& el) {return el.price == temp; });
		}
		else if (param == "year")
		{
			int temp = std::stoi(value);
			return std::find_if(std::begin(base), std::end(base), [&](auto& el) {return el.year == temp; });
		}
		else if (param == "engine_capacity")
		{
			int temp = std::stoi(value);
			return std::find_if(std::begin(base), std::end(base), [&](auto& el) {return el.engine_capacity == temp; });
		}
		else
			throw 100;
	}
	void sort(const char* param = "name")
	{
		if (param == "name")
		{
			//std::sort(std::begin(base), std::end(base), [](auto& el1, auto& el2) {return el1.name < el2.name; });
			base.sort([](auto& el1, auto& el2) {return el1.name < el2.name; });
		}
		else if (param == "price")
		{
			base.sort([](auto& el1, auto& el2) {return el1.price < el2.price; });
		}
		else if (param == "year")
		{
			base.sort([](auto& el1, auto& el2) {return el1.year < el2.year; });
		}
		else if (param == "engine_capacity")
		{
			base.sort([](auto& el1, auto& el2) {return el1.engine_capacity < el2.engine_capacity; });
		}
		else
			throw 100;
	}

};
