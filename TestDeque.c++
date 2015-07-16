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

                TYPED_TEST(Deque_Fixture, iterequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(2);
                    y[0] = 1;
                    y[2] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator ybeg = y.begin();

                    ASSERT_FALSE(xbeg == ybeg);
                }
                
                TYPED_TEST(Deque_Fixture, iterequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(3);
                    y[0] = 1;
                    y[1] = 2;
                    y[2] = 3;
                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator ybeg = y.begin();

                    ASSERT_FALSE(xbeg == ybeg);
                }

                TYPED_TEST(Deque_Fixture, iterequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    typename deque_type::iterator xbeg1 = x.begin();
                    typename deque_type::iterator xbeg2 = x.begin();

                    ASSERT_TRUE(xbeg1 == xbeg2);
                }
                // -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, iternotequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(2);
                    y[0] = 1;
                    y[2] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator ybeg = y.begin();

                    ASSERT_TRUE(xbeg != ybeg);
                }
                
                TYPED_TEST(Deque_Fixture, iternotequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(3);
                    y[0] = 1;
                    y[1] = 2;
                    y[2] = 3;
                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator ybeg = y.begin();

                    ASSERT_TRUE(xbeg != ybeg);
                }

                TYPED_TEST(Deque_Fixture, iternotequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    typename deque_type::iterator xbeg1 = x.begin();
                    typename deque_type::iterator xbeg2 = x.begin();

                    ASSERT_FALSE(xbeg1 != xbeg2);
                }
                // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, iterplus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg1 = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg1 + 1;


                    ASSERT_TRUE(xbeg1+1 == xbeg2);
                }

                
                TYPED_TEST(Deque_Fixture, iterplus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xend = x.end();


                    ASSERT_TRUE(xbeg+3 == xend);
                }
                TYPED_TEST(Deque_Fixture, iterplus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xend = x.end();


                    ASSERT_FALSE(xbeg+2 == xend);
                }



                // ----------
                // operator -
                // ----------
                TYPED_TEST(Deque_Fixture, iterminus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg1 = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg1 + 1;


                    ASSERT_TRUE(xbeg1 == xbeg2-1);
                }

                
                TYPED_TEST(Deque_Fixture, iterminus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xend = x.end();


                    ASSERT_TRUE(xbeg == xend-3);
                }
                TYPED_TEST(Deque_Fixture, iterminus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xend = x.end();


                    ASSERT_FALSE(xbeg == xend-2);
                }



                // ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, iterstar1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();

                    ASSERT_EQ(*xbeg, 1);
                }

                TYPED_TEST(Deque_Fixture, iterstar2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin() + 1;

                    ASSERT_EQ(*xbeg, 2);
                }

                TYPED_TEST(Deque_Fixture, iterstar3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin() + 1;

                    ASSERT_TRUE(*xbeg == 2);
                }

                // -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, iterarrow) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; 
                    s_a.a = 1; 
                    s_a.b = 2;

                    struct S s_b; 
                    s_b.a = 3; 
                    s_b.b = 4;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto xbeg = x.begin();

                    ASSERT_EQ(xbeg->a, 1);
                }

             
                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, iterpre_plus_plus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    ++xbeg;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpre_plus_plus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    ++xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iterpre_plus_plus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = ++xbeg;


                    ASSERT_TRUE(xbeg == xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpost_plus_plus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg++;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpost_plus_plus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg2++;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iterpost_plus_plus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg++;


                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                // -----------
                // operator --
                // -----------

                TYPED_TEST(Deque_Fixture, iterpre_minus_minus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    --xbeg;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpre_minus_minus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    --xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iterpre_minus_minus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = --xbeg;


                    ASSERT_TRUE(xbeg == xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpost_minus_minus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg--;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iterpost_minus_minus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg2--;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iterpost_minus_minus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg--;


                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iterpost_minus_minus4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;


                    ASSERT_TRUE(xbeg == xbeg2--);
                }
                // -----------
                // operator +=
                // -----------
                TYPED_TEST(Deque_Fixture, iter_plus_equals1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg += 1;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iter_plus_equals2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg2 += 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iter_plus_equals3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin();
                    typename deque_type::iterator xbeg2 = xbeg;
                    xbeg2 += 1;


                    ASSERT_FALSE(xbeg == xbeg2);
                }
                


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_minus_equals1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg -= 1;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, iter_minus_equals2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg;

                    xbeg2 -= 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iter_minus_equals3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+1;
                    typename deque_type::iterator xbeg2 = xbeg--;

                    xbeg2 -= 1;
                    ASSERT_TRUE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, iter_minus_equals4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    typename deque_type::iterator xbeg = x.begin()+5;
                    typename deque_type::iterator xbeg2 = x.begin()+2;
                    xbeg -= 3;

                    ASSERT_TRUE(xbeg == xbeg2);
                }

        // --------------
        // const_iterator
        // --------------

                // -----------
                // operator ==
                // -----------


                TYPED_TEST(Deque_Fixture, const_iterequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(2);
                    y[0] = 1;
                    y[2] = 2;

                    const deque_type constx = x;
                    const deque_type consty = y;

                    typename deque_type::const_iterator xbeg = constx.begin();
                    typename deque_type::const_iterator ybeg = consty.begin();

                    ASSERT_FALSE(xbeg == ybeg);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(3);
                    y[0] = 1;
                    y[1] = 2;
                    y[2] = 3;
                    const deque_type constx = x;
                    const deque_type consty = y;

                    typename deque_type::const_iterator xbeg = constx.begin();
                    typename deque_type::const_iterator ybeg = consty.begin();

                    ASSERT_FALSE(xbeg == ybeg);
                }

                TYPED_TEST(Deque_Fixture, const_iterequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;

                    const deque_type constx = x;

                    typename deque_type::const_iterator xbeg1 = constx.begin();
                    typename deque_type::const_iterator xbeg2 = constx.begin();
                    ASSERT_TRUE(xbeg1 == xbeg2);
                }
                // -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_notequal1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(2);
                    y[0] = 1;
                    y[2] = 2;

                    const deque_type constx = x;
                    const deque_type consty = y;

                    typename deque_type::const_iterator xbeg = constx.begin();
                    typename deque_type::const_iterator ybeg = consty.begin();

                    ASSERT_TRUE(xbeg != ybeg);
                }
                
                TYPED_TEST(Deque_Fixture, const_iter_notequal2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    deque_type y(3);
                    y[0] = 1;
                    y[1] = 2;
                    y[2] = 3;
                    const deque_type constx = x;
                    const deque_type consty = y;

                    typename deque_type::const_iterator xbeg = constx.begin();
                    typename deque_type::const_iterator ybeg = consty.begin();

                    ASSERT_TRUE(xbeg != ybeg);
                }

                TYPED_TEST(Deque_Fixture, const_iter_notequal3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;

                    const deque_type constx = x;

                    typename deque_type::const_iterator xbeg1 = constx.begin();
                    typename deque_type::const_iterator xbeg2 = constx.begin();
                    ASSERT_FALSE(xbeg1 != xbeg2);
                }
                // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, const_iterplus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg1 = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg1 + 1;


                    ASSERT_TRUE(xbeg1+1 == xbeg2);
                }

                
                TYPED_TEST(Deque_Fixture, const_iterplus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;

                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xend = y.end();


                    ASSERT_TRUE(xbeg+3 == xend);
                }
                TYPED_TEST(Deque_Fixture, const_iterplus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xend = y.end();


                    ASSERT_FALSE(xbeg+2 == xend);
                }


                // ----------
                // operator -
                // ----------

               TYPED_TEST(Deque_Fixture, const_iterminus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xend = xbeg +1;

                    ASSERT_TRUE(xbeg == xend-1);
                }

                
                TYPED_TEST(Deque_Fixture, const_iterminus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xend = y.end();


                    ASSERT_TRUE(xbeg == xend-3);
                }
                TYPED_TEST(Deque_Fixture, const_iterminus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(3); 
                    x[0] = 1; 
                    x[1] = 2;
                    x[2] = 3;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xend = y.end();


                    ASSERT_FALSE(xbeg == xend-2);
                }

                // ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, const_terstar1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();

                    ASSERT_EQ(*xbeg, 1);
                }

                TYPED_TEST(Deque_Fixture, const_iterstar2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;

                    ASSERT_EQ(*xbeg, 2);
                }

                TYPED_TEST(Deque_Fixture, const_iterstar3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1;
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;

                    ASSERT_TRUE(*xbeg == 2);
                }

                // -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, const_iterarrow) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; 
                    s_a.a = 1; 
                    s_a.b = 2;

                    struct S s_b; 
                    s_b.a = 3; 
                    s_b.b = 4;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;
                    const my_deque<S> y = x;
                    auto xbeg = y.begin();

                    ASSERT_EQ(xbeg->a, 1);
                }


                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iterpre_plus_plus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    ++xbeg;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpre_plus_plus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    ++xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iterpre_plus_plus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = ++xbeg;


                    ASSERT_TRUE(xbeg == xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpost_plus_plus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg++;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpost_plus_plus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg2++;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iterpost_plus_plus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg++;


                    ASSERT_TRUE(xbeg == ++xbeg2);
                }

                // -----------
                // operator --
                // -----------
                
                TYPED_TEST(Deque_Fixture, const_iterpre_minus_minus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    --xbeg;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpre_minus_minus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    --xbeg2;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iterpre_minus_minus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = --xbeg;


                    ASSERT_TRUE(xbeg == xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpost_minus_minus1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg--;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iterpost_minus_minus2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg2--;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iterpost_minus_minus3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg--;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iterpost_minus_minus4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;


                    ASSERT_TRUE(xbeg == xbeg2--);
                }

                // -----------
                // operator +=
                // -----------

                 TYPED_TEST(Deque_Fixture, const_iter_plus_equals1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg += 1;

                    ASSERT_TRUE(xbeg == ++xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iter_plus_equals2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;


                    xbeg2 += 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iter_plus_equals3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin();
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg2 += 1;


                    ASSERT_FALSE(xbeg == xbeg2);
                }
                

                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, const_iter_minus_equals1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg -= 1;

                    ASSERT_TRUE(xbeg == --xbeg2);
                }
                
                TYPED_TEST(Deque_Fixture, const_iter_minus_equals2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg;

                    xbeg2 -= 1;

                    ASSERT_FALSE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iter_minus_equals3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;
                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+1;
                    typename deque_type::const_iterator xbeg2 = xbeg--;

                    xbeg2 -= 1;
                    ASSERT_TRUE(xbeg == xbeg2);
                }
                TYPED_TEST(Deque_Fixture, const_iter_minus_equals4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); 
                    x[0] = 1; 
                    x[1] = 2;

                    const deque_type y = x;
                    typename deque_type::const_iterator xbeg = y.begin()+5;
                    typename deque_type::const_iterator xbeg2 = y.begin()+2;
                    xbeg -= 3;

                    ASSERT_TRUE(xbeg == xbeg2);
                }


    // --------
    // my_deque
    // --------

        // ----------
        // operator =
        // ----------

        TYPED_TEST(Deque_Fixture, deque_assign1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            deque_type y(2);
            y = x;
            ASSERT_EQ(x,y);
        }
        
        TYPED_TEST(Deque_Fixture, deque_assign2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            x = x;
            ASSERT_EQ(x,x);
        }
        TYPED_TEST(Deque_Fixture, deque_assign3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            deque_type y(1);
            y = x;
            ASSERT_EQ(x,y);
        }
        TYPED_TEST(Deque_Fixture, deque_assign4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(500);
            x[0] = 1;
            x[1] = 2;
            deque_type y(1);
            y = x;
            ASSERT_EQ(x,y);
        }

        TYPED_TEST(Deque_Fixture, deque_assign5) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            deque_type y(5);
            y = x;
            ASSERT_EQ(x,y);
        }

        // -----------
        // operator []
        // -----------

        TYPED_TEST(Deque_Fixture, deque_index1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x[0],1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_index2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x[1],2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_index3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            ASSERT_FALSE(x[2] == 0);
        }
        TYPED_TEST(Deque_Fixture, const_deque_index1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            ASSERT_EQ(y[0],1);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_index2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;           
            ASSERT_EQ(y[1],2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_index3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            ASSERT_FALSE(y[2] == 0);
        }
        // --
        // at
        // --

        TYPED_TEST(Deque_Fixture, deque_at1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x.at(0),1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_at2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x.at(1),2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_at3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            ASSERT_FALSE(x.at(2) == 0);
        }
        TYPED_TEST(Deque_Fixture, deque_at4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            bool ex = false;
            try {
                    x.at(3);
            } 
            catch (std::out_of_range oor) {
            ex = true;
            }
            ASSERT_EQ(true, ex);
        }
        TYPED_TEST(Deque_Fixture, const_deque_at1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            ASSERT_EQ(y.at(0),1);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_at2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;           
            ASSERT_EQ(y.at(1),2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_at3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            ASSERT_FALSE(y.at(2) == 0);
        }
        TYPED_TEST(Deque_Fixture, const_deque_at4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            bool ex = false;
            const deque_type y = x;
            try {
                    y.at(3);
            } 
            catch (std::out_of_range oor) {
            ex = true;
            }
            ASSERT_EQ(true, ex);
        }
        // ----
        // back
        // ----

        TYPED_TEST(Deque_Fixture, deque_back1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x.back(),2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_back2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 2;
            ASSERT_EQ(x.back(),2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_back3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            ASSERT_FALSE(x.back() == 0);
        }

        TYPED_TEST(Deque_Fixture, const_deque_back1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            ASSERT_EQ(y.back(),2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_back2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            x[2] = 2;
            const deque_type y = x;           
            ASSERT_EQ(y.back(),2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_back3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            ASSERT_FALSE(y.back() == 0);
        }

        // -----
        // begin
        // -----

        TYPED_TEST(Deque_Fixture, deque_begin1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            typename deque_type::iterator xbeg = x.begin();
            ASSERT_EQ(*xbeg,1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_begin2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            typename deque_type::iterator xbeg = x.begin();
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_begin3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 0;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator xbeg = x.begin();
            ASSERT_FALSE(*xbeg == 1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_begin1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            typename deque_type::const_iterator xbeg = y.begin();
            ASSERT_EQ(*xbeg,1);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_begin2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            const deque_type y = x;   
            typename deque_type::const_iterator xbeg = y.begin();        
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_begin3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            typename deque_type::const_iterator xbeg = y.begin();
            ASSERT_FALSE(*xbeg == 0);
        }

        // -----
        // clear
        // -----

        TYPED_TEST(Deque_Fixture, deque_clear1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            x.clear();
            ASSERT_TRUE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_clear2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x[3] = 4;
            x[4] = 5;
            x.clear();
            ASSERT_TRUE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_clear3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x[3] = 4;
            x[4] = 5;
            x.clear();
            ASSERT_FALSE(!x.empty());
        }

        // -----
        // empty
        // -----

        TYPED_TEST(Deque_Fixture, deque_empty1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            ASSERT_FALSE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_empty2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x[3] = 4;
            x[4] = 5;
            ASSERT_FALSE(x.empty());
        }

        TYPED_TEST(Deque_Fixture, deque_empty3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x[3] = 4;
            x[4] = 5;
            ASSERT_TRUE(!x.empty());
        }
        TYPED_TEST(Deque_Fixture, deque_empty4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            ASSERT_TRUE(x.empty());
        }

        // ---
        // end
        // ---

        TYPED_TEST(Deque_Fixture, deque_end1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            typename deque_type::iterator xbeg = x.end()-1;
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_end2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            typename deque_type::iterator xbeg = x.end()-1;
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_end3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 0;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator xbeg = x.end()-1;
            ASSERT_FALSE(*xbeg == 1);
        }

        TYPED_TEST(Deque_Fixture, const_deque_end1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            typename deque_type::const_iterator xbeg = y.end()-1;
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_end2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            const deque_type y = x;   
            typename deque_type::const_iterator xbeg = y.end()-1;        
            ASSERT_EQ(*xbeg,2);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_end3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            typename deque_type::const_iterator xbeg = y.end()-1;
            ASSERT_FALSE(*xbeg == 0);
        }

        // -----
        // erase
        // -----

        TYPED_TEST(Deque_Fixture, deque_erase1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            typename deque_type::iterator xbeg = x.begin();
            x.erase(xbeg);
            ASSERT_EQ(x[0],2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_erase2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 2;
            x[1] = 2;
            x[2] = 2;
            typename deque_type::iterator xbeg = x.begin();
            x.erase(xbeg);
            ASSERT_EQ(x[0],2);
        }
        
        TYPED_TEST(Deque_Fixture, deque_erase3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 0;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator xbeg = x.begin();
            x.erase(xbeg);
            ASSERT_FALSE(x[0] == 0);
        }

        TYPED_TEST(Deque_Fixture, deque_erase4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 0;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator xbeg = x.end()-1;
            x.erase(xbeg);
            ASSERT_FALSE(x.size() == 3);
        }

        // -----
        // front
        // -----

        TYPED_TEST(Deque_Fixture, deque_front1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            ASSERT_EQ(x.front(),1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_front2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 2;
            ASSERT_EQ(x.front(),1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_front3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            ASSERT_FALSE(x.front() == 0);
        }

        TYPED_TEST(Deque_Fixture, const_deque_front1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            const deque_type y = x;
            ASSERT_EQ(y.front(),1);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_front2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(2);
            x[0] = 1;
            x[1] = 2;
            x[2] = 2;
            const deque_type y = x;           
            ASSERT_EQ(y.front(),1);
        }
        
        TYPED_TEST(Deque_Fixture, const_deque_front3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            const deque_type y = x;
            ASSERT_FALSE(y.front() == 0);
        }

        // ------
        // insert
        // ------

        TYPED_TEST(Deque_Fixture, deque_insert1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator it = x.begin()+1;
            x.insert(it, 9);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],1);
            ASSERT_EQ(x[1],9);
            ASSERT_EQ(x[2],2);
            ASSERT_EQ(x[3],3);
        }

        TYPED_TEST(Deque_Fixture, deque_insert2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator it = x.begin();
            x.insert(it, 9);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],9);
            ASSERT_EQ(x[1],1);
            ASSERT_EQ(x[2],2);
            ASSERT_EQ(x[3],3);
        }

        TYPED_TEST(Deque_Fixture, deque_insert3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            typename deque_type::iterator it = x.end();
            x.insert(it, 9);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0],1);
            ASSERT_EQ(x[1],2);
            ASSERT_EQ(x[2],3);
            ASSERT_EQ(x[3],9);
        }

        // --------
        // pop_back
        // --------

        TYPED_TEST(Deque_Fixture, deque_pop_back1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_back();
            ASSERT_EQ(x.size(),2);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_back2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_back();
            x.pop_back();
            ASSERT_EQ(x.size(),1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_pop_back3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_back();
            x.pop_back();
            x.pop_back();
            ASSERT_EQ(x.size(),0);
        }
        // ---------
        // pop_front
        // ---------

        TYPED_TEST(Deque_Fixture, deque_pop_front1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_front();
            ASSERT_EQ(x.size(),2);
        }

        TYPED_TEST(Deque_Fixture, deque_pop_front2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_front();
            x.pop_front();
            ASSERT_EQ(x.size(),1);
        }
        
        TYPED_TEST(Deque_Fixture, deque_pop_front3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.pop_front();
            x.pop_front();
            x.pop_front();
            ASSERT_EQ(x.size(),0);
        }

        // ---------
        // push_back
        // ---------

        TYPED_TEST(Deque_Fixture, deque_push_back1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_back(4);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[3], 4);
        }

        TYPED_TEST(Deque_Fixture, deque_push_back2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_back(5);
            x.push_back(4);
            ASSERT_EQ(x.size(),5);
            ASSERT_EQ(x[3], 5);
            ASSERT_EQ(x[4], 4);
        }
        
        TYPED_TEST(Deque_Fixture, deque_push_back3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_back(5);
            x.push_back(9);
            ASSERT_EQ(x.size(),5);
            ASSERT_EQ(x[3], 5);
            ASSERT_EQ(x[4], 9);

        }

        // ----------
        // push_front
        // ----------

        TYPED_TEST(Deque_Fixture, deque_push_front1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_front(4);
            ASSERT_EQ(x.size(),4);
            ASSERT_EQ(x[0], 4);
        }

        TYPED_TEST(Deque_Fixture, deque_push_front2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_front(5);
            x.push_front(4);
            ASSERT_EQ(x.size(),5);
            ASSERT_EQ(x[0], 4);
            ASSERT_EQ(x[1], 5);
        }
        
        TYPED_TEST(Deque_Fixture, deque_push_front3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.push_front(5);
            x.push_front(9);
            ASSERT_EQ(x.size(),5);
            ASSERT_EQ(x[0], 9);
            ASSERT_EQ(x[1], 5);

        }

        // ------
        // resize
        // ------

        TYPED_TEST(Deque_Fixture, deque_resize1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.resize(3);
            ASSERT_EQ(x.size(), 3);
        }
        
        TYPED_TEST(Deque_Fixture, deque_resize2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(500);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.resize(2);
            ASSERT_EQ(x.size(), 2);
        }
        TYPED_TEST(Deque_Fixture, deque_resize3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.resize(10);
            ASSERT_EQ(x.size(), 10);
        }

        TYPED_TEST(Deque_Fixture, deque_resize4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.resize(2);
            ASSERT_EQ(x.size(), 2);
        }

        TYPED_TEST(Deque_Fixture, deque_resize5) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            x.resize(6);
            ASSERT_EQ(x.size(), 6);
        }
        // ----
        // size
        // ----

        TYPED_TEST(Deque_Fixture, deque_size1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1);
            ASSERT_EQ(x.size(), 1);
        }

        TYPED_TEST(Deque_Fixture, deque_size2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(10);
            ASSERT_EQ(x.size(), 10);
        }

        TYPED_TEST(Deque_Fixture, deque_size3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            ASSERT_EQ(x.size(), 0);
        }

        TYPED_TEST(Deque_Fixture, deque_size4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(5);
            deque_type y = x;
            ASSERT_EQ(y.size(), 5);
        }


        // ----
        // swap
        // ----

        TYPED_TEST(Deque_Fixture, deque_swap1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 1;
            x[1] = 2;
            x[2] = 3;
            deque_type y;
            y.swap(x);
            ASSERT_EQ(y[0], 1);
            ASSERT_EQ(y[1], 2);
        }

        TYPED_TEST(Deque_Fixture, deque_swap2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 5;
            x[1] = 4;
            x[2] = 3;
            deque_type y;
            y.swap(x);
            ASSERT_EQ(y[0], 5);
            ASSERT_EQ(y[1], 4);
        }
        TYPED_TEST(Deque_Fixture, deque_swap3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3);
            x[0] = 5;
            x[1] = 4;
            x[2] = 3;
            deque_type y(3);
            y[0] = 1;
            y[1] = 2;
            y[3] = 3;
            y.swap(x);
            ASSERT_EQ(x[0], 1);
            ASSERT_EQ(x[1], 2);
        }