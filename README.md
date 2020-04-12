# push_swap

The game is composed of 2 stacks named **A** and **B**.  
To start with:  
  **A** contains a random number of either positive or negative numbers withoutany duplicates.  
  **B** is empty.  
  
  ![Image alt](https://github.com/arptra/push_swap/blob/master/pic/ps_0.png)

The goal is to sort in ascending order numbers into stack **A**.  
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
