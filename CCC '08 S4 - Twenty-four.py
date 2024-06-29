ans = None

def begin_solving(nums):
    for num in nums:
        nums_left = nums[:]
        nums_left.remove(num)
        twentyfour(num, nums_left)
        
def twentyfour(current_result, nums_left):
    global ans
    if len(nums_left) == 0:
        if ans == None and current_result <= 24:
            ans = current_result
        elif current_result <= 24 and current_result > ans:
            ans = current_result
        return
    for num in nums_left:
        updated_nums_left = nums_left[:]
        updated_nums_left.remove(num)
        twentyfour(current_result + num, updated_nums_left)
        twentyfour(current_result - num, updated_nums_left)
        twentyfour(num - current_result, updated_nums_left)
        twentyfour(current_result * num, updated_nums_left)
        if num != 0 and current_result % num == 0:
            twentyfour(current_result // num, updated_nums_left)
        if current_result != 0 and num % current_result == 0:
            twentyfour(num // current_result, updated_nums_left)
    if len(nums_left) == 2:
        twentyfour(current_result, [nums_left[0] + nums_left[1]])
        twentyfour(current_result, [nums_left[0] - nums_left[1]])
        twentyfour(current_result, [nums_left[1] - nums_left[0]])
        twentyfour(current_result, [nums_left[0] * nums_left[1]])
        if nums_left[0] % nums_left[1] == 0 and nums_left[1] != 0:
            twentyfour(current_result, [nums_left[0] // nums_left[1]])
        if nums_left[1] % nums_left[0] == 0 and nums_left[0] != 0:
            twentyfour(current_result, [nums_left[1] // nums_left[0]])

n = int(input())
computed = dict()
for _ in range(n):
    ans = None
    inputs = []
    for _ in range(4):
        inputs.append(int(input()))
    inputs.sort()
    
    # if we've already computed the answer for this set of numbers
    if tuple(inputs) in computed.keys():
        print(computed[tuple(inputs)])
        continue
    
    begin_solving(inputs)
    print(ans)
    computed[tuple(inputs)] = ans
