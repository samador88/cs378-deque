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

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::equal()
            return true;}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::lexicographical_compare()
            return true;}

    private:
        // ----
        // data
        // ----
        allocator_type _a;
        pointer _b;
        pointer _e; //capactity
        pointer _bm; //beginning of actual data
        pointer _em; //end of actual data, size
        pointer _mm; //middle of data
        unsigned int _size;

    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return true;}

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
                 * <your documentation>
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    // <your code>
                    return true;}

                /**
                 * <your documentation>
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                // <your data>

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return true;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                iterator (/* <your arguments> */) {
                    // <your code>
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    // dummy is just to be able to compile the skeleton, remove it
                    static value_type dummy;
                    return dummy;}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator ++ () {
                    // <your code>
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                iterator& operator -- () {
                    // <your code>
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                iterator& operator += (difference_type d) {
                    // <your code>
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -= (difference_type d) {
                    // <your code>
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
                 * <your documentation>
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    // <your code>
                    return true;}

                /**
                 * <your documentation>
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----


            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return true;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator (/* <your arguments> */) {
                    // <your code>
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    // dummy is just to be able to compile the skeleton, remove it
                    static value_type dummy;
                    return dummy;}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator ++ () {
                    // <your code>
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                const_iterator& operator -- () {
                    // <your code>
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                const_iterator& operator += (difference_type) {
                    // <your code>
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -= (difference_type) {
                    // <your code>
                    assert(valid());
                    return *this;}};

    public:
        // ------------
        // constructors
        // ------------

        /**
         * default constructor
         *allocator type is defaulted
         */
        explicit my_deque (const allocator_type& a = allocator_type()) : 
            _a (a){
            _b = _e = _em = _bm = _mm = 0;
            _size = 0; 
            
            assert(valid());}

        /**
         * @param size of deque, value type, allocator type
         * creates a deque of given size, type and allocator are defaulted
         * allocates the correct size and fills it with the correct type
         * moves pointers to appropriate places
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) :
            _a (a) {
            _b = _bm = _a.allocate(s);
            _size = s;
            _e = _b + _size;
            _mm = _em = _b + (_size/2);
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        /**
         * @param that
         * copy constructor
         * creates a deque of size of that
         * copies that into the new deque
         */
        my_deque (const my_deque& that) : 
            _a (that._a) {
            _b = _bm = _a.allocate(that.size());
            _e = _b + that.size();
            _mm = _em = _b + (that.size()/2);
            _size = that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * clear and deallocate memory
         */
        ~my_deque () {
            if (_bm) {
                clear();
                _a.deallocate(_bm, (_e - _b));}
            assert(valid());}

        // ----------
        // operator =
        // ----------

        /**
         * @param rhs
         * @return a deque
         */
        my_deque& operator = (const my_deque& rhs) {
            if (this == &rhs){
                return *this;
            }
            if(rhs.size() == size()){
                std::copy(rhs.begin(), rhs.end(), begin());
            }
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());
            }
            else if (rhs.size() <= (_e-_b)) {
                std::copy(rhs.begin(), rhs.begin()+size(),begin());
                _em = &(*uninitialized_copy(_a, rhs.begin(),rhs.end(),begin()));
            }
            else{
                clear();
                //reserve(rhs.size());  either create reserve function or create new deque of that size and swap
                _em = &(*uninitialized_copy(_a,rhs.begin(),rhs.end(),begin()));
            }
            assert(valid());
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * @param index
         * @return reference to element at that index
         */
        reference operator [] (size_type index) {
            return *(_bm+index);}

        /**
         * @param index
         * @return const reference to element at that index
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * @param index
         * @return reference to that element at index
         * throws out of range if index is out of range
         */
        reference at (size_type index) {
            if (index >= size()){
                throw std::out_of_range("my_deque");
            }
            return (*this)[index];}

        /**
         * <your documentation>
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * @return reference to the last element
         */
        reference back () {
            assert(!empty());
            return *(_em - 1);}

        /**
         * @return constant reference to last element
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * @return iterator to fitst element
         */
        iterator begin () {
            return iterator(this);}

        /**
         * @return const iterator to first element
         */
        const_iterator begin () const {
            return const_iterator(this);}

        // -----
        // clear
        // -----

        /**
         * clears the deque
         */
        void clear () {
            resize(0);
            assert(valid());}
        // -----
        // empty
        // -----

        /**
         * @return true if deque is empty, false if not
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * @return an iterator to the last element
         */
        iterator end () {
            return iterator(this + size());}

        /**
         * @return const iterator to last element
         */
        const_iterator end () const {
            return const_iterator(this + size());}

        // -----
        // erase
        // -----

        /**
         * erases the element at the given position
         * @param an iterator to an element
         * @return an iterator
         */
        iterator erase (iterator it) {
            if (it == end()-1){
                pop_back;
            }
            else{
                std::copy(it+1, end(), it);
                resize(size()-1);
            }
            assert(valid());
            return it;}

        // -----
        // front
        // -----

        /**
         * @return reference to the first element
         */
        reference front () {
            return *(_bm);}

        /**
         * @return const reference to the first element
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * @param the position to insert into
         * @param the value to insert
         * @return iterator to new element
         * insert the new value into the deque at the specified position
         */
        iterator insert (iterator it, const_reference value) {
            if(it == begin()){
                push_front(value);
            }
            else if (it == end()-1){
                push_back(value);
            }
            else{
                my_deque<value_type> temp;
                iterator b = begin();
                while(b != it){
                    temp.push_back(*b);
                    ++b;
                }
                temp.push_back(v);
                while(b != end()){
                    temp.push_back(*b);
                    ++b;
                }
                swap(temp);
            }
            assert(valid());
            return it;}

        // ---
        // pop
        // ---

        /**
         * erase the last element in the deque
         */
        void pop_back () {
            assert(!empty());
            _a.destroy(_em-1);
            --_em;
            resize(size()-1);
            assert(valid());}

        /**
         * erase the first element in the deque
         */
        void pop_front () {
            assert(!empty());
            _a.destroy(_bm);
            ++_bm;
            resize(size()-1);
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * @param value to be pushed in
         * push an element into the end of the deque
         */
        void push_back (const_reference value) {
            resize(size() + 1, value);
            assert(valid());}

        /**
         * @param value to be pushed in
         * push an element into the front of the deque
         */
        void push_front (const_reference value) {
            if (!empty()) {
                if ((_e - _b) >= _size + 1) {
                    if (_bm == _b){
                        _bm = _e;
                    }
                    *(--_bm) = value;
                    ++_size;
                }
                else {
                   //*************** reserve(std::max(2*_size, _size+1)); 
                    if (_bm == _b){
                        _bm = _e;
                    } 
                    *(--_bm) = value;
                    ++_size;
                }
            } 
            else {
                insert(_bm,value);       
            }
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
