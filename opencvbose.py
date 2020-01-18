import cv2
import numpy as np
video_capture = cv2.VideoCapture(0) #the default webcam (0, the first webcam device detected). Change if you have more than one webcam connected and want to use another one than the default one
facecascade = cv2.CascadeClassifier("/Library/Python/2.7/site-packages/cv2/data/haarcascade_frontalface_default.xml") #load the trained classifier model
while True:
    ret, frame = video_capture.read() #Grab frame from webcam. Ret is 'true' if the frame was successfully grabbed.
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) #Convert image to grayscale to improve detection speed and accuracy
    #Run classifier on frame
    face = facecascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=20, minSize=(10, 10), flags=cv2.CASCADE_SCALE_IMAGE)
    for (x, y, w, h) in face: #Draw rectangle around detected faces
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2) #draw it on the colour image "frame", with arguments: (coordinates), (size), (RGB color), line thickness 2
    cv2.imshow("webcam", frame) #Display frame
    if cv2.waitKey(1) & 0xFF == ord('q'): #imshow expects a termination definition in order to work correctly, here it is bound to key 'q'
        break
