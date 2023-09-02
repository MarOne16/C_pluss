/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_Book.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:50:53 by mqaos             #+#    #+#             */
/*   Updated: 2023/07/02 15:36:55 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
class Contact
{
	private:
		std::string First_name;
		std::string Last_name;
		std::string Nick_name;
		std::string Phone;
		std::string Darkest_secret;
	public:

		void    	Set_First_name(std::string First_name_in);
		void    	Set_Last_name(std::string Last_name_in);
		void    	Set_Nick_name(std::string Last_name_in);
		void    	Set_phone(std::string Phone_in);
		void		Set_darkest_secret(std::string p_s);

		std::string Get_First_name(int x);
		std::string Get_Last_name(int x);
		std::string Get_Nick_name(int x);
		std::string Get_phone(void);
		std::string	Get_darkest_secret(int x);
		Contact(void){};
		~Contact(void){};
};

class Phonebook
{  
	private:
		class Contact	Contacts[8];
	public:
		int				Index;
		int				Add_contact(void);
		void			Search_contact(void);
		Phonebook(void){};
		~Phonebook(void){};
		
};
