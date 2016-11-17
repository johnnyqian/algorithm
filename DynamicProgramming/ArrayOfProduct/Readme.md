## Problem description
Given an array of numbers, replace each number with the product of all the numbers in the array except the number itself without using division.

See more [Google Interview: Software Engineer in Test](https://gist.github.com/johnnyqian/efff21ad4dce6bb7f3cc69a71952a8f2#google-interview-software-engineer-in-test)

### There is also a thread on StackOverflow regarding this problem:

[Given an array of numbers, return array of products of all other numbers (no division)](http://stackoverflow.com/questions/2680548/given-an-array-of-numbers-return-array-of-products-of-all-other-numbers-no-div)

>I was asked this question in a job interview, and I'd like to know how others would solve it. I'm most comfortable with Java, but solutions in other languages are welcome.
>
>Given an array of numbers, nums, return an array of numbers products, where products[i] is the product of all nums[j], j != i.
>
>Input : [1, 2, 3, 4, 5]
Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
      = [120, 60, 40, 30, 24]
You must do this in O(N) without using division.