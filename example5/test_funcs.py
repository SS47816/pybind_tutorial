import cppimport
import numpy as np

eigen_op = cppimport.imp("eigen_op")

if __name__ == '__main__':
    A = np.array([[1, 2, 1],
                  [2, 1, 0],
                  [-1, 1, 2]])
    
    print(A)
    print(eigen_op.inv(A))
    print(eigen_op.det(A))
