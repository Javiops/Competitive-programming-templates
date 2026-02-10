
# Dynamic Programming Techniques

Here I am going to share some non-trivials techniques (at least for me) that I happen to like.

---

## 1. Open & Close Interval Trick

https://cses.fi/problemset/task/1665

Your company has n coders, and each of them has a skill level between $0$ and $100$. Your task is to divide the coders into teams that work together.

Based on your experience, you know that teams work well when the skill levels of the coders are about the same. For this reason, the penalty for creating a team is the skill level difference between the best and the worst coder.

In how many ways can you divide the coders into teams such that the sum of the penalties is at most x?

The first thing to notice is that for each team we only care about the minimum and the maximum skill level, to make computing easier, sort the array in non‑decreasing order. Let $dp[i][j][k]$ be the number of ways we can form teams from the first $i$ people such that there are $j$ "unfinished" teams and the total penalty so far is $k$. If the $l$‑th person has the lowest skill in the team then their contribution will be $-t_l$. If the $r$‑th person is the one to close a team, then their contribution will be $t_r$.

We now consider 4 cases to transition from $i-1$ to $i$:

- The $i$‑th programmer is left alone, contributing $0$ to the total penalty, $dp[i][j][k] += dp[i - 1][j][k]$.

- The $i$‑th programmer is appended to an unfinished team, this contributes $0$ to the total penalty, but since there are $j$ unfinished team there are $j$ spots available, $dp[i][j][k] += j * dp[i - 1][j][k]$.

- The $i$‑th programmer closes a team, this contributes $t_i$ as stated above, $dp[i][j - 1][k + t_i] += j * dp[i - 1][j][k]$.

- The $i$‑th programmer opens a team, this contributes $-t_i$ as stated above, $dp[i][j + 1][k - t_i] += dp[i - 1][j][k]$.

Two important things: in our DP the penalty can be negative, so modify $x$ to account for this, and avoid creating a $3D$ array to save memory.
