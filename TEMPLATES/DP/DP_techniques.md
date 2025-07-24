# Dynamic Programming Techniques

In this note, I will share some non-trivial dynamic programming techniques that I find useful.

---

## 1. Open & Close Interval Trick

**Problem**: https://cses.fi/problemset/task/1665

Your company has \(n\) coders, each with a skill level between 0 and 100. You need to divide the coders into teams so that the sum of penalties is at most \(x\). A team’s penalty is defined as the difference between the highest and lowest skill levels within that team.

**Key idea**: Since only the minimum and maximum skills in each team matter, sort the skill levels in non-decreasing order.

Define \(dp[i][j][k]\) as the number of ways to form teams from the first \(i\) coders, with \(j\) “unfinished” teams (teams that have a minimum but no maximum yet), and a net penalty of \(k\). When coder \(l\) starts a team, we subtract \(t_l\) from the penalty; when coder \(r\) closes a team, we add \(t_r\).

To transition from coder \(i-1\) to coder \(i\), consider four cases:

1. **Coder \(i\) works alone**: contributes 0 to the penalty.  
   \[ dp[i][j][k] += dp[i-1][j][k] \]

2. **Coder \(i\) joins an unfinished team**: contributes 0 to the penalty, but there are \(j\) unfinished teams to choose from.  
   \[ dp[i][j][k] += j \times dp[i-1][j][k] \]

3. **Coder \(i\) closes a team**: contributes \(+t_i\) to the penalty, and reduces the count of unfinished teams by 1. There are \(j\) unfinished teams.  
   \[ dp[i][j-1][k + t_i] += j \times dp[i-1][j][k] \]

4. **Coder \(i\) opens a new team**: contributes \(-t_i\) to the penalty, increasing unfinished teams by 1.  
   \[ dp[i][j+1][k - t_i] += dp[i-1][j][k] \]

**Implementation notes**:
- Since penalties can be negative in our DP formulation, shift the penalty index by an offset when implementing, so that it always stays non-negative.
- To save memory, avoid allocating a full 3D array of size \(n \times n \times X\). Instead, use rolling arrays or hash maps.

