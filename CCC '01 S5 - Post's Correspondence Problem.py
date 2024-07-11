def solve(aString, bString, sequence, limit):
    if aString == bString and len(aString) > 0:
        return sequence
    if len(sequence) < limit:
        for idx in range(len(a)):
            newSequence = sequence[:]
            newSequence.append(idx)
            result = solve(aString + a[idx], bString + b[idx], newSequence, limit)
            if result is not None:
                return result
    return None

limit = int(input())
n = int(input())
a = []
b = []
for _ in range(n):
    a.append(input())
for _ in range(n):
    b.append(input())
    
ans = solve("", "", [], limit)
if ans is None:
    print("No solution.")
else:
    print(len(ans)) # printing k
    for num in ans:
        print(num + 1) # since problem treats A and B as 1-indexed lists
