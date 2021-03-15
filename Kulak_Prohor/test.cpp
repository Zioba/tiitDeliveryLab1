#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"
#include <vector>
#include "set.h"



TEST_CASE("vstavka element v set") {
    std::vector<int> a{1, 2, 3};
    std::vector<int> e{1, 2, 3,4};
    int b=4;
    insertv(a,b);
    CHECK(a == e);
}

TEST_CASE("union set") {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{7, 8, 9, 10};
    std::vector<int> e{1, 2, 3};
    std::vector<int> c;

    unionSet(a,b,c);
    CHECK(a == e);
}

TEST_CASE("find element two set") {
    std::vector<int> a = { 1, 2, 3 };
    std::vector<int> b = { 7, 8, 9, 10 };
    std::vector<int> c;
    linear_search(a, b, 10,c);
    CHECK(  c == b);
}

TEST_CASE("vstavka element v set") {

    std::vector<int> a{1, 2, 3};
    std::vector<int> e{1, 2, 3};
    std::vector<int> c;
    int b=4;
    insertv(a,b);
    CHECK_FALSE(a == e);
}
TEST_CASE("vstavka element v set2"){
    std::vector<int> a{1, 2, 3};
    std::vector<int> e{1, 2, 3};
    int b=3;
    insertv(a,b);
    CHECK(a == e);
}