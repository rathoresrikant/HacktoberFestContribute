
# coding: utf-8

# In[77]:


import os
import cv2
import time


# In[78]:


gesture_name = raw_input("Enter Gesture Name ")


# In[79]:


images = []
num_frames = 60


# In[80]:


capture_start = False
cv2.namedWindow("Video", cv2.WINDOW_NORMAL)

vc = cv2.VideoCapture(0)
vc.set(cv2.CAP_PROP_FPS, 5)

rval, frame = vc.read()

cnt = 0

while True:
    
    if frame is not None: 
        
        frame = cv2.flip(frame, 1)
        cv2.imshow("Video", frame)
        
    rval, frame = vc.read()
    keypress = cv2.waitKey(1)
    
    if keypress == ord('q'):
        break
    elif keypress == ord('c'):
        capture_start = True
    
    if ( capture_start ):
        img = cv2.flip(frame, 1)
        #img = cv2.cvtColor( img, cv2.COLOR_RGB2BGR )
        images.append(img)
        cnt += 1
        if ( cnt > num_frames ):
            break
        
vc.release()
cv2.destroyAllWindows()
cv2.waitKey(1)


# In[81]:


if len(images) == 0:
    print(" ERROR !!  No Frames Recorded" )
    exit()


# In[83]:


last_num = 0
folder_name = gesture_name
gestures_rec = os.listdir('./')

for i in gestures_rec:
    
    if i[0] == '.':
        continue
    if '_'.join( i.split('_')[:-1] ) == gesture_name:
        last_num = max(last_num, int( i.split('_')[-1] ) )

last_num += 1
folder_name = gesture_name + '_' + str(last_num)
try:
    print('[i] Creating directory {}...'.format(folder_name))
    os.makedirs(folder_name)
except (IOError) as e:
    print('[!]', str(e))
    exit()


# In[84]:


print ("[i] Creating Video")
output = './' + folder_name + '/output.mp4'
fourcc = cv2.VideoWriter_fourcc(*'mp4v') # Be sure to use lower case
out = cv2.VideoWriter(output, fourcc, 5.0, (images[0].shape[1], images[0].shape[0]) )

for image in images:

    f = image
    #print (f.shape)
    out.write(f) # Write out frame to video

    #cv2.imshow('video',frame)
    if (cv2.waitKey(1) & 0xFF) == ord('q'): # Hit `q` to exit
        break

# Release everything if job is finished
out.release()
cv2.destroyAllWindows()


# In[ ]:


print ("Output Video is in", output)

