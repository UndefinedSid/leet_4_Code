## PROBLEM --> 2975 (MEDIUM) --> Maximize Square Area – Complete Approach Guide (C++)
Topics --> ARRAY, HASH TABLE, ENUMERATION, CONTEST
This problem reduces to a **distance matching problem**, not a geometry problem.

We are given:

* Horizontal fences
* Vertical fences
* We must pick **two horizontal** and **two vertical** fences
* They must form a **square** → same side length
* Goal: **maximize (side × side)**

---

## 🔑 Core Observation

A square can be formed **iff** there exists a distance `d` such that:

* `d` is the distance between two horizontal fences
* `d` is also the distance between two vertical fences

So the task becomes:

> **Find the maximum common distance between all horizontal and vertical fence pairs.**

---

## 🧠 Approach 1: Brute Force (Not Efficient)

* Try every horizontal pair
* Try every vertical pair
* Compare distances

❌ **Time Complexity:** `O(H² × V²)`
❌ **Will TLE**

---

## 🧠 Approach 2: Distance Set (Recommended ✅)

### Steps:

1. Add borders: `1 & m`, `1 & n`
2. Sort fences
3. Compute **all horizontal distances** → store in `set`
4. Compute **all vertical distances**
5. If distance exists in set → update answer

### Complexity:

✅ `O(H² + V²)`
✅ Clean, readable, interview-friendly

✔️ **Best balance of simplicity and performance**

---

## 🧠 Approach 3: Two Pointer (Sorted Distances)

* Store all distances in two arrays
* Sort them
* Use two pointers to find max common distance

⏱️ `O(H² log H + V² log V)`
✔️ No hashing
❌ Slightly complex

---

## 🧠 Approach 4: Bitset Optimization (Advanced 🚀)

* Use bitset where index = distance
* Mark horizontal distances
* Check vertical distances using O(1) lookup

⏱️ `O(H² + V²)`
⚡ Very fast in practice
❌ Rarely expected in interviews

---

## 🚫 Common Mistakes

❌ Comparing fence positions instead of distances
❌ Only checking adjacent fences
❌ Using `vector.find()` (doesn’t exist in C++)

---

## 🏆 Final Verdict

| Approach     | Status           |
| ------------ | ---------------- |
| Brute Force  | ❌                |
| Distance Set | ⭐⭐⭐⭐⭐            |
| Two Pointer  | ⭐⭐⭐⭐             |
| Bitset       | ⭐⭐⭐⭐⭐ (Advanced) |

---
// 2nd Approach code 

class Solution {
public:
const int MOD= 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int ans=-1;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<int> hDist;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDist.insert(hFences[j] - hFences[i]);
            }
        }

        int side = 0;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int dist = vFences[j] - vFences[i];
                if (hDist.count(dist)) {
                    side = max(side, dist);
                }
            }
        }

     if (side == 0) 
        return -1;
     else{
        ans=( 1LL * side * side) % MOD;
     }

    return ans;
    }
};


## ✨ Key Takeaway

> Convert geometry into a **distance intersection problem**.

This shift makes the problem simple, elegant, and efficient.

---

💬 Feel free to fork, star ⭐, or suggest optimizations!
