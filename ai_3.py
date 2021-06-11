import numpy as np

x = [[90, 60, 90],
     [90, 90, 30],
     [60, 60, 60],
     [60, 60, 90],
     [30, 30, 30]]
x = np.array(x)
v = [0.38, 0.25, 0.37]
v = np.array(v)
print(np.dot(x, v.T))

# norm_x = x-x.mean(axis=0)

# a = np.dot(norm_x.T, norm_x)
# a /= 5
# print(a)
# w, v = np.linalg.eig(a)
# print("eigen value: ", w)
# print("eigen vector: ", v)


