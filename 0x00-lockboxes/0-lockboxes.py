#!/usr/bin/python3
""" lockboxes module """


def reUnlock(boxes, inc, keys, idx):
    """
    Returns: True if the all boxes is Unlock else False
    Parameters:
        boxes: is a list of lists
        inc: index of lists
        keys: keys open box
    """
    if (len(boxes) > inc):
        if(inc in keys):
            keys += boxes[inc]
        else:
            idx += [inc]
        reUnlock(boxes, inc + 1, keys, idx)

    if (inc == len(boxes)):
        for x in idx:
            if (x in keys):
                keys += boxes[x]

    if (inc < len(boxes)):
        if (inc in keys):
            keys += boxes[inc]

    return len(list(set(keys) | {0})) == len(boxes)


def canUnlockAll(boxes):
    """
    Returns:
        True if the all boxes is Unlock else False
    Parameters:
        boxes: is a list of lists
    """
    return reUnlock(boxes, 1, boxes[0], [])
