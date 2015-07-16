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
using namespace std;
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
         * <your documentation>
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}


        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

    private:
        // ----
        // data
        // ----
ddddddddd
        allocator_type _a;
        all_pointer _aPointer; 
        pointer* _outermost;    
        pointer _front;  
        pointer _back; 
        pointer _b; 
        pointer _e; 

    private:
        // -----
        // valid
        // -----

        bool valid () const {
            return (!_front && !_back && !_b && !_e) || ((_front <= _b) && (_b <= _e) && (_e <= _back));}

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
                    return lhs._deque == rhs._deque && lhs._idx == rhs._idx;}

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

                my_deque* _deque;

                size_type _idx;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return (_idx >= 0);}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                iterator (my_deque* d, size_type i = 0)
                    : _deque(d), _idx(i) {
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
                    return (*_deque)[_idx];}

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
                    ++_idx;
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
                    --_idx;
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
                    _idx += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -= (difference_type d) {
                    _idx -= d;
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
                    return (lhs._cDeque == rhs._cDeque) && (lhs._idx == rhs._idx);}

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

                const my_deque* _cDeque;

                size_type _idx;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return _idx >= 0;}

          public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
            const_iterator (const my_deque* d, size_type i)
                : _cDeque(d), _idx(i) {
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
                return (*_cDeque)[_idx];}

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
                ++_idx;
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
                --_idx;
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
                const_iterator& operator += (difference_type rhs) {
                _idx += rhs;
                assert(valid());
                return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -= (difference_type rhs) {
                _idx -= rhs;
                assert(valid());
                return *this;}};

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        explicit my_deque (const allocator_type& a = allocator_type()) 
            : _a(a), _aPointer(), _outermost(0), _front(0), _back(0), _b(0), _e(0) {
            assert(valid() );}

        /**
         * <your documentation>
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) 
            : _a(a), _aPointer() {
            size_type rows = s / 50;
            if (s % 50 != 0)
                ++rows;
            _outermost = _aPointer.allocate(rows);
            
            for (size_type i = 0; i < rows; ++i) 
                _outermost[i] = _a.allocate(50);
            
            for (size_type i = 0; i < rows; ++i) 
                _a.deallocate(_outermost[i], 50);
            
            _aPointer.deallocate(_outermost, rows);
            _front = _b = _a.allocate(s);
            _e = _back = _b + s;
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        /**
         * <your documentation>
         */
        my_deque (const my_deque& that) 
            : _a(that._a), _aPointer() {
            _outermost = 0; 
            _front = _b = _a.allocate(that.size());
            _e = _back = _front + that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * <your documentation>
         */
        ~my_deque () {
            if (_front) {
                clear();
                _a.deallocate(_front, (_back - _front));}
            assert(valid() );}

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
                copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());
            }    
            else if (rhs.size() <= (unsigned)(_back - _b)) {
                copy(rhs.begin(), rhs.begin() + size(), begin());
                _e = &(*uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end()));
            }
            else {
                clear();
                my_deque d(rhs);
                swap(d);
            }
            assert(valid());
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * <your documentation>
         */
        reference operator [] (size_type index) {
            return *(_b + index);}

        /**
         * <your documentation>
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * <your documentation>
         */
        reference at (size_type index) {
            if (index >= size())
                throw std::out_of_range("Out of bounds.");
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
         * <your documentation>
         */
        reference back () {
            assert(size() != 0);
            return *(_e - 1);}

        /**
         * <your documentation>
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * <your documentation>
         */
        iterator begin () {
            return iterator(this, 0);}

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            return const_iterator(this, 0);}

        // -----
        // clear
        // -----

        /**
         * <your documentation>
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * <your documentation>
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            return iterator(this, size());}

        /**
         * <your documentation>
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
            if(i != end() - 1) {
                copy(i + 1, end(), i);
                resize(size() - 1);
            }
            else
                pop_back();
            assert(valid() );
            return iterator(this, 0);}

        // -----
        // front
        // -----

        /**
         * <your documentation>
         */
        reference front () {
            return *(_b);}

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
        iterator insert (iterator i, const_reference v) {
            if(i != end()) {
                resize(size() + 1);
                copy(i, end(), i + 1);
                *i = v;
            }
            else
                push_back(v);
            assert(valid());
            return iterator(this);}

        // ---
        // pop
        // ---

        /**
         * <your documentation>
         */
        void pop_back () {
            assert(size() != 0);
            resize(size() - 1);
            assert(valid());}

        /**
         * <your documentation>
         */
        void pop_front () {
            assert(size() != 0);
            destroy(_a, begin(), begin() + 1);
            ++_b;
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * <your documentation>
         */
        void push_back (const_reference v) {
            resize(size() + 1, v);
            assert(valid());}

        /**
         * <your documentation>
         */
        void push_front (const_reference v) {
            if (_front == _b) {
                resize(size() + 1);
                pop_back();
            }    
            --_b;
            _a.construct(&*begin(), v); 
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * <your documentation>
         */
        void resize (size_type s, const_reference v = value_type()) {
            if (s == size())
                return;
            if (s < size())
                _e = &*destroy(_a, begin() + s, end() );
            else if ((s <= (unsigned)(_e -_front)) && (s <= (unsigned)(_back - _b)))
                _e = &*uninitialized_fill(_a, end(), begin() + s, v);
            // Not large enough capacity
            else { 
                size_type c = 2 * size();
                if (s > c)
                    c = s;
                if (c == s)
                    c += 3;
                size_type b_offset = (c - s) / 2;
                size_type e_offset = b_offset;
                if ((c - s) % 2)
                    ++e_offset;
                
                my_deque d(c, v);
                copy(begin(), end(), d.begin() + b_offset);
                destroy(d._a, d.begin(), d.begin() + b_offset);
                destroy(d._a, d.end() - e_offset, d.end());
                d._b += b_offset;
                d._e -= e_offset;
                swap(d);}
            assert(valid());}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            return _e - _b;}

        // ----
        // swap
        // ----

        /**
         * <your documentation>
         */
        void swap (my_deque& that) {
        if (_a != that._a) {
            my_deque d(*this);
            *this = that;
            that = d;
        }
        else {
            std::swap(_front, that._front);
            std::swap(_back, that._back);
            std::swap(_b, that._b);
            std::swap(_e, that._e);
        }
        assert(valid() );}};

#endif // Deque_h