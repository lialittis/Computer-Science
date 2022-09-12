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
- Open/Closed Principle : new types of products without breaking existing client code

### Cons

- The code may become more complicated since you need to introduce a lot of new subclasses.
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

It lets you produce **families of related objects without specifying their concrete classes**.

## Motivation

You have families of related products to produce.

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

- You can be sure that the products you're getting from a factory are compatible with each other

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


## Motivation

You want to build a complex object that requires laborious, step-by-setp initialization of
many fields and nested objects.

Possible Solutions :
- create a set of subclasses to cover all combinations of the parameters
- or create a giant constructor right in the base class with all possible parameters

Good Solution:
- extract the object construction code out of its own class and move it to separate objects

To create an object, you execute a series of steps on a **builder** object. Some of the
construction steps might require different implementation when you need to build various
representations of the product. In this case, you can create several different builder 
classes that implement the same set of building steps, but in a different manner.

To go further, you can extract a series of calls to the builder steps you use to construct
a product into a seperate class called **director**.

## Structure

1. The **Builder** interface declares product construction steps that are common to all
types of builders.

2. **Concrete Builders** provide different implementations of the construction steps.

3. **Products** are resulting objects.(constructed by different builders, don't have to
belong to the same class hierarchy or interface)

4. The **Director** class defines the order in which to call construction steps, so you can
create and reuse specific configurations of products.

5. The **Client** must associate one of the builder objects with the director.

## Applicability

**Use the Builder pattern to get rid of a "telescoping constructor"**

**Use the Builder pattern when you want your code to be able to create different
representations of some products (for example, stone and wooden houses).**

**Use the Builder to construct Composite trees or other complex objects**


## Pros and Cons

### Pros

- construct objects step-by-step, defer construction steps or run steps recursively
- reuse the same construction code when building various representations of products
- Single Responsibility Principle. (isolate complex construction code from the business
logic of the product)

### Cons

The overall complexity of the code increases since the pattern requires creating multiple
new classes.

# Prototype

It lets you copy existing objects without making your code dependent on their classes.

## Motivation

You have an object, you want to create an exact copy of it.

Solution:

The pattern declares a common interface for all objects that support cloning. This interface
lets you clone an object without coupling your code to the class of that object.

An object that supports cloning is called a *prototype*. When your objects have dozens of 
fields and hundreds of possible configurations, cloning them might serve as an alternative to
subclassing.

Here’s how it works: you create a set of objects, configured in various ways. When you need an
object like the one you’ve configured, you just clone a prototype instead of constructing a new 
object from scratch.

## Structure

### Basic Implementation


### Prototype registry implementation

# Singleton

It lets you ensure that a class has only one instance, while providing a global access
point to this instance.

## Motivation

The **Singleton pattern** solves two problems at the same time, violating the *Single Responsibility
Principle*:

1. Ensure that a class has just a single instance

2. Provide a global access point to that instance

Solution:
- make the default constructor private, to prevent other objects from using the new operator
with the Singleton class.
- create a static creation method that acts as a constructor.

