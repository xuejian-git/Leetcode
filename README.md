# 一些语法相关的笔记和处理技巧

## JAVA

#### 按照特殊顺序排列数组

```java
// java
List<String> rec = new ArrayList<String>();
Collections.sort(rec, new Comparator<String>() {
    public int compare(String word1, String word2) {
        // 从小到大：word1 - word2 ; 从大到小：word2 - word1
        return cnt.get(word1) == cnt.get(word2) ? word1.compareTo(word2) : cnt.get(word2) - cnt.get(word1);
}
```

```c++
// C++
sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
    return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
});
```

#### 特殊规定的PriorityQueue

```java
PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<Map.Entry<String, Integer>>(new Comparator<Map.Entry<String, Integer>>() {
    public int compare(Map.Entry<String, Integer> entry1, Map.Entry<String, Integer> entry2) {
        eturn entry1.getValue() == entry2.getValue() ? entry2.getKey().compareTo(entry1.getKey()) : entry1.getValue() - entry2.getValue();
            }
        });
```

#### 处理类似"10:20"格式的时间

[leetcode](https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/solution/jing-gao-yi-xiao-shi-nei-shi-yong-xiang-ioeiw/)

```java
// keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"]
// keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]

Map<String, List<Integer>> timeMap = new HashMap<String, List<Integer>>();
int n = keyName.length;
for (int i = 0; i < n; i++) {
    String name = keyName[i];
    String time = keyTime[i];
    timeMap.putIfAbsent(name, new ArrayList<Integer>());
    // 时间转minute方法
    int hour = (time.charAt(0) - '0') * 10 + (time.charAt(1) - '0');
    int minute = (time.charAt(3) - '0') * 10 + (time.charAt(4) - '0');
    timeMap.get(name).add(hour * 60 + minute);
}
```

## C++

#### 消除报错

```cpp
#include<bits/stdc++.h>
using namespace std;
```
