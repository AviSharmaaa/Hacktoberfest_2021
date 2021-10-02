# install the modules 'pyqrcode' and 'pypng' first if you haven't
# pip install pyqrcode
# pip install pypng

import pyqrcode
import png
from pyqrcode import QRCode

link = str(input("Enter Link - "))
# Example Input -> https://www.youtube.com/

# Generating QR code
url = pyqrcode.create(link)
print("QR Code generated successfully!")

filename = str(input("Enter filename - "))
# Example Input -> youtubeQR

pngFile = filename+".png"
svgFile = filename+".svg"

# Creating and saving the png file
url.png(pngFile, scale = 10)
print("PNG file saved successfully!")

# Creating and saving the svg file
url.svg(svgFile, scale = 10)
print("SVG file saved successfully!")