# List 00 LP/EDB I
List created to provide a warm-up for the newcomers on **LP/EDB I** Course with
Selan.

## Instructions
Each given problem will have a topic linked to it. After you finish the problem 
set, you will be able to report on the [**Feedback**](#feedback) session which topics you felt
less comfortable with.

## Summary
+ [Problem I](#problem-i)
+ [Problem II](#problem-ii)
+ [Problem III](#problem-iii)
+ [Problem IV](#problem-iv)
+ [Problem V](#problem-v)
+ [Problem VI](#problem-vi)
+ [Problem VII](#problem-vii)

## Problem Set
Try to solve the problems with the best solution you can think of. Some problems
came from **URI** - a popular programming competition website - which you can 
submit the code to check if it's correct and optimized.

### Problem I 
#### Topic
Unidimensional arrays - [URI 1178](https://www.urionlinejudge.com.br/judge/en/problems/view/1178)

#### Problem
Read a number `X`. Put this `X` at the first position of an array `N[100]`. 
In each subsequent position (1 up to 99) put half of the number inserted at the
previous position, according to the example below. Print all the vector `N`.

##### Input
The input contains a double precision number with four decimal places.

##### Output
For each position of the array `N` print `N[i] = Y`, where `i` is the array 
position and `Y` is the number stored in that position. Each number of `N[...]`
must be printed with 4 digits after the decimal point.

##### Examples
Input Sample:
```
200.0000
```

Output Sample:
```
N[0] = 200.0000
N[1] = 100.0000
N[2] = 50.0000
N[3] = 25.0000
N[4] = 12.5000
...
```

### Problem II
#### Topic
Unidimensional arrays

#### Problem
Given an unordered list of flights taken by someone, each represented as `(origin,
destination)` pairs, and a starting airport, compute the person's itinerary. If 
no such itinerary exists, return `null`. If there are multiple possible itineraries,
return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights `[('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL',
'YYZ'), ('HKO', 'ORD')]` and starting airport `'YUL'`, you should return the list 
`['YUL', 'YYZ', 'SFO', 'HKO', 'ORD']`.

Given the list of flights `[('SFO', 'COM'), ('COM', 'YYZ')]` and starting airport
`'COM'`, you should return `null`.

Given the list of flights `[('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]` and
starting airport `'A'`, you should return the list `['A', 'B', 'C', 'A', 'C']` 
even though `['A', 'C', 'A', 'B', 'C']` is also a valid itinerary. However, the 
first one is lexicographically smaller.

### Problem III
#### Topic
N-dimensional arrays - [URI 1182](https://www.urionlinejudge.com.br/judge/en/problems/view/1182)

#### Problem
Your job in this problem is to read a number that is a column of an array where
an operation will be performed, an uppercase character, indicating the operation
to be performed and all elements of a bidimentional array `M[12][12]`. Then, you 
have to calculate and print the sum or average of all elements within the green 
area according to the case. The following figure illustrates the case when is 
entered the number 5 to the array column, showing all elements that must be 
considered in the operation.

![Problem image](https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_1182.png "Problem Image")

##### Input
The first line of the input contains a simple integer `C` (0 ≤ `C` ≤ 11) 
indicating the column to be considered in the operation. The second line of the 
input contains a single uppercase character `T` (`S` or `M`), indicating the operation 
**S**um or Average (**M**édia in portuguese) to be performed with the elements of the 
array. Follow 144 floating-point numbers of the array.

##### Output
Print the calculated result (sum or average), with one digit after the decimal 
point.

##### Examples
Input Sample:
```
5
S
1.0
-3.5
2.5
4.1
...
```

Output Sample:
```
12.6
```

### Problem IV
#### Topic
N-dimensional arrays - [URI 1186](https://www.urionlinejudge.com.br/judge/en/problems/view/1186)

#### Problem
Read an uppercase character that indicates an operation that will be performed 
in an array `M[12][12]`. Then, calculate and print the sum or average considering 
only that numbers that are below of the Secundary diagonal of the array, 
like shown in the following figure (green area).

![Problem Image](https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_1186.png)

##### Input
The first line of the input contains a single uppercase character `O` (`S` or `M`), 
indicating the operation **S**um or Average (**M**édia in portuguese) to be performed 
with the elements of the array. Follow 144 floating-point numbers of the array.

##### Output
Print the calculated result (sum or average), with one digit after the decimal point.

##### Examples
Input Sample:
```
S
5.0
0.0
-3.5
2.5
4.1
...
```

Output Sample:
```
12.6
```

### Problem V
#### Topic
Functions - [URI 1153](https://www.urionlinejudge.com.br/judge/en/problems/view/1153)
#### Problem
Read a value **N**. Calculate and write its corresponding factorial. Factorial 
of N = N * (N-1) * (N-2) * (N-3) * ... * 1

**Implement both iterative/recursive versions**.

##### Input
The input contains an integer value **N**.

##### Output
The output contains an integer value corresponding to the factorial of **N**.

##### Examples
Input Sample:
```
4
```

Output Sample:
```
24
```

### Problem VI
#### Topic
Functions - [URI 1154](https://www.urionlinejudge.com.br/judge/en/problems/view/1154)

#### Problem
Write an algorithm to read an undeterminated number of data, each containing an 
individual's age. The final data, which will not enter in the calculations, 
contains the value of a negative age. Calculate and print the average age of 
this group of individuals.

##### Input
The input contains an undetermined number of integers. The input will be stop 
when a negative value is read.

##### Output
The output contains a value corresponding to the average age of individuals.

The average should be printed with two digits after the decimal point.

##### Examples
Input Sample:
```
34
56
44
23
-2
```

Output Sample:
```
39.25
```

### Problem VII - Bônus
#### Topic
Pointers - [Problem II](#problem-ii)

#### Problem
Now, reimplement the **Problem II** using pointers to help with the logic of 
the problem. Be creative!

## Feedback
Please, submit a report [here](https://goo.gl/forms/L5msU3plYzNYh1cf1).