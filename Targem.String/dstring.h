#pragma once

#include <iostream>


class dstring
{
	char* data_ = nullptr;
	unsigned int length_;

public:
	
	dstring();
	dstring(const char* data);
	dstring(const dstring& other_string);
	dstring(dstring&& other_string) noexcept;

	dstring& operator=(const dstring& other_string);
	dstring& operator=(dstring&& other_string) noexcept;
	dstring operator+(const dstring& other_string) const;
	char& operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& os, const dstring& ts);
	friend std::istream& getline(std::istream& is, dstring& ts, char delimiter);
	friend std::istream& getline(std::istream& is, dstring& ts);

	bool operator==(const dstring& other_string) const;
	bool operator>(const dstring& other_string) const;
	bool operator<(const dstring& other_string) const;

	unsigned int length() const;
	const char* c_str() const;
	~dstring();
};
