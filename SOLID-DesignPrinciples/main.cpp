#include <Journal.hpp>
#include <PersistenceManager.hpp>

int main()
{
  Journal journal{ "Dear Diary" };
  journal.add("I ate a bug");
  journal.add("I cried today");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");

  return 0;
}
