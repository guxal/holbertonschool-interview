#!/usr/bin/python3
""" lockboxes module """


def reUnlock(boxes, inc, keys):
    
    if (len(boxes) > inc):
        if(inc in keys):
            keys += boxes[inc]
        #print("box: {}, INDEX: {}".format(boxes[inc], inc))
        #print("keys: {}".format(keys))
        reUnlock(boxes, inc + 1, keys)
    
    if (inc < len(boxes)):
        if (inc in keys):
            keys += boxes[inc]
    #print("inc: {}".format(inc))
    #print("keys: {}".format(keys))
    #print("len: {}".format(set(keys) | {0}))
    
    return len(list(set(keys)| {0})) == len(boxes)
    


def canUnlockAll(boxes):
    """
    Returns:
        True  if the all boxes is Unlock else False
    Parameters:
        boxes: is a list of lists
    """
    #print("len boxes {}".format(len(boxes)))
    #print("init keys {}".format(boxes[0]))
    return reUnlock(boxes, 1, boxes[0])
