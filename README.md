*This project has been created as part of the 42 curriculum by rpinheir.

# Push_swap

*Sorting Algorithms & Complexity - 42 Project*

## Description

`push_swap` is a sorting algorithm project where we must sort a stack of integers using a limited set of instructions. We need to be efficient and "greedy", not just code a working algorithm.

Performance targets:
- **100 Numbers:** < 700 operations
- **500 Numbers:** < 5500 operations

---

## The Algorithm: "The Turk"

After researching various sorting algorithms like **Quicksort** and **Bogosort** (too slow or inneficient), I decided to implement the **Turk Algorithm**.

### Why the Turk?

Standard algorithms like Quicksort are great for arrays where swapping is cheap. In `push_swap`, every move counts. The Turk Algorithm is a "Cost-Based" or "Greedy" algorithm that is highly optimized for this specific ruleset. I also wanted a sort of a challenge, and not being introduced to algorithms already i prefered to target a more difficult algorithm, a less used one rather radix which is easier to implement. At the start of the project i know only about quicksort (vaguely) radix and turk.

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
    int             value;
    int             push_price;    // Cost to move this node
    int             position;      // Current index in the stack
    bool            cheapest;      // Is this the cheapest node to move?
    bool            above_median;  // Optimization for rotation direction
    struct stack    *target_node;  // Target position in other stack
    struct stack    *next;
    struct stack    *prev;
} t_stack;
```

Using a **circular doubly linked list** allows for **O(1)** complexity when accessing the last element (for `rra`/`rrb` operations).

**CRITICAL**: This is a CIRCULAR list, not NULL-terminated!
- `last->next = first`
- `first->prev = last`
- NEVER check for `next == NULL` or `prev == NULL`
- Use `current == first_node` to detect full loop

---

## Instructions

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

[My favorite](https://github.com/obenchkroune/push_swap_visualizer)
And the
[Most used](https://github.com/o-reo/push_swap_visualizer)

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

### 2. Optimize Cost Calculation with rr/rrr
When calculating push cost, don't just add `node->position + target->position`. If both nodes need rotation in the same direction, you can use `rr` or `rrr` to move them simultaneously.

**Example:**
- Node at position 10 in A
- Target at position 10 in B
- Naive cost: 10 + 10 = 20
- Optimized cost with `rr`: 10

### 3. CRITICAL: atol/atoll Overflow Protection
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

## Project Structure

- `src/`: Source files containing stack operations and main logic
- `include/`: Header files with function prototypes and data structures
- `libft/`: Custom C library (42 project dependency)
- `obj/`: Object files generated during compilation

---

## Key Learnings

### Double Pointer (`t_stack **stack`)
- `stack` = the pointer-to-pointer itself
- `*stack` = the pointer to the first node (or NULL if empty)
- `**stack` = the first node itself
- Always check `if (!stack || !*stack)` before dereferencing

### Circular List Patterns
```c
// Traverse all nodes
node = *stack;
while (1)
{
    // process node
    node = node->next;
    if (node == *stack)
        break;
}

// Free a circular list
(*stack)->prev->next = NULL;  // Break the circle first
while (current) { ... }       // Then free normally

// Single node points to itself
node->next = node;
node->prev = node;
```

---

## Algorithm Comparison (for the curious)

I spent way too much time researching what other people did for this project. Here's what I found, maybe it'll save you some time.

### The Big Picture

There's basically a "performance ceiling" for each algorithm type. No matter how well you optimize, you won't break through it without switching approaches entirely.

| Algorithm | 500 nums (avg) | Difficulty | Notes |
|-----------|----------------|------------|-------|
| Quicksort Ternaire | ~3800 | Hard | The absolute best, requires serious math |
| Turk / Cost-Based | ~4800-5600 | Medium | What most people use, reliable |
| LIS + Insertion | ~4500-5500 | Medium | Good for already partially sorted inputs |
| Radix Sort | ~5700-6800 | Easy | Simple to code but meh performance |

### Actual Numbers from Real Repos

I dug through a bunch of GitHub repos to get real benchmarks. Some people don't document their results (what a shame) so there are gaps.

**Top performers (< 4200 ops for 500):**

[ulsgks](https://github.com/ulsgks/push_swap) holds the crown with Quicksort Ternaire: 3680 best, 3784 average, 3871 worst. Tested on 10,000 samples. The guy also wrote [an excellent Medium article](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) explaining everything.

[TheRedShip](https://github.com/TheRedShip/42-push-swap) uses median + insertion and gets under 4700 consistently.

**Solid middle ground (4200-5500 ops):**

[duarte3333](https://github.com/duarte3333/Push_Swap) documented actual stats: 595 average for 100 nums, 4806 for 500. Cost-based algorithm with good visualizations in the README.

[jiricodes](https://github.com/jiricodes/push_swap) uses a quicksort/insertsort hybrid. No published numbers but clean code to read.

**Radix implementations (won't get you 5/5 on 500 nums):**

[to0nsa](https://to0nsa.github.io/push_swap/) has a clean writeup on Radix: ~855 for 100, ~5740 for 500. Over the 5500 threshold so only 4/5 points.

[madebypixel02](https://github.com/madebypixel02/push_swap) is honest about Radix limitations: 1025 for 100, 6756 for 500. Same deal, 4/5 points max.

### Why I Chose Turk

Quicksort Ternaire would give better numbers but i discovered it while my turk algorithm was almost finished, i did wanted to try to code it but i coded already too much to rollback and change didrections. It will be surely a little side_project to when i have time. The turk algorithm is also very interesting as it is not that "abstract" when the basics are understood (push price, the "cheapest" node, etc...).

For 100% i just need to stay under 700 (for 100 nums) and 5500 (for 500 nums). The 125% comes from the bonus checker, not from having a faster algorithm, so redoing all over again would be just plain stupid.

---

## Resources

- [Oceano's video and comments (YouTube)](https://www.youtube.com/watch?v=wRvipSG4Mmk)
  Very good video, but with some flaws, the comments below the video though are SUPER helpful, some are alerting Oceano's live code, others giving exceptionally good tips.

- [Gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/building-the-thing) It is very good for a start, but with the time i was fully understanding so i prefered to use other ressources, it may help you or not.

- [Medium Article by Ali Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
	-A gold mine, actually very good, i was following this all along my project so i could remember some details, like "is reverse_rotate clockwise or anti-clockwise ?", the picture diagrams and all schemes really helped me to understand things even further.

- [Github Readme Instructions](https://github.com/alx-sch/push_swap?tab=readme-ov-file)
	-He actually based himself from the same medium article from Ali Ogun, yet his readme instructions are also VERY good.


### AI Usage

AI (Claude) was used as a learning coach during this project:
- Made throughrly searches over the web and helped me to find some more precise info of wat i was looking.
- Asking questions to help me think through problems
- Explaining concepts when I got stuck

All code implementation, bug identification, and problem-solving were done independently.
The AI did not write code for this project.

---

## Author

**rpinheir** - 42 Lausanne
