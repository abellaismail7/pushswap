#!/usr/bin/python3
import random
import sys

a = sys.argv[1]
for i in random.sample(range(1000000), int(a)) :
    print(i, end=' ')
