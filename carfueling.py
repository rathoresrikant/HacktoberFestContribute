# python3
import sys


def compute_min_refills(distance, tank, stop):
    stop = [0]+stop+[distance]
    loc = 0
    refills = 0
    while loc <= n:
        last = loc
        while (loc <= n) and (stop[loc+1]-stop[last] <= tank):
            loc += 1
        if loc == last:
            return -1
        if loc <= n:
            refills += 1
    return refills


if __name__ == '__main__':
    d = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    stops = list(map(int, sys.stdin.readline().split()))
    print(compute_min_refills(d, m, stops))
