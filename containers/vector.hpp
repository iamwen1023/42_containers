#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <cstddef>
#include <cassert> //assert
#include <stdexcept> //out of range
namespace ft {
    template < class T, class Alloc = std::allocator<T>> 
    class vector{
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef pointer iterator;
            typedef const_pointer const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;

            //	Construct , deConstruct , operator=
            explicit vector (const allocator_type& alloc = allocator_type()):
                m_data(m_alloc.allocate(0)), m_size(0), m_capacity(0){
            }
            explicit vector (size_type n, const value_type& val = value_type(), 
                    const allocator_type& alloc = allocator_type()): m_size(n){
                m_capacity = m_size;
                m_data = m_alloc.allocate(m_capacity);
                for(size_t i =0; i < m_size; ++i){
                        m_alloc.construct(m_data + i, value);
                }
            }	
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type()){
                m_size = std::distance(first, last);
                m_capacity = m_size;
                m_data = m_alloc.allocate(m_capacity);
                for (auto it = first; it != last; ++it, ++m_data) {
                        m_alloc.construct(m_data, *it);
                }
            }
            vector (const vector& other){
                m_size = other.m_size;
                m_capacity = other.m_capacity;
                m_data = m_alloc.allocate(m_capacity);
                std::uninitialized_copy(other.m_data, other.m_data + m_size, m_data);
                //std::uninitialized_copy function, it copies the elements 
                //from the source memory location to the destination memory location 
                //without calling their copy constructors
            }
            ~vector(){
                for (size_t i = 0; i < m_size; i++) {
                        m_alloc.destroy(m_data + i);
                }
                m_alloc.deallocate(m_data, m_capacity);
            }
            vector& operator= (const vector& x){
                if (this != &x){
                    if(x.m_size > m_capacity){
                        T *new_data = m_alloc.allocate(x.m_size);
                        for(size_t i = 0; i < m_size; i++){
                            m_alloc.destroy(m_data + 1);
                        }
                        m_alloc.deallocate(m_data, m_capacity);
                        m_data = new_data;
                        m_capacity = x.m_size;
                    }
                    m_size = x.m_size;
                    std::uninitialized_copy(x.m_data, x.m_data + x.m_size, m_data);)
                }
                return *this;
            }
            //Iterators:
            iterator begin(){return iterator(m_data);}
            const_iterator begin() const{ return const_iterator(m_data);}
            iterator end(){return iterator(m_data +  m_size);}
            const_iterator end() const{return const_iterator(m_data +  m_size);}
            reverse_iterator rbegin(){return reverse_iterator(this.end());}
            const_reverse_iterator rbegin() const{ return const_reverse_iterator(this.end());}
            reverse_iterator rend(){return reverse_iterator(this.begin());}
            const_reverse_iterator rend() const{return const_reverse_iterator(this.begin());}
            //Capacity:
            size_type size() const{return m_size;}
            size_type max_size() const{return m_alloc.max_size();}

            void resize (size_type n, value_type val = value_type()){
                if (n < m)
            }
            size_type capacity() const{ return m_capacity;}
            bool empty() const{ return (m_size == 0);}

            void reserve (size_type n){
                if (n <= m_capacity)
                    return ;
                
            }
            void shrink_to_fit(){}

            //Element access:
            reference operator[] (size_type n){return m_data[n];}
            const_reference operator[] (size_type n) const{return m_data[n];}
            reference at (size_type n){
                if (n >= m_size)
                    throw std::out_of_range("vector::at");
                return m_data[n];
            }
            const_reference at (size_type n) const{
                if (n >= m_size)
                    throw std::out_of_range("vector::at");
                return m_data[n];
            }
            eference front();
            const_reference front() const;


            private:
                value_type* m_data;
                //pointer to the memory location where the elements of the vector are stored.
                size_t m_size;
                // the number of elements currently stored in the vector.
                size_t m_capacity;
                //the amount of memory allocated for the vector.
                allocator_type m_alloc;
                //an instance of an allocator class that is used to manage the memory of the vector


    };
}


#endif