# push_swap
The project consists of two programs:  
1. The first `./push_swap` sorts the stack and outputs a sequential set of commands to the standard output stream of the required ones.  
2. The second `./checker` checks that the stack is sorted ascending  
  
### The game is composed of 2 stacks named **A** and **B**.  
To start with:  
  **A** contains a random number of either positive or negative numbers without any duplicates.  
  **B** is empty.  
  
  ![Image alt](https://github.com/arptra/push_swap/blob/master/pic/ps_0.png)

### The goal is to sort in ascending order numbers into stack **A**.  
To do this you have the following operations at your disposal:  
**sa** :swap **A**-swap the first 2 elements at the top of stack **A**. Do nothing if thereis only one or no elements.  
**sb** :swap **B**-swap the first 2 elements at the top of stack **B**. Do nothing if thereis only one or no elements.  
**ss** :**sa** and **sb** at the same time.  
**pa** :push **A**-take the first element at the top of **B** and put it at the top of **A**. Donothing if **B** is empty.  
**pb** :push **B**-take the first element at the top of **A** and put it at the top of **B**. Donothing if **A** is empty.  
**ra** :rotate **A**-shift up all elements of stack **A** by 1. The first element becomesthe last one.  
**rb** :rotate **B**-shift up all elements of stack **B** by 1. The first element becomesthe last one.  
**rr** :**ra** and **rb** at the same time.  
**rra** :reverse rotate **A**-shift down all elements of stack **A** by 1. The last elementbecomes the first one.  
**rrb** :reverse rotate **B**-shift down all elements of stack **B** by 1. The last elementbecomes the first one.  
**rrr** :**rra** and **rrb** at the same time.  

# Run push_swap  
  
This will display the necessary instructions to sort the stack.  
```
./push_swap 1 5 4 3 2
```
To check whether the stack is really sorted, you can run the `./checker` program, as follows  
```
./push_swap 1 5 4 3 2  | ./checker 1 5 4 3 2
```
If the stack is sorted then the output will be `OK`; if not, then `KO`  
  
For debug mode ypu can use `-v` flag in `./checker`, as follows  
```
./checker -v 1 5 4 3 2
```
In this mode, you can sequentially execute the instructions given above and keep track of the current state of the stack  
![Alt Text](https://github.com/arptra/push_swap/blob/master/pic/stack_sort.gif)  
