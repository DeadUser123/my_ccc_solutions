min_distance = int(input())
max_distance = int(input())
n = int(input())
motel_locations = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
for i in range(n):
    motel_locations.append(int(input()))
motel_locations.sort()

dp = [0] * (len(motel_locations))
dp[0] = 1

for i in range(len(motel_locations)):
    for j in range(i + 1, len(motel_locations)):
        if min_distance <= motel_locations[j] - motel_locations[i] <= max_distance:
            dp[j] += dp[i]

count = dp[-1]
print(count)
