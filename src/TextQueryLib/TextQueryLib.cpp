#include "TextQueryLib.h"
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream &is) : file_(new std::vector<std::string>) {
    std::string text;
    while (getline(is, text)) {
#ifndef NDEBUG
        std::cout << text << std::endl;
#endif
        file_->push_back(text);
        line_no n = file_->size() - 1;

        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = word_to_lines_map_[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> no_data(new std::set<line_no>);
    auto loc = word_to_lines_map_.find(word);
    if (loc == word_to_lines_map_.end())
        return QueryResult(word, file_, no_data);
    return QueryResult(word, file_, loc->second);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.word_ << " occurs " << qr.lines_->size()
       << (qr.lines_->size() > 1 ? " times" : " time") << std::endl;

    for (auto line : *qr.lines_) {
        std::cout << "(line " << line + 1 << ") " << *(qr.file_->begin() + line)
                  << std::endl;
    }

    return os;
}