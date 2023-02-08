#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "./reverse_iterator.hpp"
#include "./iterator_traits.hpp"
#include "./utils/utils.hpp"
#include <iterator>
#include <memory>
#include <cstddef>
#include <cassert> //assert
#include <stdexcept> //out of range
#include <algorithm> //swap
//check operator= /assign /push_back /
//insert (when the iterator passed as the first argument is not the end() iterator)
//resize (when the new size is greater than the current size)
//for trivially copy
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
            explicit vector(const allocator_type& alloc = allocator_type()):
                m_alloc(alloc), m_data(0), m_size(0), m_capacity(0){}
            explicit vector(size_type n, const value_type& val = value_type(), 
                    const allocator_type& alloc = allocator_type()): m_size(n), m_capacity(m_size), m_alloc(alloc){
                m_data = m_alloc.allocate(m_capacity);
                for(size_t i =0; i < m_size; ++i){
                        m_alloc.construct(m_data + i, val);
                }
            }	
            template <class InputIterator>
            vector(InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type()):m_size(std::distance(first, last)), m_capacity(m_size), m_alloc(alloc){
                m_data = m_alloc.allocate(m_capacity);
                for (InputIterator it = first; it != last; ++it, ++m_data){
                        m_alloc.construct(m_data, *it);
                }
            }
            //The newly-created %vector uses a copy of the allocation
            //object used by @a x.  All the elements of @a x are copied,
            //but any extra memory in
            //@a x (for fast expansion) will not be copied.
            vector(const vector& other){
                m_alloc = other.m_alloc;
                m_size = other.m_size;
                m_capacity = other.m_capacity;
                m_data = m_alloc.allocate(m_capacity);
                std::uninitialized_copy(other.m_data, other.m_data + m_size, m_data);
                //std::uninitialized_copy function, it copies the elements 
                //from the source memory location to the destination memory location 
                //without calling their copy constructors
            }
            ~vector(){
                clear();
            }
            vector& operator=(const vector& x){
                if (this != &x){
                    clear();
                    this(x);
                }
                return *this;
            }
            //Iterators:
            iterator begin(){return iterator(m_data);}
            const_iterator begin() const{ return const_iterator(m_data);}
            iterator end(){return iterator(m_data +  m_size);}
            const_iterator end() const{return const_iterator(m_data +  m_size);}
            reverse_iterator rbegin(){return reverse_iterator(end());}
            const_reverse_iterator rbegin() const{ return const_reverse_iterator(end());}
            reverse_iterator rend(){return reverse_iterator(begin());}
            const_reverse_iterator rend() const{return const_reverse_iterator(begin());}
            //Capacity:
            size_type size() const{return m_size;}
            size_type max_size() const{return m_alloc.max_size();}
            void resize (size_type n, value_type val = value_type()){
                if (n < m_size){
                    for (size_t i = n; i < m_size; i++)
                        m_alloc.destroy(m_data + i);
                    m_size = n;
                }else if (n > m_size){
                    if (n > m_capacity)
                        reserve(n);
                    for (size_t i = m_size; i < n ; ++i){
                        m_alloc.construct(m_data + i, val);
                    }
                    m_size = n;
                }
            }
            size_type capacity() const{ return m_capacity;}
            bool empty() const{ return (m_size == 0);}
            void reserve (size_type n){
                if (n > max_size())
                    throw std::out_of_range("vector::reserve");
                if (n <= m_capacity)
                    return ;
                T* new_data = m_alloc.allocate(n);
                for(size_t i = 0; i < m_size; ++i){
                    m_alloc.construct(new_data +i, m_data[i]);
                }
                clear();
                m_data = new_data;
                m_capacity = n;
            }
            void shrink_to_fit(){
                if (m_size < m_capacity){
                    T* new_data = m_alloc.allocate(m_size);
                    for(size_t i = 0; i < m_size; ++i){
                        m_alloc.construct(new_data +i, m_data[i]);
                    }
                    clear();
                    m_data = new_data;
                    m_capacity = m_size;
                }
            }
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
            reference front(){ return m_data[0];}
            const_reference front() const{return m_data[0];}
            reference back(){return m_data[m_size -1];}
            const_reference back() const{return m_data[m_size -1];}
            T* data(){ std::addressof(front());}
            const T* data() const{std::addressof(front());}

            //Modifiers:
            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last){
                size_type new_size = std::distance(first, last);
                if (new_size > m_capacity){
                    T* new_data = m_alloc.allocate(new_size);
                    clear();
                    m_data = new_data;
                    m_capacity = new_size;
                }
                m_size = new_size;
                std::uninitialized_copy(first, last, m_data);
            }
            void assign (size_type n, const value_type& val){
                if (n > m_capacity){
                    T* new_data = m_alloc.allocate(n);
                    clear();
                    m_data = new_data;
                    m_capacity = n;
                }
                m_size = n;
                std::uninitialized_copy(m_data, m_data + m_size, val);
            }
            void push_back (const value_type& val){
                // if (m_size == m_capacity){
                //     T* new_data = m_alloc.allocate(m_data + 1);
                //     for(size_t i = 0; i < m_size; ++i){
                //         m_alloc.construct(new_data +i, m_data[i]);
                //     }
                //     clear();
                //     m_data = new_data;
                //     m_capacity = new_size + 1;
                // }
                // m_alloc.construct(m_data + m_size, val);
                // m_size = new_size + 1;
                if (m_size == m_capacity) {
                    reserve(m_capacity == 0 ? 1 : 2 * m_capacity); //geometric growth
                }
                m_alloc.construct(m_data + m_size, val);
                ++m_size;
            }
            void pop_back(){
                if (m_size > 0){
                    m_alloc.destroy(m_data + m_size -1);
                    --m_size;
                }
            }
            iterator insert (iterator position, const value_type& val){
                if (m_size == m_capacity){
                    size_t new_cap = m_capacity == 0 ? 1: 2*m_capacity;
                    T* new_data = m_alloc.allocate(new_cap);
                    std::uninitialized_copy(m_data, m_data + m_size , new_data);
                    clear();
                    m_data = new_data;
                    m_capacity = new_cap;
                }
                for (iterator it= end() -1; it > position; --it){
                    *(it + 1) = *(it);
                }
                *position = val;
                m_size++;
                return position;
            }
            void insert (iterator position, size_type n, const value_type& val){
                if (n == 0)
                    return;
                size_t new_size = m_size + n;
                if (new_size > m_capacity){
                    size_t new_cap = m_capacity;
                    while(new_cap < new_size)
                        new_cap *= 2;
                    reserve(new_cap);
                }
                for (iterator it= end() -1; it >= position; --it){
                    *(it + 1) = *(it);
                }
                for (iterator it= position; it< position +n; ++it){
                    *it = val;
                }
                m_size = new_size;
            }
            template <class InputIterator>    
            void insert (iterator position, InputIterator first, InputIterator last){

            }
            iterator erase (iterator position){
                if(position >= m_data + m_size)
                    throw std::out_of_range("vector::erase");
                for(iterator it = position; it != m_data + m_size -1; ++it){
                    *(it) = *(it + 1);
                }
                m_alloc.destroy(m_data + m_size -1);
                --m_size;
                return position;
            }
            iterator erase (iterator first, iterator last){
                if(first >= m_data + m_size || last > m_data + m_size)
                    throw std::out_of_range("vector::erase");
                size_t diff = last - first;
                iterator it = first;
                for(; it != m_data + m_size - diff; ++it){
                    *(it) = *(it + diff);
                }
                for(size_t i = 0; i < diff; ++i){
                    m_alloc.destroy(it);
                    ++it;
                }
                m_size -= diff;
                return first;
            }
            void swap (vector& x){
                std::swap(m_data, x.m_data);
                std::swap(m_size, x.m_size);
                std::swap(m_capacity, x.m_capacity);
                std::swap(m_alloc, x.m_alloc);
            }
            void clear(){
                for (size_t i = 0; i < m_size; i++) {
                    m_alloc.destroy(m_data + i);
                }
                m_alloc.deallocate(m_data, m_capacity);
            }
            allocator_type get_allocator() const{}

            private:
                value_type* m_data;
                //pointer to the memory location where the elements of the vector are stored.
                size_t m_size;
                // the number of elements currently stored in the vector.
                size_t m_capacity;
                //the amount of memory allocated for the vector.
                allocator_type m_alloc;
                //an instance of an allocator class that is used to manage the memory of the vector
                template <class InputIterator>  
                void M_range_insert(iterator pos, InputIterator first, InputIterator last, std::input_iterator_tag){
                    for (; first != last; ++first){
                        pos = insert(pos, *first);
                        ++pos;
                    }
                }
                template<typename ForwardIterator>
                void M_range_insert(iterator position, ForwardIterator first, ForwardIterator last, std::forward_iterator_tag){
                    if (first != last){
                        const size_type n = std::distance(first, last);
      

            friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
            }
            friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (!(lhs == rhs));
            }
            friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
            }
            friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (rhs < lhs);
            }
            friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (!(lhs > rhs));
            }
            friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (!(rhs > lhs));
            }
    };
}


#endif