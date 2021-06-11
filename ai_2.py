import numpy as np
import math

def entropy(p1, p2):
    return -p1*math.log(p1,2) - p2*math.log(p2,2)

p1 = float(input("p1: "))
p2 = float(input("p2: "))

print("entropy: ", entropy(p1,p2))