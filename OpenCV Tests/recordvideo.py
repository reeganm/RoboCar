import numpy as np
import cv2
import time


cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320) #1280 max
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 180) #720 max

fgbg = cv2.createBackgroundSubtractorMOG2()

#fourcc = cv2.VideoWriter_fourcc(*'DIVX')
#out = cv2.VideoWriter('output.avi',fourcc, 40.0, (int(cap.get(3)),int(cap.get(4)))) #1280 720

lasttime = time.time()
count = 0.0
starttime = time.time()

while(True):
    ret, frame = cap.read()
    print()
    print("frame size: ",frame.shape)
        
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    laplacian = cv2.Laplacian(frame,cv2.CV_64F)
    sobelx = cv2.Sobel(frame,cv2.CV_64F,1,0,ksize=5)
    sobely = cv2.Sobel(frame,cv2.CV_64F,0,1,ksize=5)
    edges = cv2.Canny(frame,100,200)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    _,ostu = cv2.threshold(gray,0,255,cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    fgmask = fgbg.apply(frame)
    
#    out.write(frame)
    cv2.imshow('frame',frame)
    cv2.imshow('hsv',hsv)
    cv2.imshow('laplacian',laplacian)
    cv2.imshow('sobelx',sobelx)
    cv2.imshow('sobely',sobely)
    cv2.imshow('edges',edges)
    cv2.imshow('gray',gray)
    cv2.imshow('ostu',frame&(np.repeat(ostu[:,:,np.newaxis], 3, axis=2)))
    cv2.imshow('fgmask',np.repeat(fgmask[:,:,np.newaxis], 3, axis=2)&hsv)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    count = count + 1
    print("sample time (ms): ", round((time.time()-lasttime)*1000,1))
    print("average_fps: ",round(count/(time.time()-starttime),1))
    lasttime = time.time()

cap.release()
#out.release()
cv2.destroyAllWindows()