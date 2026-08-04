*fcamasa | Elilopez*

# push_swap

Sort a stack of integers using two stacks and a restricted set of operations, in as few moves as possible.

## Description

Push_swap is an algorithmic project: given a list of integers in stack A and an empty stack B, produce the shortest sequence of operations to leave stack A sorted in ascending order with B empty.

The challenge is selecting the right algorithm for the right input — a brute-force O(n²) strategy fails at scale, while an O(n log n) strategy wastes operations on nearly-sorted data. The program detects the input regime and adapts automatically.

## Usage

```sh
make        # build push_swap
make bonus  # build checker
make re     # clean rebuild
make fclean # remove binaries and objects
```

Requires `cc`, `make`, and a POSIX system. `libft/` is bundled.

**Run:**
```sh
./push_swap 4 2 7 1 9 3
```

Prints the operation sequence to stdout, one per line.

**Verify with checker:**
```sh
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
```

**Benchmark mode:**
```sh
./push_swap --bench 4 67 3 87 23
./push_swap --bench --simple 5 4 3 2 1
```

Prints disorder index, strategy, total ops and per-op breakdown to stderr after sorting.

## Rules

Two stacks **A** and **B**. All numbers start in A; goal is A sorted ascending, B empty.

| Op | Effect |
|----|--------|
| `sa` / `sb` | Swap top two of A / B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top of B→A / top of A→B |
| `ra` / `rb` | Rotate A / B (top → bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate A / B (bottom → top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithms

### Simple — Selection sort O(n²)

For each rank from 1 to n, locate that element in A, rotate it to the top using the shortest path (forward `ra` or backward `rra`), push it to B. Then pull everything back.

Used when: `--simple` flag, or by the adaptive algorithm when disorder < 0.2 (elements are close to their final position so the total cost is effectively O(n)).

### Medium — Chunk sort O(n√n)

**Push phase:** divide ranks into chunks of size √n. Scan A to find the element in the current chunk closest to the top (using `min(pos, n−pos)` as cost), rotate it to the top, push to B. Move to the next chunk when the current one is exhausted.

**Pull phase:** pull elements back from B in descending rank order, always rotating the target to the top first.

Used when: `--medium` flag, or by the adaptive algorithm when 0.2 ≤ disorder < 0.5.

### Complex — LSD radix sort O(n log n)

Sort by bit, from least significant to most. Each pass: elements whose current bit is 0 are pushed to B; elements with bit 1 rotate to the back of A. Then all of B is pushed back to A. After ⌈log₂ n⌉ passes, A is sorted.

Deterministic: exactly n × ⌈log₂ n⌉ × 2 push/pull operations regardless of input order.

Used when: `--complex` flag, or by the adaptive algorithm when disorder ≥ 0.5.

### Adaptive (default)

Selects the strategy based on the disorder index (inversions / total pairs) computed before any operation:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | sort_simple | O(n) |
| 0.2 – 0.5 | sort_medium | O(n√n) |
| ≥ 0.5 | sort_complex | O(n log n) |

**Threshold rationale:**

- **0.2**: Below this, at most 20% of pairs are inverted. Elements are close to their final position so selection sort needs very few rotations — total cost is linear in n.
- **0.5**: A completely random permutation has an expected disorder of exactly 0.5. Inputs at or above this threshold benefit from the O(n log n) guarantee of radix sort. Inputs below 0.5 still have exploitable structure that chunk sort takes advantage of.

## Performance

| n | Strategy | Typical ops | Score |
|---|----------|-------------|-------|
| 3–5 | adaptive | ≤ 12 | max |
| 100 | sort_medium | ~700 | good (< 1500) |
| 500 | sort_complex | ~6800 | good (< 8000) |

## File structure

```
push_swap.h           — structs, constants, all prototypes
push-swap-floren/
  sort_utils.c        — assign_ranks, is_sorted, parse_flag
  disorder.c          — compute_disorder (inversion ratio)
  sort_adaptive.c     — adaptive strategy selector
  sort_simple.c       — O(n²) selection sort
  sort_medium.c       — O(n√n) chunk sort (pull phase + entry)
  sort_medium_utils.c — O(n√n) chunk sort (push phase helpers)
  sort_complex.c      — O(n log n) LSD radix sort
push-swap-elias/
  main.c              — argument parsing, strategy dispatch
  parse.c             — input validation, duplicate detection
  stack_utils.c       — node/stack allocation primitives
  stack_free.c        — stack_free, stacks_free
  ops_swap.c          — sa, sb, ss
  ops_push.c          — pa, pb
  ops_rotate.c        — ra, rb, rr
  ops_rr.c            — rra, rrb, rrr
  error.c             — error_exit, print_bench
  checker_bonus.c     — checker: reads ops from stdin, prints OK/KO
  checker_ops_bonus.c — checker: silent operation implementations
libft/                — standard C library subset
```

## Contributions

| Student | Contribution |
|---------|--------------|
| fcamasa | Sorting algorithms: sort_simple, sort_medium, sort_complex, sort_adaptive, disorder index, benchmarking |
| Elilopez | Core infrastructure: parsing, stack operations, error handling, main, checker bonus |

## Resources

- Knuth, D. (1998). *The Art of Computer Programming, Vol. 3: Sorting and Searching*. Addison-Wesley.
- [Visualgo — Sorting Algorithms](https://visualgo.net/en/sorting)
- Norminette v3 documentation — 42 school code style rules.

### AI usage

Claude (Anthropic) was used as an assistant during the development of this project for:
- Algorithmic complexity analysis and comparison of chunk sort vs radix sort strategies.
- Identification of norminette violations (functions > 25 lines, > 5 functions per file).
- Debugging the benchmark script and zsh word-splitting behavior.
- Generation and verification of the checker bonus.

All generated code was reviewed, tested, and understood by both students before being incorporated into the project.
