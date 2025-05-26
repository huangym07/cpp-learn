#ifndef __TEXTQUERYLIB_H__
#define __TEXTQUERYLIB_H__

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>


class QueryResult;
class TextQuery {
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &is);
    QueryResult query(const std::string &word) const;

  private:
    std::shared_ptr<std::vector<std::string>> file_;
    std::map<std::string, std::shared_ptr<std::set<line_no>>>
        word_to_lines_map_;
};

class QueryResult {
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

  public:
    using line_no = TextQuery::line_no;
    QueryResult(const std::string &word,
                std::shared_ptr<std::vector<std::string>> file,
                std::shared_ptr<std::set<line_no>> lines)
        : word_(word), file_(file), lines_(lines) {}

  private:
    std::string word_;
    std::shared_ptr<std::vector<std::string>> file_;
    std::shared_ptr<std::set<line_no>> lines_;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);

#endif