#pragma once
#include "MedalRow.h"
class MedalsTable
{
public:
	static const int maxSize{ 10 };
private:
	MedalRow* medalRows;
	int size;
	int findCountry(const char* country)const
	{
		for (int i{ 0 }; i < size; ++i)
		{
			if (strcmp(medalRows[i].getCountry(),
				country) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	void addRow(const char* country) {
		if (medalRows == nullptr) {
			this->size = 1;
			medalRows = new MedalRow[size];
			medalRows->setCountry(country);
		}
		else {
			MedalRow* temp = new MedalRow[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = this->medalRows[i];
			}
			temp[size].setCountry(country);

			delete[] medalRows;
			medalRows = temp;
			size++;
		}
	}

public:
	MedalsTable() : size{ 0 }, medalRows{ nullptr } {
		std::cout << "create MEDAL TABLE " << this << "\n";
	};

	MedalsTable(const MedalsTable& medalsTable) {
		this->medalRows = new MedalRow[medalsTable.size];
		for (int i = 0; i < medalsTable.size; i++) {
			this->medalRows[i] = medalsTable.medalRows[i];
		}
	}
	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(size < MedalsTable::maxSize and
				"Table is FULL!");
			/*idx = size++;
			medalRows[idx].setCountry(country);*/
			addRow(country);
			idx = size - 1;
		}
		return medalRows[idx];
	}
	const MedalRow& operator[](const char* country)const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 and "Country not found on const "
			"table");
		return medalRows[idx];
	}
	void print()const
	{
		for (int i{ 0 }; i < size; ++i)
		{
			medalRows[i].print();
		}
	}

	~MedalsTable() {
		std::cout << "dest medal table " << this << "\n";
		if (this->medalRows != nullptr) {
			delete[] medalRows;
		}
	}
};


