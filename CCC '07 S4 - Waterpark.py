# setting things up
n = int(input())
connections = dict()
for i in range(1, n + 1):
    connections[str(i)] = []
    
while True:
    point1, point2 = input().split()
    if point1 == '0' and point2 == '0':
        break
    connections[point2].append(point1) # sets dp up

waysToReach = {'1' : 1,} # initial point
for num in range(2, n + 1):
    waysToReach[str(num)] = 0
    for reachablePoint in connections[str(num)]:
        waysToReach[str(num)] += waysToReach[reachablePoint] # determines number of ways to reach each point
        
print(waysToReach[str(n)])
