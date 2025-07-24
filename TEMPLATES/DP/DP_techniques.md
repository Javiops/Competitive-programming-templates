# Dynamic Programming Techniques

Here I am going to share some non-trivials techniques (at least for me) that I happen to like.

---

## 1. Open & Close Interval Trick

https://cses.fi/problemset/task/1665

Your company has n coders, and each of them has a skill level between $0$ and $100$. Your task is to divide the coders into teams that work together.

Based on your experience, you know that teams work well when the skill levels of the coders are about the same. For this reason, the penalty for creating a team is the skill level difference between the best and the worst coder.

In how many ways can you divide the coders into teams such that the sum of the penalties is at most x?

The first thing to notice is that for each team we only care about the minimum and the maximum skill level, to make computing easier, sort the array in non-decreasing order. Let $dp[i][j][k]$ The number of ways we can form teams from the first $i$ people such that there are $j$ "unfinished" teams and the total penalty so far is $k$. If the $l-th$ person has the lowest skill in the team then its contribution will be $-t_l$. If the $r-th$ person is the one to close a team, then its contrubution will be $t_r$.

