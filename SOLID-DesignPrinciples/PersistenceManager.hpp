#include <Journal.hpp>
#include <iostream>
#include <fstream>

#pragma once

//TODO: PersistenceManager should handle any printable type.
struct PersistenceManager
{
  static void save(const Journal &j, const std::string &filename)
  {
    std::ofstream ofs(filename);

    for (auto &s : j.entries) {
      ofs << s << std::endl;
    }
  }
};
