import cppimport
import numpy as np

numpy_op = cppimport.imp("numpy_op")

if __name__ == '__main__':
    xs = np.arange(12).reshape(3, 4).astype('float')
    print(xs)
    print("np :", xs.sum())
    print("cpp :", numpy_op.sum(xs))

    print()
    numpy_op.twice(xs)
    print(xs)
