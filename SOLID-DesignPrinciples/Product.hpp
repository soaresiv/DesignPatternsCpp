#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

enum class Color { red,
  green,
  blue };

enum class Size { small,
  medium,
  large };

struct Product
{
  std::string name;
  Color color;
  Size size;
};

#endif
