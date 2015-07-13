// --------------------------------
// projects/c++/deque/TestDeque.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// http://www.cplusplus.com/reference/deque/deque/

// --------
// includes
// --------

#include <deque>     // deque
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"

#include "Deque.h"

// -----
// Using
// -----

using namespace std;

using testing::Test;
using testing::Types;

// -----
// Types
// -----

template <typename T>
struct Deque_Fixture : Test {
    typedef T                               deque_type;
    typedef typename deque_type::value_type value_type;};

typedef Types<
               deque<int>,
            my_deque<int>>
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);

// -----
// Tests
// -----


// -----
// Constructors
// _____

TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}

TYPED_TEST(Deque_Fixture, test_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(5);
    //***************remember to change this backASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),5);}

// -----
// =operator
// -----

TYPED_TEST(Deque_Fixture, assignment1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(5, 1);
    deque_type y(10, 2);
    x = y;
    ASSERT_EQ(x,y);}

TYPED_TEST(Deque_Fixture, assignment2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(10, 2);
    deque_type y(5, 1);
    x = y;
    ASSERT_EQ(x,y);}

TYPED_TEST(Deque_Fixture, assignment3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(5, 1);
    deque_type y(5, 1);
    x = y;
    ASSERT_EQ(x,y);}

TYPED_TEST(Deque_Fixture, assignment4) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(5, 2);
    deque_type y(5, 1);
    x = y;
    ASSERT_EQ(x,y);}

// -----
// index
// -----

TYPED_TEST(Deque_Fixture, index1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(5, 1);
    ASSERT_EQ(x[1],1);}