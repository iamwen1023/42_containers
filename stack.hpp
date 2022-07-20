#ifndef STACK_HPP
#define STACK_HPP

namespace ft {
    template<class T, class Container = std::deque<T>> 
    class stack{
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef container_type::reference reference;
            typedef container_type::const_reference const_reference;
            typedef size_t size_type;
        protected:
	        container_type 	_container;

            //memeber functions
            explicit stack( const Container& cont = Container() ): _container(cont);
            ~stack();
            stack& operator=( const stack& other ){this->Container = other.Container; return (*this);};
            bool empty() const { return (this->Container.empty());};
            size_type size() const{return (this->Container.size());};
            value_type& top() {return this->Container.back();};
            const value_type& top() const{return this->Container.back();};
            //所有container都有這些func?
            void push (const value_type& val);





    };

}




#endif