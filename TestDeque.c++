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

// -------
// my_deque
// -------

        // -----------
        // operator ==
        // -----------

        TYPED_TEST(Deque_Fixture, equal1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(2);
            y[0] = 0;
            y[1] = 1;

            ASSERT_TRUE(x == y);
            ASSERT_TRUE(y == x);
        }

        TYPED_TEST(Deque_Fixture, equal2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(x);


            ASSERT_TRUE(x == y);
            ASSERT_TRUE(y == x);
        }
        TYPED_TEST(Deque_Fixture, equal3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(1);
            deque_type y;
            y.push_front(1);

            ASSERT_TRUE(x == y);
            ASSERT_TRUE(y == x);
        }

        TYPED_TEST(Deque_Fixture, equal4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(3);
            deque_type y;
            y.push_front(9);

            ASSERT_FALSE(x == y);
            ASSERT_FALSE(y == x);
        }
        // -----------
        // operator !=
        // -----------
       TYPED_TEST(Deque_Fixture, notequal1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(2);
            y[0] = 0;
            y[1] = 1;

            ASSERT_FALSE(x != y);
            ASSERT_FALSE(y != x);
        }

        TYPED_TEST(Deque_Fixture, notequal2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(x);


            ASSERT_FALSE(x != y);
            ASSERT_FALSE(y != x);
        }
        TYPED_TEST(Deque_Fixture, notequal3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(1);
            deque_type y;
            y.push_front(1);

            ASSERT_FALSE(x != y);
            ASSERT_FALSE(y != x);
        }

        TYPED_TEST(Deque_Fixture, notequal4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(3);
            deque_type y;
            y.push_front(9);

            ASSERT_TRUE(x != y);
            ASSERT_TRUE(y != x);
        }
     
        // ----------
        // operator <
        // ----------
        TYPED_TEST(Deque_Fixture, less1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(2);
            y[0] = 0;
            y[1] = 1;

            ASSERT_FALSE(x < y);
            ASSERT_FALSE(y < x);
        }

        TYPED_TEST(Deque_Fixture, less2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 0;
            x[1] = 1;
            deque_type y(x);


            ASSERT_FALSE(x < y);
            ASSERT_FALSE(y < x);
        }
        TYPED_TEST(Deque_Fixture, less3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(1);
            deque_type y;
            y.push_front(1);

            ASSERT_FALSE(x < y);
            ASSERT_FALSE(y < x);
        }

        TYPED_TEST(Deque_Fixture, less4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(3);
            deque_type y;
            y.push_front(9);

            ASSERT_TRUE(x < y);
            ASSERT_FALSE(y < x);
        }
     

        // --------
        // iterator
        // --------

                // -----------
                // operator ==
                // -----------

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); x[0] = 1; x[1] = 4;
                    deque_type y(5); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;
                    deque_type y(2); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_TRUE(x_b == x_e);
                }
                // -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); x[0] = 1; x[1] = 4;
                    deque_type y(5); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;
                    deque_type y(2); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_FALSE(x_b != x_e);
                }
 // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_TRUE(x_b1 + 2 == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_FALSE(x_b1 + 1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(100, 10); _x[24] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin() + 24;

                    ASSERT_EQ(*x_b1, 1);
                }

                // ----------
                // operator -
                // ----------

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin() + 1;

                    ASSERT_TRUE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    ASSERT_TRUE(x_b1 - 2 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    ASSERT_FALSE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(92, 31); x[50] = 1;

                    typename deque_type::iterator x_b1 = x.end();

                    ASSERT_EQ(*(x_b1 - 42), 1);
                }


                // ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_EQ(*x_b1, 1);
                }

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ++x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();

                    --x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                // -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_1) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->a, 1);
                }

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_2) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->b, 3);
                }

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_3) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin(); ++x_b1;

                    ASSERT_EQ(x_b1->b, 7);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_1) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->a, 1);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_2) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->b, 3);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_3) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin(); ++x_b1;

                    ASSERT_EQ(x_b1->b, 7);
                }

                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ++x_b1;
                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    x_b1++;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    ASSERT_FALSE(x_b1++ == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1++;
                    x_b1++;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // -----------
                // operator --
                // -----------

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 1;

                    --x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x.end();

                    --x_b2;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x.end();

                    --x_b2;

                    ASSERT_TRUE(x_b1 == --x_b2);
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 1;

                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 2;

                    x_b2--;

                    ASSERT_FALSE(x_b2-- == x_b1);
                }

                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 2;

                    x_b1--;
                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                // -----------
                // operator +=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    x_b1 += 1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 2;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 1;

                    ASSERT_FALSE(x_b1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(1000); x[324] = 42;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 324;

                    ASSERT_EQ(*x_b1, 42);
                }


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin() + 1;

                    x_b1 -= 1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    x_b1 -= 2;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    x_b1 -= 1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

        // --------------
        // const_iterator
        // --------------

                // -----------
                // operator ==
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_equality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(5); _x[0] = 1; _x[1] = 4;
                    deque_type _y(5); _y[0] = 1; _y[1] = 3;

                    const deque_type x = _x;
                    const deque_type y = _y;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, const_iter_equality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;
                    deque_type _y(2); _y[0] = 1; _y[1] = 3;

                    const deque_type x = _x;
                    const deque_type y = _y;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, const_iter_equality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_TRUE(x_b == x_e);
                }

                // -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_inequality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(5); _x[0] = 1; _x[1] = 4;
                    deque_type _y(5); _y[0] = 1; _y[1] = 3;

                    const deque_type x = _x;
                    const deque_type y = _y;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator y_b = y.begin();

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, const_iter_inequality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;
                    deque_type _y(2); _y[0] = 1; _y[1] = 3;

                    const deque_type x = _x;
                    const deque_type y = _y;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, const_iter_inequality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b = x.begin();
                    typename deque_type::const_iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_FALSE(x_b != x_e);
                }

                // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    ASSERT_TRUE(x_b1 + 2 == x.end());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    ASSERT_FALSE(x_b1 + 1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(29); _x[24] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin() + 24;

                    ASSERT_EQ(*x_b1, 1);
                }

                // ----------
                // operator -
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin() + 1;

                    ASSERT_TRUE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin();

                    ASSERT_TRUE(x_b1 - 2 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin();

                    ASSERT_FALSE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(92, 31); _x[50] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();

                    ASSERT_EQ(*(x_b1 - 42), 1);
                }

                // ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    ASSERT_EQ(*x_b1, 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    ++x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();

                    --x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                // -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_arrow_op_test_1) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> _x(2); 
                    _x[0] = s_a;
                    _x[1] = s_b;

                    const deque<S> x = _x;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->a, 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_arrow_op_test_2) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> _x(2); 
                    _x[0] = s_a;
                    _x[1] = s_b;

                    const deque<S> x = _x;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->b, 3);
                }

                TYPED_TEST(Deque_Fixture, const_iter_arrow_op_test_3) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> _x(2); 
                    _x[0] = s_a;
                    _x[1] = s_b;

                    const deque<S> x = _x;

                    auto x_b1 = x.begin(); ++x_b1;

                    ASSERT_EQ(x_b1->b, 7);
                }

                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1 + 1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    ++x_b1;
                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1 + 1;

                    x_b1++;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;
                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1 + 1;

                    ASSERT_FALSE(x_b1++ == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    x_b1++;
                    x_b1++;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // -----------
                // operator --
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x_b1 - 1;

                    --x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x.end();

                    --x_b2;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x.end();

                    --x_b2;

                    ASSERT_TRUE(x_b1 == --x_b2);
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x_b1 - 1;

                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x_b1 - 2;

                    x_b2--;

                    ASSERT_FALSE(x_b2-- == x_b1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x_b1 - 2;

                    x_b1--;
                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                // -----------
                // operator +=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;


                    typename deque_type::const_iterator x_b1 = x.begin();
                    typename deque_type::const_iterator x_b2 = x_b1;

                    x_b1 += 1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    x_b1 += 2;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    x_b1 += 1;

                    ASSERT_FALSE(x_b1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(100, 10); _x[24] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin();

                    x_b1 += 24;

                    ASSERT_EQ(*x_b1, 1);
                }


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin() + 1;

                    x_b1 -= 1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin();

                    x_b1 -= 2;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.end();
                    typename deque_type::const_iterator x_b2 = x.begin();

                    x_b1 -= 1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

    // --------
    // my_deque
    // --------

        // ----------
        // operator =
        // ----------

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y = x;
            ASSERT_EQ(x,y);
        }

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y(4);
            y = x;
            x[0] = 20;
            ASSERT_TRUE(x != y);
        }

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y = x;
            y[0] = 20;
            ASSERT_TRUE(x != y);
        }

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y;
            x = y;
            ASSERT_EQ(x,y);
        }

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_5) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(100, 10);
            deque_type y(2);
            x = y;
            ASSERT_EQ(x,y);
        }

        TYPED_TEST(Deque_Fixture, deque_assignment_op_test_6) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(100, 10);
            deque_type y(2);
            y = x;
            ASSERT_EQ(x,y);
        }

        // -----------
        // operator []
        // -----------

        TYPED_TEST(Deque_Fixture, deque_index_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x[0],1);
        }

        TYPED_TEST(Deque_Fixture, deque_index_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x[1],2);
        }

        TYPED_TEST(Deque_Fixture, deque_index_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x[2],3);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_index_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y[0],1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_index_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y[1],2);
        }

        TYPED_TEST(Deque_Fixture, const_deque_index_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y[2],3);
        }

        // --
        // at
        // --

        TYPED_TEST(Deque_Fixture, deque_at_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.at(0),1);
        }

        TYPED_TEST(Deque_Fixture, deque_at_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.at(1),2);
        }

        TYPED_TEST(Deque_Fixture, deque_at_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.at(2),3);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_at_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.at(0),1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_at_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.at(1),2);
        }

        TYPED_TEST(Deque_Fixture, const_deque_at_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.at(2),3);
        }

        // ----
        // back
        // ----

        TYPED_TEST(Deque_Fixture, deque_back_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y(x); 
            ASSERT_EQ(x.back(),4);
        }

        TYPED_TEST(Deque_Fixture, deque_back_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.back(),0);
        }

        TYPED_TEST(Deque_Fixture, deque_back_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.back(),3);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_back_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            const deque_type y = x;
            ASSERT_EQ(y.back(),4);
        }

        TYPED_TEST(Deque_Fixture, const_deque_back_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.back(),0);
        }

        TYPED_TEST(Deque_Fixture, const_deque_back_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.back(),3);
        }

        // -----
        // begin
        // -----

        TYPED_TEST(Deque_Fixture, deque_begin_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,1);
        }

        TYPED_TEST(Deque_Fixture, deque_begin_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,5);
        }

        TYPED_TEST(Deque_Fixture, deque_begin_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,0);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_begin_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_begin_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,5);
        }

        TYPED_TEST(Deque_Fixture, const_deque_begin_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            typename deque_type::iterator x_b = x.begin();
            ASSERT_EQ(*x_b,0);
        }

        // -----
        // clear
        // -----

        TYPED_TEST(Deque_Fixture, deque_clear_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(100); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x[0],1);
            ASSERT_EQ(x[1],2);
            ASSERT_EQ(x[2],3);
            x.clear();
            ASSERT_TRUE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_clear_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            ASSERT_FALSE(x.empty());
            ASSERT_EQ(x[0],0);
            ASSERT_EQ(x[1],0);
            ASSERT_EQ(x[2],0);
            x.clear();
            ASSERT_TRUE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_clear_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            ASSERT_TRUE(x.empty());

            x.clear();
            ASSERT_TRUE(x.empty());
        }

        // -----
        // empty
        // -----

        TYPED_TEST(Deque_Fixture, deque_empty_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_FALSE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_empty_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            ASSERT_FALSE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_empty_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            ASSERT_TRUE(x.empty());
        }

        // ---
        // end
        // ---

        TYPED_TEST(Deque_Fixture, deque_end_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            typename deque_type::iterator x_e = x.end();

            ASSERT_EQ(*(--x_e),4);
        }

        TYPED_TEST(Deque_Fixture, deque_end_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator x_b = x.begin();
            typename deque_type::iterator x_e = x.end();
            ++x_b;
            ++x_b;
            ++x_b;
            ASSERT_FALSE(x_b == x_e);
        }

        TYPED_TEST(Deque_Fixture, deque_end_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 1;
            typename deque_type::iterator x_b = x.begin();
            typename deque_type::iterator x_e = x.end();

            ++x_b;

            ASSERT_TRUE(x_b == x_e);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_end_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            const deque_type _x = x;
            typename deque_type::const_iterator x_e = _x.end();
            ASSERT_EQ(*(--x_e),4);
        }

        TYPED_TEST(Deque_Fixture, const_deque_end_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 5; x[1] = 2; x[2] = 3;
            const deque_type _x = x;
            typename deque_type::const_iterator x_b = _x.begin();
            typename deque_type::const_iterator x_e = _x.end();
            ++x_b;
            ++x_b;
            ++x_b;
            ASSERT_FALSE(x_b == x_e);
        }

        TYPED_TEST(Deque_Fixture, const_deque_end_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 1;
            const deque_type _x =x;
            typename deque_type::const_iterator x_b = _x.begin();
            typename deque_type::const_iterator x_e = _x.end();
            ++x_b;
            ASSERT_TRUE(x_b == x_e);
        }

        // -----
        // erase
        // -----

        TYPED_TEST(Deque_Fixture, deque_erase_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.begin();
            x.erase(it);
            ASSERT_EQ(x.size(), 2);
            ASSERT_EQ(x[0], 2);
        }

        TYPED_TEST(Deque_Fixture, deque_erase_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.begin();
            ++it;
            x.erase(it);
            ASSERT_EQ(x.size(), 2);
            ASSERT_EQ(x[0], 1);
            ASSERT_EQ(x[1], 3);
        }

        TYPED_TEST(Deque_Fixture, deque_erase_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.begin();
            ++++it;
            x.erase(it);
            ASSERT_EQ(x.size(), 2);
            ASSERT_EQ(x[0], 1);
            ASSERT_EQ(x[1], 2);
        }

        // -----
        // front
        // -----

        TYPED_TEST(Deque_Fixture, deque_front_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.front(),1);
        }

        TYPED_TEST(Deque_Fixture, deque_front_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            ASSERT_EQ(x.front(),5);
        }

        TYPED_TEST(Deque_Fixture, deque_front_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 42;
            ASSERT_EQ(x.front(),42);
        }

        // reference and const_reference

        TYPED_TEST(Deque_Fixture, const_deque_front_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.front(),1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_front_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            const deque_type y = x;
            ASSERT_EQ(y.front(),5);
        }

        TYPED_TEST(Deque_Fixture, const_deque_front_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 42;
            const deque_type y = x;
            ASSERT_EQ(y.front(),42);
        }

        // ------
        // insert
        // ------

       /* TYPED_TEST(Deque_Fixture, deque_insert_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.begin();
            ++it;
            x.insert(it, 1);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],1);
            ASSERT_EQ(x[2],2);
            ASSERT_EQ(x[3],3);
        }

        TYPED_TEST(Deque_Fixture, deque_insert_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.begin();
            x.insert(it, 1);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],1);
            ASSERT_EQ(x[1],5);
            ASSERT_EQ(x[2],2);
            ASSERT_EQ(x[3],3);
        }*/

        TYPED_TEST(Deque_Fixture, deque_insert_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            typename deque_type::iterator it = x.end();
            x.insert(it, 1);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],2);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],1);
        }

        // --------
        // pop_back
        // --------

        TYPED_TEST(Deque_Fixture, deque_pop_back_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            x.pop_back();
            ASSERT_EQ(x.size(),2);
            ASSERT_EQ(x[1],2);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_back_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 5;
            x.pop_back();
            ASSERT_EQ(x.size(),0);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_back_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.pop_back();
            x.pop_back();
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],5);
        }

        // ---------
        // pop_front
        // ---------

        TYPED_TEST(Deque_Fixture, deque_pop_front_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            x.pop_front();
            ASSERT_EQ(x.size(),2);
            ASSERT_EQ(x[0],2);
            ASSERT_EQ(x[1],3);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_front_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 5;
            x.pop_front();
            ASSERT_EQ(x.size(),0);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_front_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.pop_front();
            x.pop_front();
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],3);
        }

        // ---------
        // push_back
        // ---------

        TYPED_TEST(Deque_Fixture, deque_push_back_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            x.push_back(26);

            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],2);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],26);
        }

        TYPED_TEST(Deque_Fixture, deque_push_back_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_back(5);
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],5);
        }

        TYPED_TEST(Deque_Fixture, deque_push_back_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.push_back(26);
            x.push_back(42);

            ASSERT_EQ(x.size(),5);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],1);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],26);
            ASSERT_EQ(x[4],42);
        }

        // ----------
        // push_front
        // ----------

        TYPED_TEST(Deque_Fixture, deque_push_front_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 2; x[2] = 3;
            x.push_front(26);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],26);
            ASSERT_EQ(x[1],5);
            ASSERT_EQ(x[2],2);
            ASSERT_EQ(x[3],3);
        }

        TYPED_TEST(Deque_Fixture, deque_push_front_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.push_front(5);
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],5);
        }

        TYPED_TEST(Deque_Fixture, deque_push_front_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.push_front(26);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(42);
            x.push_front(3);
            x.push_front(1);
            x.push_front(5);
            x.push_front(26);
            x.push_front(42);
            ASSERT_EQ(x.size(),19);
            ASSERT_EQ(x[0],42);
            ASSERT_EQ(x[1],26);
            ASSERT_EQ(x[2],5);
            ASSERT_EQ(x[3],1);
            ASSERT_EQ(x[4],3);
        }

        // ------
        // resize
        // ------

        TYPED_TEST(Deque_Fixture, deque_resize_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.resize(20);

            ASSERT_EQ(x.size(),20);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],1);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],0);
            ASSERT_EQ(x[19],0);
        }

        TYPED_TEST(Deque_Fixture, deque_resize_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            x.resize(20);
            ASSERT_EQ(x.size(),20);
            ASSERT_EQ(x[0],0);
            ASSERT_EQ(x[1],0);
            ASSERT_EQ(x[2],0);
            ASSERT_EQ(x[3],0);
            ASSERT_EQ(x[19],0);
        }

        TYPED_TEST(Deque_Fixture, deque_resize_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.resize(1);
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],5);
        }

        TYPED_TEST(Deque_Fixture, deque_resize_test_4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 5; x[1] = 1; x[2] = 3;
            x.resize(0);
            ASSERT_TRUE(x.empty());
            ASSERT_EQ(x.size(), 0);
            x.resize(3);
            ASSERT_FALSE(x.empty());
            ASSERT_EQ(x.size(), 3);
            ASSERT_EQ(x[0], 0);
            ASSERT_EQ(x[1], 0);
            ASSERT_EQ(x[2], 0);
        }

        TYPED_TEST(Deque_Fixture, deque_resize_test_5) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1000); x[0] = 5; x[1] = 1; x[2] = 3;
            x.resize(1);
            ASSERT_EQ(x.size(),1);
            ASSERT_EQ(x[0],5);
        }

        TYPED_TEST(Deque_Fixture, deque_resize_test_6) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(10); x[0] = 5; x[1] = 1; x[2] = 3;
            x.resize(10);
            ASSERT_EQ(x.size(),10);
            ASSERT_EQ(x[0],5);
            ASSERT_EQ(x[1],1);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],0);
            ASSERT_EQ(x[9],0);
        }

        // ----
        // size
        // ----

        TYPED_TEST(Deque_Fixture, deque_size_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            ASSERT_EQ(x.size(), 0);
        }

        TYPED_TEST(Deque_Fixture, deque_size_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(10);
            ASSERT_EQ(x.size(), 10);
        }

        TYPED_TEST(Deque_Fixture, deque_size_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            const deque_type x(30000);
            ASSERT_EQ(x.size(),30000);
        }

        // ----
        // swap
        // ----

        TYPED_TEST(Deque_Fixture, deque_swap_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            deque_type x_copy = x;
            deque_type y(3); y[0] = 10; y[1] = 20; y[2] = 30;
            deque_type y_copy = y;

            x.swap(y);
            ASSERT_TRUE(x == y_copy);
            ASSERT_TRUE(y == x_copy);
        }

        TYPED_TEST(Deque_Fixture, deque_swap_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 1;
            deque_type x_copy = x;
            deque_type y(3); y[0] = 10; y[1] = 20; y[2] = 30;
            deque_type y_copy = y;

            x.swap(y);
            ASSERT_EQ(x.size(), 3);
            ASSERT_EQ(y.size(), 1);
            ASSERT_TRUE(x == y_copy);
            ASSERT_TRUE(y == x_copy);
        }
