#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP
# include <iostream>

class Template
{
	private :

	public :
		Template();
		~Template();
		Template(const Template& copy);
		
		Template &operator=(const Template &op);
};

#endif