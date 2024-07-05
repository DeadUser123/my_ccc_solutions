def findLineEquation(x1, y1, x2, y2):
    if x1 == x2:  # Vertical line
        return None, x1
    else:
        slope = (y2 - y1) / (x2 - x1)
        intercept = y1 - slope * x1
        return slope, intercept

def findIntercept(slope1, slope2, intercept1, intercept2):
    if slope1 is None and slope2 is None: # if both lines are vertical
        return ("colinear", "colinear") if intercept1 == intercept2 else (None, None)
    elif slope1 is None: # if the first is vertical
        x = intercept1
        y = slope2 * x + intercept2
    elif slope2 is None: # if the second is vertical
        x = intercept2
        y = slope1 * x + intercept1
    elif slope1 != slope2: # if both aren't colinear
        x = (intercept2 - intercept1) / (slope1 - slope2)
        y = slope1 * x + intercept1
    else: # if both are colinear
        return ("colinear", "colinear") if intercept1 == intercept2 else (None, None)
    return x, y

def isOnSegment(px, py, x1, y1, x2, y2):
    return min(x1, x2) <= px <= max(x1, x2) and min(y1, y2) <= py <= max(y1, y2)

x1, y1, x2, y2 = list(map(int, input().split()))
slope, intercept = findLineEquation(x1, y1, x2, y2)
intersects = 0
n = int(input())
for _ in range(n):
    pointsList = list(map(int, input().split()))
    pointsList.pop(0)  # Remove the first element as it represents the number of points
    for pointIndex in range(0, len(pointsList), 2):
        testX1, testY1 = pointsList[pointIndex], pointsList[pointIndex + 1] # test points represent the edge we are testing
        if pointIndex + 2 >= len(pointsList):
            testX2, testY2 = pointsList[0], pointsList[1]
        else:
            testX2, testY2 = pointsList[pointIndex + 2], pointsList[pointIndex + 3]
        
        testSlope, testIntercept = findLineEquation(testX1, testY1, testX2, testY2)
        intersectX, intersectY = findIntercept(slope, testSlope, intercept, testIntercept)
        
        if intersectX is None and intersectY is None:
            continue
        if intersectX == "colinear" and intersectY == "colinear":
            if isOnSegment(testX1, testY1, x1, y1, x2, y2) or isOnSegment(testX2, testY2, x1, y1, x2, y2):
                intersects += 1
                break
            elif isOnSegment(x1, y1, testX1, testY1, testX2, testY2) or isOnSegment(x2, y2, testX1, testY1, testX2, testY2):
                intersects += 1
                break
        elif isOnSegment(intersectX, intersectY, x1, y1, x2, y2) and isOnSegment(intersectX, intersectY, testX1, testY1, testX2, testY2):
            intersects += 1
            break

print(intersects)
