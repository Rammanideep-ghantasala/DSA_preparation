/*In this you can find some important techniques and algorithms to solve some advanced problems
1.)SLIDING WINDOW TECHNIQUE:Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data (arrays or strings) and then moving that window across the data to perform some operation within the window. This technique is commonly used in algorithms like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.
How to use Sliding Window Technique?
There are basically two types of sliding window:

1. Fixed Size Sliding Window:
The general steps to solve these questions by following below steps:

Find the size of the window required, say K.
Compute the result for 1st window, i.e. include the first K elements of the data structure.
Then use a loop to slide the window by 1 and keep computing the result window by window.
2. Variable Size Sliding Window:
The general steps to solve these questions by following below steps:
In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
We follow these steps until we reach to the end of the array.*/
