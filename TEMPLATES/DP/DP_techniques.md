# Dynamic Programming Techniques Cheat‑Sheet

A quick reference of common DP optimizations and “tricks” to help you speed up transitions, reduce memory, or simplify implementation. Includes:

- Open & Close Interval Trick  
- Prefix/Suffix Sum Optimization  
- Monotonic Queue (Sliding Window)  
- Divide‑&‑Conquer Optimization  
- Knuth Optimization  
- Convex Hull Trick  
- Bitmask / State‑Compression DP  

---

## 1. Open & Close Interval Trick

**Use case:** When many DP transitions add or remove the same cost/value over contiguous ranges of states, you can avoid an inner loop by “sweeping” adds/removes.

### Idea

1. Precompute two arrays (or event lists):  
   - `open[i]` = list of values to **add** when entering state _i_.  
   - `close[i]` = list of values to **subtract** when leaving state _i_.

2. Maintain a running accumulator `cur` as you iterate your DP index `i` in increasing order:
   ```pseudo
   cur ← 0
   for i in 0…N:
     for v in open[i]:
       cur += v
     dp[i] = min(dp[i], cur, …)   # or use `cur` in your transition
     for v in close[i]:
       cur -= v
