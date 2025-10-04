# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge and quick sorts are going to be explored in the team activity for Module 06. You can start on it now, but welcome to wait.

 

### Table [^note]
| N | Bubble | Selection | Insertion | Merge | Quick |
|---|--------|-----------|-----------|-------|-------|
| 1 | 0.000000 | 0.000000 | 0.000000 | 0.000000 | 0.000002 |
| 100 | 0.000012 | 0.000007 | 0.000003 | 0.000005 | 0.000006 |
| 1000 | 0.000741 | 0.000337 | 0.000209 | 0.000055 | 0.000050 |
| 5000 | 0.017600 | 0.007603 | 0.005200 | 0.000342 | 0.000296 |
| 10000 | 0.070632 | 0.030043 | 0.020727 | 0.000717 | 0.000635 |
| 20000 | 0.283691 | 0.118526 | 0.082086 | 0.001519 | 0.001351 |
| 30000 | 0.661037 | 0.266084 | 0.187009 | 0.002396 | 0.002103 |
| 40000 | 1.234059 | 0.474748 | 0.329944 | 0.003238 | 0.002964 |
| 50000 | 2.098254 | 0.743368 | 0.516032 | 0.004094 | 0.003608 |
| 75000 | 6.034614 | 1.671856 | 1.157118 | 0.006314 | 0.005522 |
| 100000 | 14.434092 | 4.470347 | 3.697982 | 0.012817 | 0.011126 |

## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth. Due to speed differences, you may need to break up the $O(\log n)$ and $O(n^2)$ into different charts.

Include the image in your markdown. As a reminder, you save the image in your repo, and use [image markdown].

![Runtime Growth of Quadratic Sorting Algorithms - Bubble, Selection, Insertion](https://github.com/CS5008Fall2025/homework-sorts-skakked/blob/main/Files/QudraticSorts.png)

![Runtime Growth of Logarithmic Sorting Algorithms - Merge and Quick](https://github.com/CS5008Fall2025/homework-sorts-skakked/blob/main/Files/LogarithmicSorts.png)


### 2. Analysis
Looking at the graph and the table, what can you say about the various sorts? Which are the fastest? Which are the slowest? Which are the most consistent? Which are the least consistent? Use this space to reflect in your own words your observations.

> Quick Sort and Merge Sort are the fastest algorithms, with Quick achieving ≈0.011s and Merge ≈0.013s at N=100,000, while Bubble Sort is the slowest at ≈14.43s wjich is approximately a 1,300x performance difference. Among O(n²) algorithms, Insertion Sort consistently outperforms Selection Sort (3.70s vs. 4.47s at N=100,000). Merge Sort is the most consistent algorithm, showing predictable O(n log n) behavior regardless of input ordering, while Bubble Sort exhibits the highest variance because nearly-sorted arrays benefit from early-exit optimization but reverse-sorted arrays lead to maximum comparisons.


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do.

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Bubble Sort [1] | O(n) | O(n²) | O(n²) |
| Selection Sort[1] | O(n²) | O(n²) | O(n²) |
| Insertion Sort [1] | O(n) | O(n²) | O(n²) |
| Merge Sort [1] | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort [1] | O(n log n) | O(n log n) | O(n²) |


#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

| Algorithm | Worst Case Complexity | Example Array |
|-----------|---------------------|---------------|
| Bubble Sort [2] | O(n²) | `[5, 4, 3, 2, 1]` |
| Selection Sort [2] | O(n²) | Any array |
| Insertion Sort [2] | O(n²) | `[5, 4, 3, 2, 1]` |
| Merge Sort [2] | O(n log n) | Any array |



#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 

| Algorithm | Best Case Complexity | Example Array |
|-----------|---------------------|---------------|
| Bubble Sort [2] | O(n) | `[1, 2, 3, 4, 5]` |
| Selection Sort [2] | O(n²) | Any array |
| Insertion Sort [2] | O(n) | `[1, 2, 3, 4, 5]` |
| Merge Sort [2] | O(n log n) | Any array |


#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

> Memory Usage Ranking (Most to Least): Merge Sort O(n), Quick Sort o(log n), Bubble Sort O(1), Selection Sort O(1), Insertion sort O(1) [4]


### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$
#### Categories

* O(1) - Constant: $100$, $10000$
* O(n) - Linear: $3n$, $100n$
* O(n log n) - Linearithmic: $n\log_2n$
* O(n²) - Quadratic: $n^2$, $5n^2+5n$
* O(2^n) - Exponential: $2^n$, $2^{(n-1)}$
* O(n!) - Factorial: $n!$


### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    | Cubic |
| $O(1)$      | Constant |
| $O(n)$      | Linear |
| $O(\log_2n)$ | Logarithmic |
| $O(n^2)$    | Quadratic |
| $O(n!)$     | Factorial |
| $O(2^n)$    | Exponential |



### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  
> A stable sorting algorithm is a sorting method that preserves the relative order of elements that are considered equal according to the sorting criteria. [5]
> Merge sort is stable because the relative order is maintained because it always sorts from the left subarray first preserving order. Quick sort is unstable because it doesn't preserve the original order because swaps elements around without tracking its order. [5]

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 
> We need stability in cases where we are sorting by multiple criteria or when equal elements have additional information that shouldn't be lost. For example sorting for a shopping site, sorting products by category and then by price within each category. [5]


### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.
> We can use divide and conquer. First lets divide i.e., Split the n number of coins into A, B and C. Then conquer i.e., determine which of the 3 pile has the rare coin (via weighing). A against B of they balance the heavy coin is in C, if not, its in the heavier of the A or B. Discard the other two piles and repeat the sameway split on the suspect pile until a single coin remains. This is effectively a ternary search, requiring about $\\log_{3} n$ weighings (approx. 5 for 250). [4,5]

#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 
> Each weighing discards roughly $ \tfrac{2}{3} $ of the coins, so the number of weighings grows like:
> Average / expected: $ \Theta(\log_{3} n) $ (about $ \log_{3} n $ weighings) [4.5]
> Worst case: $ \lceil \log_{3} n \rceil $ weighings due to uneven splits
> For $ n = 250 $: $ \log_{3} 250 \approx 5.03 $ which is about 5 on average and worst case would be $ \le 6 $ weighings
> Average time complexity  would be $ \Theta(\log_{3} n) $ [4,5]

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

> When would we want an algorithm with a higher time complexity than another faster algorithm?
> Answer: When you have nearly sorted data because insertion Sort is O(n²) worst case but O(n) for nearly sorted data. On partially sorted arrays, it can beat Quick Sort or Merge Sort despite worse theoretical complexity. A second reason a programmer might chose an algorithm with a higher time complexity is when you have a small dataset like for small n (n < 50), simpler O(n²) algorithms like insertion sort can outperform O(n log n) algorithms due to fewer operations. [5]


2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

> Leetcode Problem 20. Valid Parentheses: https://github.com/CS5008Fall2025/homework-sorts-skakked/blob/main/Files/Leetcode_20_Valid_Parentheses.c
 

## Deeper Thinking
Sorting algorithms are still being studied today. They often include a statistical analysis of data before sorting. This next question will require some research, as it isn't included in class content. When you call `sort()` or `sorted()` in Python 3.6+, what sort is it using? 

> Python 3.6 through 3.10 uses Timsort, a hybrid sorting algorithm that combines insertion sort and merge sort. [6] Starting with Python 3.11, Python switched to Powersort.[7]  

#### Visualize
> Find a graphic / visualization (can be a youtube video) that demonstrates the sort in action.
> Timsort Visualization: https://www.chrislaux.com/timsort

#### Big O
Give the worst and best case time-complexity, and examples that would generate them. 
> Best Case: Best-case time complexity is O(n), which occurs when the input array is already sorted. E.g. [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] [6]

> Worst Case: The worst-case time complexity is O(n log n). E.g. Random data with no eixsting order, a random array of integers 1 to 100. [6]

<hr>

## References
Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Use [ACM Reference format].

1. Bhargava, A. 2016. Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People. Manning Publications, Shelter Island, NY. ISBN 9781617292231.
2. Rowell, E. n.d. Big-O Algorithm Complexity Cheat Sheet (Know Thy Complexities!). BigOCheatSheet.com. Retrieved October 4, 2025 from https://www.bigocheatsheet.com/
3. GeeksforGeeks. 2025. Analysis of Algorithms. Big-O analysis. (August 27, 2025) Retrieved September 7, 2025 from https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/
4. Cormen, T. H., Leiserson, C. E., Rivest, R. L., and Stein, C. 2022. Introduction to Algorithms (4th ed.). MIT Press, Cambridge, MA. ISBN 978-0262046305.
5. Sedgewick, R., and Wayne, K. Algorithms, 4th Edition (Companion Site). Princeton University. Accessed Oct. 4, 2025.
6. GeeksforGeeks. 2025. Tim Sort in Python. Retrieved Oct. 4, 2025 from https://www.geeksforgeeks.org/dsa/tim-sort-in-python/
7. James, M. 2022. Python Now Uses Powersort. i-Programmer, Dec. 21, 2022. Retrieved Oct. 4, 2025 from https://www.i-programmer.info/news/216-python/15954-python-now-uses-powersort.html





## Footnotes:
[^note]: You will want at least 10 different N values, probably more to see the curve for Merge and Quick. If bubble, selection, and insertion start to take more than a  minute, you can say $> 60s$ or - . For example 
    | N | Bubble | Selection | Insertion | Merge | Quick |
    | :-- | :--: | :--: | :--: | :--: | :--: |
    | 10,000|0.197758|0.070548|0.000070|0.000513|0.000230|
    |100,000|-|-|-|0.131061|0.018602|

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf