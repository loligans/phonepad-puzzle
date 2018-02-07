# Description
This numerical puzzle originates from the Turkish Intelligence Foundation sent to Will Shortz by Turkish puzzler Metin Orsel. 

| No crossing digits - <span style="color:green">Valid</span> | Crossing digits - <span style="color:green">Valid</span> | Reusing digits - <span style="color:red">Invalid</span> |
|:-----------------------:|:--------------------:|:----------------------------:|
|![phonepad no crossing](https://imgur.com/IjFiynj.png)|![phonepad crossing](https://imgur.com/0Zgcnc1.png)|![phonepad crossing](https://imgur.com/uHqXhYS.png)|
|125 + 478 = 690 (**<span style="color:green">false</span>**) | 152 + 478 = 690 (**<span style="color:green">false</span>**) | 125 + 485 = 690 (**<span style="color:red">Invalid</span>**)|

## How it works
1. First you start with a any digit on a telephone keypad. 
2. Then you move to another digit adjacent from the previous digit either: horizontally, vertically or diagonally. 
3. Continue the process until you have 9-digits total.
4. When you have collected your 9-digits the number formed from the first 3-digits plus the second 3-digits will equal the last 3-digits.

## Requirements
+ You may **_not_** use the same digit more than once.
+ You may **_only_** use digits adjacent to each other.

## Extra
**Optional:** To make things more difficult check to make sure adjacent digits do not cross paths.

# Projects
This repository contains the solution to the phonepad problem in 2-languages: C++ and Typescript. To figure out how to build and run the projects continue reading below. **I highly recommend you try to solve this problem yourself first.**
## C++
This project assumes `cmake` and `make` are on your **PATH** variable.
1. Open a command/terminal window in the project root directory.
2. enter `cd .cmake; cmake .; make`
## Typescript
This project assumes you have `Node.js`, `NPM`, and `Gulp` installed globally.
1. Open a command/terminal window in the project root directory.
2. enter `npm install; gulp start`