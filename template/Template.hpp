#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP
# include <iostream>

class Template
{
	private :

	public :
		Template();
		~Template();
		Template(const Template&);
		
		Template &operator=(const Template &op);
};

#endif