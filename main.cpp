#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int print_error(int n)
{
	if (n == 0)
		std::cout << "Please enter info : NAME (Name of the class you want to create), NAME , ect..." << std::endl;
	else if (n == 1)
		std::cerr << "Error : input file" << std::endl;
	else if (n == 2)
		std::cerr << "Error : output file" << std::endl;
	return (1);
}

void	replace_strings(std::ofstream &fileOut, std::string s1, std::string s2, std::string input)
{
	size_t pos;
	size_t to_skip;

	pos = input.find(s1);
	if (pos == std::string::npos)
	{
		fileOut << input;
		return ;
	}
	else
	{
		fileOut << input.substr(0, pos);
		fileOut << s2;
		to_skip = pos + s1.length();
		replace_strings(fileOut, s1, s2, input.substr(to_skip));
	}
}

int	replace(std::string className, std::string format, std::string s1, std::string origin)
{
	std::ifstream	fileIn;
	std::ofstream	fileOut;
	std::string		s2 = className;
	std::string		buffer;
	std::string		file = origin + format;
	std::string		new_file = "result/" + className + format;

	fileIn.open(file.c_str());
	if (fileIn.good() == false)
		return (print_error(1));
	fileOut.open(new_file.c_str());
	if (fileOut.good() == false)
	{
		fileIn.close();
		return (print_error(2));
	}
	while (getline(fileIn, buffer))
		replace_strings(fileOut, s1, s2, buffer + '\n');
	fileIn.close();
	fileOut.close();
	return (0);
}

void	replace_template(char *className)
{
	replace((std::string)className, (std::string)".cpp", (std::string)"Template", (std::string)"template/Template");
	replace((std::string)className, (std::string)".hpp", (std::string)"Template", (std::string)"template/Template");
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (print_error(0));
	for (int i = 1; i < ac; i++)
	{
		replace_template(av[i]);
	}
	std::cout << "The job is done." << std::endl;
	return (0);
}