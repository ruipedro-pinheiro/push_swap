# Push_swap - Sorting Algorithms & Complexity

**Score:** TBD/100

## About the Project

`push_swap` is a sorting algorithm project where we must sort a stack of integers using a very limited set of instructions. The goal isn't just to sort, but to sort using the **minimum number of operations** possible.

We are graded on efficiency:
- **100 Numbers:** Target < 700 operations
- **500 Numbers:** Target < 5500 operations

---

## The Algorithm: "The Turk"

After researching various sorting algorithms like **Quicksort** and **Bogosort** (too slow!), I decided to implement the **Turk Algorithm**.

### Why the Turk?

Standard algorithms like Quicksort are great for arrays where swapping is cheap. In `push_swap`, every move counts. The Turk Algorithm is a "Cost-Based" or "Greedy" algorithm that is highly optimized for this specific ruleset.

### How it Works

1. **Push to B (Pre-sort):**
   - Move numbers from Stack A to Stack B
   - Keep 3 numbers in A (usually max/min/median)
   - **Key Optimization:** If the number being pushed is smaller than the median of B, rotate B (`rb`)
   - This pre-sorts B in descending order, making the return trip cheaper

2. **Calculate Costs:**
   - For every number remaining in Stack A, calculate exactly how many moves (rotations) it would take to place it in the correct position in Stack B
   - Calculate the cost for *every* number and pick the **cheapest** one to move
   - **Important:** Account for `rr`/`rrr` combos to reduce total cost (not just adding positions)

3. **Push Back to A (The Sort):**
   - Once A is empty (except for 3 numbers), sort the 3 numbers in A using `sort_three()`
   - Push everything back from B to A
   - Since B is sorted (descending), we just need to ensure we push them back into their correct slot

4. **Final Rotation:**
   - Rotate Stack A until the smallest number is at the top

*Credits: This logic was heavily inspired by the "Turk" strategy discussions in the 42 community and insights from [Oceano's tutorials](https://www.youtube.com/watch?v=wRvipSG4Mmk).*

---

## Data Structure

I used a **Doubly Linked List** for the stacks.

```c
typedef struct stack
{
    int value;
    int push_price;    // Cost to move this node
    int position;      // Current index in the stack
    bool cheapest;     // Is this the cheapest node to move?
    bool above_median; // Optimization for rotation direction
    struct stack *next;
    struct stack *prev;
} t_stack;
```

Using a doubly linked list allows for **O(1)** complexity when accessing the last element (for `rra`/`rrb` operations), which is crucial for performance.

---

## Usage

### Compilation
```bash
make
```

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```
Or as a single string:
```bash
./push_swap "4 67 3 87 23"
```

### Testing
Recommended tester/visualiser:

[More complete](https://github.com/obenchkroune/push_swap_visualizer)
[Most used](https://github.com/o-reo/push_swap_visualizer)=
---

## Available Operations

- `sa` - Swap first 2 elements of stack A
- `sb` - Swap first 2 elements of stack B
- `ss` - Execute `sa` and `sb` simultaneously
- `pa` - Push top element from B to A
- `pb` - Push top element from A to B
- `ra` - Rotate stack A up (first becomes last)
- `rb` - Rotate stack B up
- `rr` - Execute `ra` and `rb` simultaneously
- `rra` - Reverse rotate stack A (last becomes first)
- `rrb` - Reverse rotate stack B
- `rrr` - Execute `rra` and `rrb` simultaneously

---

## Key Optimizations & Tips

### 1. Median Pre-sorting During Push to B
When pushing numbers from A to B, check if the number is below the median of B. If yes, perform `rb` to rotate B. This keeps B in descending order, reducing the cost of pushing back to A later.

**Expected Result:** ~4500 moves for 500 numbers (instead of 5000+)

### 2. Find Longest Pre-sorted Sequence
Instead of pushing everything to B, identify the longest sequence of numbers already sorted in A and keep them there. Only push numbers that are out of order.

**Result:** Fewer total operations

### 3. Optimize Cost Calculation with rr/rrr
When calculating push cost, don't just add `node->position + target->position`. If both nodes need rotation in the same direction, you can use `rr` or `rrr` to move them simultaneously.

**Example:**
- Node at position 10 in A
- Target at position 10 in B
- Naive cost: 10 + 10 = 20
- Optimized cost with `rr`: 10

### 4. CRITICAL: atol/atoll Overflow Protection
Using `atol()` or `atoll()` without validation can cause overflow with very large numbers (2^64).

**Solution:** After conversion, verify the number is within `INT_MIN` to `INT_MAX` range:
```c
long num = atoll(str);
if (num < INT_MIN || num > INT_MAX)
    error_exit();
```

### 5. Handle Mixed Input Formats
The subject allows inputs like:
```bash
./push_swap 1 6 2 "65 23 3" 16 10
```

Your parser must handle both single arguments and multi-arg with quoted strings.

---

## Performance Targets

- **3 Numbers:** 2-3 moves max
- **5 Numbers:** ~12 moves max
- **100 Numbers:** ~600 moves (target < 700)
- **500 Numbers:** ~4500 moves (target < 5500)

---

## Common Pitfalls to Avoid

### Circular Linked List Bugs
- **free_stack():** Using `while(current)` will infinite loop in circular lists. Must break the circle first or use a counter.
- **ft_listcount():** Condition `node != first_node->prev` skips the last node. Use `node->next != first_node` instead.
- **pos_change():** Condition `node->prev != *stack` never becomes true in circular lists, causing infinite loop.

### Parsing Bugs
- **atol overflow:** Can accept invalid numbers beyond INT_MAX/INT_MIN
- **Missing validation:** Always check `if (num < INT_MIN || num > INT_MAX)` after conversion
- **Incomplete input handling:** Must support both `argc == 2` (single string) and `argc > 2` (multiple args)

### Algorithm Bugs
- **Naive cost calculation:** Not accounting for `rr`/`rrr` combos inflates costs
- **No median optimization:** Pushing to B without checking median results in 1000+ extra moves

---

## Development Status

See `TODO.c` for current progress, bugs, and pending tasks.

---

## Project Structure

- `src/`: Source files containing stack operations and main logic
- `include/`: Header files with function prototypes and data structures
- `libft/`: Custom C library (42 project dependency)
- `obj/`: Object files generated during compilation

---

## Resources

- [Oceano's Push_swap Tutorial (YouTube)](https://www.youtube.com/watch?v=wRvipSG4Mmk)
- [Push_swap Medium Article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Oceano's Community Notion](https://suspectedoceano.notion.site/push_swap-be0032a86f8c46fd98e71c2ad04721c1)
- [Thuggonaut's Visual Tutorial](https://www.youtube.com/watch?v=OaG81sDEpVk)
- [Faster Solution by Vikingu-del](https://github.com/Vikingu-del/Push_swap)

---

## Author

**rpinheir** - 42 Lausanne
