#include "testvariableset.h"
#include "../src/errormessage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestVariableSet);

TestVariableSet::TestVariableSet () {

}
    
void TestVariableSet::setUp () {

}

void TestVariableSet::tearDown () {

}

void TestVariableSet::test1 () {
    // given a variable set and two variables
    VariableSet variableSet;
    Variable variable1 (nullptr, nullptr, "id1");
    Variable variable2 (nullptr, nullptr, "id2");

    // when add two variables
    variableSet.add(&variable1);
    variableSet.add(&variable2);

    // then the set has two variables
    CPPUNIT_ASSERT_EQUAL(2, variableSet.count());

    // and the ids are setted
    CPPUNIT_ASSERT_EQUAL(0, variable1.getId());
    CPPUNIT_ASSERT_EQUAL(1, variable2.getId());

    // and the names too
    CPPUNIT_ASSERT_EQUAL(std::string("id1"), variable1.name());
    CPPUNIT_ASSERT_EQUAL(std::string("id2"), variable2.name());

    // search
    CPPUNIT_ASSERT_EQUAL(0, variableSet.searchId("id1"));
    CPPUNIT_ASSERT_EQUAL(1, variableSet.searchId("id2"));
}

void TestVariableSet::test2 () {
    // given a variable set and two variables
    VariableSet variableSet;
    Variable variable1 (nullptr, nullptr, "id1");
    Variable variable2 (nullptr, nullptr, "id2");
    variableSet.add(&variable1);
    variableSet.add(&variable2);

    // search not found id
    try { 
        variableSet.searchId("id3"); 
    } catch (std::string s) { 
        CPPUNIT_ASSERT_EQUAL(s, EM_ID_NOT_FOUND);
    }
}


void TestVariableSet::test3 () {
    // given a variable set and two variables
    VariableSet variableSet;
    Variable variable1 (nullptr, nullptr, "id1");
    Variable variable2 (nullptr, nullptr, "id2");
    variableSet.add(&variable1);
    variableSet.add(&variable2);

    // search not found id
    try { 
        variableSet.get(-1); 
    } catch (std::string s) { 
        CPPUNIT_ASSERT_EQUAL(s, EM_ID_OUT_OF_BOUNDS);
        return;
    }

    CPPUNIT_FAIL("Exception not thrown");
}

void TestVariableSet::test4 () {
    // given a variable set and two variables
    VariableSet variableSet;
    Variable variable1 (nullptr, nullptr, "id1");
    Variable variable2 (nullptr, nullptr, "id2");
    variableSet.add(&variable1);
    variableSet.add(&variable2);

    // search not found id
    try { 
        variableSet.get(2); 
    } catch (std::string s) { 
        CPPUNIT_ASSERT_EQUAL(s, EM_ID_OUT_OF_BOUNDS);
        return;
    }

    CPPUNIT_FAIL("Exception not thrown");
}