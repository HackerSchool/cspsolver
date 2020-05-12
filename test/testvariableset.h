#ifndef TEST_VARIABLE_SET_H
#define TEST_VARIABLE_SET_H

// CppUnit
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../src/variableset.h"
#include <string>

class TestVariableSet : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TestVariableSet);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST_SUITE_END();

private:
    
    
public:
    TestVariableSet ();
    
    // init and clean up
    void setUp ();
    void tearDown ();

    // tests
    void test1 ();
};


#endif