from itertools import combinations

n, m = map(int,input().split())
chicken, house = [], []

for r in range(n):
    data = list(map(int, input().split()))  #한줄씩 행 입력
    for c in range(n):                      #입력받은거 원소 하나씩 판단
        if data[c] == 1:                    # 가정집이면
            house.append((r,c))
        elif data[c] == 2:                  # 치킨집이면
            chicken.append((r,c))

candidates = list(combinations(chicken,m)) # m개의 치킨집 고르는 경우의 수

def get_sum(candidate):     #치킨거리의 합 계산
    result = 0
    for hx,hy in house:     #모든 집의 좌표
        temp = 1e9
        for cx,cy in candidate:    #치킨집의 좌표
            temp = min(temp, abs(hx-cx) + abs(hy-cy)) #가장 가까운 치킨집 찾기 
        result += temp      #도시의 치킨거리 합
    return result

result = 1e9
for candidate in candidates:
    result = min(result, get_sum(candidate)) #모두 검사하여 가장 작은 치킨거리 찾기

print(result)