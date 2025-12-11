# Push_swap - T0DO List

# 📋 T0DO - Not Started


## Double circular lists
  - [!] Implement append_node() to create and add nodes to circular list
    - [ ] Single node: node->prev = node, node->next = node
    - [ ] Multiple nodes: last->next = first, first->prev = last
    - [ ] Add function prototype to push_swap.h

## Sorting Algorithms
  - [ ] Implement Turk Algorithm for large stacks:
    - [ ] init_nodes_a() - Initialize nodes in stack A (set indices, etc.)
    - [ ] init_nodes_b() - Find optimal targets in stack A for nodes in B
    - [ ] current_index() - Update position indices
    - [ ] set_cheapest() - Calculate push cost and mark cheapest node
    - [ ] Main sorting loop using Turk Algorithm

## Testing & Validation
  - [ ] Test with edge cases (empty stack, single element, duplicates)
  - [ ] Benchmark performance (100 numbers < 700 ops, 500 numbers < 5500 ops)
  - [ ] Test with checker program
  - [ ] Memory leak testing with valgrind

  ---

# 🚧 In Progress

## Algorithms
  - [ ] Implement sort_three() for 3-element stacks
## Position Management
  - [ ] Fix pos_change() inP push.c
  - [ ] Update position indices after each operation

  ---


# 🐛 Known Bugs

## BUG: pos_change() infinite loop (push.c:64)
  - [!] Loop condition `node->prev != *stack` never becomes true
  - [ ] Why: In circular list, going backwards from *stack loops forever,
  	never hits *stack again
  - [ ] Fix: Use counter or track first_node differently

## BUG: ft_listcount() off-by-one (ft_list_operations.c:34)
  - [ ] Stops at `node != first_node->prev` so misses last node
  - [ ] Why: Loop exits when reaching last node but doesn't count it
  - [ ] Fix: Change condition to `node->next != first_node`
          or count before loop check


## BUG: free_stack() doesn't handle circular lists correctly (ft_list_operations.c:48)
  - [ ] Uses `while (current)` but in circular list,
        current never becomes NULL
  - [ ] Why: In circular list, last->next points back to first, infinite loop
	- [ ] Fix: Break circle before freeing or use different termination condition

## BUG: is_duplicate() infinite loop with circular lists (push_swap.c:41)
  - [ ] Uses `while (a)` but in circular list, a never becomes NULL
  - [ ] Why: In circular list, a->next always points to something, never NULL
  - [ ] Fix: Track first node and stop when node->next == first_node

## BUG: push() crashes if dest is NULL (push.c:31)
  - [ ] No NULL check before dereferencing dest
  - [ ] Why: Assumes both stacks always have elements
  - [ ] Fix: Add NULL check at start of function

##BUG: process_arg() missing exit (push_swap.c:76-79)
  - [ ] Prints "Error\n" but function continues executing
  - [ ] Why: No exit(1) call after freeing
  - [ ] Fix: Add exit(1) after free_stack()

  ---

# ✅ Completed

## Stack Operations
  - [X] Implement swap operations (sa, sb, ss)
  - [X] Implement push operations (pa, pb)
  - [X] Implement rotate operations (ra, rb, rr)
  - [X] Implement reverse rotate operations (rra, rrb, rrr)

## Error Handling & Memory Management
  - [X] Check for duplicate integers in input
  - [X] Validate input syntax (non-numeric, overflows/underflows)

## Argument Parsing
  - [X] Parse command-line arguments (single or multiple strings)
  - [X] Handle space-separated integers
  - [X] Validate integer range (INT_MIN to INT_MAX)

