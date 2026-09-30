from PIL import Image

# Open the image
image = Image.open("IMG_20260923_172045 644_HDR.jpg")

# Convert to grayscale
gray_image = image.convert("L")

# Save the grayscale image
gray_image.save("my_photo_grayscale.jpg")

print("Grayscale image created successfully!")
