import sys

dic = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6, "G": 7, "H": 8}
dic_reverse = {v: k for k, v in dic.items()}

k_start, s_start, N = map(str, sys.stdin.readline().split())
k_x, k_y = dic[k_start[0]], int(k_start[1])
s_x, s_y = dic[s_start[0]], int(s_start[1])

def go(command):
    global k_x, k_y, s_x, s_y

    dx, dy = 0, 0
    if command == "R":
        dx, dy = 1, 0
    elif command == "L":
        dx, dy = -1, 0
    elif command == "B":
        dx, dy = 0, -1
    elif command == "T":
        dx, dy = 0, 1
    elif command == "RT":
        dx, dy = 1, 1
    elif command == "LT":
        dx, dy = -1, 1
    elif command == "RB":
        dx, dy = 1, -1
    elif command == "LB":
        dx, dy = -1, -1

    temp_k_x, temp_k_y = k_x + dx, k_y + dy

    if 1 <= temp_k_x <= 8 and 1 <= temp_k_y <= 8:
        if temp_k_x == s_x and temp_k_y == s_y:
            temp_s_x, temp_s_y = s_x + dx, s_y + dy
            if 1 <= temp_s_x <= 8 and 1 <= temp_s_y <= 8:
                s_x, s_y = temp_s_x, temp_s_y
                k_x, k_y = temp_k_x, temp_k_y
        else : k_x, k_y = temp_k_x, temp_k_y
                

for _ in range(int(N)):
    command = sys.stdin.readline().strip()
    go(command)

print(f'{dic_reverse.get(k_x)}{k_y}')
print(f'{dic_reverse.get(s_x)}{s_y}')
