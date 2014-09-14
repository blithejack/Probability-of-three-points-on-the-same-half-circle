#!/usr/bin/python
__author__ = 'blithejack'

import random

def gen():
    return random.uniform(0,2)

def maxDist(points):
    points.sort()
    return max(points[1] - points[0],
               points[2] - points[1],
               points[0] - points[2] + 2)

if __name__ == "__main__":
    n = 10000
    cnt = 0
    for i in range(n):
        dicing = [gen(), gen(), gen()]
        if maxDist(dicing) >= 1:
            cnt += 1
    pSameHalf = 1.0 * cnt / n
    print("The probability of three points on the same half circle is "+str(pSameHalf))
