import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score


df = pd.read_csv("pima-indians-diabetes.csv")
X = df.drop('Class', axis=1)
Y = df['Class']


X_train, X_test, Y_train, Y_test = train_test_split(
    X, Y, test_size=0.3, random_state=42
)

def evaluate(model, X_train, X_test, Y_train, Y_test):
    model.fit(X_train, Y_train)
    pred = model.predict(X_test)
    return [
        accuracy_score(Y_test, pred),
        precision_score(Y_test, pred),
        recall_score(Y_test, pred),
        f1_score(Y_test, pred)
    ]


lr = LogisticRegression(max_iter=1000)
knn = KNeighborsClassifier(n_neighbors=5)
dt = DecisionTreeClassifier()


print("BEFORE SCALING ")
print("Logistic:", evaluate(lr, X_train, X_test, Y_train, Y_test))
print("KNN:", evaluate(knn, X_train, X_test, Y_train, Y_test))
print("DT:", evaluate(dt, X_train, X_test, Y_train, Y_test))


scaler = MinMaxScaler()
X_train_s = scaler.fit_transform(X_train)
X_test_s = scaler.transform(X_test)


print("\nAFTER SCALING ")
print("Logistic:", evaluate(lr, X_train_s, X_test_s, Y_train, Y_test))
print("KNN:", evaluate(knn, X_train_s, X_test_s, Y_train, Y_test))
print("DT:", evaluate(dt, X_train_s, X_test_s, Y_train, Y_test))