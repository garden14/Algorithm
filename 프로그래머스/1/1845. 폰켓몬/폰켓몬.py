def solution(nums):
    selec = len(nums) // 2
    if len(set(nums)) >= selec :
        return selec 
    else :
        return len(set(nums))