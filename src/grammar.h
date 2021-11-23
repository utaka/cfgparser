#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "type.h"
#include "utils.h"

class Rule {
   private:
   public:
    const Pos X;
    const Pos Y;
    const Pos Z;

    Rule(Pos x, Pos y, Pos z) : X(x), Y(y), Z(z) {}
    bool operator<(const Rule& other) const;
};

std::ostream& operator<<(std::ostream& os, const Rule& other);

class Grammar {
   private:
    bool load_rules(const std::string& filename);

   public:
    const std::set<Pos> terminals;
    const std::set<Pos> nonterminals;
    const Pos start;
    std::set<Rule> rules;

    Grammar(const std::string& filename);
    bool has_rule(Pos X, Pos Y, Pos Z) const;
};