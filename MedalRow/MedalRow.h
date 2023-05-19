#pragma once
#include <iostream>
#include <cassert>


class MedalRow
{
	char country[4];
	int medals[3];
public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };
	MedalRow(const char* countryP, const int* medalsP)
	{
		std::cout << "create MEDAL ROW " << this << "\n";
		strcpy_s(country, 4, countryP ? countryP : "NON");
		for (int i{ 0 }; i < 3; ++i)
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}
	MedalRow() : MedalRow(nullptr, nullptr) {
	}

	MedalRow(const MedalRow& medalRow) {
		std::cout << "create MEDAL ROW " << this << "\n";
		for (size_t i = 0; i < 4; i++)
		{
			this->country[i] = medalRow.country[i];
		}
		for (size_t i = 0; i < 3; i++) {
			this->medals[i] = medalRow.medals[i];
		}
	}

	MedalRow& operator=(const MedalRow& medalRow) {
		std::cout << "= MEDAL ROW " << this << "\n";
		if (this != &medalRow) {
			for (size_t i = 0; i < 4; i++)
			{
				this->country[i] = medalRow.country[i];
			}
			for (size_t i = 0; i < 3; i++) {
				this->medals[i] = medalRow.medals[i];
			}
		}
		return *this;
	}
	MedalRow& setCountry(const char* countryP)
	{
		if (countryP)
		{
			strcpy_s(country, 4, countryP);
		}
		return *this;
	}
	const char* getCountry()const { return country; }

	int& operator[](int idx)
	{
		assert((idx >= 0 and idx < 3) and "Index out "
			"of range!");
		return medals[idx];
	}
	int operator[](int idx)const
	{
		assert((idx >= 0 and idx < 3) and "Index out "
			"of range!");
		return medals[idx];
	}
	void print()const
	{
		std::cout << '[' << country << "]-( ";
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << medals[i];
			if (i < 2) { std::cout << '\t'; }
		}
		std::cout << " )\n";
	}
	~MedalRow() {
		std::cout << "dest medal row " << this << "\n";
	}
};





