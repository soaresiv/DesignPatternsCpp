# SOLID Design Principles: C++

The SOLID ideas are

- The single-responsibility principle: Every class should have only one responsibility.
- The open–closed principle: "Software entities, should be open for extension, but closed for modification.

## Single Responsibility Principle

**Single responsibility principle**  basically states that a class should have a single reason to change. A class should have a primary responsibility and it should not take up other responsibilities.

So the `Journal` class contains a title and a number of entries. We make a constructor where sets the title, and in addition to that, we want to add the functionality for adding entries, and get the entries numbered.

So if we want to implement a persistence functionality to save the journal in a file, the wrong way to go, is to add the functionality right inside the journal.

### **The problem with this approach**

If you're working on a dozen other domains objects and you give every one of them a function called `save`, then when you want to change it, you would have to change it in all classes that are actually using it.

Essentially the Journal should take care of the journal entries and the journal title. But if you want to persist it on a file, you need to have a separated class to save the Journal.

### Example file:

- `Journal.hpp`
- `PersistenceMananger.hpp`

## Open and Close principle

**Open and Close principle** means that your class should be open to be extend but close to modifications. So, your class should allow to be extended(e.g by inheritance) and without modifying its source code. 

In our example code we created a filter to match some items with a given specification.The specification is going to be very generic and is going to inherit from a specification of type T. Doing this, you would never require yourself to go back into the filter interface to change a the filter specification.

### Example file:

- `Product.hpp`
- `ProductFilter.hpp`
