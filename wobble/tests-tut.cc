#include <wobble/tests.h>

using namespace std;
using namespace wobble;
using namespace wobble::tests;

namespace {

class Tests : public TestCase
{
    using TestCase::TestCase;

    void register_tests() override
    {
        add_method("bools", []() {
            wassert(actual(true).istrue());
            wassert(actual(false).isfalse());
        });

        add_method("numbers", []() {
            wassert(actual(1).istrue());
            wassert(actual(0).isfalse());
            wassert(actual(1) == 1);
            wassert(actual(1) != 2);
            wassert(actual(1) < 2);
            wassert(actual(1) <= 1);
            wassert(actual(1) <= 2);
            wassert(actual(1) > 0);
            wassert(actual(1) >= 1);
            wassert(actual(1) >= 0);
        });

        add_method("pointers", []() {
            wassert(actual(nullptr).isfalse());
            wassert(actual((void*)"foo").istrue());
        });

        add_method("cstrings", []() {
            wassert(actual(nullptr).isfalse());
            wassert(actual("").istrue());
            wassert(actual("foo").istrue());
            wassert(actual("foo") == "foo");
            wassert(actual("foo") != "bar");
            wassert(actual("bar") < "foo");
            wassert(actual("bar") <= "bar");
            wassert(actual("bar") <= "foo");
            wassert(actual("foo") > "bar");
            wassert(actual("foo") >= "foo");
            wassert(actual("foo") >= "bar");
            wassert(actual("foo").startswith("fo"));
            wassert(actual("foo").endswith("oo"));
            wassert(actual("foo").contains("o"));
        });

        add_method("stdstrings", []() {
            wassert(actual(string("foo")) == string("foo"));
            wassert(actual(string("foo")) != string("bar"));
            wassert(actual(string("bar")) < string("foo"));
            wassert(actual(string("bar")) <= string("bar"));
            wassert(actual(string("bar")) <= string("foo"));
            wassert(actual(string("foo")) > string("bar"));
            wassert(actual(string("foo")) >= string("foo"));
            wassert(actual(string("foo")) >= string("bar"));
            wassert(actual(string("foo")).startswith("fo"));
            wassert(actual(string("foo")).endswith("oo"));
            wassert(actual(string("foo")).contains("o"));
        });

        add_method("strings", []() {
            wassert(actual(string("foo")) == "foo");
            wassert(actual(string("foo")) != "bar");
            wassert(actual(string("bar")) < "foo");
            wassert(actual(string("bar")) <= "bar");
            wassert(actual(string("bar")) <= "foo");
            wassert(actual(string("foo")) > "bar");
            wassert(actual(string("foo")) >= "foo");
            wassert(actual(string("foo")) >= "bar");

            wassert(actual("foo") == string("foo"));
            wassert(actual("foo") != string("bar"));
            wassert(actual("bar") < string("foo"));
            wassert(actual("bar") <= string("bar"));
            wassert(actual("bar") <= string("foo"));
            wassert(actual("foo") > string("bar"));
            wassert(actual("foo") >= string("foo"));
            wassert(actual("foo") >= string("bar"));
        });

        auto parametric = [](int val) {
            wassert(actual(val) != 0);
        };
        add_method("parametric1", parametric, 1);
        add_method("parametric2", parametric, 2);
    }
} tests("tests");

}

