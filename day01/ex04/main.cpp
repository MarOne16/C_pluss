/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:23:18 by mqaos             #+#    #+#             */
/*   Updated: 2023/09/02 22:48:32 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


std::string my_replace(std::string	&line, size_t pos,  std::string	&New, size_t last_pos)
{
    std::string result;

    if (pos <= line.length())
	{
		result = line.substr(0, pos);
		result += New;
		result += line.substr(last_pos, line.length());
    }
	else
        result = line;
    return result;
}

std::string replace_in_file(std::string line, std::string& s1, std::string& s2)
{
	size_t pos = 0;
	std::string new_line = line;

	if (s1.empty())
		return line;
	while ((pos = new_line.find(s1, pos)) != std::string::npos)
		new_line = my_replace(new_line, pos, s2,pos + s1.length());
	return new_line;
}

int main(int argc, char const *argv[])
{
	if (argc == 4)
	{
		std::string line;
		std::string filein = argv[1];
		std::string s1     = argv[2];
		std::string s2     = argv[3];

		std::ifstream inputfile(filein);
		if (!inputfile)
		{
			std::cerr << "open file failed" << std::endl;
			return (1);
		}   
		std::ofstream outputfile(filein + ".replace");
		if (!outputfile)
		{
			std::cerr << "open file failed" << std::endl;
			return (1);
		}   
		while (std::getline(inputfile, line))
		{
			line = replace_in_file(line, s1, s2);
			outputfile << line << std::endl;
		}
		inputfile.close();
		outputfile.close();
	}
	else
		std::cerr << "Number arg is not correct" << std::endl;
	return 0;
}
