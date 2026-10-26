# Interview prep: SDE2 / Google SWE III (L4) / L5

## Leveling

- Google: SWE II = L3, **SWE III = L4**, Senior SWE = L5.
- Amazon SDE2 ≈ Google L4. L5 at Google/Meta is senior, with a noticeably higher bar.

## What the coding bar looks like at these levels

- Classic mediums (e.g. Minimum Path Sum) are warm-ups: finish in ~15 minutes **including** the optimized
  version, leaving time for a harder follow-up or a second problem.
- Medium-hard is normal: DP on intervals/strings, graphs (BFS/DFS, topological sort, Dijkstra), heaps,
  sliding window, binary search on the answer, tries, union-find.
- At L4+ you are expected to drive optimizations yourself; at L3 the interviewer often prompts them.

## Correct first, but name the optimization up front

Building the straightforward version first is the right order. Say you know the better one before you start:

> "dp[i][j] only depends on the row above and the cell to the left, so this can be done in O(n) space.
> I'll write the 2-D version first so it's easy to verify, then compress it."

Staying silent until asked "can you do better on space?" reads as not knowing.

## Coding-round habits

- State the recurrence, base cases and time/space complexity before writing code.
- Walk through a small example and edge cases afterwards; catch your own bugs.
- Be ready for "can this overflow?" on any sentinel value (`INT_MAX` + something).
- Small polish gets noticed: cache `m`/`n`, avoid signed/unsigned comparisons, consistent formatting.

## What decides the level at L4/L5

- **System design**: often what separates L4 from L5; at L5 it can outweigh coding.
- **Behavioural / leadership**: ownership, scope, ambiguity, conflict (Google "Googleyness & Leadership",
  Amazon Leadership Principles).
- **Communication** throughout: trade-offs, testing, reacting to hints.

## Practice plan for this repo

- For every DP problem: recurrence, base case, complexity, and the space-optimized version.
- Time yourself: ~20 minutes per medium, explaining out loud.
- Broaden beyond grid DP: graphs and intervals next.
