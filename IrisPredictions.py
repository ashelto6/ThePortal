from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn import preprocessing
import numpy as np
import pickle
import sys

user_inputs = [sys.argv[1:5]]
inputs=np.array(user_inputs, dtype=np.float32)

flowers = load_iris()
flower_names = flowers.target_names

filename = '/home/pi/Documents/iris_finalized_model.sav'

try:
    loaded_model = pickle.load(open(filename, "rb"))
    print(flower_names[int(loaded_model.predict(inputs))])
    
except (OSError, IOError) as e:
    X_train, X_test, y_train, y_test = train_test_split(flowers.data, flowers.target, test_size=0.2) 
    
    model = LogisticRegression()
    model.fit(X_train, y_train)
    pickle.dump(model, open(filename, "wb"))
    print(flower_names[int(model.predict(inputs))])

