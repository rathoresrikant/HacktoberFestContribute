#!/usr/bin/python3

def knapsack(W, wt, val):
    k = [[0 for _ in range(W+1)] for _ in range(len(wt) + 1)]

    for i in range(1, len(wt)+1):
        for w in range(1, W+1):
            if wt[i-1] <= w:
                k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w])
            else:
                k[i][w] = k[i-1][w]

    return k[len(wt)][W]


def main():
    n = int(input())
    val = [int(input()) for _ in range(n)]
    wt = [int(input()) for _ in range(n)]
    W = int(input())
    print(knapsack(W, wt, val))


if __name__ == "__main__":
        main()
