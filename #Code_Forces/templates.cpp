#include<bits/stdc++.h>
using namespace std;

/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
    }
}

/*
ChatGPT said:
For Div. 2 A & B problems, you don’t need the full heavy DSA arsenal — you need a set of mental templates for small-to-medium complexity problems.
These are the “instant recall” tools that let you solve 80–90% of A/B in under 10 minutes.

1. Basic DSA Templates (must be muscle memory)
Arrays & Strings
Frequency count (array/map)

Prefix sums (1D and 2D)

Sliding window (fixed & variable size)

Two pointers (search for pairs, subsequences)

String parsing / reversing / checking substrings

Sorting & Searching
Sorting + custom comparator

Binary search on sorted data

lower_bound / upper_bound (C++)

Maps & Sets
Counting unique elements

Finding duplicates

Maintaining order with set or map

2. Math Templates
Modular arithmetic (especially % with negatives)

GCD / LCM (Euclid’s algorithm)

Parity check (odd/even reasoning)

Arithmetic series formula

Divisors & prime checks (simple version)

Power of 2 / bit counting (log2, __builtin_popcount)

3. Logical / Constructive Patterns
Greedy choice (pick smallest/largest first)

Difference arrays (range update tricks)

Simulation (step-by-step movement)

Pattern repetition (periodicity detection)

Invariants (what doesn’t change after operations)

4. Graph / Grid Mini-Templates
BFS/DFS on small grids

Flood-fill (for connected component counting)

Manhattan distance calculation

Direction arrays dx, dy for moves

5. Algorithmic Thinking Templates
If input size ≤ 10^3 → brute force possible

If constraints are huge but values small → precompute

If operations repeat in cycles → modulus or periodicity

If condition is “exists” → stop early

If order changes predictably → simulate until stable or cycle
*/

/*

## **Template Set 1: Invariant-Based Problems**

**Core idea:** Identify something that **remains constant** or follows strict rules during operations, and use it to guide the solution.

* **Steps to apply:**

  1. Identify invariant(s) in the problem.
  2. Analyze how operations affect the invariant.
  3. Construct an algorithm that respects the invariant to reach the desired outcome.
* **Example problems discussed:**

  * GCD merge operations on arrays (finding final possible value by invariant).
* **Key insights:**

  * Invariants guide the solution, but additional logic (DP, greedy, etc.) is often needed.
  * Can handle “what’s possible after repeated operations” type questions.

---

## **Template Set 2: Sliding Window / Two Pointers**

**Core idea:** Maintain a window (or segment) over the array/string and track information dynamically.

* **Steps to apply:**

  1. Define window bounds (usually left/right pointers).
  2. Maintain data about the current window (sum, max, min, frequency, etc.).
  3. Adjust pointers based on constraints.
* **Example problems discussed:**

  * Sliding window minimum/maximum using monotonic deque.
* **Key insights:**

  * Monotonic queues allow O(1) access to min/max.
  * Useful in range constraints, substring/subarray queries.
  * Two-pointer approach is a simpler variant for problems without monotonic requirements.

---

## **Template Set 3: BFS/Traversal Verification**

**Core idea:** Verify if a given sequence can result from a valid BFS/DFS traversal.

* **Steps to apply:**

  1. Track visited nodes.
  2. Optionally track parent and level to maintain BFS invariants.
  3. Validate sequence based on adjacency and queue expansion rules.
* **Example problems discussed:**

  * BFS order verification on trees with arbitrary neighbor ordering.
* **Key insights:**

  * Level tracking is not always enough; parent/neighbor checks are necessary.
  * Valid BFS sequences can vary due to arbitrary neighbor orderings.

---

## **Template Set 4: Greedy + Reverse Logic**

**Core idea:** Sometimes solving a problem in **reverse** or considering “what to remove last” can simplify the logic.

* **Steps to apply:**

  1. Identify the final desired state.
  2. Work backward, choosing optimal elements to remove/modify.
* **Example problems discussed:**

  * Substring removal to make all characters equal.
  * Polygon/cannon grid filling verification (reverse reasoning about shooting sequences).
* **Key insights:**

  * Greedy choice often aligns with maximal/minimal operations that respect constraints.
  * Reverse thinking reduces complexity by focusing on necessary actions.

---

## **Template Set 5: 2D Grid Checks**

**Core idea:** Iterate over a 2D grid and apply **local condition checks** for each cell.

* **Steps to apply:**

  1. Identify conditions for invalid placement/configuration.
  2. Use boundary checks to avoid out-of-range errors.
  3. Return immediately if invalid condition is met.
* **Example problems discussed:**

  * Cannon shooting simulation on a grid.
  * Matrix validation for adjacency rules (0/1 placement).
* **Key insights:**

  * Straightforward nested loops + early termination.
  * Efficient for small to moderate n; time complexity is usually O(n²).
  * Condition logic is more important than traversal technique here.

---

## **Template Set 6: Dynamic Programming for Partition Problems**

**Core idea:** Use DP to **store intermediate solutions** and avoid recomputation in recursive partitioning/merging problems.

* **Steps to apply:**

  1. Define state variables (start index, end index, current partition info).
  2. Base conditions reflect trivial cases or invalid partitions.
  3. Recurrence captures merging or removal operations.
* **Example problems discussed:**

  * Minimizing sum of maximums after merging partitions.
* **Key insights:**

  * DP reduces exponential recursion to polynomial time.
  * Careful choice of states is critical for memory/time efficiency.

---

## **Template Set 7: Monotonic Structures**

**Core idea:** Maintain a data structure that preserves order or monotonicity to quickly answer queries.

* **Steps to apply:**

  1. Use deque/stack to keep elements in increasing/decreasing order.
  2. Pop elements that no longer satisfy monotonic condition.
  3. Front/back always gives current min/max.
* **Example problems discussed:**

  * Sliding window min/max with two pointers.
* **Key insights:**

  * Enables O(1) query per step.
  * Crucial in problems with constraints on subarray/subsequence min or max.

---

### ✅ Summary of Mental Template Coverage

| Template                      | Core Use Case                         | Key Problem Example                |
| ----------------------------- | ------------------------------------- | ---------------------------------- |
| Invariant-Based               | Operations affecting final state      | GCD merge, BFS sequence validation |
| Sliding Window / Two Pointers | Subarrays/substrings with constraints | Sliding min/max                    |
| BFS / Traversal Validation    | Verify BFS order                      | Tree BFS sequence                  |
| Greedy / Reverse              | Min/max operations by reverse logic   | Substring removal, grid shooting   |
| 2D Grid Checks                | Local condition checks                | Polygon cannon grid                |
| DP for Partitions             | Recursive partition optimization      | Minimum sum of partition maxes     |
| Monotonic Structures          | Efficient min/max in sliding ranges   | Sliding window min/max             |

---
*/

/*
## **Big 36 Major Templates (Core of CF Div 2 mastery)**

1. **Frequency Maps / Counting** – counting occurrences, using maps for validation, duplicates, frequency-based decisions.
2. **Two Pointers / Sliding Window** – subarray/subsequence with constraints.
3. **Monotonic Stack / Deque** – next greater/lesser element, sliding min/max.
4. **Prefix / Suffix Sum** – cumulative sums for range queries or optimization.
5. **Binary Search on Answer** – optimizing via monotonic function.
6. **Greedy Selection** – choosing local optima that lead to global solution.
7. **DP on Subsets / Bitmask** – combinatorial state tracking.
8. **DP on Intervals / Partitions** – merging, splitting, minimizing/maximizing over segments.
9. **Invariant-Based Operations** – what remains constant under repeated operations.
10. **Graph BFS / DFS** – traversal, level, parent tracking.
11. **Graph Topological Sort** – ordering tasks or nodes respecting dependencies.
12. **Union-Find / DSU** – connectivity, components, merging sets.
13. **Segment Tree / Fenwick Tree** – efficient range queries & updates.
14. **Sparse Table** – RMQ / immutable range queries.
15. **Priority Queue / Heap** – dynamic selection of min/max.
16. **Dijkstra / Shortest Paths** – weighted graph shortest paths.
17. **Bipartite Check / Coloring** – graph validation.
18. **Flood Fill / Connected Components** – 2D grid or graph exploration.
19. **String Hashing / Rolling Hash** – substring equality checks efficiently.
20. **KMP / Prefix Function** – pattern matching.
21. **Trie / Prefix Tree** – efficient string insert/search.
22. **Sliding Window for Strings** – substring constraints, counts, min/max.
23. **Greedy + Reverse Thinking** – removing elements from end/backtracking for optimization.
24. **DP + Greedy hybrid** – e.g., DP on partitions but greedy merges.
25. **Graph BFS Verification** – checking BFS sequences, adjacency order constraints.
26. **2D Grid Checks / Simulation** – cell-based local rules.
27. **Binary Lifting / LCA** – tree queries for ancestor/distance.
28. **Tree DP / Subtree DP** – recursive info collection on trees.
29. **Euler Tour / Flatten Tree** – subtree ranges for segment tree queries.
30. **Bitmask + DP** – combinatorial optimization with small n.
31. **Convex Hull Trick / Slope Optimization** – DP optimization over lines.
32. **Meet-in-the-middle** – splitting problem into halves for efficiency.
33. **Mathematical / Number Theory templates** – GCD, LCM, modular arithmetic, prime sieve.
34. **Combinatorial Counting** – permutations, combinations, inclusion-exclusion.
35. **Sliding Window Min/Max with Monotonic Queue** – O(1) query for subarray extrema.

---

## **New Major Templates Identified in Background Task**

*(Observed while processing problems for schedule construction and mapping to templates)*

36. **Parent/Level Tracking in Tree BFS Validation** – checking BFS order when neighbor ordering is arbitrary.
37. **Reverse Greedy Substring Removal** – removing substrings to achieve uniform strings efficiently.
38. **Grid Shooting / Propagation Simulation** – local rules for 2D grids with cascading effects.
39. **Partition Merge Cost Minimization** – iterative merging of partitions while minimizing a cost function.
40. **Invariant + Recursive DP Hybrid** – using invariants to prune recursive states in DP.

*/


// 1. Prefix sums & difference arrays
// 2. Binary search on answer
// 3. Two pointers (fixed & variable window)
// 4. Sliding window with monotonic deque (min/max tracking)
// 5. Frequency maps / counting arrays
// 6. Sorting + greedy pairing
// 7. Meeting-in-the-middle
// 8. Coordinate compression
// 9. Sweep line / events sorting
// 10. Stack-based processing (monotonic stack, histogram)
// 11. Segment tree (sum/min/max)
// 12. Fenwick tree / BIT
// 13. DSU / Union-Find
// 14. Binary lifting / LCA
// 15. Graph BFS/DFS basics
// 16. Topological sort + DAG DP
// 17. Shortest paths (Dijkstra, Bellman-Ford, Floyd-Warshall)
// 18. Minimum spanning tree (Kruskal / Prim)
// 19. Bitmask DP
// 20. Subset enumeration / meet-in-middle for subsets
// 21. Interval DP
// 22. Knapsack DP variants
// 23. Digit DP
// 24. Invariant-based reasoning
// 25. Mathematical number theory (GCD/LCM, modular arithmetic)
// 26. Modular inverse / combinatorics precomputation
// 27. Matrix exponentiation
// 28. Game theory (Grundy numbers, nim)
// 29. String hashing / rolling hash
// 30. KMP / Z-function / prefix-function
// 31. Trie-based problems
// 32. Suffix array / suffix automaton
// 33. Geometry basics (orientation, convex hull)
// 34. Binary search in state space (parametric search)
// 35. Flow / matching (max flow, bipartite matching)
// 36. Constructive (invariants + case analysis + implementation strategy)

// ### 1. **Invariant-based reasoning**
// * **Core idea:** Identify a property that stays constant (or follows strict rules) across operations.
// * **Use:** Guides greedy choices, DP transitions, and correctness checks.
// * **Example:** CF 1237B – Balanced Tunnel (two-pointer ordering invariant), CF 1360D – Buying Shovels (factorization invariant).

// ### 2. **Extremal principle / Greedy bounds**
// * **Core idea:** The solution often involves focusing on extreme values (max/min) and reasoning that certain operations must involve them.
// * **Use:** Designing greedy strategies, choosing elements to reduce/maximize.
// * **Example:** CF 1409B – Minimum Product (minimizing product by targeting largest factors).

// ### 3. **Monotonicity constraints**
// * **Core idea:** Many sequences or subarrays are required to maintain monotonic properties (increasing, decreasing, or bounded).
// * **Use:** Allows sliding window, monotonic deque, or binary search on subarray length.
// * **Example:** CF 1472C – Long Jumps (jump sequence monotonicity), CF 1398C – Good Subarrays.

// ### 4. **Parity / modular reasoning**
// * **Core idea:** Certain problems reduce to checking parity, remainder classes, or modulo constraints.
// * **Use:** Simplifies constraints for DP, greedy, or constructive solutions.
// * **Example:** CF 1343B – Balanced Array (even/odd splitting), CF 1459B – Move and Turn.

// ### 5. **Connectivity / reachability**
// * **Core idea:** Elements or states are linked; operations propagate effects along a graph or array.
// * **Use:** BFS/DFS, DSU, or simulation to ensure constraints hold.
// * **Example:** CF 1237B (tunnel segments as graph), CF 1512B (grid reachability).

// ### 6. **Constraint propagation**
// * **Core idea:** Updating one part of the system forces updates elsewhere; you track these changes until stabilization.
// * **Use:** Greedy + DP + simulation, often with queues or priority structures.
// * **Example:** CF 1400C – Binary String Reconstruction (propagating known values to unknowns).

// ### 7. **Symmetry / reduction**
// * **Core idea:** Exploit symmetry to reduce state space or identify equivalent solutions.
// * **Use:** Helps in DP optimization or combinatorial reduction.
// * **Example:** CF 1365B – Trouble Sort (pairing positions by parity).

// ### 8. **Extremal substructure identification**
// * **Core idea:** Identify the “critical subarray” / segment / element that determines the global optimum.
// * **Use:** Guides sliding windows, two-pointer traversal, or divide & conquer.
// * **Example:** CF 1399C – Boats Competition (maximal pair sum subarray), CF 1237B – Balanced Tunnel.

// ### 9. **Invariant under transformation**
// * **Core idea:** Some transformations leave key properties unchanged; exploiting this allows simplifications.
// * **Use:** Reverse greedy, factoring, DP compression.
// * **Example:** CF 1360D – Buying Shovels, CF 1472C – Long Jumps.

// ### 10. **Frequency / counting backbone**
// * **Core idea:** The count of occurrences or frequency of elements constrains possible moves or outcomes.
// * **Use:** Frequency maps, counting arrays, combinatorial reasoning.
// * **Example:** CF 1343B – Balanced Array, CF 1399C – Boats Competition.

/*
Got it. Here’s a **mapping of Week 1 schedule problems to the major templates** including the new **Constructive (36)** template. This shows which template each problem reinforces:

---

**Day 1 (LOCKED)**

1. **CF 1237B – Balanced Tunnel** → **Frequency maps / counting arrays (5)**
2. **CF 1343B – Balanced Array** → **Constructive (36)**
3. **CF 1360D – Buying Shovels** → **Mathematical number theory (25)**
4. **CF 1472C – Long Jumps** → **DP / Interval DP / backward DP accumulation** → **Interval DP (21)**
5. **CF 1409B – Minimum Product** → **Reverse Greedy → Subtemplate under Invariant-based reasoning (24)**

---

**Day 2**

1. **CF 550B – Preparing Olympiad** → **Subset enumeration / meet-in-middle for subsets (20)**
2. **CF 1092B – Teams Forming** → **Sorting + greedy pairing (6)**
3. **CF 1512C – A-B Palindrome** → **Two pointers (3)**
4. **CF 1365B – Trouble Sort** → **Invariant-based reasoning (24)**
5. **CF 1374C – Move Brackets** → **Stack-based processing (10)**

---

**Day 3**

1. **CF 1454C – Sequence Transformation** → **Frequency maps / counting arrays (5)**
2. **CF 1473B – String LCM** → **Mathematical number theory (25)**
3. **CF 1352C – K-th Not Divisible by n** → **Binary search on answer (2)**
4. **CF 1459B – Move and Turn** → **Constructive (36)**
5. **CF 1399C – Boats Competition** → **Sorting + greedy pairing (6)**

---

**Day 4**

1. **CF 1203B – Equal Rectangles** → **Frequency maps / counting arrays (5)**
2. **CF 1430C – Numbers on Whiteboard** → **Simulation / Constructive (36)**
3. **CF 1385C – Make It Good** → **Suffix checks / monotonic traversal → could map to Interval DP (21)**
4. **CF 1328C – Ternary XOR** → **Greedy (Sorting + pairing logic) (6)**
5. **CF 1399B – Gifts Fixing** → **Greedy / Constructive combination (36)**

---

**Day 5**

1. **CF 702B – Powers of Two** → **Hashing / Frequency maps (5)**
2. **CF 1475B – New Year's Number** → **Mathematical number theory (25)**
3. **CF 1256B – Minimize the Permutation** → **Greedy (6)**
4. **CF 1400C – Binary String Reconstruction** → **Constraint propagation → Constructive (36)**
5. **CF 1426C – Increase and Copy** → **Mathematical optimization / Greedy (6)**

---

**Day 6**

1. **CF 1200B – Kill ’Em All** → **Sorting + cutoff (6)**
2. **CF 1374B – Multiply by 2, divide by 6** → **Mathematical reasoning (25)**
3. **CF 1462C – Unique Number** → **Digit-based greedy → Constructive (36)**
4. **CF 1360E – Polygon** → **Grid DP / Interval DP (21)**
5. **CF 1342B – Binary Period** → **String / period analysis → Constructive (36)**

---

**Day 7**

1. **CF 1398C – Good Subarrays** → **Prefix sums / frequency maps (1, 5)**
2. **CF 1512B – Almost Rectangle** → **Constructive (36)**
3. **CF 1475C – Ball in Berland** → **Frequency maps + Greedy pairing (5, 6)**
4. **CF 1335B – Construct the String** → **Constructive (36)**
5. **CF 1389B – Array Walk** → **DP / Path choice → Interval DP (21)**

---

✅ **Summary of major templates reinforced in Week 1**:

* **1. Prefix sums & difference arrays** → 1 problem
* **2. Binary search on answer** → 1 problem
* **3. Two pointers** → 1 problem
* **5. Frequency maps / counting arrays** → 5 problems
* **6. Sorting + greedy pairing** → 7 problems
* **10. Stack-based processing** → 1 problem
* **21. Interval DP** → 4 problems
* **24. Invariant-based reasoning** → 2 problems
* **25. Mathematical number theory** → 5 problems
* **36. Constructive** → 10 problems
* **Subtemplate: Reverse Greedy** → 1 problem

---

If you want, I can **draw a visual map of Week 1 showing problem → major template → subtemplate** so it’s easier to reinforce connections.

Do you want me to do that?

*/

/*
Got it — here’s your **locked Week 1 schedule** with direct CF links (all Div.2 B/C, 1100–1900 range, template-focused).

---

### 🔒 **Week 1 – Locked Final (Div.2 B & C only)**

**Day 1 (locked, unchangeable)**

1. [CF 1237B – Balanced Tunnel](https://codeforces.com/problemset/problem/1237/B)
2. [CF 1343B – Balanced Array](https://codeforces.com/problemset/problem/1343/B)
3. [CF 1360D – Buying Shovels](https://codeforces.com/problemset/problem/1360/D)
4. [CF 1472C – Long Jumps](https://codeforces.com/problemset/problem/1472/C)
5. [CF 1409B – Minimum Product](https://codeforces.com/problemset/problem/1409/B)

---

**Day 2**

1. [CF 1490C – Sum of Cubes](https://codeforces.com/problemset/problem/1490/C)
2. [CF 1399C – Boats Competition](https://codeforces.com/problemset/problem/1399/C)
3. [CF 1352C – K-th Not Divisible by n](https://codeforces.com/problemset/problem/1352/C)
4. [CF 1520C – Not Adjacent Matrix](https://codeforces.com/problemset/problem/1520/C)
5. [CF 1538C – Number of Pairs](https://codeforces.com/problemset/problem/1538/C)

---

**Day 3**

1. [CF 1512C – A-B Palindrome](https://codeforces.com/problemset/problem/1512/C)
2. [CF 1256B – Minimize Permutation Subarrays](https://codeforces.com/problemset/problem/1256/B)
3. [CF 1389B – Array Walk](https://codeforces.com/problemset/problem/1389/B)
4. [CF 1294C – Product of Three Numbers](https://codeforces.com/problemset/problem/1294/C)
5. [CF 1462C – Unique Number](https://codeforces.com/problemset/problem/1462/C)

---

**Day 4**

1. [CF 1348B – Phoenix and Beauty](https://codeforces.com/problemset/problem/1348/B)
2. [CF 1328C – Ternary XOR](https://codeforces.com/problemset/problem/1328/C)
3. [CF 1353C – Board Moves](https://codeforces.com/problemset/problem/1353/C)
4. [CF 1251B – Binary Palindromes](https://codeforces.com/problemset/problem/1251/B)
5. [CF 1433C – Dominant Piranha](https://codeforces.com/problemset/problem/1433/C)

---

**Day 5**

1. [CF 1473C – No More Inversions](https://codeforces.com/problemset/problem/1473/C)
2. [CF 1333C – Eugene and Array](https://codeforces.com/problemset/problem/1333/C)
3. [CF 1454C – Sequence Transformation](https://codeforces.com/problemset/problem/1454/C)
4. [CF 1392C – Omkar and Waterslide](https://codeforces.com/problemset/problem/1392/C)
5. [CF 1506C – Double-ended Strings](https://codeforces.com/problemset/problem/1506/C)

---

**Day 6**

1. [CF 1406C – Link Cut Centroids](https://codeforces.com/problemset/problem/1406/C)
2. [CF 1370C – Number Game](https://codeforces.com/problemset/problem/1370/C)
3. [CF 1401C – Mere Array](https://codeforces.com/problemset/problem/1401/C)
4. [CF 1257C – Dominated Subarray](https://codeforces.com/problemset/problem/1257/C)
5. [CF 1365C – Rotation Matching](https://codeforces.com/problemset/problem/1365/C)

---

**Day 7**

1. [CF 1485C – Floor and Mod](https://codeforces.com/problemset/problem/1485/C)
2. [CF 1355C – Count Triangles](https://codeforces.com/problemset/problem/1355/C)
3. [CF 1463C – Busy Robot](https://codeforces.com/problemset/problem/1463/C)
4. [CF 1380C – Create The Teams](https://codeforces.com/problemset/problem/1380/C)
5. [CF 1497C1 – k-LCM (easy version)](https://codeforces.com/problemset/problem/1497/C1)

---

⚡ This is the **exact Week 1 locked schedule with CF links**.

Want me to also annotate which **template/track** each problem belongs to (e.g. greedy, two-pointer, DP, etc.) so you can instantly recall why it’s there?

*/

/*
Got it—you want **fresh Div.2-only (or Educational rated for Div.2) B/C problems**, not Div.3/4. Here’s a clean 5-pack that fits your bar and maps to solid templates:

**1) CF 1622C — Set or Decrease (Div.2 C)**
Template: Greedy + Binary search on answer / sorting.
Link: [https://codeforces.com/problemset/problem/1622/C](https://codeforces.com/problemset/problem/1622/C) ([Codeforces][1])

**2) CF 1602C — Array Elimination (Div.2 C)**
Template: Bitwise counts / number theory (gcd of frequencies).
Link: [https://codeforces.com/problemset/problem/1602/C](https://codeforces.com/problemset/problem/1602/C) ([Codeforces][2])

**3) CF 1526B — I Hate 1111 (Round #723 Div.2 B)**
Template: Number theory + constructive reasoning.
Link: [https://codeforces.com/problemset/problem/1526/B](https://codeforces.com/problemset/problem/1526/B) ([Codeforces][3])

**4) CF 1730B — Meeting on the Line (Round #823 Div.2 B)**
Template: Greedy + binary/ternary search over meeting point.
Link: [https://codeforces.com/problemset/problem/1730/B](https://codeforces.com/problemset/problem/1730/B) ([Codeforces][4], [vjudge.net][5])

**5) CF 1626C — Monsters and Spells (Educational Round 121, rated for Div.2 C)**
Template: Greedy on merged intervals / prefix aggregation.
Link: [https://codeforces.com/problemset/problem/1626/C](https://codeforces.com/problemset/problem/1626/C) ([Codeforces][6])

If you want, I can slot these into a “Day X” with time caps and the exact template goals for that day.

[1]: https://codeforces.com/problemset/problem/1622/C?utm_source=chatgpt.com "Problem - 1622C - Codeforces"
[2]: https://codeforces.com/problemset/problem/1602/C?utm_source=chatgpt.com "Problem - 1602C"
[3]: https://codeforces.com/problemset/problem/1526/B?utm_source=chatgpt.com "Problem - 1526B"
[4]: https://codeforces.com/problemset/problem/1730/B?utm_source=chatgpt.com "Problem - 1730B"
[5]: https://vjudge.net/problem/CodeForces-1730B?utm_source=chatgpt.com "Meeting on the Line - CodeForces 1730B"
[6]: https://codeforces.com/problemset/problem/1626/C?utm_source=chatgpt.com "Problem - 1626C"

*/

/*
Alright, let’s give you **five hand-picked Codeforces problems** at a similar level as yesterday’s—tough enough to teach something new, but approachable so you won’t get stuck. I dug into Div2 B/C territory (\~1500–1700 rating), balancing familiarity with challenge.

---

### Suggested Problems to Practice

1. **[Problem 2024B – “Lemonade Machine” (Rating \~1500-1600)](https://codeforces.com/problemset/problem/2024/B)**

   * **Topic:** Greedy + reasoning about worst-case uncertainty.
   * **Why it fits:** Requires careful case breakdown and planning similar to template-building logic.

2. **[Problem 1600E – “Array Game” (Rating \~1600)](https://codeforces.com/problemset/problem/1600/E)**

   * **Topic:** Game theory, optimal play between two players.
   * **Why it fits:** A classic pick-left-or-right recursion—complexity lies in managing choices and strategy.

3. **[Problem 2104B – “Move to the End” (Rating \~1600)](https://codeforces.com/problemset/problem/2104/B)**

   * **Topic:** Prefix sums / aggregation and maximizing sums under operations.
   * **Why it fits:** Teaches careful accumulation and greedy selection—good for strengthening template logic.

4. **[Problem 2078C – “Breach of Faith” (Rating \~1700)](https://codeforces.com/problemset/problem/2078/C)**

   * **Topic:** Reconstruction from constraints.
   * **Why it fits:** Adds the flavor of constructive thinking—figuring out hidden elements from partial information.

5. **[Problem 1600C – “Restaurant Game” (Rating \~1600)](https://codeforces.com/problemset/problem/1600/C)**

   * **Topic:** Simulation with edge behavior and modular arithmetic.
   * **Why it fits:** Requires careful thought about movement rules and simulating efficiently for large $n$.

---

### Problem At-a-Glance Table

| Problem                  | Skill Focus                          |
| ------------------------ | ------------------------------------ |
| 2024B – Lemonade Machine | Greedy + worst-case planning         |
| 1600E – Array Game       | Game theory, optimal play            |
| 2104B – Move to the End  | Sum aggregation, greedy maximization |
| 2078C – Breach of Faith  | Constructive reconstruction          |
| 1600C – Restaurant Game  | Simulation under structured rules    |

---

### How to Approach

* **Set a timer** (e.g., 30–45 mins per problem). If you get stuck, pause and reflect on why.
* Write quick notes in your own words—don’t go straight to code. That helps build templates.
* Only peek at editorial or others’ solutions **after** you’ve tried, even if just to resolve a tricky thought.

This set avoids super-hard edge-cases but still digs into deeper reasoning. Let me know how it goes or if you want to walk through any problem logic—happy to guide you through patterns, invariants, or why something works when it seems stuck.

*/



