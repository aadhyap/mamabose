from PIL import Image
import os, sys

path = ('/Users/afreglette/mamabose/mamabose/dataset')
# dirs = os.listdir(path)
files = [path + '/' + x for x in os.listdir(path)]

def resize():
    for dir in files:
        if dir[-5:] == 'Store': continue
        for item in os.listdir(dir):
            print(item)
            if item[-5:] == 'Store': continue
            im = Image.open(dir + '/' + item)
            f, e = os.path.splitext(item)
            imResize = im.resize((350, 350), Image.ANTIALIAS)
            imResize.save(dir + '/' + item, 'JPEG', quality=90)

resize()