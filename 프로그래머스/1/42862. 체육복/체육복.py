def solution(n, lost, reserve):
    lost_ = set(lost) - set(reserve)
    reserve_ = set(reserve) - set(lost)
    
    answer = 0

    for i in reserve_ :
        front = i - 1
        back = i + 1
        if front in lost_ :
            lost_.remove(front)
        elif back in lost_ :
            lost_.remove(back)
            
    return n - len(lost_)