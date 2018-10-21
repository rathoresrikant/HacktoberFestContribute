#!/usr/bin/python3

def knapsack(W, wt, val):
    k = [[0 for _ in range(W+1)] for _ in range(2)]

    for i in range(len(wt)):
        curr = i % 2
        prev = (i+1) % 2

        for w in range(W+1):
            if wt[i] <= w:
                k[curr][w] = max(val[i] + k[prev][w-wt[i]], k[prev][w])
            else:
                k[curr][w] = k[prev][w]

    return k[1][W] if len(wt) % 2 == 0 else k[0][W]


def main():
    n = int(input())
    val = [int(input()) for _ in range(n)]
    wt = [int(input()) for _ in range(n)]
    W = int(input())
    print(knapsack(W, wt, val))


if __name__ == "__main__":
    main()
