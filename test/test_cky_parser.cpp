#include "test.h"

void cout_test();

int main() {
    CkyParser p1(Config{dict : "./asset/dict1", rule : "./asset/rule1"});
    assert(p1.parse("the child runs quickly to the large house").ok);
    assert(!p1.parse("the runs").ok);
    assert(!p1.parse("").ok);

    CkyParser p2(Config{dict : "./asset/dict2", rule : "./asset/rule2"});
    assert(p2.parse("I saw a girl with a telescope").ok);
    assert(!p2.parse("I saw saw").ok);
    assert(!p2.parse("").ok);

    // cout_test();

    return 0;
}

void cout_test() {
    Entry e(Pos::NOUN, std::make_pair(-1, -1), std::make_pair(-1, -1));
    std::cout << e << '\n';

    Cell c(std::vector<Entry>{
        Entry(Pos::NOUN, std::make_pair(1, 1), std::make_pair(1, 1)),
        Entry(Pos::VERB, std::make_pair(2, 2), std::make_pair(2, 2)),
    });
    std::cout << c << '\n';
}
