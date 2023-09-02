/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:51:21 by mqaos             #+#    #+#             */
/*   Updated: 2023/06/28 15:27:50 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone_Book.h"

// Set_Contact
void   Contact::Set_First_name(std::string First_name_in)
{
    First_name = First_name_in;
}

void    Contact::Set_Last_name(std::string Last_name_in)
{
    Last_name = Last_name_in;
}

void    Contact::Set_Nick_name(std::string Last_name_in)
{
    Nick_name = Last_name_in;
}

void    Contact::Set_phone(std::string Phone_in)
{
    Phone = Phone_in;
}

void		Contact::Set_darkest_secret(std::string p_s)
{
    Darkest_secret = p_s;
}
//
//Get_Contact
std::string Contact::Get_First_name(int x)
{
    std::string clone = "";
    int i = 0;
    if (x == 1)
        return (First_name);
    while (First_name[i] && i < 10)
    {
        clone += First_name[i];
        i++;
    }
    return (clone);
}
std::string Contact::Get_Last_name(int x)
{
    std::string clone = "";
    int i = 0;
    if (x == 1)
        return (Last_name);
    while (Last_name[i] && i < 10)
    {
        clone += Last_name[i];
        i++;
    }
    return (clone);
}
std::string Contact::Get_Nick_name(int x)
{
    std::string clone = "";
    int i = 0;
    if (x == 1)
        return (Nick_name);
    while (Nick_name[i] && i < 10)
    {
        clone += Nick_name[i];
        i++;
    }
    return (clone);
}
std::string         Contact::Get_phone(void)
{
    std::string clone = "";
    int i = 0;
    while (Phone[i] && i < 10)
    {
        clone += Phone[i];
        i++;
    }
    return (clone);
}

std::string Contact::Get_darkest_secret(int x)
{
    std::string clone = "";
    int i = 0;
    if (x == 1)
        return (Darkest_secret);
    while (Darkest_secret[i] && i < 10)
    {
        clone += Darkest_secret[i];
        i++;
    }
    return (clone);
}
//
int Phonebook::Add_contact(void) {
    Contact contact;
    std::string First_name;
    std::string Last_name;
    std::string Nick_name;
    std::string Darkest_secret;
    std::string phone;

    start_1:
    std::cout << "Enter first name: ";
    if (!getline(std::cin, First_name) || First_name.empty())
    {
        if(std::cin.eof())
            return 1;
        goto start_1;
    }
    start_2:
    std::cout << "Enter last name: ";
    if (!getline(std::cin, Last_name) || Last_name.empty())
    {
        if(std::cin.eof())
            return 1;
        goto start_2;
    }
    start_3:
    std::cout << "Enter nick name: ";
    if (!getline(std::cin, Nick_name) || Nick_name.empty() )
    {
        if(std::cin.eof())
            return 1;
        goto start_3;
    }
    start_4:
    std::cout << "Enter Darkest secret: ";
    if (!getline(std::cin, Darkest_secret) || Darkest_secret.empty())
    {
        if(std::cin.eof())
            return 1;
        goto start_4;
    }
    start_5:
    std::cout << "Enter phone: ";
    if (!getline(std::cin, phone) || phone.empty())
        return 1;
    for (int i = 0; i < (int)phone.length(); i++) {
        if (!isdigit(phone[i])) {
            std::cout << "Error: phone number must be a 10-digit number." << std::endl;
            goto start_5;
        }
    }
    contact.Set_phone(phone);
    contact.Set_First_name(First_name);
    contact.Set_Last_name(Last_name);
    contact.Set_Nick_name(Nick_name);
    contact.Set_darkest_secret(Darkest_secret);
    Contacts[Index] = contact;
    Index++;
    if (Index > 7)
        Index = 0;
    return 0;
}


void    Phonebook::Search_contact(void)
{
    int i;
    int j = 0;
    std::string First_name;
    std::string Last_name;
    std::string Nick_name;

    i = 0;
    std::cout << std::right << std::setw(10) << "Index  | first name  | last name  | nickname" << std::endl;
    while (i < 8) {
        std::cout << std::left << std::setw(6) << i << " | ";
        std::cout << std::left << std::setw(11) << Contacts[i].Get_First_name(0) << " | ";
        std::cout << std::left << std::setw(10) << Contacts[i].Get_Last_name(0) << " | ";
        std::cout << Contacts[i].Get_Nick_name(0) << std::endl;
        i++;
    }
    std::cout << "Enter Index: ";
    if (!getline(std::cin, First_name) || First_name.empty())
        exit(0);
    j = atoi(First_name.c_str());
    if (j < 0 || j > 7)
    {
        std::cout << "Error: Index must be between 0 and 7" << std::endl;
        return ;
    }
    std::cout << "first name: " << Contacts[j].Get_First_name(1) << std::endl;
    std::cout << "last name: " << Contacts[j].Get_Last_name(1) << std::endl;
    std::cout << "nick name: " << Contacts[j].Get_Nick_name(1) << std::endl;
    std::cout << "phone: " << Contacts[j].Get_phone() << std::endl;
    std::cout << "Darkest secret: " << Contacts[j].Get_darkest_secret(1) << std::endl;
}

int main()
{
    Phonebook Phonebook;
    std::string command;
    Phonebook.Index = 0;
    int ON = 1;
    do
    {
        std::cout << "Enter command (ADD | SEARCH | EXIT)) : ";
        getline(std::cin, command);
        if (command == "EXIT" || command.empty())
            exit(0);
        else if (command == "ADD")
        {
            if (Phonebook.Add_contact() == 1)
                ON = 0;
            else
                std::cout << "Contact added" << std::endl;
        }
        else if (command == "SEARCH")
            Phonebook.Search_contact();
    }while (ON);
    std::cout << "\nEOF\n"; 
    return 0;
}
