# Exhaustive Search on Key Cells of First Round Key K1 for GIFT
### Find all the *l*'s which satisfies *s(q + k) + s(q' + k) = l*, for all possible *q*, *q'*, *k*, and *q != q'* under *GF(2^4)* and AES's S-box. Variables *p*, *p'*, *k*, and *m* are polynomials under *GF(2^4)*.

Both programs, `Q1Q2K.cpp` and `Q1Q2K_SIMPLIFY.cpp`, exhaustively simulate all 16 *k*'s under each possible combinations of *q* and *q'*, with constraint *q != q'*. The total possible *{q, q'} * 's are are *15 + 14 + ... + 2 + 1 = 120*. `Q1Q2Q3K_SIMPLFY.cpp` exhaustively simulate all 16 *k*'s under all possible combinations of *q*, *q'*, *q''*, with constraint *q != q'!= q''*. The total possible *{q, q',q''}*'s are are *C(16,3)= 16\*15\*14/(3*2*1)=560*.

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
