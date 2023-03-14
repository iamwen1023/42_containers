#ifndef STACK_HPP
#define STACK_HPP
#include <vector>

namespace ft {
    template<class T, class Container = std::vector<T> > 
    class stack{
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef std::size_t size_type;

            //memeber functions
            explicit stack( const Container& cont = Container() ): _container(cont){};
            stack& operator=( const stack& other ){this->_container = other._container; return (*this);};
            bool empty() const { return (this->_container.empty());};
            size_type size() const{return (this->_container.size());};
            value_type& top() {return this->_container.back();};
            const value_type& top() const{return this->_container.back();};
            //所有container都有這些func?
            void push (const value_type& value){ this->_container.push_back(value);};
            void pop(){ this->_container.pop_back();};
            //Note: We can declare friend class or function anywhere 
            //in the base class body whether its private,
            // protected or public block. It works all the same.
            friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  == rhs._container);
            };
            friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  != rhs._container);
            };
            friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  < rhs._container);
            };
            friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  <= rhs._container);
            };
            friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  > rhs._container);
            };
            friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
                return (lhs._container  >= rhs._container);
            };

        protected:
	        container_type 	_container;

    };
}

#endif