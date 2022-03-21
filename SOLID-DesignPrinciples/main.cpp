//Single responsibility principle
#include <Journal.hpp>
#include <PersistenceManager.hpp>

//Open and Close principle
#include <Product.hpp>
#include <ProductFilter.hpp>

#include <vector>

int main()
{
  //Single responsibility principle
  Journal journal{ "Dear Diary" };
  journal.add("I ate a bug");
  journal.add("I cried today");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");


  //Open and Close principle
  Product apple{ "Apple", Color::green, Size::small };
  Product tree{ "Tree", Color::green, Size::large };
  Product louko{ "Louko", Color::green, Size::large };
  Product house{ "House", Color::blue, Size::large };

  const std::vector<Product *> all{ &apple, &tree, &house, &louko };

  ProductFilter prodfilter;
  ColorSpecification green(Color::green);

  const auto green_things = prodfilter.filter(all, green);

  for (auto &x : green_things)
    std::cout << x->name << " is green\n";

  //Example using AndSpecification to get green and large items
  SizeSpecification large(Size::large);
  AndSpecification<Product> green_and_large(green, large);

  const auto big_green_things = prodfilter.filter(all, green_and_large);

  for (auto &x : big_green_things)
    std::cout << x->name << " is green and large\n";

  return 0;
}
