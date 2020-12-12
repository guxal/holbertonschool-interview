#!/usr/bin/python3
""" lockboxes module """


class Unlock:
    """
    Class definition: Unlock
    """
    def all(self, box):
        """ Function all

        Returns:
            box: box array to open
        """
        size = len(box)
        self.keys = [False]*size
        self.helper(box, 0)
        return all(self.keys)

    def helper(self, box, index):
        """ Function helper

        Returns:
            box: box to open
            index: current index
        """
        if self.keys[index]:
            return
        self.keys[index] = True
        for i in box[index]:
            if isinstance(i, int) and i >= 0 and i < len(box)\
             and not self.keys[i]:
                self.helper(box, i)
            elif (len(box) + 1 == 1000):
                return
            else:
                continue


def canUnlockAll(boxes):
    """
    Returns:
        True if the all boxes is Unlock else False
    Parameters:
        boxes: is a list of lists
    """
    if len(boxes) == 0:
        return True

    if not isinstance(boxes, list):
        return False

    return Unlock().all(boxes)
