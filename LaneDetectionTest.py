import numpy as np
import cv2
import time


cap = cv2.VideoCapture('TestVideos\hercules_runTrim.mp4')
#cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320) #1280 max
#cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 180) #720 max

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
    
    #brg?
    mask = cv2.inRange(frame,(225,0,0),(255,255,255))
    
    
    
    edges = cv2.Canny(mask,100,200)

    
#   out.write(frame)
    cv2.imshow('frame',frame)
    cv2.imshow('edges',edges)
    cv2.imshow('mask',mask)


    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    count = count + 1
    print("sample time (ms): ", round((time.time()-lasttime)*1000,1))
    print("average_fps: ",round(count/(time.time()-starttime),1))
    lasttime = time.time()

cap.release()
#out.release()
cv2.destroyAllWindows()