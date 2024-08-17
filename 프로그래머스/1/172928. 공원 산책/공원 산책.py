def startDirec(park) :
    row, col = 0, 0
    for i in range (len(park)) :
        for j in range (len(park[0])) :
            if park[i][j] == 'S' :
                row, col = i, j
                break
    return row, col

def solution(park, routes):
    H, W = len(park) - 1, len(park[0]) - 1
    op = {'E' : (0,1), 'W' : (0,-1), 'S' : (1,0), 'N' : (-1,0)}
    x, y = startDirec(park)
    
    for route in routes :
        direc, num = route.split(" ")
        xx, yy = x, y
        
        for i in range (int(num)) :
            move_x = x + op[direc][0]
            move_y = y + op[direc][1]
            
            if (move_x>H or move_x<0 or move_y>W or move_y<0) or ('X' == park[move_x][move_y]) :
                x, y = xx, yy
                break
            else :
                x, y = move_x, move_y

    return (x, y)