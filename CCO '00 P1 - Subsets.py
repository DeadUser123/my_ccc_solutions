n = int(input())
di = dict()
for _ in range(n):
    x, y = input().split(" contains ")
    try:
        di[x].append(y)
    except:
        di[x] = [y]
    if y.isupper() and di.get(y) == None:
            di[y] = []
            
for key in sorted(di.keys()):
    elements = set()
    q = [key]
    visited = set()
    visited.add(key)
    while q:
        curr = q.pop(0)
        for ele in di.get(curr):
            if ele.islower():
                elements.add(ele)
            elif ele not in visited:
                q.append(ele)
                visited.add(ele)
    print(f"{key} = " + "{" + ",".join(sorted(list(elements))) + "}")
