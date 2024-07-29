def solution(players, callings):
    answer = {player : i for i, player in enumerate(players)}
    
    for i in callings : 
        idx = answer[i]
        answer[i] -= 1
        answer[players[idx-1]] += 1
        players[idx-1], players[idx] = players[idx], players[idx-1]
        
    return players