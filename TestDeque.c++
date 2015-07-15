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

TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}

        // -----------
        // operator ==
        // -----------

        TYPED_TEST(Deque_Fixture, equalop1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); 
            x[1];
            deque_type y(1); 
            y[1];

            ASSERT_TRUE(x == y);
        }

        /*NEED TO CHANGE THESE
        TYPED_TEST(Deque_Fixture, equalop2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_FALSE(x == y);
        }

        TYPED_TEST(Deque_Fixture, deque_equality_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_FALSE(x == y);
        }*/

		// ----------
        // operator <
        // ----------

        /*NEED TO CHANGE THIS
        TYPED_TEST(Deque_Fixture, lessthanop1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;

            ASSERT_FALSE(x < y);
        }*/

       /*DONT NEED TO CHANGE THESE
        TYPED_TEST(Deque_Fixture, lessthanop2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5); 
            x[0] = 5; 
            x[1] = 5; 
            x[2] = 5;
            deque_type y(5); 
            y[0] = 5;
            y[1] = 5; 
            y[2] = 6;

            ASSERT_TRUE(x < y);
        }

        TYPED_TEST(Deque_Fixture, lessthanop3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); 
            x[0] = 5;
            deque_type y(3); 
            y[0] = 5; 
            y[1] = 4; 
            y[2] = 3;
            ASSERT_TRUE(x < y);
        }
*/
        /*DON'T NEED TO CHANGE THESE
        TYPED_TEST(Deque_Fixture, lessthanop4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[2] = 2;
            x[3] = 3;
            deque_type y;
            ASSERT_FALSE(x < y);
        }

        TYPED_TEST(Deque_Fixture, lessthanop5) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1);
            deque_type y(1);
            x[0] = 2;
            y[0] = 1;
            ASSERT_FALSE(x < y);
        }*/
		// --------
        // iterator
        // --------

                // -----------
                // operator ==
                // -----------

               /* NEED TO CHANGE THESE
               TYPED_TEST(Deque_Fixture, iter_equal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); x[0] = 1; x[1] = 4;
                    deque_type y(5); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;
                    deque_type y(2); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_TRUE(x_b == x_e);
                }*/
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

                /* Need to change these
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
*/
                /*Need to change these
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
                }*/

				/*NEED TO CHANGE THESE
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
                }*/

				/*NEED TO CHANGE THESE
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
*/