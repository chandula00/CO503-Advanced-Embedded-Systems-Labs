import numpy as np
from scipy.fftpack import dct

def dct_2d(matrix):
    # Perform DCT on rows
    dct_rows = dct(matrix, type=2, norm='ortho', axis=0)
    # Perform DCT on columns
    dct_result = dct(dct_rows, type=2, norm='ortho', axis=1)
    return dct_result

def compare_dct(input_data, transformed_data):
    # Convert the input data to a numpy array
    input_matrix = np.array(input_data).reshape((8, 8))
    
    # Compute the DCT of the input matrix
    dct_computed = dct_2d(input_matrix)
    
    # Convert the provided transformed data to a numpy array
    transformed_matrix = np.array(transformed_data).reshape((8, 8))
    
    # Compare the computed DCT with the provided transformed data
    comparison = np.allclose(dct_computed, transformed_matrix, atol=1e-2)
    
    return comparison, dct_computed, transformed_matrix

# Example input data (from the provided example)
input_data = np.array([
    -54,  -79,  -36,   -8,  -35,  -37,  -19,  -40,
   -121,  -18,  -23,  -17,  -19,   -7,  -21,    8,
     2,  -89,  -27,  -12,  -30,  -23,  -39,  -32,
    -20,  -88,  -53,  -24,  -46,  -49,  -24,    2,
    -47,  -17, -123,  -37,  -21,    6,    1,  -20,
    -31,  -12,  -38,  -67,  -35,  -45,  -50,  -41,
    -43,  -19,  -26,  -92,  -19,  -13,  -37,  -61,
    -56,  -59,  -12,  -32, -117,   21,   17,    5
])

# Example transformed data (from the provided example)
transformed_data = [
    -26, 0, 4, 3, 1, 0, -2, -3, 
    -8, 2, -5, -6, -8, -8, 3, 10, 
    -33, -10, 0, -1, 0, 4, -3, -10, 
    6, 3, -8, -6, 3, 6, 0, -4, 
    -76, -6, -1, -1, -1, 1, -5, -9, 
    -53, -5, 0, 4, 1, -5, -2, 3, 
    116, -1, 11, 7, -4, -6, 0, 2, 
    -20, 10, -3, 0, 0, -8, -2, 8
]

# Compare the DCT results
comparison, dct_computed, transformed_matrix = compare_dct(input_data, transformed_data)

print("Is the DCT correct?", comparison)
print("Computed DCT:\n", dct_computed)
print("Provided Transformed Data:\n", transformed_matrix)
