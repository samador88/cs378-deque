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

        TYPED_TEST(Deque_Fixture, equalop2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); 
            x[0] = 5; 
            x[1] = 4; 
            x[2] = 3; 
            x[3] = 2;
            deque_type y(10); 
            y[0] = 1; 
            y[1] = 1; 
            y[2] = 1;
            y[3] = 1; 
            y[4] = 1; 
            y[5] = 1;
            y[6] = 1; 
            y[7] = 1; 
            y[8] = 1;
            y[9] = 1;
            ASSERT_FALSE(x == y);
        }

        TYPED_TEST(Deque_Fixture, equalop3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            deque_type y(3); 
            y[0] = 1; 
            y[1] = 1; 
            y[2] = 1;
            ASSERT_FALSE(x == y);
        }
       

		// ----------
        // operator <
        // ----------

       
        TYPED_TEST(Deque_Fixture, lessthanop1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); 
            x[0] = 5; 
            x[1] = 4; 
            x[2] = 3;
            x[3] = 4;
            deque_type y(4); 
            y[0] = 5; 
            y[1] = 4; 
            y[2] = 3;
            y[3] = 4;

            ASSERT_FALSE(x < y);
            ASSERT_TRUE(x == y);}

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
        }
		// --------
        // iterator
        // --------

                // -----------
                // operator ==
                // -----------

               //NEED TO CHANGE THESE
               TYPED_TEST(Deque_Fixture, iter_equal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(10);
                    x[0] = 3; 
                    x[1] = 2;
                    deque_type y(10); 
                    y[0] = 3; 
                    y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 0; 
                    x[1] = 0;
                    deque_type y(2); 
                    y[0] = 1; 
                    y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    --x_e;

                    ASSERT_TRUE(x_b == x_e);
                }
				
				// -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_notequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(10); 
                    x[0] = 10; 
                    x[1] = 0;
                    deque_type y(10); 
                    y[0] = 10; 
                    y[1] = 1;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_notequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(10); 
                    x[0] = 10; 
                    x[1] = 0;
                    deque_type y(10); 
                    y[0] = 0; 
                    y[1] = 10;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_notequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 0;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_FALSE(x_b != x_e);
                }
 				// ----------
                // operator +
                // ----------


                TYPED_TEST(Deque_Fixture, iter_plus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); 
                    x[0] = 1; 
                    x[1] = 4;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg = xbeg + 1;

                    ASSERT_TRUE(xbeg == xbeg2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 1;

                    typename deque_type::iterator xbeg = x.begin();

                    ASSERT_TRUE(xbeg + 2 == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 1;

                    typename deque_type::iterator xbeg = x.begin();

                    ASSERT_FALSE(xbeg + 1 == x.begin());
                }

                /*TYPED_TEST(Deque_Fixture, iter_plus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(100, 10); _x[24] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin() + 24;

                    ASSERT_EQ(*xbeg, 1);
                }
*/

                // ----------
                // operator -
                // ----------

                TYPED_TEST(Deque_Fixture, iter_minus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;
                    x[3] = 4;
                    x[5] = 5;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin() + 1;

                    ASSERT_TRUE(xbeg - 4 == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 0; 
                    x[1] = 0;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin();

                    ASSERT_TRUE(xbeg - 1 == xbeg2+1);
                }

                TYPED_TEST(Deque_Fixture, iter_minus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 20;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin();

                    ASSERT_FALSE(xbeg - 1 == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(100, 1); 
                    x[10] = 4;

                    typename deque_type::iterator xbeg = x.end();

                    ASSERT_EQ(*(xbeg - 90), 4);
                }


				// ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, iter_star1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); 
                    x[0] = 9; 
                    x[1] = 15;

                    typename deque_type::iterator xbeg = x.begin();

                    ASSERT_EQ(*xbeg, 9);
                }

                TYPED_TEST(Deque_Fixture, iter_star2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); 
                    x[0] = 5; 
                    x[1] = 5;

                    typename deque_type::iterator xbeg = x.begin();

                    ++xbeg;

                    ASSERT_EQ(*xbeg, 5);
                }

                TYPED_TEST(Deque_Fixture, iter_star3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 100000; 
                    x[1] = 1;

                    typename deque_type::iterator xbeg = x.end();

                    --xbeg;

                    ASSERT_EQ(*xbeg, 1);
                }


				// -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, iter_arrow) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 9; s_a.b = 8;
                    struct S s_b; s_b.a = 6; s_b.b = 7;

                    my_deque<S> x(3); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto xbeg = x.begin();

                    ASSERT_EQ(xbeg->a, 9);
                }

                

                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, iter_plusplus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(10); 
                    x[0] = 100000; 
                    x[1] = 10;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg + 1;

                    ++xbeg;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_plusplus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 5; 
                    x[1] = 0;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    ++xbeg;

                    ASSERT_FALSE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_plusplus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 0; 
                    x[1] = 0;

                    typename deque_type::iterator xbeg = x.begin();

                    ++xbeg;
                    ++xbeg;

                    ASSERT_TRUE(xbeg == x.end());
                }


                TYPED_TEST(Deque_Fixture, iter_postplusplus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); 
                    x[0] = 1; 
                    x[1] = 10;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg + 1;

                    xbeg++;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_postplusplus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 1;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg + 1;

                    ASSERT_FALSE(xbeg++ == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_postplusplus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1000000000; 
                    x[1] = 100000000;

                    typename deque_type::iterator xbeg = x.begin();

                    xbeg++;
                    xbeg++;

                    ASSERT_TRUE(xbeg == x.end());
                }

                // -----------
                // operator --
                // -----------

                TYPED_TEST(Deque_Fixture, iter_minusminus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 10; 
                    x[1] = 15;
                    x[2] = 12;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = xbeg - 1;

                    --xbeg;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minusminus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 15;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = x.end();

                    --xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minusminus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 15;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = x.end();

                    --xbeg2;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }



                TYPED_TEST(Deque_Fixture, iter_minusminuspost1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 145;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = xbeg - 1;

                    xbeg--;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minusminuspost2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 153;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = xbeg - 2;

                    xbeg2--;

                    ASSERT_FALSE(xbeg2-- == xbeg);
                }

                TYPED_TEST(Deque_Fixture, iter_minusminuspost3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 10; 
                    x[1] = 1000;
                    x[2] = 10000;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = xbeg - 3;

                    xbeg--;
                    xbeg--;
                    xbeg--;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                // -----------
                // operator +=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_plusequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 5000;
                    x[2] = 10000;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg += 1;

                    ASSERT_TRUE(xbeg == xbeg2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plusequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 10000; 
                    x[1] = 50000;
                    x[2] = 100000;

                    typename deque_type::iterator xbeg = x.begin();

                    xbeg += 3;

                    ASSERT_TRUE(xbeg == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plusequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 5; 
                    x[1] = 5;

                    typename deque_type::iterator xbeg = x.begin();

                    xbeg += 1;

                    ASSERT_FALSE(xbeg == x.begin());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(100); 
                    x[10] = 233;

                    typename deque_type::iterator xbeg = x.begin();

                    xbeg += 10;

                    ASSERT_EQ(*xbeg, 233);
                }


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_minusequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 5; 
                    x[1] = 10;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin() + 1;

                    xbeg -= 1;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minusequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 5; 
                    x[1] = 100000;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin();

                    xbeg -= 2;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, iter_minusequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1000000; 
                    x[1] = 0;

                    typename deque_type::iterator xbeg = x.end();
                    typename deque_type::iterator xbeg2 = x.begin();

                    xbeg -= 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }


        // --------------
        // const_iterator
        // --------------

          /*      // -----------
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
*/
       /* //      NEED TO CHANGE THESE 
                // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    ++xbeg;

                    ASSERT_TRUE(xbeg == xbeg2 + 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    ASSERT_TRUE(xbeg + 2 == x.end());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    ASSERT_FALSE(xbeg + 1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(29); _x[24] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin() + 24;

                    ASSERT_EQ(*xbeg, 1);
                }

                // ----------
                // operator -
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin() + 1;

                    ASSERT_TRUE(xbeg - 1 == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin();

                    ASSERT_TRUE(xbeg - 2 == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin();

                    ASSERT_FALSE(xbeg - 1 == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(92, 31); _x[50] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();

                    ASSERT_EQ(*(xbeg - 42), 1);
                }*/
                /* NEED TO CHANGE THESE    
				// ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    ASSERT_EQ(*xbeg, 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    ++xbeg;

                    ASSERT_EQ(*xbeg, 4);
                }

                TYPED_TEST(Deque_Fixture, const_iter_deref_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();

                    --xbeg;

                    ASSERT_EQ(*xbeg, 4);
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

                    auto xbeg = x.begin();

                    ASSERT_EQ(xbeg->a, 1);
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

                    auto xbeg = x.begin();

                    ASSERT_EQ(xbeg->b, 3);
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

                    auto xbeg = x.begin(); ++xbeg;

                    ASSERT_EQ(xbeg->b, 7);
                }*/

/* 			NEED TO CHANGE THESE
				// -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg + 1;

                    ++xbeg;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    ++xbeg;

                    ASSERT_FALSE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    ++xbeg;
                    ++xbeg;

                    ASSERT_TRUE(xbeg == x.end());
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg + 1;

                    xbeg++;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;
                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg + 1;

                    ASSERT_FALSE(xbeg++ == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    xbeg++;
                    xbeg++;

                    ASSERT_TRUE(xbeg == x.end());
                }

                // -----------
                // operator --
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = xbeg - 1;

                    --xbeg;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = x.end();

                    --xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_pre_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = x.end();

                    --xbeg2;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = xbeg - 1;

                    xbeg--;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = xbeg - 2;

                    xbeg2--;

                    ASSERT_FALSE(xbeg2-- == xbeg);
                }

                TYPED_TEST(Deque_Fixture, const_iter_post_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = xbeg - 2;

                    xbeg--;
                    xbeg--;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                // -----------
                // operator +=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;


                    typename deque_type::const_iterator xbeg = x.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg += 1;

                    ASSERT_TRUE(xbeg == xbeg2 + 1);
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    xbeg += 2;

                    ASSERT_TRUE(xbeg == x.end());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    xbeg += 1;

                    ASSERT_FALSE(xbeg == x.begin());
                }

                TYPED_TEST(Deque_Fixture, const_iter_plus_op_equal_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(100, 10); _x[24] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.begin();

                    xbeg += 24;

                    ASSERT_EQ(*xbeg, 1);
                }


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin() + 1;

                    xbeg -= 1;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin();

                    xbeg -= 2;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

                TYPED_TEST(Deque_Fixture, const_iter_minus_equal_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(2); _x[0] = 1; _x[1] = 4;

                    const deque_type x = _x;

                    typename deque_type::const_iterator xbeg = x.end();
                    typename deque_type::const_iterator xbeg2 = x.begin();

                    xbeg -= 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
*/
    // --------
    // my_deque
    // --------

        // ----------
        // operator =
        // ----------

  /*      TYPED_TEST(Deque_Fixture, deque_assignment_op_test_1) {
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
*/


/*NEED TO CHANGE THESE
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
*/