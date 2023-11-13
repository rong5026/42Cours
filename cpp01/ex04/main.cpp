/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:11 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 17:02:17 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char *av[])
{
	std::string result_file;
	std::string word1;
	std::string word2;


	if (ac != 4)
	{
		std::cout << "./File <파일이름> <단어1> <단어2>" << std::endl;
		return (1);
	}

	int word1_len;
	int word2_len;

	word1 = av[2];
	word2 = av[3];
	word1_len = word1.length();
	word2_len = word2.length();

	if (std::strlen(av[1]) == 0 || word1_len == 0 || word2_len == 0)
	{
		std::cout << "Inter valid word" << std::endl; 
		return (1);
	}
	
	std::ifstream in_file;
	in_file.open(av[1]);

	if (in_file.fail())
	{
		std::cout << "Can not open " << av[1] << std::endl;
		return (1); 
	}

	result_file = av[1];
	result_file.append(".replace"); 

	std::ofstream out_file;
	out_file.open(result_file);

	if (out_file.fail())
	{
		std::cout << "Can not open " << av[1] << std::endl;
		in_file.close();
		return (1); 
	}

	std::string contents;

	while (true)
	{
		std::getline(in_file, contents);
		
		size_t position = 0;
		while (true)
		{
			position = contents.find(word1, position);
			if (position == std::string::npos)
				break ;
			contents.erase(position, word1_len);
			contents.insert(position, word2);
			position += word2_len;
		}
		out_file << contents;
		if (in_file.eof())
			break ;
		out_file << std::endl;	
	}
	in_file.close();
	out_file.close();
	return (0);
}