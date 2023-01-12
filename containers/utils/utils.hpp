#ifndef UTILS_HPP
#define UTILS_HPP
namespace ft {
    
    //is_integral
    template <class T, T v> 
    struct integral_constant{
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T,v> type;
    };
    typedef integral_constant<bool, true>	true_type;
    typedef integral_constant<bool, false>	false_type;

    template < class T > struct is_integral : public false_type {};
	template <>			 struct is_integral<bool> : public true_type {};
	template <>			 struct is_integral<char> : public true_type {};
	template <>			 struct is_integral<char16_t> : public true_type {};
	template <>			 struct is_integral<char32_t> : public true_type {};
	template <>			 struct is_integral<wchar_t> : public true_type {};
	template <>			 struct is_integral<signed char> : public true_type {};
	template <>			 struct is_integral<short int> : public true_type {};
	template <>			 struct is_integral<int> : public true_type {};
	template <>			 struct is_integral<long int> : public true_type {};
	template <>			 struct is_integral<long long int> : public true_type {};
	template <>			 struct is_integral<unsigned char> : public true_type {};
	template <>			 struct is_integral<unsigned short int> : public true_type {};
	template <>			 struct is_integral<unsigned int> : public true_type {};
	template <>			 struct is_integral<unsigned long int> : public true_type {};
	template <>			 struct is_integral<unsigned long long int> : public true_type {};

    //enable_if
    template<bool Cond, class T = void> 
    struct enable_if {};
    template<class T> 
    struct enable_if<true, T> {
        typedef T type;};

    //equal
    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
        for (; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2)) {
                return false;
            }
        }
        return true;
    }
    template< class InputIt1, class InputIt2, class BinaryPredicate >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p ){
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

    //lexicographical_compare
    template< class InputIt1, class InputIt2 >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (*first1 < *first2) return true;
            if (*first2 < *first1) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp){
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (comp(*first1, *first2)) return true;
            if (comp(*first2, *first1)) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

}


#endif
