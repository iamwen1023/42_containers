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
namespace ft {
    template <class T, class Allocator = allocator<T> >
    class vector {
        public:
        // types:
            typedef typename Allocator::reference reference;
            typedef typename Allocator::const_reference const_reference;
            typedef pointer iterator;
            typedef const_pointer const_iterator;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer const_pointer
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

            explicit vector(const allocator_type& alloc = Allocator()): m_size(0), m_capacity(0), m_data(0), m_alloc(alloc){}
            explicit vector(size_type n, const T& value = T(), const Allocator& alloc= Allocator()):m_size(n),m_capacity(n) m_alloc(alloc){
                m_data = m_alloc.allocate(m_capacity);
                for(size_t i =0; i < m_size; ++i){
                        m_alloc.construct(m_data + i, val);
                }
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type()):m_size(std::distance(first, last)), m_capacity(m_size), m_alloc(alloc){
                m_data = m_alloc.allocate(m_capacity);
                for (InputIterator it = first; it != last; ++it, ++m_data) {
                        m_alloc.construct(m_data, *it);
                }
            }
            vector(const vector<T,Allocator>& other){
                m_alloc = other.m_alloc;
                m_size = other.m_size;
                m_capacity = other.m_capacity;
                m_data = m_alloc.allocate(m_capacity);
                std::uninitialized_copy(other.m_data, other.m_data + m_size, m_data);
            }
            ~vector(){
                clear();
            }
            vector<T,Allocator>& operator=(const vector<T,Allocator>& x){
                if(&x == this)
                    return;
                if (x.size() > m_capacity){
                    clear();
                    //m_alloc = x.get_allocator();
                    m_size = x.size();
                    m_capacity = m_size;
                    m_data = m_alloc.allocate(m_size);
                    std::uninitialized_copy(x.begin(), x.end(), m_data);
                }else if (x.size()) <= m_size{
                    vector<T>::iterator i=std::copy(x.begin(), x.end(), m_data);
                    for(; i != end(), ++i)
                        m_alloc.destroy(i);
                        m_size = x.size();
                }else{
                    std::copy(x.begin(), x.begin() + m_size, m_data);
                    std::uninitialized_copy(x.begin() + m_size, x.end(), m_data + m_size);
                    m_size = x.size();
                }
                return *this;
            }
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last){
                erase(begin(), end());
                insert(begin(), first, last);
            }
            void assign(size_type n, const T& u){
                erase(begin(), end());
                insert(begin(), n, t);
            }
            allocator_type get_allocator() const{ return m_alloc;}
            // iterators:
            iterator begin(){return iterator(m_data);}
            const_iterator begin() const{ return const_iterator(m_data);}
            iterator end(){return iterator(m_data + m_size);}
            const_iterator end() const{return const_iterator(m_data +  m_size);}
            reverse_iterator rbegin(){return reverse_iterator(end());}
            const_reverse_iterator rbegin() const{ return const_reverse_iterator(end());}
            reverse_iterator rend(){return reverse_iterator(begin());}
            const_reverse_iterator rend() const{return const_reverse_iterator(begin());}
            // 23.2.4.2 capacity:
            size_type size() const{ return m_size;}
            size_type max_size() const{return m_alloc.max_size();}
            void resize (size_type n, value_type val = value_type()){
                if (n < m_size){
                    for (size_t i = n; i < m_size; i++)
                        m_alloc.destroy(m_data + i);
                    m_size = n;
                }else if (n > m_size){
                    if (n > max_size())
                        throw std::length_error("vector::resize");
                    insert(end(), n - m_size, val);
                    //m_size = n;
                }
            }
            size_type capacity() const{return m_capacity;}
            bool empty() const{ return (m_size == 0);}
            void reserve(size_type n){
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
            // element access:
            reference operator[](size_type n){ return m_data[n];}
            const_reference operator[](size_type n) const{ return m_data[n];}
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
            // 23.2.4.3 modifiers:
            void push_back(const T& x){
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
            iterator insert(iterator position, const T& x){
                size_type i = position - begin();
                if (m_size < m_capacity && position == end()){
                    std::construct(end(), x);
                    ++m_size;
                } else {
                    insert_middle(position,x);
                }
                return begin() + i;
            }
            void insert(iterator position, size_type n, const T& x){
                if(n == 0)
                    return;
                if(m_size + n < m_capacity){
                    size_t new_cap = m_capacity;
                    while(new_cap < new_size)
                        new_cap *= 2;
                    T* new_data = alloc.allocate(new_cap);
                    std::uninitialized_copy(begin(), position, new_data);
                    std::uninitialized_fill_n(new_data + (position - begin()), n ,x);
                    std::uninitialized_copy(position, end(), position - begin() + n);
                    clear();
                    m_capacity = new_cap;
                    m_size = m_size + n;
                    m_size = new_data;
                } else {
                    if(position != end()){

                    }else{
                        
                    }
                }
                
            }
            template <class InputIterator>
            void insert(iterator position,
            InputIterator first, InputIterator last);
            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);
            void swap(vector<T,Allocator>&);
            void clear(){
                for (size_t i = 0; i < m_size; i++) {
                    m_alloc.destroy(m_data + i);
                }
                m_alloc.deallocate(m_data, m_capacity);
            }
        private:
            value_type *m_data;
            size_type m_size;
            size_type m_capacity;
            allocator_type m_alloc;
            template <class T>
            void vector<T>::insert_middle(iterator position, const T& x){
                if (m_size < m_capacity){
                    alloc.construct(end(), *(end() - 1));
                    std::copy_backward(position , end() -1, end());
                    *position = x;
                    ++m_size;
                } else{
                    m_capacity =  m_size *2 ;
                    T* new_data = m_alloc.allocate(m_capacity);
                    std::uninitialized_copy(begin(), position, new_data);
                    m_alloc.construct(new_data + (position - begin()), x);
                    std::uninitialized_copy(position, end(), new_data + (position - begin()));
                    clear();
                    m_data = new_data;
                    ++m_size;
                }
            } 

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
            // specialized algorithms:
            template <class T, class Allocator>
            void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
            }
#endif