#ifndef COMPLEX_TYPES_HPP
# define COMPLEX_TYPES_HPP

# include <iostream>

template <typename T>
struct A {
		typedef	T		value_type;

		value_type		_value;

		A() {};
		A(value_type value) : _value(value) {};

		value_type	get_value() const {return _value; }
};

class B {
	private:
		std::string		_name;
		int				_age;
		std::string		_favourite_animal;
		
	public:
		B() : _name("Briouffy"), _age(0), _favourite_animal("Gekko") {};
		B(std::string name, int age, std::string animal) :
			_name(name), _age(age), _favourite_animal(animal) {}
		~B() {}
		
		std::string	m(void)	{return "non const called"; }
		std::string	m(void)	const {return "const called"; }
		void get_older(){
			_age++;
		}
};


#endif