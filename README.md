# Summary
This project was my first experience working with sorting algorithms. The program takes as arguments a set of unique integers, and sorts them using only two stacks, using only push_swap instructions, as efficiently as possible (in terms of number of moves, not in terms of computational speed).

## Allowed operations:
* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

## Goals
The goal was to fully sort the integers provided, under the following limits:
* 5 integers: 12
* 100 integers: 700
* 500 integers: 5500

## Approach
I decided that it would be easier to complete this project if I was able to use vectors, so it would be easier to insert and move values than it would be with a standard array. Since vectors are not available by default in C, I followed this very helpful tutorial (https://github.com/juliuskoskela/c-vec) and added the relevant functions to my libft library.

For small sets, the logic is very straightforward and largely hardcoded. For larger sets (>5 integers), we use an insertion sort model that pushes integers into reverse order in stack b, until there are three remaining in a. It then pushes all the b stack back into a in order.

The biggest challenge was choosing the integers with the lowest cost to move to the appropriate spot in stack b, considering that double moves are more economical (rr and rrr operations). My project also discounts the cost of moving one integer if the following integer would also be able to be immediately inserted. This step improved efficiency a great deal.

## Example
```
./push_swap 5 4 6 7 2 1 3
pb
pb
pb
rrb
sb
pb
sa
rra
pa
sa
pa
sa
pa
sa
pa
sa
rra
rra
```
