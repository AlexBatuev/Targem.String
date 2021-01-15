#include <iostream>

#include "dstring.h"


dstring::dstring()
{
	length_ = 0;
	data_ = new char[length_];
	data_[0] = '\0';
}

dstring::dstring(const char* const data)
{
	length_ = strlen(data);
	data_ = new char[length_ + 1];
	strcpy(data_, data);
}

// copy constructor
dstring::dstring(const dstring& other_string)
{
	length_ = other_string.length_;
	data_ = new char[length_ + 1];
	strcpy(data_, other_string.data_);
}

// copy assignment
dstring& dstring::operator=(const dstring& other_string)
{
	if (this == &other_string)
		return *this;
	
	delete[] data_;
	
	length_ = other_string.length_;
	data_ = new char[length_ + 1];
	strcpy(data_, other_string.data_);
	return *this;
}

// move constructor
dstring::dstring(dstring&& other_string) noexcept
{
	delete[] data_;

	length_ = other_string.length_;
	data_ = other_string.data_;
	other_string.data_ = nullptr;
}

// move assignment
dstring& dstring::operator=(dstring&& other_string) noexcept
{
	delete[] data_;

	length_ = other_string.length_;
	data_ = other_string.data_;
	other_string.data_ = nullptr;
	return *this;
}

dstring dstring::operator+(const dstring& other_string) const
{
	dstring new_string;
	new_string.length_ = this->length_ + other_string.length_;
	new_string.data_ = new char[new_string.length_ + 1];
	strcpy(new_string.data_, this->data_);
	strcpy(new_string.data_ + this->length_, other_string.data_);
	return new_string;
}

char& dstring::operator[](const size_t index) const
{
	return data_[index];
}

std::ostream& operator<<(std::ostream& os, const dstring& ts)
{
	return os << ts.data_;
}

std::istream& getline(std::istream& is, dstring& ts, const char delimiter)
{
	auto* cc = new char[1024];
	size_t n = 0;
	
	do {
		const auto c = static_cast<char>(is.get());
		if (c == delimiter)
		{
			break;
		}
		cc[n++] = c;
	} while (true);

	auto* dd = new char[n];
	strncpy(dd, cc, n);
	dd[n] = '\0';
	ts = dstring(dd);
	
	delete[] cc;
	delete[] dd;
	
	return is;
}

std::istream& getline(std::istream& is, dstring& ts)
{
	return getline(is, ts, '\n');
}

bool dstring::operator==(const dstring& other_string) const
{
	if (length() != other_string.length())
	{
		return false;
	}

	size_t n = 0;
	while (n < other_string.length() && static_cast<char>(tolower(data_[n])) == static_cast<char>(tolower(other_string[n])))
	{
		n++;
	}
	
	return (n == other_string.length());
}

bool dstring::operator>(const dstring& other_string) const
{
	const auto min_length = (length() < other_string.length()) ? length() : other_string.length();

	size_t n = 0;
	while ((n < min_length) && static_cast<char>(tolower(data_[n])) == static_cast<char>(tolower(other_string[n])))
	{
		n++;
		if (n == min_length)
		{
			return (length() > other_string.length());
		}
	}

	return static_cast<char>(tolower(data_[n])) > static_cast<char>(tolower(other_string[n]));
}

bool dstring::operator<(const dstring& other_string) const
{
	return !(*this == other_string) && !(*this > other_string);
}

unsigned int dstring::length() const
{
	return length_;
}

const char* dstring::c_str() const
{
	return data_;
}

dstring::~dstring()
{
	delete[] data_;
}
