import pandas as pd
from sklearn.tree import DecisionTreeClassifier 
from sklearn import tree
import numpy as np
from IPython.display import Image  
import pydotplus
import os 

col_names = ['toothed','hair', 'breathes', 'legs', 'label']
data = pd.read_csv("ai.csv", header=None, names=col_names)
data.head()
print("original\n", data)

data.toothed = data.toothed.replace(False, 0)
data.toothed = data.toothed.replace(True, 1)

data.hair = data.hair.replace(False, 2)
data.hair = data.hair.replace(True, 3)

data.breathes = data.breathes.replace(False, 4)
data.breathes = data.breathes.replace(True, 5)

data.legs = data.legs.replace(False, 6)
data.legs = data.legs.replace(True, 7)

data.label = data.label.replace('mammal', 8)
data.label = data.label.replace('reptile', 9)

print(data)

X = np.array(pd.DataFrame(data, columns=['toothed', 'hair', 'breathes', 'legs']))
y = np.array(pd.DataFrame(data, columns=['label']))



clf = DecisionTreeClassifier()
clf = clf.fit(X,y)
prediction = clf.predict(X)





os.environ["PATH"] += os.pathsep + 'C:/Program Files/Graphviz/bin/'
feature_names = data.columns.tolist()
feature_names = feature_names[0:4]
target_name = np.array(['mammal', 'reptile'])

dt_dot_data = tree.export_graphviz(clf, out_file = None,
                                   feature_names = feature_names,
                                   class_names = target_name,
                                   filled = True, rounded = True,
                                   special_characters = True)

dt_graph = pydotplus.graph_from_dot_data(dt_dot_data)
dt_graph.write_png('ai.png')
Image(dt_graph.create_png())
