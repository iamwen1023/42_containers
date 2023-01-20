#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <cstddef>
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
                
            }


            private:
                T* m_data;
                //pointer to the memory location where the elements of the vector are stored.
                size_t m_size;
                // the number of elements currently stored in the vector.
                size_t m_capacity;
                //the amount of memory allocated for the vector.
                Alloc m_alloc;
                //an instance of an allocator class that is used to manage the memory of the vector


    };
}


#endif