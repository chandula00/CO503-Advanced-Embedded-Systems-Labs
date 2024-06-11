from PIL import Image
import numpy as np

# Function to read BMP image and get RGB values
def read_bmp_image(image_path):
    # Open the image file
    with Image.open(image_path) as img:
        # Convert image to RGB
        img = img.convert('RGB')
        # Get image data as a NumPy array
        img_data = np.array(img)
    return img_data

# Path to your BMP image
image_path = 'resized_image.bmp'

# Get RGB values
rgb_values = read_bmp_image(image_path)

print(rgb_values)
