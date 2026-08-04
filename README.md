*fcamasa | Elilopez*

# push_swap

Sort a stack of integers using two stacks and a restricted set of operations, in as few moves as possible.

## Descripción

Push_swap is an algorithmic project: given a list of integers in stack A and an empty stack B, produce the shortest sequence of operations to leave stack A sorted in ascending order with B empty.

The challenge is selecting the right algorithm for the right input — a brute-force O(n²) strategy fails at scale, while an O(n log n) strategy wastes operations on nearly-sorted data. The program must detect the input regime and adapt.

## Instrucciones

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

Prints disorder, strategy, total ops and per-op breakdown to stderr after sorting.

## Reglas

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

## Algoritmos

### Algoritmo simple — Selection sort O(n²)

For each rank from 1 to n, locate that element in A, rotate it to the top using the shortest path (forward `ra` or backward `rra`), push it to B. Then pull everything back. For n elements this is O(n²) in the worst case.

Used when: `--simple` flag, or by the adaptive algorithm when disorder < 0.2 (in this regime the elements are close to their correct positions so the cost is effectively O(n)).

### Algoritmo medio — Chunk sort O(n√n)

**Push phase:** divide ranks into chunks of size √n. Scan all of A to find the element in the current chunk closest to the top (using `min(pos, n−pos)` as cost), rotate it to the top, push to B. When a chunk is exhausted, move to the next.

**Pull phase:** pull elements back from B in descending rank order, always rotating the target to the top first.

Total rotations ≈ n · (√n / 4) for the push phase and a similar amount for the pull phase → O(n√n) operations.

Used when: `--medium` flag, or by the adaptive algorithm when 0.2 ≤ disorder < 0.5.

### Algoritmo complejo — LSD radix sort O(n log n)

Sort by bit, from least significant to most. Each pass: elements whose current bit is 0 are pushed to B; elements with bit 1 rotate to the back of A. Then all of B is pushed back to A. After ⌈log₂ n⌉ passes, A is sorted.

This is deterministic: exactly n × ⌈log₂ n⌉ × 2 push/pull operations regardless of input order.

Used when: `--complex` flag, or by the adaptive algorithm when disorder ≥ 0.5.

### Algoritmo adaptativo (por defecto)

Selects strategy based on the disorder index computed before any operation:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | sort_simple | O(n) |
| 0.2 – 0.5 | sort_medium | O(n√n) |
| ≥ 0.5 | sort_complex | O(n log n) |

**Justificación de los umbrales:**

- **0.2**: Below this, at most 20% of pairs are inverted. Elements are close to their final position so selection sort needs very few rotations per element — the total cost is linear in n.
- **0.5**: A completely random permutation has an expected disorder of exactly 0.5 (each pair is equally likely to be in or out of order). Inputs at or above this threshold are effectively random and benefit from the O(n log n) guarantee of radix sort. Inputs below 0.5 still have significant structure that chunk sort exploits.

These thresholds were validated empirically: for n=100 with disorder < 0.2, sort_simple uses ≤ 2n operations; for n=500 with disorder ≥ 0.5, sort_complex uses ~6800 operations (well under the 8000 "good" threshold).

## Rendimiento

| n | Strategy | Typical ops | Score |
|---|----------|-------------|-------|
| 3–5 | adaptive | ≤ 12 | max |
| 100 | sort_medium (disorder 0.2–0.5) | ~800 | good (< 1500) |
| 500 | sort_complex (disorder ≥ 0.5) | ~6800 | good (< 8000) |

## Estructura de archivos

```
push_swap.h           — structs, constants, all prototypes
main.c                — argument parsing, strategy dispatch
parse.c               — input validation, duplicate detection
sort_utils.c          — assign_ranks, is_sorted, parse_flag
disorder.c            — compute_disorder (inversion ratio)
sort_adaptive.c       — adaptive strategy selector
sort_simple.c         — O(n²) selection sort
sort_medium.c         — O(n√n) chunk sort (pull phase + entry)
sort_medium_utils.c   — O(n√n) chunk sort (push phase helpers)
sort_complex.c        — O(n log n) LSD radix sort
ops_swap.c            — sa, sb, ss
ops_push.c            — pa, pb
ops_rotate.c          — ra, rb, rr
ops_rr.c              — rra, rrb, rrr
stack_utils.c         — node/stack allocation primitives
stack_free.c          — stack_free, stacks_free
error.c               — error_exit, print_bench
libft/                — standard C library subset
checker_bonus.c       — checker: reads ops from stdin, prints OK/KO
checker_ops_bonus.c   — checker: silent operation implementations
```

## Contribuciones

| Estudiante | Contribución |
|------------|--------------|
| fcamasa | Algoritmos: sort_simple, sort_medium, sort_complex, sort_adaptive, disorder, benchmarking |
| Elilopez | Core: parsing, operaciones, stack, manejo de errores, main, checker bonus |

## Recursos

### Referencias

- Knuth, D. (1998). *The Art of Computer Programming, Vol. 3: Sorting and Searching*. Addison-Wesley. — Fundamentos de radix sort y ordenación por selección.
- [Visualgo — Sorting Algorithms](https://visualgo.net/en/sorting) — Visualización interactiva de algoritmos de ordenación.
- Documentación de la norminette v3: reglas de estilo de código para proyectos de 42.

### Uso de IA

Claude (Anthropic) fue utilizado como asistente durante el desarrollo de este proyecto para:
- Análisis de complejidad algorítmica y comparación de estrategias de chunk sort vs radix sort.
- Identificación de violaciones de norminette (funciones > 25 líneas, > 5 funciones por archivo).
- Depuración del script de benchmark y del comportamiento de word-splitting en zsh.
- Generación y verificación del checker bonus.

Todo el código generado fue revisado, probado y comprendido por ambos estudiantes antes de su incorporación al proyecto.
