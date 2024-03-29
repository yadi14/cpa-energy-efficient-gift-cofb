# Exhaustive Search on Key Cells of First Round Key K1 of GIFT-COFB

### Find all the *l*'s which satisfies *s(q + k) + s(q' + k) = l*, for all possible *q*, *q'*, *k*, and *q != q'* under *GF(2^4)* and GIFT's S-box. Variables *p, p', k*, and *m* are polynomials under *GF(2^4)*.

Both programs, `Q1Q2K.cpp` and `Q1Q2K_SIMPLIFY.cpp`, exhaustively simulate all 16 *k*'s under each possible combinations of *q* and *q'*, with constraint *q != q'*. The total possible *{q, q'}* 's are are *15 + 14 + ... + 2 + 1 = 120*. `Q1Q2Q3K_SIMPLFY.cpp` exhaustively simulate all 16 *k*'s under all possible combinations of *q, q', q''*, with constraint *q != q'!= q''*. The total possible *{q, q',q''}*'s are are *C(16,3)= 16\*15\*14/(3\*2\*1)=560*.

Verification is done in MATLAB with `verifyQ1Q2K.m` and `verifyQ1Q2Q3K.m` to confirm the statement made in <u>Section IV Result</u>.

# Quick Start
* Create three new directories

```
mkdir Q1Q2_verbose
mkdir Q1Q2_simplfy
mkdir Q1Q2Q3_simplfy
```
* Compile c++ program

```
g++ Q1Q2K.cpp -o q1q2k_verbose.out
g++ Q1Q2K_SIMPLFY.cpp -o q1q2k_simplify.out
g++ Q1Q2Q3K_SIMPLFY.cpp -o q1q2q3k_simplify.out
```
* Execute
```
./q1q2k_verbose.out
./q1q2k_simplify.out
./q1q2q3k_simplify.out
```
* Verify all text files in folder `Q1Q2_simplfy` that has at least two different key cells with the same value *l*.

Directly run `verifyQ1Q2K.m` in MATLAB. 

* Verify all text files in folder `Q1Q2Q3_simplfy` that 416 pairs of *{q, q',q''}* can uniquely determine a 4-bit key cell.

Directly run `verifyQ1Q2Q3K.m` in MATLAB.

# Observation
### There are multiple solutions of *k*  (for all 16 combinations) which have the same value of *l* of under any fixed *q, q'* and *q != q'*.
### 416 pairs of *{q, q',q''}* (out of 560 possibilities) which allow the attacker to uniquely identify the correct value for a 4-bit key. The summary list of all 416 pairs are stored in file `summaryList.log`.


# Software Tools
- g++ or MinGW
- MATLAB __R2020b__ or later release. `verifyQ1Q2K.m` and `verifyQ1Q2Q3K.m` use function [readlines](https://www.mathworks.com/help/matlab/ref/readlines.html), which is introduced on __R2020b__.

# Software Used
All C++ programs have tested under g++ 7.5.0. MATLAB program has been tested on both MATLAB __R2020b__ and __R2021a__.

# Publications
Y. Zhong, and U. Guin, “Chosen-Plaintext Attack on Energy-Efficient Hardware Implementation of GIFT-COFB,”  in IEEE International Symposium on Hardware Oriented Security and Trust (HOST), pp. 1-4, 2022. 
