# Computor_V1
This project is the first in a series that aims to make you rekindle with maths.

# Introduction
This project aims to make you code a simple equation solving program. It will take **polynomial equations** into account. 

These equations will only require exponents. No complex function. The program will have to display its solution(s).

Why polynomials? 

Just because it’s one of the simplest and most powerful tools in
mathematics. It is used in every field on every level to simplify and express many things.

For instance, they help calculate functions such as _sin_, _cos_, _tan_, etc.
Or check out the [Stone–Weierstrass theorem](https://en.wikipedia.org/wiki/Stone%E2%80%93Weierstrass_theorem)

# Mandatory part
Write a program that solves a polynomial second or lower degree equation. You will have
to show at least:
- The equation in its reduced form.
- The degree of the equation.
- It’s solution(s) and the polarity of the discriminant if it makes sens.

examples:
```sh
$>./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131
$>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
Reduced form: 1 * X^0 + 4 * X^1 = 0
Polynomial degree: 1
The solution is:
-0.25
./computor "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
Reduced form: 5 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 0
Polynomial degree: 3
The polynomial degree is strictly greater than 2, I can't solve.
```

We will always expect the entry to have the right format, ie. every term respect the
form `a∗x^p`

Exponents are organized and present. Beware, it doesn’t mean the equation
has a solution! If so, your program should detect it and specify it. 

You should also think of zero, negative or non whole coefficients...

There might be exceptions you will have to manage. In the equation 42∗X^0 = 42∗X^0, for instance, each real number is a solution...

Third degree equation resolution is not required.

# Bonus part
Here is a bonus list you might want to implement:
- Manage entry mistakes (vocabulary and syntax).
- Manage free form entrie.

```sh
./computor "5 + 4 * X + X^2= X^2"
Reduced form: 5 + 4 * X = 0
Polynomial degree: 1
The solution is:
-1.25
```
- Display solution(s) as an irreducible fraction if it’s interesting.
- Display the intermediate steps.
- ...
# Useful Links
https://blogs.sas.com/content/iml/2016/05/16/babylonian-square-roots.html
