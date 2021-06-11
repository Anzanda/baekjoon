import numpy as np

def sigmoid(x):
    return 1 / (1+np.exp(-x))


def errorFunction(y, t):
    return np.sum((y-t)**2)

    
X = np.array([-1,4])


W1 = np.array([[6,-3],[-2,5]])
h1 = sigmoid(np.dot(X,W1))

W2 = np.array([[1,-2], [0.25, 2]])
y = sigmoid(np.dot(h1, W2)) # 

t = np.array([0,1])

print("Error: ",errorFunction(y, t))