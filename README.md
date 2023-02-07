# 一些语法相关的笔记

## JAVA

#### 按照特殊顺序排列数组

``` java
// java
List<String> rec = new ArrayList<String>();
Collections.sort(rec, new Comparator<String>() {
    public int compare(String word1, String word2) {
        // 从小到大：word1 - word2 ; 从大到小：word2 - word1
        return cnt.get(word1) == cnt.get(word2) ? word1.compareTo(word2) : cnt.get(word2) - cnt.get(word1);
}
```

``` c++
// C++
sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
    return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
});
```

#### 特殊规定的PriorityQueue

``` java
PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<Map.Entry<String, Integer>>(new Comparator<Map.Entry<String, Integer>>() {
    public int compare(Map.Entry<String, Integer> entry1, Map.Entry<String, Integer> entry2) {
        eturn entry1.getValue() == entry2.getValue() ? entry2.getKey().compareTo(entry1.getKey()) : entry1.getValue() - entry2.getValue();
            }
        });
```

## C++
