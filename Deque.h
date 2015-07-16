// --------------------------
// projects/c++/deque/Deque.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Deque_h
#define Deque_h

// --------
// includes
// --------

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

// -----
// using
// -----

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;

// -------
// destroy
// -------

template <typename A, typename BI>
BI destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

// ------------------
// uninitialized_copy
// ------------------

template <typename A, typename II, typename BI>
BI uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        destroy(a, p, x);
        throw;}
    return x;}

// ------------------
// uninitialized_fill
// ------------------

template <typename A, typename BI, typename U>
BI uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        destroy(a, p, b);
        throw;}
    return e;}

// -------
// my_deque
// -------

template < typename T, typename A = std::allocator<T> >
class my_deque {
    public:
        // --------
        // typedefs
        // --------

        typedef A                                           allocator_type;
        typedef typename allocator_type::value_type         value_type;

        typedef typename allocator_type::size_type          size_type;
        typedef typename allocator_type::difference_type    difference_type;

        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;

        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;

        typedef typename A::template rebind<pointer>::other B;
        typedef typename allocator_type::template rebind<T*>::other all_pointer;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * @param two my_deques
         * @return true if they are equal to one another
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}


        // ----------
        // operator <
        // ----------

        /**
         * @param take in two mydeques
         * @return true if the left is less than right
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

    private:
        // ----
        // data
        // ----

        allocator_type _a;
        pointer _lb;  
        pointer _le; 
        pointer _bd; 
        pointer _ed; 
        pointer* _outermost; 
        all_pointer _aP; 
    private:
        // -----
        // valid
        // -----

        bool valid () const {
            return (!_bd && !_ed && !_lb && !_le) || ((_bd <= _ed) && (_ed <= _le) && (_lb <= _bd));}

public:
        // --------
        // iterator
        // --------

        class iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::pointer               pointer;
                typedef typename my_deque::reference             reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param take in two iterators
                 * @return true if they are equal
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    return lhs._d == rhs._d && lhs._i == rhs._i;}

                /**
                 * @param take in two iterators
                 * @return true if they are not equal
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param iterator
                 * @param difference type
                 * @return the iterator advanced difference_type number of places (sum)
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param iterator
                 * @param difference type
                 * @return decremented iterator by number of difference type
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                my_deque* _d;
                size_type _i;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return (_i >= 0);}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param a my deque
                 * @param a size type
                 * set iterator on deque at position given
                 */
                iterator (my_deque* d, size_type i = 0){
                    _d = d;
                    _i = i;
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @return a reference to element at that position
                 */
                reference operator * () const {
                    return (*_d)[_i];}

                 // -----------
                // operator ->
                // -----------

                /**
                 * @param return pointer to this
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * pre-increment iterator by one to next position
                 */
                iterator& operator ++ () {
                    ++_i;
                    assert(valid());
                    return *this;}

                /**
                 * post-increment iterator by one to next position
                 */
                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * pre-decrement iterator to previous position
                 */
                iterator& operator -- () {
                    --_i;
                    assert(valid());
                    return *this;}

                /**
                 * post-decrement iterator to previous position
                 */
                iterator operator -- (int) {
                    iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * increment iterator by value given
                 */
                iterator& operator += (difference_type d) {
                    _i += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * decrement iterator by value given
                 */
                iterator& operator -= (difference_type d) {
                    _i -= d;
                    assert(valid());
                    return *this;}};

    public:
        // --------------
        // const_iterator
        // --------------

        class const_iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::const_pointer         pointer;
                typedef typename my_deque::const_reference       reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param two const iterators
                 * @return true if the iterators are equal
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    return (lhs._d == rhs._d) && (lhs._i == rhs._i);}

                /**
                 * @param two iterators
                 * @return true if the iterators are not equal
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param a const iterator
                 * @param a difference type
                 * @return the iterator position advanced
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param a const iterator
                 * @param difference type
                 * @return iterator decremented by difference type
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}


            private:
                // ----
                // data
                // ----

                const my_deque* _d;

                size_type _i;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return _i >= 0;}

          public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param a const my_deque
                 * @param size_type
                 * @return a const iterator starting at position given for given deque
                 */
            const_iterator (const my_deque* d, size_type i=0) {
                _d = d;
                _i = i;
                assert(valid());}

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @return reference to element at current index
                 */
                reference operator * () const {
                return (*_d)[_i];}

                // -----------
                // operator ->
                // -----------

                /**
                 * @ return pointer to this
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * pre-increment
                 * @return const iterator incremented once
                 */
                const_iterator& operator ++ () {
                ++_i;
                assert(valid());
                return *this;}


                /**
                 * post-increment
                 * @return const iterator incremented once
                 */
                const_iterator operator ++ (int) {
                    const_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * pre-decrement
                 * @return const iterator decremented once
                 */
                const_iterator& operator -- () {
                --_i;
                assert(valid());
                return *this;}

                /**
                 * post-decrement
                 * @return const iterator decremented once
                 */
                const_iterator operator -- (int) {
                    const_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * @param difference type
                 * @return const iterator incremented by that many
                 */
                const_iterator& operator += (difference_type d) {
                _i += d;
                assert(valid());
                return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param difference type
                 * @return const iterator decremented by that many
                 */
                const_iterator& operator -= (difference_type d) {
                _i -= d;
                assert(valid());
                return *this;}};

    public:
        // ------------
        // constructors
        // ------------

        /**
         * defaul constructor
         * @param allocator type defaulted
         * set everything to 0
         */
        explicit my_deque (const allocator_type& a = allocator_type()) 
            : _a(a), _aP() {
             _lb = _le = _bd = _ed = 0;
            _outermost = 0;
            assert(valid() );}

        /**
         * constructor with given size
         * split size up into rows and columns
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) 
            : _a(a), _aP() {

            size_type numrows = s / 10;         //divide the size into different rows
            
            if (s % 10 > 0){                   //make sure there is no extra space, add an extra row if remainder
                ++numrows;

                _outermost = _aP.allocate(numrows);
            
                size_type x = 0;
                while (x != numrows){
                    _outermost[x] = _a.allocate(10);
                    ++x;
                }

                x = 0;
                while(x != numrows){
                    _a.deallocate(_outermost[x], 10);
                    ++x;
                }
            
                _aP.deallocate(_outermost, numrows);
                _bd = _lb = _a.allocate(s);

                _ed = _le = _bd + s;

                uninitialized_fill(_a, begin(), end(), v);
                assert(valid());
                }

            else{
                _outermost = _aP.allocate(numrows);
            
                size_type x = 0;
                while (x != numrows){
                    _outermost[x] = _a.allocate(10);
                    ++x;
                }

                x = 0;
                while(x != numrows){
                    _a.deallocate(_outermost[x], 10);
                    ++x;
                }
            
                _aP.deallocate(_outermost, numrows);
                _bd = _lb = _a.allocate(s);

                _ed = _le = _bd + s;

                uninitialized_fill(_a, begin(), end(), v);
                assert(valid());}}
        /**
         * copy constructor
         * @param my_deque to be copied
         */
        my_deque (const my_deque& that) 
            : _a(that._a), _aP() {
            _outermost = 0; 
            _lb = _bd = _a.allocate(that.size());
            _ed = _le = _lb + that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * destructor
         * if not empty, clear and deallocate space
         */
        ~my_deque () {
            if (_lb) {  //check if it's empty.  if not, deallocate entire capacity
                clear();
                _a.deallocate(_lb, (_le - _lb));}

            assert(valid() );}

        // ----------
        // operator =
        // ----------

        /**
         * @param my_deque
         */
        my_deque& operator = (const my_deque& rhs) {
            if (this == &rhs)
                return *this;
            if (rhs.size() == size())
                std::copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());
            }    
            else if (rhs.size() <= (_le - _bd)) {
                std::copy(rhs.begin(), rhs.begin() + size(), begin());
                _ed = &(*uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end())); //had to do * & because compiler said canot convert types
            }
            else {
                clear();
                my_deque x(rhs);
                swap(x);
            }    
            assert(valid());
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * @return reference to value at index from beginning of data
         */
        reference operator [] (size_type index) {
            return *(_bd + index);}

        /**
         * @return const reference to value at index from beginning of data
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * @return reference to value at index
         */
        reference at (size_type index) {
            if (index >= size())
                throw std::out_of_range("my_deque");
            return (*this)[index];}

        /**
         * @return const reference to value at index
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * @return the reference to last element
         * has to be end of data, not end of capacity
         */
        reference back () {
            assert(size() > 0);
            return *(_ed - 1);}

        /**
         * @return const reference to last element
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * @return iterator to beginning position (default)
         */
        iterator begin () {
            return iterator(this);}

        /**
         * @return constant iterator to beginning position (default)
         */
        const_iterator begin () const {
            return const_iterator(this);}

        // -----
        // clear
        // -----

        /**
         * resize to 0 to clear all data
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * @return true if my_deque is empty
         */
        bool empty () const {
            return size()==0;}

        // ---
        // end
        // ---

        /**
         * @return iterator to the end
         */
        iterator end () {
            return iterator(this, size());}

        /**
         * @return const iterator to the end
         */
        const_iterator end () const {
            return const_iterator(this, size());}

        // -----
        // erase
        // -----

        /**
         * <your documentation>
         */
        iterator erase (iterator i) {
            if(i == end()-1){       //if at the last element, just pop it off
                pop_back();
            }

            else{                    //else copy elements after over curent element, resize
                std::copy(i+1, end(), i);
                resize(size()-1);
            }
            assert(valid() );
            return iterator(this);}

        // -----
        // front
        // -----

        /**
         * @return reference to the first element
         */
        reference front () {
            assert(!empty());
            return *(_bd);}

        /**
         * @return const reference to first element
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * @return iterator to given position, but with new value
         */
        iterator insert (iterator it, const_reference r) {
            if(it == end()){ //if at the end already, just need to push it to the back
                push_back(r);
            }
            else{           //have to grow the deque and copy everything, moving it one position down.  insert the value into current position
                resize(size()+1);
                std::copy(it, end(), it+1);
            }
            assert(valid());
            return iterator(this);}

        // ---
        // pop
        // ---

        /**
         * shrink deque to cut off last element
         */
        void pop_back () {
            assert(size() != 0);
            resize(size() - 1);
            assert(valid());}

        /**
         * destroy the first element
         * move pointer of beginning data to next element
         */
        void pop_front () {
            assert(size() != 0);
            destroy(_a, begin(), begin() + 1);
            ++_bd;
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * make size bigger by one and input new value with resize
         */
        void push_back (const_reference v) {
            resize(size() + 1, v);
            assert(valid());}

        /**
         * make sure there is space for element
         * once there is, construct a new space and insert element
         */
        void push_front (const_reference v) {
            if (_bd == _lb) {
                resize(size() + 1);
                pop_back();
            }    
            --_bd;
            _a.construct(&*begin(), v); 
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * @param size type
         * check to see if possible to fill current deque, or resize
         * if not, make a new deque of the right size and copy elements over, swap
         */
        void resize (size_type s, const_reference v = value_type()) {
            if (s == size())
                return;
            if (s < size())
                _ed = &(*destroy(_a, begin() + s, end() )); //had to put &* to compile
            else if (s <= (_ed -_lb))
                _ed = &*uninitialized_fill(_a, end(), begin() + s, v);
         
            else {              //need to make new, bigger deque but keep all pointers the same
                size_type newsize = size() * 2;
                if (s > newsize){
                    newsize = s;
                }

                if (newsize == s){
                    newsize = newsize + 10;
                }

                size_type middled = (newsize - s) / 2;
                size_type enddata = middled;

                if ((newsize - s) % 2){
                    ++enddata;
                }
                
                my_deque x(newsize, v);

                std::copy(begin(), end(), x.begin() + middled);

                destroy(x._a, x.begin(), x.begin() + middled);
                destroy(x._a, x.end() - enddata, x.end());
                x._bd = x._bd + middled;
                x._ed = x._ed - enddata;

                swap(x);}
            assert(valid());}

        // ----
        // size
        // ----

        /**
         * @return the distance from beginning of data to end of data
         */
        size_type size () const {
            return (_ed - _bd);}

        // ----
        // swap
        // ----

        /**
         * replace this with that
         * swap all pointers
         */
        void swap (my_deque& that) {
            if(_a == that._a) {
                std::swap(_bd, that._bd);
                std::swap(_lb, that._lb);
                std::swap(_ed, that._ed);
                std::swap(_le, that._le);
            }
            else{
                my_deque x(*this);
                *this = that;
                that = x;
            }
            assert(valid() );}};

#endif // Deque_h