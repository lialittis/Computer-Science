# Calculator

## Concept & Requirement

The end target of the three questions is to implement a calculator which has these
functions : +, -, *, /, parentheses and spaces

The parentheses must be caluculated first, and then * and / must be calculated second, and 
+ and - must be calculated last.

{ open brace ; open curly

} close brace ; close curly

( open parenthesis ; open paren

) close parenthesis ; close paren

() brakets ; parentheses

[ open bracket

] close bracket

[] square brackets

## pre-knowledge

if only single number : how to check if it is a number
1. char > '0' due to +-*/ all has smaller asscii code
2. '0' <= char && char <= '9'

- String to Integer :
  e.g. : "123232" -> 123232
  for each position of the char, minus '0' and then plus 10 * last num

if only have '+' and '-' : use a stack is good enough(or deque), push num or - num when meet a new operator char or at the end of the string, when finished, sum them up (by poping in order).

if only have + - * / : use a stack, similar with above, but for * and /, we need to pop up the top value and do the calculation then push it back.

if have + - * / and ( ) : when meet (, we open a new stack, the do the calculation, push it back to the last stack when meet ). [stack + recursive]

## Basic Calculator 224

Implement a basic calculator to evaluate a simple expression string, which contains ( ,), +, -, non-negative integers and empty spaces

### implementation

1. iterative + pure stack
quick and little space

2. stack with recursive help
a little bit slow and much more space
