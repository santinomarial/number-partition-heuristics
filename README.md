# Number Partition Heuristics

A study of approximation heuristics for the **Number Partition** problem — an NP-complete problem in which a multiset of positive integers must be divided into two subsets so that the absolute difference of their sums (the *residue*) is minimized.

Because exact algorithms are infeasible for large instances, this project implements and benchmarks a family of deterministic and randomized heuristics, comparing two fundamentally different ways of representing a candidate solution.

---

## Solution Representations

### Standard (sign-vector) representation
Each element $a_i$ is assigned a sign $s_i \in \{+1, -1\}$, placing it in subset A or B. The residue is $\left|\sum_i s_i a_i\right|$.

Neighborhood moves flip one sign, or swap the signs of two elements.

### Prepartition representation
A function $p : \{0,\ldots,n{-}1\} \to \{0,\ldots,n{-}1\}$ maps each element to a *group*. The transformed instance collapses each group into a single element $a'_j = \sum_{p(i)=j} a_i$, then runs Karmarkar-Karp on the collapsed instance. This representation implicitly explores a much richer solution space.

---

## Algorithm Codes

| Code | Representation  | Algorithm              |
|------|-----------------|------------------------|
| 0    | —               | Karmarkar-Karp (KK)    |
| 1    | Standard        | Repeated Random        |
| 2    | Standard        | Hill Climbing          |
| 3    | Standard        | Simulated Annealing    |
| 11   | Prepartition    | Repeated Random        |
| 12   | Prepartition    | Hill Climbing          |
| 13   | Prepartition    | Simulated Annealing    |

---

## Build

```
make
```

Requires g++ with C++17 support. Produces a binary named `partition`.

```
make clean   # remove object files and binary
```

## Run

```
./partition <flag> <algorithm> <inputfile>
```

- `<flag>` — integer; 0 for standard grader mode, other values for debug/extension modes.
- `<algorithm>` — one of the codes in the table above.
- `<inputfile>` — path to a file containing 100 integers (up to 10^12), one per line.

The program prints the residue to stdout.

### Example

```
./partition 0 0 input.txt    # run Karmarkar-Karp
./partition 0 3 input.txt    # run Simulated Annealing (standard rep.)
./partition 0 13 input.txt   # run Simulated Annealing (prepartition rep.)
```
