# push_swap

### Description:

This project is about sorting data. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to
manipulate both stacks. The goal is to write a C program that calculates and displays the shortest sequence of instructions needed to sort the given integers.

### The rules:
You have 2 stacks named a and b.
- At the beginning:
  - The stack a contains a random number of unique negative and/or positive integers.
  - The stack b is empty.
- The goal is to sort the numbers in stack a in ascending order. To achieve this, you have the following operations at your disposal:
  - sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
  - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
  - ss : sa and sb at the same time.
  - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - rr : ra and rb at the same time.
  - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  - rrr : rra and rrb at the same time.
 
### Learning process:

Key things learned from this project:

- Sorting algorithms
- Improved understanding of linked lists
- Organizing a somewhat complex project

The first challenge for this project was deciding which sorting algorithm to use. I read a few online articles, 
including [this one](https://www.geeksforgeeks.org/dsa/sorting-algorithms/), which classifies algorithms into comparison-based and non comparison-based types.
The latter type seemed compelling given the project requirements. However, those same requirements make this project unique in the sense that Big O is not per se 
a useful measure of efficiency. Shortly after, I learned about the Mechanical Turk
which I decided to use because of its guaranteed effectiveness. The algoritm's logic can be found in 
[this article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) written by its creator. The concept is quite simple: First push (i.e., move) members of 
stack A into stack B in descending order until only 3 remain in stack A. Then push them back to stack A in ascending order. 
In order to achieve this, for each member of stack A calculate the cost (i.e., the number of moves) to reach the top of the stack, 
plus the cost of its match in B (i.e., the closest smaller element in B, or if A were to become the smallest number in B, then the largest number in B).
After calculating the cost of each member in A, choose the one with the lowest cost, and move A and its match in B to the top using the available set of instructions. 
Then push A to B. To push B to A calculating the cost is no longer necessary. Its is only necesary to check which number is the closest higher than B. 
A more detailed description can be found in the article.

This implementation of the Mechanical Turk is able to,
  - Sort 3 random numbers in fewer than 3 operations
  - Sort 5 random numbers in less than 11 operations
  - Sort 100 random numbers in fewer than 700 operations.
  - Sort 500 random numbers in no more than 5500 operations.

### Testing:

Testing can be done using the [checker](/checker_linux) in this repository. Running something similar to `ARG=($(shuf -i1-800 -n100)); ./push_swap $ARG | ./checker_linux $ARG`

