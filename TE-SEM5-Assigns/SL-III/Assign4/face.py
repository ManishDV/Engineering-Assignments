import numpy as np
import cv2

face_cascade = cv2.CascadeClassifier('/home/neo/haarcascade_frontalface_default.xml')
# eye_cascade = cv2.CascadeClassifi	er('haarcascade_eye.xml')

cap = cv2.VideoCapture(0)

while (True):
    
    ret,img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # cv2.imshow('Color',gray)
    faces = face_cascade.detectMultiScale(img, 1.3, 5)
    for (x,y,w,h) in faces:
        gray = cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = gray[y:y+h, x:x+w]
        cv2.imshow('frame',gray)      
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
            break
            
cap.release()
cv2.destroyAllWindows()