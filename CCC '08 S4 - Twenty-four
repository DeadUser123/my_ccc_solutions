ans = 0.14

def start(li):
    for i in li:
        x = li[:]
        x.remove(i)
        twentyfour(i, x)
        
def twentyfour(current, li):
    global ans
    if len(li) == 0:
        if ans == 0.14 and current <= 24:
            ans = current
        elif current <= 24 and current > ans:
            ans = current
        return current
    for i in li:
        x = li[:]
        x.remove(i)
        twentyfour(current + i, x)
        twentyfour(current - i, x)
        twentyfour(i - current, x)
        twentyfour(current * i, x)
        if i != 0 and current % i == 0:
            twentyfour(current // i, x)
        if current != 0 and i % current == 0:
            twentyfour(i // current, x)
    if len(li) == 2:
        twentyfour(current, [li[0] + li[1]])
        twentyfour(current, [li[0] - li[1]])
        twentyfour(current, [li[1] - li[0]])
    

n = int(input())
done = dict()
for _ in range(n):
    ans = 0.14
    res = []
    for _ in range(4):
        res.append(int(input()))
    res.sort()
    
    # if we've already computed the answer for this set of numbers
    if tuple(res) in done.keys():
        print(done[tuple(res)])
        continue
    
    start(res)
    print(ans)
    done[tuple(res)] = ans
