# 1. Factory Method

It provides an **interface** for creating objects in a superclass, but allows subclasses
to **alter the type of objects** that will be created.

## Structure

The **Product** declares the interface, which is common to all objects that can be produced
by the creator and its subclasses.

**Concrete Products** are different implementations of the product interface.

The **Creator** class declares the factory method that returns new product objects. It is 
important that the return type of this method matches the *product* interface.

You can declare the factory method as *abstract* to force all subclasses to implement their
own versions of the method. As an alternative, the *base* factory method can return some
default product type.

## Applicability

**Use the Factory Method when you don't know beforehand the exact types and dependencies 
of the objects your code should work with.**

The Factory Method separates product construction code from the code that actually uses 
the product. => easier to extend the product construction code independently. (e.g. to
add a new product type, we only need a new creator)

**Use the Factory Method when you want to provide users of your library or framework
with a way to extend its internal components.**

**Use the Factory Method when you want to save resources by reusing existing objects instead
of rebuilding them each time.**

a regular method capable of creating new objects as well as reusing existing ones.


## How to implement

1. Make all products follow the same interface. This interface should declare methods that
make sense in every product.

2. Add an empty factory method inside the creator class. The return type of the method should
match the common product interface.

3. In the creator's code, find all references to product constructors, replace them with
calls to the factory method.

4. Create a set of creator subclasses for each type of product.

5. If there are too many product types, reuse the control parameter from the base class in
subclasses.

6. If the base factory method has become empty, you can make it abstract.

## Pros and Cons

### Pros

- Avoid tight coupling between the creator and the concrete products
- Single Responsiblity Principle
- Open/Close Principle : new types of products without breaking existing client code

### Cons

- The code may becom more complicated since you need to introduce a lot of new subclasses.
The best case scenario is when you're introducing the pattern into an existing hierarchy of
creator classes.

## Relations with Other Patterns

- Many design start by using **Factory Method**(less complicated and more customizable via
subclasses) and evolve toward **Abstract Fractory**, **Prototype**, or **Builder**.

- **Abstract Factory** classes are often based on a set of **Factory Method**

- **Prototype** isn't based on inheritance, so it doesn't have its drawbacks. On the other 
hand, Prototype requires a complicated initialization of the cloned object. Factory Method
is based on inheritance but doesn't require an initialization step.

# Abstract Factory

It lets you produce **families of related objects without specifying their concrete
classes**.

## Motivation

You have a family of related products to produce.

The client doesn't want to be aware of the factory's class.

## Structure

1. **Abstract Products** declare interfaces for a set of distinct but related products which
make up a product family.

2. **Concrete Products** are various implementations of abstract products, grouped by variants.

3. The **Abstract Factory** interface declares a set of methods for creating each of abstract
products.

4. **Concrete Factories** implement creation methods of the abstract factory. Each concrete
factory corresponds to a specific variant of products and creates only those product variants.

## Applicability

**Use the Abstract Factory when you code needs to work with various families of related
product, but you don't want it to depend on the concrete clases of those products , they might
be unknow beforehand or you simply want to allow for future extensibility**

## How to implement

1. Map out a matrix of distinct product types versus variants of these products.

2. Declare abstract product interfaces for all product types.

3. Declare the abstract factory interface with a set of creation methods of all abstract products.

4. Implement a set of concrete factory classes, one for each product variant.

5. Create factory initialization code somewhere in the code. It should instantiate one of the
conrete factory classes, depending on the configuration or environment.

6. Replace product constructors with calls to the appropriate creation method on the factory
object.

## Pros and Cons

### Pros

- You can be sure that the products you're getting from a factory are compatible with eahc other

- Avoid tight coupling between concrete products and client code

- Single Responsibility Principle. (extract product creation code into one place)

- Open/Closed Principle. (introduce new variants of products, without breaking existing client 
code)

### Cons

- The code may become more complicated than it should be, since a lot of new interfaces and
classes are introduced along with the pattern.
- New type of products ??







# Builder

It lets you construct **complex objects step by step**. The pattern allows you to produce
**different types and representations of an object** using the same construction code.


# Prototype

It lets you copy existing objects without making your code dependent on their classes.


# Singleton

It lets you ensure that a class has only one instance, while providing a global access
point to this instance.



