import numpy as np

def rms(a, n):
    # Represent the readings as a 1 x n matrix (row vector)
    A = np.array(a, dtype=float).reshape(1, n)
    
    # Multiplying A (1 x n) by its transpose A.T (n x 1) yields the sum of squares
    sum_sq = (A @ A.T)[0, 0]
    
    # Calculate the root mean square
    return np.sqrt(sum_sq / n)

if __name__ == "__main__":
    n = int(input().strip())
    readings = list(map(float, input().split()))
    
    result = rms(readings, n)
    print(f"{result:.2f}")

