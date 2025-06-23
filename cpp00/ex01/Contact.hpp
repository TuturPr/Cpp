#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>

class Contact
{
	public:
		Contact( void );
		~Contact( void );
		void addContact(void);
		void displayContact(void) const;
		void print_contacts_list(void) const;
		void print_column(int fieldIndex) const;

	private:
		enum contactFields
		{
			FIRST_NAME = 0,
			LAST_NAME,
			NICKNAME,
			PHONE_NUMBER,
			DARKEST_SECRET,
		};
		std::string _fields[5];
};

