

#ifndef PRODUCTFILTER_HPP
#define PRODUCTFILTER_HPP

#include <Product.hpp>
#include <vector>

namespace Filters {

template<typename Type>
struct SpecificationInterface
{
  virtual ~SpecificationInterface() = default;
  virtual bool is_satisfied(const Type *item) const = 0;
};

template<typename Type>
struct FilterInterface
{
  virtual std::vector<Type *> filter(const std::vector<Type *> items, const SpecificationInterface<Type> &spec) = 0;
};

}// namespace Filters

struct ProductFilter : Filters::FilterInterface<Product>
{
  std::vector<Product *> filter(const std::vector<Product *> items, const Filters::SpecificationInterface<Product> &spec) override
  {
    std::vector<Product *> result;
    for (const auto &p : items)
      if (spec.is_satisfied(p))
        result.push_back(p);
    return result;
  }
};

struct ColorSpecification : Filters::SpecificationInterface<Product>
{
  Color color;

  explicit ColorSpecification(const Color color) : color(color) {}

  bool is_satisfied(const Product *item) const override
  {
    return item->color == color;
  }
};

struct SizeSpecification : Filters::SpecificationInterface<Product>
{
  Size size;

  explicit SizeSpecification(const Size size) : size{ size }
  {
  }

  bool is_satisfied(const Product *item) const override
  {
    return item->size == size;
  }
};

/**
 * Create an AND filter type
 */

template<typename T>
struct AndSpecification : Filters::SpecificationInterface<T>
{
  const Filters::SpecificationInterface<T> &first;
  const Filters::SpecificationInterface<T> &second;

  AndSpecification(const Filters::SpecificationInterface<T> &first, const Filters::SpecificationInterface<T> &second)
    : first(first), second(second) {}

  bool is_satisfied(const T *item) const override
  {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

#endif
