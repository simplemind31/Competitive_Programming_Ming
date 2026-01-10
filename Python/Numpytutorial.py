import numpy as np

arr = np.array([1, 2, 3, 4, 5])

#print(arr)

#print(type(arr))

#print(np.__version__)
"""
# 0-D array
arr = np.array(42)
# 1-D
arr = np.array([1, 2, 3, 4, 5])
# 2-D
arr = np.array([[1, 2, 3], [4, 5, 6]])
# 3-D
arr = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])
print(arr)
"""
"""
a = np.array(42)
b = np.array([1, 2, 3, 4, 5])
c = np.array([[1, 2, 3], [4, 5, 6]])
d = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])

#print the number of dimensions
print(a.ndim)
print(b.ndim)
print(c.ndim)
print(d.ndim)
"""
"""
arr = np.array([[1,2,3,4],[5,6,7,8]], ndmin=5)

print(arr)
"""
arr = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])

#print(arr[0, 1, 2])
arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])

#print(arr[0:2, 1:4])
#print(arr[0:2, 2])
#print(arr.dtype)
arr = np.array([1, 2, 3, 4], dtype='S')

#print(arr)
#print(arr.dtype)
arr = np.array([1.1, 2.1, 3.1])

newarr = arr.astype('i')

#print(newarr)
#print(newarr.dtype)
arr = np.array([1, 2, 3, 4, 5])
x = arr.view()
arr[0] = 42

#print(arr)
#print(x)
x = arr.copy()
y = arr.view()

#print(x.base)
#print(y.base)
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
newarr = arr.reshape(2, 3, 2)
newarr[0][0]=3
newarr = arr.reshape(2, 2, -1)
#print(newarr)
arr = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])

"""
for x in np.nditer(arr):
  print(x)
"""
arr = np.array([1, 2, 3])
"""
for x in np.nditer(arr, flags=['buffered'], op_dtypes=['S']):
  print(x)
print(arr)
"""
arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
"""
for x in np.nditer(arr[:, ::2]):
  print(x)
"""
arr = np.array([1, 2, 3])
"""
for idx, x in np.ndenumerate(arr):
  print(idx, x)
"""
arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
"""
for idx, x in np.ndenumerate(arr):
  print(idx, x)
"""
arr1 = np.array([1, 2, 3])

arr2 = np.array([4, 5, 6])

arr = np.concatenate((arr1, arr2))
arr = np.stack((arr1, arr2), axis=1)
arr = np.hstack((arr1, arr2))
arr = np.vstack((arr1, arr2))
arr = np.dstack((arr1, arr2))
#print(arr)
arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])
arr = np.concatenate((arr1, arr2), axis=1)
#print(arr)
arr = np.array([1, 2, 3, 4, 5, 6])
newarr = np.array_split(arr, 4)
arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12], [13, 14, 15], [16, 17, 18]])

newarr = np.array_split(arr, 3, axis=1)

#print(newarr)
newarr = np.hsplit(arr, 3)
arr = np.array([1, 2, 3, 4, 5, 4, 4])
x = np.where(arr == 4)
arr = np.array([6, 7, 8, 9])

x = np.searchsorted(arr, 7, side='right')
arr = np.array([[3, 2, 4], [5, 0, 1]])
arr = np.array([41, 42, 43, 44])
"""
x = [True, False, True, False]
newarr = arr[x]
"""
filter_arr=arr>42
newarr=arr[filter_arr]
x=np.random.randint(1,100)
x=np.random.randint(100, size=(100))
x=np.random.randint(100, size=(3, 5))
#float
x=np.random.rand(5)
x=np.random.rand(3, 5)
x=np.random.choice([3, 5, 7, 9])
x=np.random.choice([3, 5, 7, 9], size=(3, 5))
#print(x)
arr = np.array([1, 2, 3, 4, 5])
np.random.shuffle(arr)
#print(arr)
#print(np.random.permutation(arr))

#import matplotlib.pyplot as plt
#import seaborn as sns
"""
sns.displot([0, 1, 2, 3, 4, 5])
plt.show()
"""
"""
sns.displot([0, 1, 2, 3, 4, 5], kind="kde")
plt.show()
"""
x=np.random.normal(size=(2, 3))
x=np.random.normal(loc=1, scale=2, size=(2, 3))
#sns.displot(np.random.normal(size=1000), kind="kde")
#plt.show()
x=np.random.binomial(n=10, p=0.5, size=10)
x=np.random.poisson(lam=2, size=10)
x=np.random.uniform(size=(2, 3))
print(x)