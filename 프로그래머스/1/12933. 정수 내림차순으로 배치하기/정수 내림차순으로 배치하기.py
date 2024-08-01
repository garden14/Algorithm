def solution(n):
    num = list(map(int,str(n)))
    num.sort(reverse=True)
    
    answer = ''.join(map(str, num))
    
    return int(answer)