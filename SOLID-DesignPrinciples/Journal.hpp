
#include <string>
#include <vector>

#pragma once

struct Journal
{
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string &title) : title{ title }
  {
  }

  void add(const std::string &entry)
  {
    static int count = 1;
    entries.push_back(std::to_string(++count) + ": " + entry);
  }

  //TODO: Implement to_string method.
};
