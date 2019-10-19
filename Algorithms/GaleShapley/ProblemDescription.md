## Stable Matching Problem
Used the Gale-Shapley algorithm to solve this problem
### Problem Statement
Given an equal number of men and women to be paired for marriage, each man ranks all the women in order of his preference and each woman ranks all the
men in order of her preference. A stable set of engagements for marriage is one where no man prefers a woman over the one he is engaged to, where that other woman also prefers that man over the one she is engaged to. i.e. with consulting marriages, there would be no reason for the engagements between the people to change. Use the stable matching algorithm to find a stable set of engagements.

- **Input Format**
    1st line of the input mentions the number of men or women, **n**, for which the stable marriage problem is going to be solved.
    The next *n* lines will denote the priority list of the men. Each *i^th^* line will contain *n* entries corresponding to the priority of the women, where the leftmost women will be given the highest priority.
    The next *n* lines after this will contain the women priority list in the same format.
    All indexes of men and women are 0-based.
    *Example Input*:
    This input corresponds to the input data which is given in the assignment.
    ```
    5
    0 1 4 2 3
    0 2 3 1 4
    3 1 4 0 2
    4 3 2 1 0
    2 3 0 1 4
    0 1 2 4 3
    2 1 4 3 0
    3 4 0 2 1
    4 2 3 0 1
    0 3 4 2 1
    ```
- **Output Format**
    The output will contain *n* lines of matched pairs between the men and women.
    *Example Output*:
    This output is corresponding to the input above.
    ```
    (0, 0)
    (1, 1)
    (2, 3)
    (3, 4)
    (4, 2)
    ```
