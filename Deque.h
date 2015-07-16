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
        typedef typename allocator_type::template rebind<T*>::other allocator_pointer_type;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * @param takes in two const my_deque reference
         * @return true if they are equal
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}


        // ----------
        // operator <
        // ----------

        /**
         * @param two const my_deque reference
         * @return true if lhs is less than rhs
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

    private:
        // ----
        // data
        // ----

        allocator_type _a; 
        pointer* _outermost;  
        pointer _bd; //beginning of actual data
        pointer _ed; //end of actual data 
        pointer _lb;  
        pointer _le; //capacity
        allocator_pointer_type _aP;

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
                 * @param take in two const iterators
                 * @return true if they are equal
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    if(lhs._d == rhs._d && lhs._i == rhs._i){
                        return true;
                    }
                    return false;}

                /**
                 * @param take in two const iterators
                 * @return true if lhs and rhs are not equal to each other
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param take in an iterator and a difference_type
                 * @return the sum of a adding the difference type to iterator
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param take in an iterator and a difference type
                 * @return the difference between the iterator and the difference type (subtract)
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                size_type _i; //current position/size
                my_deque* _d;       //deque we are using

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                   if(_i >= 0){
                    return true;
                   } 
                   return false;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param take in a deque and a starting position
                 * starting position is index 0 by default
                 * set _d to equal given deck and _i to equal given index
                 */
                iterator (my_deque* d, size_type i = 0) {
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
                 * @return the value at the given index of the deque
                 */
                reference operator * () const {
                    return (*_d)[_i];}

                // -----------
                // operator ->
                // -----------

                /**
                 * @return pointer
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * move to the next index
                 * @return this
                 */
                iterator& operator ++ () {
                    ++_i;
                    assert(valid());
                    return *this;}

                /**
                 * post ++
                 * make copy of current iterator before incrementing
                 * increment current iterator
                 * @return copy
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
                 * move to previous index
                 * @return this
                 */
                iterator& operator -- () {
                    --_i;
                    assert(valid());
                    return *this;}

                /**
                 * post --
                 * make copy of current this before decrementing
                 * decrement this
                 * @return copy
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
                 * @param difference type which is how much we are incrementing by
                 * increment curernt index by d
                 * @return this
                 */
                iterator& operator += (difference_type d) {
                    _i += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param difference type which is how much we are decrementing by
                 * decrement current index by d
                 * @return this
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
                 * @param take in two const iterators
                 * @return true if they are equal deques and equal positions
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    if(lhs._constd == rhs._constd && lhs._i == rhs._i){
                        return true;
                    }
                    return false;}

                /**
                 * @param two const iterators
                 * @return true if they are nto equal deques or not equal positions
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * @param const iterator
                 * @param difference type
                 * @return iterator plus the difference type
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * @param iterator
                 * @param difference type
                 * @return the difference of iterator and difference type (subtract)
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                const my_deque* _constd; //deque we are using
                size_type _i; //current position

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    if(_i>=0){
                        return true;
                    }
                    return false;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param const deque
                 * @param difference type
                 * set iterator to given deque and position
                 */
                const_iterator (const my_deque* d, size_type i = 0) {
                    _constd = d;
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
                 * @return the value at the given index of the deque
                 */
                reference operator * () const {
                    return (*_constd)[_i];}

                // -----------
                // operator ->
                // -----------

                /**
                 * @return pointer
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * increment the current position by one
                 * @return this
                 */
                const_iterator& operator ++ () {
                    ++_i;
                    assert(valid());
                    return *this;}

                /**
                 * post ++
                 * make a copy of the current iterator
                 * increment the current iterator
                 * @return copy
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
                 * pre --
                 * decrement current position
                 * @return this
                 */
                const_iterator& operator -- () {
                    --_i;
                    assert(valid());
                    return *this;}

                /**
                 * post --
                 * make a copy of the current iterator
                 * decrement the current position
                 * @return copy
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
                 * @param number to increment by
                 * increment current position by number
                 * @return this
                 */
                const_iterator& operator += (difference_type d) {
                    _i += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param number to decrement by
                 * decrement current position by number
                 * @return this
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
         * @param allocator type, defaulted
         * default constructor
         */
        explicit my_deque (const allocator_type& a = allocator_type()) :
                _a (a), _aP(), _outermost(0) {
             _bd = _ed = _lb = _le = 0;
            assert(valid());}

        /**
         * @param size, value type defaulted, allocated type defaulted
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type())  : _a(a), _aP() {
            size_type numrows = s/50;       //divide the whole size by 100 and make that many rows in inner array
            if(s % 50 != 0){                //if there are leftovers, make an extra row
                ++numrows;
            }

            _outermost = _aP.allocate(numrows); //allocate space to have each row
            size_type outerindex = 0;
            while(outerindex != numrows){       //for each row allocate enough space for 100 elements
                _outermost[outerindex] = _a.allocate(50);
                ++outerindex;
            }
    
            outerindex = 0;
            while(outerindex != numrows){              
                _a.deallocate(_outermost[outerindex], 50);
                ++outerindex;
            }

            _aP.deallocate(_outermost, numrows);
            _lb = _bd = _a.allocate(s);
            _ed = _le = _bd + s;
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}
        /**
         * @param const deque
         * copy constructor
         */
        my_deque (const my_deque& that)
            : _a(that._a), _aP() { 
            _lb = _bd = _a.allocate(that.size());
            _ed = _lb = _bd + that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * deconstructor
         * clear and deallocate the capacity
         */
        ~my_deque () {
            if (!empty()) {
                clear();
                _a.deallocate(_lb, (_le-_lb));}
            assert(valid());}

        // ----------
        // operator =
        // ----------

        /**
         * <your documentation>
         */
        my_deque& operator = (const my_deque& rhs) {
            if (this == &rhs) 
                return *this;
            if (rhs.size() == size())
                std::copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());}
            else if (rhs.size() <= (_le-_bd)) {
                std::copy(rhs.begin(), rhs.begin() + size(), begin());
                _ed = uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end());}
            else { //if rhs is greater than the capacity of lhs we need to make a new deque and swap
                clear();
                my_deque temp(rhs);
                swap(temp);}
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * @param size_type index of element we want
         * @return reference of the element at the index within the data
         */
        reference operator [] (size_type index) {
            return *(_bd+index);}

        /**
         * @param size_type index of element we want
         * @return const reference of that element
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * @param size_type index
         * @return reference to element at that index
         * throw exception if index is out of range
         */
        reference at (size_type index) {
            if (index >= size())
                throw std::out_of_range("my_deque");
            return (*this)[index];}

        /**
         * @param size_type index
         * @return const reference to element at that index
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * @return reference to the last element in the deque
         */
        reference back () {
            assert(size()>0);
            return *(_ed - 1);}

        /**
         * @return const reference to last element in deque
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * @return iterator to this
         */
        iterator begin () {
            return iterator(this);}

        /**
         * @return iterator to this
         */
        const_iterator begin () const {
            return const_iterator(this);}

        // -----
        // clear
        // -----

        /**
         * resizes deque to 0 which clears all data
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * @return true is size is 0
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * @return iterator for this deque of this size
         */
        iterator end () {
            return iterator(this, size());}

        /**
         * @return iterator for this deque of this size
         */
        const_iterator end () const {
            return const_iterator(this, size());}

        // -----
        // erase
        // -----

        /**
         * @param takes in a position of an element iterator
         * erases the element at that position
         * if at the end, just pop that element
         * else
         * copies everything past the current position into the current position on
         * resizes to one less
         * returns an iterator at the same position with a new element now
         */
        iterator erase (iterator element) {
            if(element == end() -1){
                pop_back();
            }
            else{
                std::copy(element+1, end(), element);
                resize(--size());
            }
            assert(valid() );
            return iterator(this, 0);}


        // -----
        // front
        // -----

        /**
         * <your documentation>
         */
        reference front () {
            // <your code>
            // dummy is just to be able to compile the skeleton, remove it
            static value_type dummy;
            return dummy;}

        /**
         * <your documentation>
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * <your documentation>
         */
        iterator insert (iterator, const_reference) {
            // <your code>
            assert(valid());
            return iterator();}

        // ---
        // pop
        // ---

        /**
         * <your documentation>
         */
        void pop_back () {
            // <your code>
            assert(valid());}

        /**
         * <your documentation>
         */
        void pop_front () {
            // <your code>
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * <your documentation>
         */
        void push_back (const_reference) {
            // <your code>
            assert(valid());}

        /**
         * <your documentation>
         */
        void push_front (const_reference) {
            // <your code>
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * <your documentation>
         */
        void resize (size_type s, const_reference v = value_type()) {
            // <your code>
            assert(valid());}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            // <your code>
            return 0;}

        // ----
        // swap
        // ----

        /**
         * <your documentation>
         */
        void swap (my_deque&) {
            // <your code>
            assert(valid());}};

#endif // Deque_h