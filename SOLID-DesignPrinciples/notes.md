# SOLID Design Principles: C++

## Single Responsibility Principle

**Single responsibility principle**  basically states that a class should have a single reason to change. A class should have a primary responsibility and it should not take up other responsibilities.

So the `Journal` class contains a title and a number of entries. We make a constructor where sets the title, and in addition to that, we want to add the functionality for adding entries, and get the entries numbered.

So if we want to implement a persistence functionality to save the journal in a file, the wrong way to go, is to add the functionality right inside the journal.

### **The problem with this approach**

If you're working on a dozen other domains objects and you give every one of them a function called `save`, then when you want to change it, you would have to change it in all classes that are actually using it.

Essentially the Journal should take care of the journal entries and the journal title. But if you want to persist it on a file, you need to have a separated class to save the Journal.

## Example file:

- `Journal.hpp`
- `PersistenceMananger.hpp`
